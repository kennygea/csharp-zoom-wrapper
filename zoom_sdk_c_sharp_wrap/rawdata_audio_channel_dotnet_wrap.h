#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	public enum class RawDataMemoryMode : int
	{
		RawDataMemoryMode_Stack,
		RawDataMemoryMode_Heap,
	};

	public ref class DotNetAudioRawData
	{
	public:
		bool CanAddRef();
		bool AddRef();
		int Release();
		array<Byte>^ GetBuffer();
		UInt32 GetBufferLen();
		UInt32 GetSampleRate();
	private:
		AudioRawData* _data;

	public:
		DotNetAudioRawData(AudioRawData* data) {
			_data = data;
		}
	};

//	public interface class IAudioRawDataReceiverDotNetWrap {
//	public: 
//		void onMixedAudioRawDataReceived(AudioRawData^ data_);
//		void onOneWayAudioRawDataReceived(AudioRawData^ data_, UInt32 node_id);
//	};

	public delegate void onMixedAudioRawDataReceived(DotNetAudioRawData^ data);
	public delegate void onOneWayAudioRawDataReceived(DotNetAudioRawData^ data_, UInt32 node_id);

	public ref class AudioRawDataChannelDotNetWrap {
	public: 
		SDKError Start(RawDataMemoryMode mode, onMixedAudioRawDataReceived^ onMixedDataRecieved, onOneWayAudioRawDataReceived^ onOneWayDataReceived);
		SDKError Stop();

	private:
		onMixedAudioRawDataReceived^ event_onMixedAudioRawDataReceived;
		onOneWayAudioRawDataReceived^ event_onOneWayAudioRawDataReceived;
	};
}