#include "stdafx.h"
#include "rawdata_audio_channel_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"

namespace ZOOM_SDK_DOTNET_WRAP {

	class AudioRawDataReceiver : public ZOOM_RAWDATA_NAMESPACE::IAudioRawDataReceiver {
	public:
		void onMixedAudioRawDataReceived(AudioRawData* data_) {

		}
		void onOneWayAudioRawDataReceived(AudioRawData* data_, unsigned int node_id) {

		}
	};

	SDKError AudioRawDataChannelDotNetWrap::Start(RawDataMemoryMode mode, onMixedAudioRawDataReceived^ onMixedDataRecieved, onOneWayAudioRawDataReceived^ onOneWayDataReceived) {

	}

	SDKError AudioRawDataChannelDotNetWrap::Stop() {

	}
}