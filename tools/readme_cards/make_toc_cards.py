#!/usr/bin/env python3
"""Generate the "📑 Contents" cards for the iTeach READMEs.

Each README section gets a dark SVG card (numbered badge, category chip,
title, one-line description, sub-sections) in <repo>/media/toc/, and the
"## 📑 Contents" block of <repo>/README.md is rewritten with the card grid
plus a collapsible text index.

Usage (from a directory that contains the iTeach, iTeachSkillsApp and
iTeach-UOIS clones):

    python iTeach/tools/readme_cards/make_toc_cards.py            # all repos
    python iTeach/tools/readme_cards/make_toc_cards.py iTeach-UOIS  # one repo

When you add, rename or reorder a README section, edit CARDS below and
re-run. Headings are matched by their exact text (emoji included); the
script fails loudly if a heading or anchor is missing, or if a line is too
long to fit on a card.
"""
import html
import os
import re
import sys
import unicodedata

ROOT = os.getcwd()

# category -> (chip label, accent colour)
CATEGORY = {
    'understand': ('UNDERSTAND', '#58a6ff'),
    'setup':      ('SET UP',     '#3fb950'),
    'run':        ('RUN',        '#f0883e'),
    'ref':        ('REFERENCE',  '#bc8cff'),
    'more':       ('MORE',       '#8b949e'),
}
COLOURS = dict(bg='#161b22', border='#30363d', title='#f0f6fc', text='#9198a1')
FONT = "-apple-system, BlinkMacSystemFont, 'Segoe UI', 'Noto Sans', Helvetica, Arial, sans-serif"
W, H = 460, 132
MAX_TITLE, MAX_LINE = 28, 54

MORE = [('📜 License', 'License'), ('📚 Citation', 'Citation'), ('📬 Contact', 'Contact'), ('🙏 Acknowledgements', 'Thanks')]

# repo -> [(README heading, card title, category, description, [(sub-heading, label), ...])]
CARDS = {
    'iTeach': [
        ('🎬 How It Works', 'How It Works', 'understand', 'The overview video and the FS3 labelling steps', []),
        ('📈 Results', 'Results', 'understand', 'Perception, manipulation and the user study',
         [('🎯 Perception adaptation', 'Perception'), ('🦾 Manipulation follows', 'Manipulation'),
          ('👥 Who can teach? · 12-participant user study', 'User study')]),
        ('🧩 Code', 'Code', 'setup', 'Which repository does what, and in what order',
         [('📦 Data & Checkpoints', 'Data & checkpoints'), ('🛠️ Hardware', 'Hardware')]),
        ('🚪 iTeach v1: Door & Handle Detection (DH-YOLO)', 'iTeach v1 · DH-YOLO', 'ref',
         'The earlier door and handle detection system',
         [('🚀 Getting started in 3 steps', 'Getting started'), ('📁 Directory structure', 'Directory structure')]),
        ('📜 License', 'License · Cite · Contact', 'more', 'License, citation, contact and thanks', MORE),
    ],
    'iTeachSkillsApp': [
        ('🧭 System Overview', 'System Overview', 'understand', 'How the robot, laptop and HoloLens fit together',
         [('🔁 The teaching loop', 'Loop'), ('🏗️ Architecture', 'Architecture'), ('🎬 One iTeach round', 'One round')]),
        ('🚀 Running the Live System on the Robot', 'Run on the Robot', 'run', 'A full iTeach session on the Fetch', []),
        ('🛠️ Build and Deploy the HoloLens 2 App', 'Build the HoloLens App', 'setup',
         'Build in Unity and install on the headset',
         [('Requirements', 'Requirements'), ('Which Unity project?', 'Which project'), ('Steps', 'Steps')]),
        ('🔌 Point the App at Your ROS Server', 'Configure ROS', 'setup', 'Required: upload the config to LocalAppData',
         [('1 · Prepare `ROSConnectionConfig.json`', 'Prepare'),
          ('2 · Upload it with the Windows Device Portal', 'Upload via Device Portal')]),
        ('📦 Environment Setup', 'Environment Setup', 'setup', 'Python, ROS Noetic and the TCP endpoint',
         [('1 · Conda environment', 'Conda'), ('2 · ROS 1 Noetic via [RoboStack](https://robostack.github.io/)', 'ROS Noetic'),
          ('3 · Build `ros_tcp_endpoint`', 'Endpoint')]),
        ('🧪 Test Without the Robot', 'Test Offline', 'run', 'Try the app with a video or a recorded scene', []),
        ('📤 Output Format and Hand-off to iTeach-UOIS', 'Output Format', 'ref', 'prompts.json and the hand-off to iTeach-UOIS',
         [('`prompts.json`', 'prompts.json'), ('Scene layout expected by iTeach-UOIS', 'Scene layout')]),
        ('📜 License', 'License · Cite · Contact', 'more', 'License, citation, contact and thanks', MORE),
    ],
    'iTeach-UOIS': [
        ('📦 Datasets', 'Datasets', 'setup', 'Download the data and see where it goes', []),
        ('🔑 Checkpoints', 'Checkpoints', 'setup', 'Pretrained and iTeach fine-tuned weights', []),
        ('⚙️ Setup', 'Setup', 'setup', 'Install with Docker or locally',
         [('🐳 Option A: Docker (recommended)', 'Docker'), ('🧰 Option B: Local install', 'Local install')]),
        ('🗂️ iTeach-HumanPlay Data Layout', 'Data Layout', 'ref', 'What every scene folder must contain', []),
        ('🎭 Generating ground-truth masks for new HumanPlay scenes', 'Ground-Truth Masks', 'run',
         'Turn a new capture into labels with SAM2', []),
        ('🏋️ MSMFormer Training', 'Training', 'run', 'Fine-tune MSMFormer: RGB, RGB-D, LoRA', []),
        ('🤖 Live ROS node on the robot', 'Live ROS Node', 'run', 'Serve predictions to the HoloLens', []),
        ('📊 Evaluation', 'Evaluation', 'run', 'Score a model on the HumanPlay test set', []),
        ('🐛 Known Error Fixes', 'Troubleshooting', 'ref', 'Fixes for common install and runtime errors', []),
        ('🙌 Built On', 'Credits · License · Cite', 'more', 'Built on, license, citation, contact, thanks',
         [('🙌 Built On', 'Built On')] + MORE),
    ],
}


def slug(heading):
    """GitHub's heading anchor: lower-case, drop punctuation/emoji, spaces -> '-'."""
    t = re.sub(r'<[^>]+>', '', heading).replace('`', '')
    t = re.sub(r'\[([^\]]*)\]\([^)]*\)', r'\1', t).strip().lower()
    keep = (c for c in t if unicodedata.category(c)[0] in 'LMN' or unicodedata.category(c) == 'Pc' or c in ' -')
    return ''.join(keep).replace(' ', '-')


def card_svg(num, title, cat, desc, subs):
    label, acc = CATEGORY[cat]
    c, e = COLOURS, html.escape
    chip_w = 22 + 8.4 * len(label)
    sub_line = f'<text x="96" y="104" font-family="{FONT}" font-size="12.5" font-weight="600" fill="{acc}" fill-opacity="0.9">{e("↳ " + " · ".join(subs))}</text>' if subs else ''
    return f'''<svg xmlns="http://www.w3.org/2000/svg" width="{W}" height="{H}" viewBox="0 0 {W} {H}">
  <defs><clipPath id="card"><rect x="1" y="1" width="{W-2}" height="{H-2}" rx="14"/></clipPath></defs>
  <rect x="1" y="1" width="{W-2}" height="{H-2}" rx="14" fill="{c['bg']}"/>
  <rect x="0" y="0" width="7" height="{H}" fill="{acc}" clip-path="url(#card)"/>
  <rect x="1" y="1" width="{W-2}" height="{H-2}" rx="14" fill="none" stroke="{c['border']}" stroke-width="1.5"/>
  <circle cx="52" cy="{H//2}" r="26" fill="{acc}" fill-opacity="0.14" stroke="{acc}" stroke-width="2"/>
  <text x="52" y="{H//2 + 7}" text-anchor="middle" font-family="{FONT}" font-size="20" font-weight="700" fill="{acc}">{e(num)}</text>
  <rect x="{W - 16 - chip_w}" y="16" width="{chip_w}" height="22" rx="11" fill="{acc}" fill-opacity="0.16"/>
  <text x="{W - 16 - chip_w/2}" y="31.5" text-anchor="middle" font-family="{FONT}" font-size="11" font-weight="700" letter-spacing="0.8" fill="{acc}">{e(label)}</text>
  <text x="96" y="{50 if subs else 58}" font-family="{FONT}" font-size="21" font-weight="700" fill="{c['title']}">{e(title)}</text>
  <text x="96" y="{76 if subs else 86}" font-family="{FONT}" font-size="14" fill="{c['text']}">{e(desc)}</text>
  {sub_line}
</svg>
'''


def build(repo):
    readme = os.path.join(ROOT, repo, 'README.md')
    s = open(readme).read()
    body = re.sub(r'```.*?```', '', s, flags=re.S)
    anchors = {h: slug(h) for h in re.findall(r'^#{2,3} (.+)$', body, re.M)}

    outdir = os.path.join(ROOT, repo, 'media', 'toc')
    os.makedirs(outdir, exist_ok=True)
    for f in os.listdir(outdir):
        if f.endswith('.svg'):
            os.remove(os.path.join(outdir, f))

    tiles, index = [], []
    for i, (head, title, cat, desc, subs) in enumerate(CARDS[repo], 1):
        more = cat == 'more'
        num, stem = ('✦', 'more') if more else (f'{i:02d}', f'{i:02d}')
        for h in [head] + [h for h, _ in subs]:
            assert h in anchors, f'{repo}: heading not found: {h!r}'
        labels = [l for _, l in subs]
        assert len(title) <= MAX_TITLE, f'{repo}: title too long: {title!r}'
        for line in (desc, '↳ ' + ' · '.join(labels)):
            assert len(line) <= MAX_LINE, f'{repo}: line too long ({len(line)}): {line!r}'

        with open(os.path.join(outdir, f'{stem}.svg'), 'w') as f:
            f.write(card_svg(num, title, cat, desc, labels))
        alt = html.escape(f'{num} · {title}: {desc}')
        tiles.append(f'<a href="#{anchors[head]}"><img src="media/toc/{stem}.svg" width="49%" alt="{alt}"></a>')

        if more:
            index.append('  <li>' + ' · '.join(f'<a href="#{anchors[h]}">{l}</a>' for h, l in subs) + '</li>')
        else:
            sub_html = ''.join(f'\n    <li><a href="#{anchors[h]}">{l}</a></li>' for h, l in subs)
            index.append(f'  <li><a href="#{anchors[head]}"><b>{title}</b></a> · {desc}'
                         + (f'\n    <ul>{sub_html}\n    </ul>\n  ' if subs else '') + '</li>')

    toc = ('## 📑 Contents\n\n<p align="center">\n' + '\n'.join(tiles) + '\n</p>\n\n'
           '<details>\n<summary><b>🗂️ Full index</b> <sub>(every section and subsection as text links)</sub></summary>\n<br>\n\n'
           '<ol>\n' + '\n'.join(index) + '\n</ol>\n\n</details>\n')

    start = s.index('## 📑 Contents')
    end = s.index('</details>\n', start) + len('</details>\n')
    with open(readme, 'w') as f:
        f.write(s[:start] + toc + s[end:])
    print(f'{repo}: {len(CARDS[repo])} cards')


if __name__ == '__main__':
    for repo in (sys.argv[1:] or CARDS):
        build(repo)
