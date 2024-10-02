#if UNITY_OPENXR_PACKAGE

using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Xml;
using UnityEditor.Build.Reporting;
using UnityEditor.XR.OpenXR.Features;
using UnityEngine.XR.Hands;
using UnityEngine.XR.Hands.OpenXR;
using UnityEngine.XR.OpenXR;
using UnityEngine.XR.OpenXR.Features;
using UnityEngine.XR.OpenXR.Features.MetaQuestSupport;

namespace UnityEditor.XR.Hands.OpenXR
{
    class ModifyAndroidManifest : OpenXRFeatureBuildHooks
    {
        public override int callbackOrder => 10;

        public override Type featureType => typeof(HandTracking);

        protected override void OnPreprocessBuildExt(BuildReport report)
        {
        }

        protected override void OnPostGenerateGradleAndroidProjectExt(string path)
        {
            var androidManifest = new AndroidManifest(GetManifestPath(path));
            androidManifest.UpdateHandTrackingMetaData();
            androidManifest.Save();
        }

        protected override void OnPostprocessBuildExt(BuildReport report)
        {
        }

        string GetManifestPath(string basePath)
        {
            if (!string.IsNullOrEmpty(m_ManifestFilePath))
                return m_ManifestFilePath;

            var pathBuilder = new StringBuilder(basePath);
            pathBuilder.Append(Path.DirectorySeparatorChar).Append("src");
            pathBuilder.Append(Path.DirectorySeparatorChar).Append("main");
            pathBuilder.Append(Path.DirectorySeparatorChar).Append("AndroidManifest.xml");
            m_ManifestFilePath = pathBuilder.ToString();

            return m_ManifestFilePath;
        }

        string m_ManifestFilePath;

        class AndroidXmlDocument : XmlDocument
        {
            string m_Path;
            protected XmlNamespaceManager nsMgr;
            public readonly string AndroidXmlNamespace = "http://schemas.android.com/apk/res/android";

            public AndroidXmlDocument(string path)
            {
                m_Path = path;
                using (var reader = new XmlTextReader(m_Path))
                {
                    reader.Read();
                    Load(reader);
                }

                nsMgr = new XmlNamespaceManager(NameTable);
                nsMgr.AddNamespace("android", AndroidXmlNamespace);
            }

            public string Save()
            {
                return SaveAs(m_Path);
            }

            public string SaveAs(string path)
            {
                using (var writer = new XmlTextWriter(path, new UTF8Encoding(false)))
                {
                    writer.Formatting = Formatting.Indented;
                    Save(writer);
                }

                return path;
            }
        }

        class AndroidManifest : AndroidXmlDocument
        {
            readonly XmlElement ApplicationElement;
            readonly XmlElement ActivityIntentFilterElement;
            readonly XmlElement ActivityElement;
            readonly XmlElement ManifestElement;

            public AndroidManifest(string path) : base(path)
            {
                ApplicationElement = SelectSingleNode("/manifest/application") as XmlElement;
                ActivityIntentFilterElement = SelectSingleNode("/manifest/application/activity/intent-filter") as XmlElement;
                ActivityElement = SelectSingleNode("manifest/application/activity") as XmlElement;
                ManifestElement = SelectSingleNode("/manifest") as XmlElement;
            }

            internal void UpdateHandTrackingMetaData()
            {
                var questFeature = OpenXRSettings.ActiveBuildTargetInstance.GetFeature<MetaQuestFeature>();
                var handTrackingFeature = OpenXRSettings.ActiveBuildTargetInstance.GetFeature<HandTracking>();
                if (questFeature == null || !questFeature.enabled || handTrackingFeature == null || !handTrackingFeature.enabled)
                    return;

                UpdateOrCreateAttribute(
                    ManifestElement,
                    "uses-permission",
                    "com.oculus.permission.HAND_TRACKING");
                UpdateOrCreateAttribute(
                    ManifestElement,
                    "uses-feature",
                    "oculus.software.handtracking",
                    ("required", "false"));
            }

            XmlAttribute CreateAndroidAttribute(string key, string value)
            {
                XmlAttribute attr = CreateAttribute("android", key, AndroidXmlNamespace);
                attr.Value = value;
                return attr;
            }

            void UpdateOrCreateAttribute(XmlElement xmlParentElement, string tag, string name, params (string name, string value)[] attributes)
            {
                var xmlNodeList = xmlParentElement.SelectNodes(tag);
                XmlElement targetNode = null;

                // Check all XmlNodes to see if a node with matching name already exists.
                foreach (XmlNode node in xmlNodeList)
                {
                    XmlAttribute nameAttr = (XmlAttribute)node.Attributes.GetNamedItem("name", AndroidXmlNamespace);
                    if (nameAttr != null && nameAttr.Value.Equals(name))
                    {
                        targetNode = (XmlElement)node;
                        break;
                    }
                }

                // If node exists, update the attribute values if they are present or create new ones as requested. Else, create new XmlElement.
                if (targetNode != null)
                {
                    for (int i = 0; i < attributes.Length; i++)
                    {
                        XmlAttribute attr = (XmlAttribute)targetNode.Attributes.GetNamedItem(attributes[i].name, AndroidXmlNamespace);
                        if (attr != null)
                        {
                            attr.Value = attributes[i].value;
                        }
                        else
                        {
                            targetNode.SetAttribute(attributes[i].name, AndroidXmlNamespace, attributes[i].value);
                        }
                    }
                }
                else
                {
                    XmlElement newElement = CreateElement(tag);
                    newElement.SetAttribute("name", AndroidXmlNamespace, name);
                    for (int i = 0; i < attributes.Length; i++)
                        newElement.SetAttribute(attributes[i].name, AndroidXmlNamespace, attributes[i].value);
                    xmlParentElement.AppendChild(newElement);
                }
            }
        }
    }
}

#endif // UNITY_OPENXR_PACKAGE
