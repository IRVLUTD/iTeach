#----------------------------------------------------------------------------------------------------
# Work done while being at the Intelligent Robotics and Vision Lab at the University of Texas, Dallas
# Please check the licenses of the respective works utilized here before using this script.
# 🖋️ Jishnu Jaykumar Padalunkal (2024) (Thanks to OpenAI ChatGPT for a bit of assistance! 😜)
#----------------------------------------------------------------------------------------------------

from setuptools import setup, find_packages

setup(
    name="IRVLUTDDoorHandleDataset",  # Package name
    version="0.0.2",                  # Version
    author="Jishnu Jaykumar P",        # Your name
    author_email="jishnu.p@utdallas.edu",  # Your email
    description="PyTorch dataset loader for IRVLUTD Door Handle dataset",
    long_description=open("README.md").read(),
    long_description_content_type="text/markdown",
    url="https://irvlutd.github.io/iTeach",  # Project page link
    packages=find_packages(),
    install_requires=[
        "torch",
        "Pillow",
        "numpy"
    ],
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    python_requires='>=3.6',
)
