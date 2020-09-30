#include "stdafx.h"
#include "rawdata_audio_channel_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"

namespace ZOOM_SDK_DOTNET_WRAP {
	class AudioRawDataReceiver : public ZOOM_RAWDATA_NAMESPACE::IAudioRawDataReceiver {
	public:
		virtual void onMixedAudioRawDataReceived(AudioRawData* data_) {
			DotNetAudioRawData^ data_c = gcnew DotNetAudioRawData(data_);
			_wrap->onMixedAudioRawDataReceived(data_c);
		}
		virtual void onOneWayAudioRawDataReceived(AudioRawData* data_, unsigned int node_id) {
			DotNetAudioRawData^ data_c = gcnew DotNetAudioRawData(data_);
			_wrap->onOneWayAudioRawDataReceived(data_c, node_id);
		}

		AudioRawDataReceiver(IAudioRawDataReceiverDotNetWrap* wrap) {
			_wrap = wrap;
		}

	private: 
		IAudioRawDataReceiverDotNetWrap* _wrap;
	};

	CAudioRawDataChannelDotNetWrap::CAudioRawDataChannelDotNetWrap()
	{
	}

	CAudioRawDataChannelDotNetWrap::~CAudioRawDataChannelDotNetWrap()
	{
	}

	SDKError CAudioRawDataChannelDotNetWrap::Stop()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKExtWrap::GetInst().GetAudioRawDataChannelWrap().Stop();
	}

	SDKError CAudioRawDataChannelDotNetWrap::Start(RawDataMemoryMode mode, IAudioRawDataReceiverDotNetWrap* receiver)
	{
		ZOOM_RAWDATA_NAMESPACE::RawDataMemoryMode mode_c = (ZOOM_RAWDATA_NAMESPACE::RawDataMemoryMode)mode;
		ZOOM_RAWDATA_NAMESPACE::IAudioRawDataReceiver* receiver_c = new AudioRawDataReceiver(receiver);

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKExtWrap::GetInst().GetAudioRawDataChannelWrap().Start(mode_c, receiver_c);
	}
}