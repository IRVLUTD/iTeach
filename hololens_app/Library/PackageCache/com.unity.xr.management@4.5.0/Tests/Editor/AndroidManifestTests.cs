using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Xml;
using Unity.XR.Management.AndroidManifest.Editor;
using UnityEditor;
using UnityEditor.XR.Management;
using UnityEngine;
using UnityEngine.XR.Management;

public class AndroidManifestTests
{
    private const string k_androidXmlNamespace = "http://schemas.android.com/apk/res/android";
    private const string k_unityActivityName = "com.unity3d.player.UnityPlayerActivity";
    private const string k_unityGameActivityName = "com.unity3d.player.UnityPlayerGameActivity";
    private readonly List<string> k_activityPath = new List<string> { "manifest", "application", "activity" };
    private readonly List<string> k_categoryPath = new List<string> { "manifest", "application", "activity", "intent-filter", "category" };

    private string tempProjectPath;
    private string xrManifestTemplateFilePath;
    private string xrLibraryManifestFilePath;
    private string unityLibraryManifestFilePath;
    private DirectoryInfo dirInfo;
    private XRManagerSettings mockXrSettings;
    private Type supportedLoaderType;

    [SetUp]
    public void SetUp()
    {
        tempProjectPath = FileUtil.GetUniqueTempPathInProject();
        dirInfo = Directory.CreateDirectory(tempProjectPath);

        var xrPackagePath = dirInfo.CreateSubdirectory(string.Join(Path.DirectorySeparatorChar.ToString(), "xrPackage", "xrmanifest.androidlib"));
        var xrLibraryPath = dirInfo.CreateSubdirectory("xrmanifest.androidlib");
        var unityLibraryPath = dirInfo.CreateSubdirectory(string.Join(Path.DirectorySeparatorChar.ToString(), "src", "main"));

        xrManifestTemplateFilePath = string.Join(Path.DirectorySeparatorChar.ToString(), xrPackagePath.FullName,  "AndroidManifest.xml");
        xrLibraryManifestFilePath = string.Join(Path.DirectorySeparatorChar.ToString(), xrLibraryPath.FullName, "AndroidManifest.xml");
        unityLibraryManifestFilePath = string.Join(Path.DirectorySeparatorChar.ToString(), unityLibraryPath.FullName, "AndroidManifest.xml");

        CreateMockManifestDocument(xrManifestTemplateFilePath);
        CreateMockManifestDocument(xrLibraryManifestFilePath);
        CreateMockManifestDocument(unityLibraryManifestFilePath);

        mockXrSettings = ScriptableObject.CreateInstance<XRManagerSettings>();
        supportedLoaderType = typeof(MockXrLoader);
        mockXrSettings.TrySetLoaders(new List<XRLoader>
        {
            ScriptableObject.CreateInstance<MockXrLoader>()
        });
    }

    [TearDown]
    public void TearDown()
    {
        dirInfo.Delete(true);
        ScriptableObject.DestroyImmediate(mockXrSettings);
    }

    [Test]
    public void AndroidManifestProcessor_AddOneNewManifestElement()
    {
        var processor = CreateProcessor();

        // Initialize data
        var newElementPath = new List<string> { "manifest", "application", "meta-data" };
        var newElementAttributes = new Dictionary<string, string>()
        {
            { "name", "custom-data" },
            { "value", "test-data" },
        };
        var providers = new List<IAndroidManifestRequirementProvider>()
        {
            new MockManifestRequirementProvider(new ManifestRequirement
            {
                SupportedXRLoaders = new HashSet<Type>
                {
                    supportedLoaderType
                },
                NewElements = new List<ManifestElement>()
                {
                    new ManifestElement()
                    {
                        ElementPath = newElementPath,
                        Attributes = newElementAttributes
                    }
                }
            })
        };

        // Execute
        processor.ProcessManifestRequirements(providers);

        // Validate
        var updatedLibraryManifest = GetXrLibraryManifest();
        var nodes = updatedLibraryManifest.SelectNodes(string.Join("/", newElementPath));
        Assert.AreEqual(
            1,
            nodes.Count,
            "Additional elements exist in the Manifest when expecting 1");

        var attributeList = nodes[0].Attributes;
        Assert.AreEqual(
            newElementAttributes.Count,
            attributeList.Count,
            "Attribute count in element doesn't match expected count");

        AssertAttributesAreEqual(nodes[0].Name, newElementAttributes, attributeList);
    }

    [Test]
    public void AndroidManifestProcessor_AddTwoNewManifestElements()
    {
        var processor = CreateProcessor();

        // Initialize data
        var newElementPath = new List<string> { "manifest", "application", "meta-data" };
        var newElementAttributes = new Dictionary<string, string>()
        {
            { "name", "custom-data" },
            { "value", "test-data" },
        };
        var providers = new List<IAndroidManifestRequirementProvider>()
        {
            new MockManifestRequirementProvider(new ManifestRequirement
            {
                SupportedXRLoaders = new HashSet<Type>
                {
                    supportedLoaderType
                },
                NewElements = new List<ManifestElement>()
                {
                    new ManifestElement()
                    {
                        ElementPath = newElementPath,
                        Attributes = newElementAttributes
                    },
                    new ManifestElement()
                    {
                        ElementPath = newElementPath,
                        Attributes = newElementAttributes
                    }
                }
            })
        };

        // Execute
        processor.ProcessManifestRequirements(providers);

        // Validate
        var updatedLibraryManifest = GetXrLibraryManifest();
        var nodes = updatedLibraryManifest.SelectNodes(string.Join("/", newElementPath));
        Assert.AreEqual(
            2,
            nodes.Count,
            "Additional elements exist in the Manifest when expecting 2");

        foreach(XmlElement node in nodes)
        {
            var attributeList = node.Attributes;
            Assert.AreEqual(
                newElementAttributes.Count,
                attributeList.Count,
                "Attribute count in element doesn't match expected count");

            AssertAttributesAreEqual(node.Name, newElementAttributes, attributeList);
        }
    }

    [Test]
    public void AndroidManifestProcessor_CreateSingleNewManifestElementFromTwoOverridenElements()
    {
        // Use the Assert class to test conditions
        var processor = CreateProcessor();

        // Initialize data
        var overrideElementPath = new List<string> { "manifest", "application" };
        var overrideElement1Attributes = new Dictionary<string, string>();
        var overrideElement2Attributes = new Dictionary<string, string>();
        var providers = new List<IAndroidManifestRequirementProvider>()
        {
            new MockManifestRequirementProvider(new ManifestRequirement
            {
                SupportedXRLoaders = new HashSet<Type>
                {
                    supportedLoaderType
                },
                OverrideElements = new List<ManifestElement>()
                {
                    new ManifestElement()
                    {
                        ElementPath = overrideElementPath,
                        Attributes = overrideElement1Attributes
                    },
                    new ManifestElement()
                    {
                        ElementPath = overrideElementPath,
                        Attributes = overrideElement2Attributes
                    }
                }
            })
        };

        // Execute
        processor.ProcessManifestRequirements(providers);

        // Validate
        var updatedLibraryManifest = GetXrLibraryManifest();
        var nodes = updatedLibraryManifest.SelectNodes(string.Join("/", overrideElementPath));
        Assert.AreEqual(
            1,
            nodes.Count,
            "Additional elements exist in the Manifest when expecting 1");

        var attributeList = nodes[0].Attributes;
        var expectedElementAttrributes = MergeDictionaries(overrideElement1Attributes, overrideElement2Attributes);
        Assert.AreEqual(
            expectedElementAttrributes.Count,
            attributeList.Count,
            $"Attribute count in element doesn't match expected {expectedElementAttrributes.Count}");

        AssertAttributesAreEqual(nodes[0].Name, expectedElementAttrributes, attributeList);
    }


    [Test]
    public void AndroidManifestProcessor_UpdateExistingElementWithOverridenElement()
    {
        // Use the Assert class to test conditions
        var processor = CreateProcessor();

        // Initialize data
        var overrideElementPath = new List<string> { "manifest", "test-tag" };
        var existingElementAttributes = new Dictionary<string, string>()
        {
            { "name", "com.test.app" }
        };
        var overrideElementAttributes = new Dictionary<string, string>()
        {
            { "isGame", "true" },
            { "testOnly", "true" },
        };
        var providers = new List<IAndroidManifestRequirementProvider>()
        {
            new MockManifestRequirementProvider(new ManifestRequirement
            {
                SupportedXRLoaders = new HashSet<Type>
                {
                    supportedLoaderType
                },
                OverrideElements = new List<ManifestElement>()
                {
                    new ManifestElement()
                    {
                        ElementPath = overrideElementPath,
                        Attributes = overrideElementAttributes
                    }
                }
            })
        };

        // Prepare test document
        var libManifest = GetXrLibraryManifest();
        libManifest.CreateNewElement(overrideElementPath, existingElementAttributes);
        libManifest.Save();

        // Execute
        processor.ProcessManifestRequirements(providers);

        // Validate
        var updatedLibraryManifest = GetXrLibraryManifest();
        var nodes = updatedLibraryManifest.SelectNodes(string.Join("/", overrideElementPath));
        Assert.AreEqual(
            1,
            nodes.Count,
            "Additional elements exist in the Manifest when expecting 1");

        var attributeList = nodes[0].Attributes;
        var expectedElementAttrributes = MergeDictionaries(existingElementAttributes, overrideElementAttributes);
        Assert.AreEqual(
            expectedElementAttrributes.Count,
            attributeList.Count,
            $"Attribute count {attributeList.Count} in element doesn't match expected {expectedElementAttrributes.Count}");

        AssertAttributesAreEqual(nodes[0].Name, expectedElementAttrributes, attributeList);
    }

    [Test]
    public void AndroidManifestProcessor_UpdateExistingActivityElementWithOverridenElement()
    {
        // Use the Assert class to test conditions
        var processor = CreateProcessor();

        // Initialize data
        var existingElementAttributes = new Dictionary<string, string>()
        {
            { "name", k_unityActivityName }
        };
        var overrideElementAttributes = new Dictionary<string, string>()
        {
            { "isGame", "true" },
            { "testOnly", "true" },
        };
        var providers = new List<IAndroidManifestRequirementProvider>()
        {
            new MockManifestRequirementProvider(new ManifestRequirement
            {
                SupportedXRLoaders = new HashSet<Type>
                {
                    supportedLoaderType
                },
                OverrideElements = new List<ManifestElement>()
                {
                    new ManifestElement()
                    {
                        ElementPath = k_activityPath,
                        Attributes = overrideElementAttributes
                    }
                }
            })
        };

        // Execute
        processor.ProcessManifestRequirements(providers);

        // Validate
        var updatedLibraryManifest = GetXrLibraryManifest();
        var nodes = updatedLibraryManifest.SelectNodes(string.Join("/", k_activityPath));
        Assert.AreEqual(
            1,
            nodes.Count,
            "Additional elements exist in the Manifest when expecting 1");

        var attributeList = nodes[0].Attributes;
        var expectedElementAttrributes = MergeDictionaries(existingElementAttributes, overrideElementAttributes);
        Assert.AreEqual(
            expectedElementAttrributes.Count,
            attributeList.Count,
            $"Attribute count {attributeList.Count} in element doesn't match expected {expectedElementAttrributes.Count}");

        AssertAttributesAreEqual(nodes[0].Name, expectedElementAttrributes, attributeList);
    }
    
    [Test]
    public void AndroidManifestProcessor_UpdateAllActivityElementWithOverridenElement()
    {
        IgnoreIfGameActivityIsNotSupported();

        // Use the Assert class to test conditions
        var processor = CreateProcessor();
        processor.UseActivityAppEntry = true;
        processor.UseGameActivityAppEntry = true;

        // Initialize data
        var existingElementAttributes = new Dictionary<string, string>()
        {
            { "name", k_unityActivityName }
        };
        var overrideElementAttributes = new Dictionary<string, string>()
        {
            { "isGame", "true" },
            { "testOnly", "true" },
        };
        var providers = new List<IAndroidManifestRequirementProvider>()
        {
            new MockManifestRequirementProvider(new ManifestRequirement
            {
                SupportedXRLoaders = new HashSet<Type>
                {
                    supportedLoaderType
                },
                OverrideElements = new List<ManifestElement>()
                {
                    new ManifestElement()
                    {
                        ElementPath = k_activityPath,
                        Attributes = overrideElementAttributes
                    }
                }
            })
        };

        // Execute
        processor.ProcessManifestRequirements(providers);

        // Validate
        var updatedLibraryManifest = GetXrLibraryManifest();
        var nodes = updatedLibraryManifest.SelectNodes(string.Join("/", k_activityPath));
        Assert.AreEqual(
            2,
            nodes.Count,
            "Additional elements exist in the Manifest when expecting 2");

        foreach (XmlNode node in nodes)
        {
            var attributeList = node.Attributes;
            var expectedElementAttrributes = MergeDictionaries(existingElementAttributes, overrideElementAttributes);
            Assert.AreEqual(
                expectedElementAttrributes.Count,
                attributeList.Count,
                $"Attribute count {attributeList.Count} in element doesn't match expected {expectedElementAttrributes.Count}");

            foreach (XmlAttribute attrib in attributeList)
            {
                var attributeName = attrib.Name.Split(':').Last(); // Values are returned with preffixed namespace name, pick only the attribute name
                if ("name".Equals(attributeName))
                {
                    // Check if the activity name is UnityPlayerActivity or UnityPlayerGameActivity
                    bool isUnityActivity =
                        k_unityActivityName.Equals(attrib.Value)
                        || k_unityGameActivityName.Equals(attrib.Value);
                    Assert.IsTrue(isUnityActivity, "Activity name is not UnityPlayerActivity or UnityPlayerGameActivity");
                }
                else if (!expectedElementAttrributes.Contains(new KeyValuePair<string, string>(attributeName, attrib.Value)))
                {
                    Assert.Fail($"Unexpected attribute \"{attrib.Name}\" " +
                        $"with value \"{attrib.Value}\" found in element {node.Name}");
                }
            }
        }
    }

    [Test]
    public void AndroidManifestProcessor_DeleteExistingManifestElement()
    {
        var processor = CreateProcessor();

        // Initialize data
        var deletedElementPath = new List<string> { "manifest", "uses-permission" };
        var deletedElementAttributes = new Dictionary<string, string>()
        {
            { "name", "BLUETOOTH" }
        };
        var providers = new List<IAndroidManifestRequirementProvider>()
        {
            new MockManifestRequirementProvider(new ManifestRequirement
            {
                SupportedXRLoaders = new HashSet<Type>
                {
                    supportedLoaderType
                },
                RemoveElements = new List<ManifestElement>()
                {
                    new ManifestElement()
                    {
                        ElementPath = deletedElementPath,
                        Attributes = deletedElementAttributes
                    }
                }
            })
        };

        // Prepare test document
        var appManifest = GetUnityLibraryManifest();
        appManifest.CreateNewElement(deletedElementPath, deletedElementAttributes);
        appManifest.Save();

        // Execute
        processor.ProcessManifestRequirements(providers);

        // Validate
        var updatedAppManifest = GetXrLibraryManifest();
        var removedElementPath = string.Join("/", deletedElementPath);
        var removedNodes = updatedAppManifest.SelectNodes(removedElementPath);
        Assert.AreEqual(
            0,
            removedNodes.Count,
            $"Expected element in path \"{removedElementPath}\" wasn't deleted");
    }

    [Test]
    public void AndroidManifestProcessor_DontModifyManifestIfNoSupportedLoadersAdded()
    {
        var processor = CreateProcessor();

        // Initialize data
        var newElementPath = new List<string> { "manifest", "application", "meta-data" };
        var newElementAttributes = new Dictionary<string, string>()
        {
            { "name", "custom-data" },
            { "value", "test-data" },
        };
        var providers = new List<IAndroidManifestRequirementProvider>()
        {
            new MockManifestRequirementProvider(new ManifestRequirement
            {
                SupportedXRLoaders = new HashSet<Type>
                {
                    typeof(object) // Dummy object representing an inactive loader
                },
                NewElements = new List<ManifestElement>()
                {
                    new ManifestElement()
                    {
                        ElementPath = newElementPath,
                        Attributes = newElementAttributes
                    }
                }
            })
        };

        // Execute
        processor.ProcessManifestRequirements(providers);

        // Validate
        var updatedLibraryManifest = GetXrLibraryManifest();
        var nodes = updatedLibraryManifest.SelectNodes(string.Join("/", newElementPath));
        Assert.AreEqual(
            0,
            nodes.Count,
            "Elements exist in the Manifest when expecting 0");
    }

    [Test]
    public void AndroidManifestProcessor_CheckThatActivityElementHasExportedAttributeWithIntents()
    {
        var processor = CreateProcessor();

        var newElementAttributes = new Dictionary<string, string>()
        {
            { "name", "com.oculus.intent.category.VR" }
        };
        var requirementPrvoider = new List<IAndroidManifestRequirementProvider>()
        {
            new MockManifestRequirementProvider(new ManifestRequirement
            {
                SupportedXRLoaders = new HashSet<Type>
                {
                    typeof(object) // Dummy object representing an inactive loader
                },
                NewElements = new List<ManifestElement>()
                {
                    new ManifestElement()
                    {
                        ElementPath = k_categoryPath,
                        Attributes = newElementAttributes
                    }
                }
            })
        };

        processor.ProcessManifestRequirements(requirementPrvoider);

        var xrLibManifest = GetXrLibraryManifest();
        var activityNodes = xrLibManifest.SelectNodes(string.Join("/", k_activityPath));

        Assert.AreEqual(1, activityNodes.Count, "Expected 1 activity node in the manifest");

        bool foundExportedAttribute = false;
        foreach (XmlElement activityNode in activityNodes)
        {
            var attributeValue = activityNode.GetAttribute("exported", k_androidXmlNamespace);
            if ("true".Equals(attributeValue))
            {
                foundExportedAttribute = true;
                break;
            }
        }

        Assert.IsFalse(foundExportedAttribute, "exported attribute shouldn't be present");
    }

    [Test]
    public void AndroidManifestProcessor_CheckThatActivityElementDoesntHaveExportedAttributeWithoutIntents()
    {
        var processor = CreateProcessor();

        processor.ProcessManifestRequirements(new List<IAndroidManifestRequirementProvider>());

        var xrLibManifest = GetXrLibraryManifest();
        var activityNodes = xrLibManifest.SelectNodes(string.Join("/", k_activityPath));

        Assert.AreEqual(1, activityNodes.Count, "Expected 1 activity node in the manifest");

        bool foundExportedAttribute = false;
        foreach (XmlElement activityNode in activityNodes)
        {
            var attributeValue = activityNode.GetAttribute("exported", k_androidXmlNamespace);
            if ("true".Equals(attributeValue))
            {
                foundExportedAttribute = true;
                break;
            }
        }

        Assert.IsFalse(foundExportedAttribute, "exported attribute shouldn't be present");
    }

    [Test]
    public void AndroidManifestProcessor_CheckThatGameActivityCanBeCreated()
    {
        IgnoreIfGameActivityIsNotSupported();

        var processor = CreateProcessor();
        processor.UseActivityAppEntry = true;
        processor.UseGameActivityAppEntry = false;

        processor.ProcessManifestRequirements(new List<IAndroidManifestRequirementProvider>());

        var xrLibManifest = GetXrLibraryManifest();
        var activityNodes = xrLibManifest.SelectNodes(string.Join("/", k_activityPath));

        Assert.AreEqual(1, activityNodes.Count, "Expected 1 activity node in the manifest");

        bool foundUnityActivity = false;
        foreach (XmlElement activityNode in activityNodes)
        {
            var attributeValue = activityNode.GetAttribute("name", k_androidXmlNamespace);
            if (k_unityActivityName.Equals(attributeValue))
            {
                foundUnityActivity = true;
                break;
            }
        }

        Assert.IsTrue(foundUnityActivity, "UnityPlayerActivity not found in the manifest");
    }

    [Test]
    public void AndroidManifestProcessor_CheckThatNormalActivityAndGameActivityCanBeCreated()
    {
        IgnoreIfGameActivityIsNotSupported();

        var processor = CreateProcessor();
        processor.UseActivityAppEntry = true;
        processor.UseGameActivityAppEntry = true;

        processor.ProcessManifestRequirements(new List<IAndroidManifestRequirementProvider>());

        var xrLibManifest = GetXrLibraryManifest();
        var activityNodes = xrLibManifest.SelectNodes(string.Join("/", k_activityPath));

        Assert.AreEqual(2, activityNodes.Count, "Expected 2 activity nodes in the manifest");

        bool foundUnityActivity = false;
        bool foundUnityGameActivity = false;
        foreach (XmlElement activityNode in activityNodes)
        {
            var attributeValue = activityNode.GetAttribute("name", k_androidXmlNamespace);
            switch (attributeValue)
            {
                case k_unityActivityName:
                    foundUnityActivity = true;
                    break;
                case k_unityGameActivityName:
                    foundUnityGameActivity = true;
                    break;
            }
        }

        Assert.IsTrue(foundUnityActivity, "UnityPlayerActivity not found in the manifest");
        Assert.IsTrue(foundUnityGameActivity, "UnityPlayerGameActivity not found in the manifest");
    }

    [Test]
    public void AndroidManifestProcessor_NewCategoryElementsAreAddedAlongExistingCategoryElements()
    {
        var categoryElementName = "category";
        var processor = CreateProcessor();
        var categoryPath = new List<string>(k_categoryPath);
        categoryPath.Append(categoryElementName);

        // Existing Intent-Filter Category element
        var unityLibManifest = GetUnityLibraryManifest();
        var categoryAttributes = new Dictionary<string, string>()
        {
            { "name", "android.intent.category.LAUNCHER" }
        };
        unityLibManifest.CreateNewElement(categoryPath, categoryAttributes);
        unityLibManifest.Save();

        // New Intent-Filter Category element
        var newElementAttributes = new Dictionary<string, string>()
        {
            { "name", "com.oculus.intent.category.VR" }
        };
        var requirementPrvoider = new List<IAndroidManifestRequirementProvider>()
        {
            new MockManifestRequirementProvider(new ManifestRequirement
            {
                SupportedXRLoaders = new HashSet<Type>
                {
                    supportedLoaderType
                },
                NewElements = new List<ManifestElement>()
                {
                    new ManifestElement()
                    {
                        ElementPath = k_categoryPath,
                        Attributes = newElementAttributes
                    }
                }
            })
        };

        processor.ProcessManifestRequirements(requirementPrvoider);

        // Reload the manifest
        unityLibManifest = GetUnityLibraryManifest();
        var nodes = unityLibManifest.SelectNodes(string.Join("/", k_categoryPath));
        Assert.AreEqual(
            2,
            nodes.Count,
            "Additional elements exist in the Manifest when expecting 2");

        bool existingCategoryFound = false;
        bool newCategoryFound = false;
        foreach (XmlElement node in nodes)
        {
            if (categoryElementName.Equals(node.Name))
            {
                var categoryAttribValue = node.Attributes.GetNamedItem("name", k_androidXmlNamespace).Value;
                existingCategoryFound |= "android.intent.category.LAUNCHER".Equals(categoryAttribValue);
                newCategoryFound |= "com.oculus.intent.category.VR".Equals(categoryAttribValue);
            }
        }
        Assert.IsTrue(existingCategoryFound, "Existing category element not found");
        Assert.IsTrue(newCategoryFound, "New category element not found");
    }

#if UNITY_2021_1_OR_NEWER
    [Test]
    public void AndroidManifestProcessor_AddNewIntentsOnlyInUnityLibraryManifest()
    {
        var processor = CreateProcessor();

        // Initialize data
        var newElementAttributes = new Dictionary<string, string>()
        {
            { "name", "com.oculus.intent.category.VR" }
        };
        var providers = new List<IAndroidManifestRequirementProvider>()
        {
            new MockManifestRequirementProvider(new ManifestRequirement
            {
                SupportedXRLoaders = new HashSet<Type>
                {
                    supportedLoaderType
                },
                NewElements = new List<ManifestElement>()
                {
                    new ManifestElement()
                    {
                        ElementPath = k_categoryPath,
                        Attributes = newElementAttributes
                    }
                }
            })
        };

        // Execute
        processor.ProcessManifestRequirements(providers);

        var elementPath = string.Join("/", k_categoryPath);

        // Validate that the intent is created in Unity library manifest
        var unityLibManifest = GetUnityLibraryManifest();
        var addedNodes = unityLibManifest.SelectNodes(elementPath);
        Assert.AreEqual(
            1,
            addedNodes.Count,
            $"Expected new element in path \"{elementPath}\" in Unity Library manifest");

        // Validate that the intent isn't created in XR Library manifest
        var xrLibManifest = GetXrLibraryManifest();
        var emptyNodes = xrLibManifest.SelectNodes(elementPath);
        Assert.AreEqual(
            0,
            emptyNodes.Count,
            $"Expected no new element in path \"{elementPath}\" in XR Library manifest");
    }

    [Test]
    public void AndroidManifestProcessor_KeepOnlyOneIntentOfTheSameType()
    {
        var processor = CreateProcessor();

        // Initialize data
        var newElementAttributes = new Dictionary<string, string>()
        {
            { "name", "com.oculus.intent.category.VR" }
        };
        var providers = new List<IAndroidManifestRequirementProvider>()
        {
            new MockManifestRequirementProvider(new ManifestRequirement
            {
                SupportedXRLoaders = new HashSet<Type>
                {
                    supportedLoaderType
                },
                NewElements = new List<ManifestElement>()
                {
                    new ManifestElement()
                    {
                        ElementPath = k_categoryPath,
                        Attributes = newElementAttributes
                    }
                }
            })
        };

        // Prepare test document
        var appManifest = GetUnityLibraryManifest();
        appManifest.CreateNewElement(k_categoryPath, newElementAttributes);
        appManifest.Save();

        // Execute
        processor.ProcessManifestRequirements(providers);

        var elementPath = string.Join("/", k_categoryPath);

        // Validate that only one intent of the same kind is in the manifest
        var unityLibManifest = GetUnityLibraryManifest();
        var addedNodes = unityLibManifest.SelectNodes(elementPath);
        Assert.AreEqual(
            1,
            addedNodes.Count,
            $"Expected only 1 element in path \"{elementPath}\" in Unity Library manifest");

    }

    [Test]
    public void AndroidManifestProcessor_AddManyIntentsOfTheSameTypeButKeepOnlyOne()
    {
        var processor = CreateProcessor();

        // Initialize data
        var newElementAttributes = new Dictionary<string, string>()
        {
            { "name", "com.oculus.intent.category.VR" }
        };
        var providers = new List<IAndroidManifestRequirementProvider>()
        {
            new MockManifestRequirementProvider(new ManifestRequirement
            {
                SupportedXRLoaders = new HashSet<Type>
                {
                    supportedLoaderType
                },
                NewElements = new List<ManifestElement>()
                {
                    new ManifestElement()
                    {
                        ElementPath = k_categoryPath,
                        Attributes = newElementAttributes
                    },
                    new ManifestElement()
                    {
                        ElementPath = k_categoryPath,
                        Attributes = newElementAttributes
                    }
                }
            })
        };

        // Execute
        processor.ProcessManifestRequirements(providers);

        var elementPath = string.Join("/", k_categoryPath);

        // Validate that only one intent of the same kind is in the manifest
        var unityLibManifest = GetUnityLibraryManifest();
        var addedNodes = unityLibManifest.SelectNodes(elementPath);
        Assert.AreEqual(
            1,
            addedNodes.Count,
            $"Expected only 1 element in path \"{elementPath}\" in Unity Library manifest");

    }
#endif

    private AndroidManifestDocument GetXrLibraryManifest()
    {
#if UNITY_2021_1_OR_NEWER
        return new AndroidManifestDocument(xrLibraryManifestFilePath);
#else
        // Unity 2020 and lower use the same manifest for XR entries as the rest of the app
        return GetUnityLibraryManifest();
#endif
    }

    private AndroidManifestDocument GetUnityLibraryManifest()
    {
        return new AndroidManifestDocument(unityLibraryManifestFilePath);
    }

    private AndroidManifestProcessor CreateProcessor()
    {
#if UNITY_2021_1_OR_NEWER
        return new AndroidManifestProcessor(
            tempProjectPath,
            tempProjectPath,
            mockXrSettings);
#else
        return new AndroidManifestProcessor(tempProjectPath, mockXrSettings);
#endif
    }

    private void CreateMockManifestDocument(string filePath)
    {
        var manifestDocument = new AndroidManifestDocument();
        var manifestNode = manifestDocument.CreateElement("manifest");
        manifestNode.SetAttribute("xmlns:android", k_androidXmlNamespace);
        manifestDocument.AppendChild(manifestNode);
        var applicationNode = manifestDocument.CreateElement("application");
        manifestNode.AppendChild(applicationNode);
        manifestDocument.SaveAs(filePath);
    }

    private void AssertAttributesAreEqual(
        string elementName,
        Dictionary<string, string> expectedAttributes,
        XmlAttributeCollection attributes)
    {
        foreach (XmlAttribute attrib in attributes)
        {
            var attributeName = attrib.Name.Split(':').Last(); // Values are returned with preffixed namespace name, pick only the attribute name
            if (!expectedAttributes.Contains(new KeyValuePair<string, string>(attributeName, attrib.Value)))
            {
                Assert.Fail($"Unexpected attribute \"{attrib.Name}\" " +
                    $"with value \"{attrib.Value}\" found in element {elementName}");
            }
        }
    }

    private Dictionary<TKey, TValue> MergeDictionaries<TKey, TValue>(Dictionary<TKey, TValue> dict1, Dictionary<TKey, TValue> dict2)
    {
        return new List<Dictionary<TKey, TValue>> { dict1, dict2 }
        .SelectMany(dict => dict)
        .ToDictionary(pair => pair.Key, pair => pair.Value);
    }

    private void IgnoreIfGameActivityIsNotSupported()
    {
#if !UNITY_2023_1_OR_NEWER
        Assert.Ignore("Ignoring test as GameActivity is not supported in Unity versions before 2023.1");
#endif
    }

    private class MockManifestRequirementProvider : IAndroidManifestRequirementProvider
    {
        private readonly ManifestRequirement requirement;

        public MockManifestRequirementProvider(ManifestRequirement mockRequirments)
        {
            requirement = mockRequirments;
        }

        public ManifestRequirement ProvideManifestRequirement()
        {
            return requirement;
        }
    }

    private class MockXrLoader : XRLoader
    {
        public override T GetLoadedSubsystem<T>()
        {
            throw new NotImplementedException();
        }
    }
}
