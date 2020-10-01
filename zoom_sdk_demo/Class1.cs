using System;
using ZOOM_SDK_DOTNET_WRAP;

namespace zoom_sdk_demo
{
    public class TestReceiver : IAudioRawDataReceiverDotNetWrap
    {
        public void onMixedAudioRawDataReceived(DotNetAudioRawData data_)
        {
            Console.WriteLine($"mixed audio received {data_.GetSampleRate()}");
        }

        public void onOneWayAudioRawDataReceived(DotNetAudioRawData data_, uint node_id)
        {
            Console.WriteLine($"mixed audio received {data_.GetSampleRate()} {node_id}");
        }
    }
}
