using System.Collections;
using System.Collections.Generic;
using UnityEngine;

#if WINDOWS_UWP
using Windows.Networking.Connectivity;
using Windows.Networking;
using Windows.UI.Notifications;
using Windows.Data.Xml.Dom;
#endif

namespace iTeach.Utils
{
    public static class Helpers
    {

        public static string GetNetworkSSID()
        {
            #if WINDOWS_UWP
                var profile = NetworkInformation.GetInternetConnectionProfile();
                if (profile != null && profile.IsWlanConnectionProfile)
                {
                    var ssid = profile.WlanConnectionProfileDetails.GetConnectedSsid();
                    return ssid;
                }
            #endif
            return "SSID not found";
        }

        public static string GetLocalIPAddress()
        {
            #if WINDOWS_UWP
                var hosts = NetworkInformation.GetHostNames();
                foreach (var host in hosts)
                {
                    if (host.IPInformation != null && host.Type == HostNameType.Ipv4)
                    {
                        return host.CanonicalName;
                    }
                }
            #endif
            return "IP not found";
        }

        public static void ShowNativeToast(string message)
        {
            #if WINDOWS_UWP
                XmlDocument toastXml = ToastNotificationManager.GetTemplateContent(ToastTemplateType.ToastText02);
                XmlNodeList stringElements = toastXml.GetElementsByTagName("text");
                stringElements[0].AppendChild(toastXml.CreateTextNode(message));

                ToastNotification toast = new ToastNotification(toastXml);

                // Set the expiration time to 11 seconds
                // toast.ExpirationTime = DateTimeOffset.UtcNow.AddSeconds(11);
                ToastNotificationManager.CreateToastNotifier().Show(toast);
            #endif
        }

        public static void ShowNetworkDetails()
        {
            #if WINDOWS_UWP
                string ssid = GetNetworkSSID();
                string ip = GetLocalIPAddress();
                Helpers.ShowNativeToast("Connected to SSID: " + ssid + "\nIP Address: " + ip);
            #endif
        }

        // Convert BoxIdentifier.RectType to a string label
        public static string RectTypeToLabel(BoxIdentifier.RectType rectType)
        {
            return rectType == BoxIdentifier.RectType.door ? "0" : "1";
        }

        // Convert a string label to BoxIdentifier.RectType
        public static BoxIdentifier.RectType LabelToRectType(string label)
        {
            if (label == "0")
            {
                return BoxIdentifier.RectType.door;
            }
            else if (label == "1")
            {
                return BoxIdentifier.RectType.handle;
            }
            else
            {
                throw new System.ArgumentException("Invalid label for RectType.");
            }
        }

    }
}
