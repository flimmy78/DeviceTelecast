#include <iostream>
#include <string>
#include <sstream>
#include <time.h>

#include "StdAfx.h"
#include "DPVideoServerConnect.h"
#include "DateTime.h"

#include "ScheduleServer.h"

#include "WideMultiChange.h"

using namespace ScheduleServer;

CDPVideoServerConnect* CDPVideoServerConnect::global_connector = NULL;

// ----------------------------------------------------------------------
// ������: real_data_callback
// ����: ������
// ����: ��Ƶ���ݻص�
// ����ֵ: 
//   [void] 
// ����: 
//   [LONG lRealHandle] ʵʱ��Ƶͨ�����
//   [DWORD dwDataType] ��������
//   [BYTE *pBuffer] ���ݻ�����ָ��
//   [DWORD dwBufSize] ���ݰ���С
//   [DWORD dwUser] �û��Զ�������
// ----------------------------------------------------------------------
void CALLBACK dp_real_data_callback(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize, LONG lParam, DWORD dwUser)
{
    if (!CDPVideoServerConnect::global_connector) return;

    CDPVideoServerConnect::global_connector->data_callback(REAL_VIDEO_DATA, pBuffer, dwBufSize, 1, dwUser);
}

// ----------------------------------------------------------------------
// ������: voice_data_callback
// ����: fuym
// ����: �����Խ�ʱ�����ݻص�
// ����ֵ: 
//   [void CALLBACK] 
// ����: 
//   [LONG lVoiceComHandle] �����Խ����
//   [char *pRecvDataBuffer] ���ݻ�����ָ��
//   [DWORD dwBufSize] ���ݰ���С
//   [BYTE byAudioFlag] �������ݱ�ʶ��byAudioFlag = 0��ʾ�ɼ��������ݣ�byAudioFlag = 1��ʾ���յ�������
//   [DWORD dwUser] �û��Զ�������
// ----------------------------------------------------------------------
void CALLBACK dp_voice_data_callback(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser)
{
    if (!CDPVideoServerConnect::global_connector) return;

    if(byAudioFlag == 1)
    {
        CDPVideoServerConnect::global_connector->data_callback(REAL_AUDIO_DATA, (BYTE *)pRecvDataBuffer, dwBufSize, 1, dwUser);
    }
}

// ----------------------------------------------------------------------
// ������: CDPVideoServerConnect::data_callback
// ����: fuym
// ����: 
// ����ֵ: 
//   [void] 
// ����: 
//   [DWORD dwDataType] ��������
//   [BYTE *pBuffer] ��������
//   [DWORD dwBufSize] �������ݳ���
//   [int bMark] ���ݱ��
//   [DWORD source_uuid] ý��Դ��ʶ
// ----------------------------------------------------------------------
void CDPVideoServerConnect::data_callback(DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, int bMark, DWORD source_uuid)
{
	TRACE("\nDH<%d %x %x %x>", dwDataType, *pBuffer, *(pBuffer + 1), *(pBuffer + 2), *(pBuffer + 2));

	if(1 != dwDataType)
		return;

	CUserAgent* ua = SINGLETON(CScheduleServer).fetch_ua(source_uuid);
	if(NULL == ua)
		return;

	if(false == ua->_start_hls)
		return;

	//ua->input_video_frame(pBuffer);
	ua->input_video_packet(pBuffer, dwBufSize);

	return;

    //if (!_packet_callback_ptr) return;

    std::map<INT, DPCHANNEL_INFO>::iterator iter = _dpchannel_info_map.find(source_uuid);
    if (iter == _dpchannel_info_map.end()) return;

    // ����������ݰ����ȴ���Ĭ����󳤶ȣ�MAX_PAYLOAD_SIZE��
    // ��Ҫ�������ݰ���ִ���������ݰ����س��ȡ���ź�ʱ����ͬ
    INT block_size = dwBufSize;
    INT block_count = dwBufSize / MAX_PAYLOAD_SIZE;
    if (dwBufSize % MAX_PAYLOAD_SIZE > 0) block_count++;

    iter->second.packet_data.info.source_uuid = source_uuid;
    iter->second.packet_data.info.mark = bMark;
    iter->second.packet_data.info.data_type = dwDataType;
    iter->second.packet_data.info.payload_block_count = block_count;
    iter->second.packet_data.info.payload_origin_size = dwBufSize;
    iter->second.packet_data.info.iframe = 0;
    iter->second.packet_data.info.sequence = iter->second.sequence;
    iter->second.packet_data.info.time_stamp = DateTime::get_current_timestamp();

    for (INT i=0; i<block_count; i++)
    {
        if (i < (block_count - 1)) 
        {
            iter->second.packet_data.info.mark = 0;
            block_size = MAX_PAYLOAD_SIZE;
        }
        else
        {
            iter->second.packet_data.info.mark = 1;
            block_size = dwBufSize - i * MAX_PAYLOAD_SIZE;
        }
		
		//if (!_packet_callback_ptr) return;

        iter->second.packet_data.info.payload_block_id = i;
        iter->second.packet_data.info.payload_block_size = block_size;

        // �����зֺ������
        ::memcpy(iter->second.packet_data.payload, (pBuffer + i * MAX_PAYLOAD_SIZE), block_size);

        //if (!_packet_callback_ptr) return;
        //_packet_callback_ptr->receive_packet(&iter->second.packet_data);
    }

    iter->second.sequence++;
}

//�豸�Ͽ�ʱ�ص�������������������Ͽ����豸�б�ĸ��¼��豸��ɾ������
void CALLBACK dp_device_disconnect_callback(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser)
{
    if(dwUser == 0) return;

    CDPVideoServerConnect *dpconnect_ptr = (CDPVideoServerConnect *)dwUser;
    dpconnect_ptr->device_disconnect_callback(lLoginID, pchDVRIP, nDVRPort);
}

void CDPVideoServerConnect::device_disconnect_callback(LONG lLoginID, char *pchDVRIP, LONG nDVRPort)
{
    //PLUGIN_LOG(_packet_callback_ptr, "device disconnect! ip=" << pchDVRIP << " port=" << nDVRPort);
}

//�豸��������ʱ�ص�����
void CALLBACK dp_device_reconnect_callback(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser)
{
    if(dwUser == 0) return;

    CDPVideoServerConnect *dpconnect_ptr = (CDPVideoServerConnect *)dwUser;
    dpconnect_ptr->device_reconnect_callback(lLoginID, pchDVRIP, nDVRPort);
}

void CDPVideoServerConnect::device_reconnect_callback(LONG lLoginID, char *pchDVRIP, LONG nDVRPort)
{
	//PLUGIN_LOG(_packet_callback_ptr, "device reconnect! ip=" << pchDVRIP << " port=" << nDVRPort);
}

// ----------------------------------------------------------------------
// ������: CDPVideoServerConnect::CDPVideoServerConnect
// ����: fuym
// ����: ���캯��
// ����: 
//   [IPacketCallbackPtr packet_callback_ptr] ���ݰ��ص�����ָ��
// ----------------------------------------------------------------------
CDPVideoServerConnect::CDPVideoServerConnect()//IPacketCallbackPtr packet_callback_ptr)
{
    _is_init_ok = FALSE;

    // �������ݰ��ص�����ָ��
    //_packet_callback_ptr = packet_callback_ptr;

    global_connector = this;

	if(DPSDK_RET_SUCCESS != DPSDK_Create(DPSDK_CORE_SDK_SERVER, _sdk_handler))
		return;

	

    // DVR��ʼ��
    //if (CLIENT_Init(::device_disconnect_callback, (DWORD)this))
    {
        // ��ȡSDK�汾��Ϣ
        //DWORD sdk_version = CLIENT_GetSDKVersion();
        //PLUGIN_LOG(_packet_callback_ptr, "sdk version=" << sdk_version);

        //���ö�������
       //CLIENT_SetAutoReconnect(::device_reconnect_callback, (DWORD)this);

        //�������ӵȴ�ʱ��
        //CLIENT_SetConnectTime(_dpplugin_config.wait_time, 3);

        _is_init_ok = TRUE; 
    }
    //else
    {
        //PLUGIN_LOG(_packet_callback_ptr, "CLIENT_Init() fail! error code=" << CLIENT_GetLastError());
    }
}

// ----------------------------------------------------------------------
// ������: CDPVideoServerConnect::~CDPVideoServerConnect
// ����: fuym
// ����: ��������
// ����: 
//   [void] 
// ----------------------------------------------------------------------
CDPVideoServerConnect::~CDPVideoServerConnect(void)
{   
}

// ----------------------------------------------------------------------
// ������: CDPVideoServerConnect::uninit
// ����: fuym
// ����: �رմ��豸����
// ����ֵ: 
//   [void] 
// ����: 
//   [void] 
// ----------------------------------------------------------------------
void CDPVideoServerConnect::uninit(void)
{
    // ������ݰ��ص�����ָ��
    //_packet_callback_ptr = NULL;

    // �ر�����ͨ��
    for (std::map<INT, DPCHANNEL_INFO>::iterator iter = _dpchannel_info_map.begin();
         iter != _dpchannel_info_map.end();
         iter++)
    {
        close_channel(iter->second);
    }

    if (_is_init_ok)
    {
        //CLIENT_Cleanup();
    }
}

void DPSDK_CALLTYPE CDPVideoServerConnect::PacketCallback(int32_t nPDLLHanlde, int32_t nSeq, int StreamType, const char *Data, int DataLen, const char *DecoderTag, void *UserData)
{
	/*if(1 != StreamType) return;

	//TRACE("\n%d %x %x %x %x %x %s %d %d", StreamType, *(Data), *(Data + 1), *(Data + 2), *(Data + 3), *(Data + 4), DecoderTag, DataLen);
	TRACE("\n%d %s %d %d", StreamType, DecoderTag, DataLen, (unsigned long)(UserData));
	//return;

	CUserAgent* ua = SINGLETON(CScheduleServer).fetch_ua((unsigned long)(UserData));
	if(NULL == ua)
		return;

	//if(false == ua->_start_hls) return;

	{
		const char* dat = Data + 40;

		if(false == ua->_start_push)
		{
			if(0 == dat[0] && 0 == dat[1] && 0 == dat[2] && 1 == dat[3] && 0x67 == dat[4]) ua->_start_push = true;
		}

		//if(true == ua->_start_push)
		{
			char file[256];
			sprintf(file, "%d.dat", (unsigned long)(UserData));
			FILE* f = fopen(file, "ab+");
			fwrite(Data + 40, 1, DataLen - 40, f);
			fclose(f);
			return;
		}
	}

	return;

	//ua->input_video_packet((unsigned char*)(const_cast<char*>(Data)), DataLen);
	ua->input_dh_frame((unsigned char*)(const_cast<char*>(Data)), DataLen);*/

	return;


}

//nPDLLHandle sdk���
//nSeq �������к�
//pBuf YUV��������
//nLen YUV�������ݳ���
//pFrameInfo ֡��Ϣ,�μ�FRAME_INFO
//pUserParam �û�����
//CRTMPSession _rtmp_session;
//unsigned char frame[65535];
//int frame_pos = 0;
//NAL_TYPE frame_type = NAL_INVALID;
//int DH_OFFSET = 40;
//bool sent_sps_pps = false;
unsigned long timestamp = 0;

unsigned char _frame[65536 * 10];
NAL_TYPE _last_frame_type = NAL_INVALID;
int _frame_pos = 0;

/*void add_dh_video_frame(unsigned char* frame, int length, unsigned long timestamp)
{
	if(length && NULL != _ua)
	{
		int offset = 0;
		NAL_TYPE type = CRTMPSession::get_video_packet_type(frame, length, offset);
		if(NAL_INVALID == type)
			return;

		VIDEO_PACKET_PTR packet_ptr;

		CMemPool::malloc_video_packet(packet_ptr);

		packet_ptr.packet->ua_id = _task_info.ua_id;
		packet_ptr.packet->sequence = 0;
		packet_ptr.packet->timestamp = timestamp;
		packet_ptr.packet->payload_size = length;//���ɳ���
		packet_ptr.packet->mark = true;
		memcpy(packet_ptr.packet->payload, frame, length);

		//TRACE("\nP1 %d", _video_frame_length);
		if(SS_NoErr != _ua->add_sample_video_packet(packet_ptr))//for sps and pps
		{
			CMemPool::free_video_packet(packet_ptr);
		}
	}
}*/

#include "useragent.h"

unsigned char _dh_video_frame[65536 * 10];
NAL_TYPE _last_dh_video_type;
int _dh_video_frame_length;

void add_dh_video_frame(unsigned char* frame, int length, unsigned long timestamp, unsigned long id)
{
	CUserAgent* _ua = SINGLETON(CScheduleServer).fetch_ua(id);

	if(length && NULL != _ua)
	{
		int offset = 0;
		NAL_TYPE type = CRTMPSession::get_video_packet_type(frame, length, offset);
		if(NAL_INVALID == type)
			return;

		VIDEO_PACKET_PTR packet_ptr;

		CMemPool::malloc_video_packet(packet_ptr);

		packet_ptr.packet->ua_id = 123;
		packet_ptr.packet->sequence = 0;
		packet_ptr.packet->timestamp = timestamp;
		packet_ptr.packet->payload_size = length;//���ɳ���
		packet_ptr.packet->mark = true;
		memcpy(packet_ptr.packet->payload, frame, length);

		//TRACE("\nP1 %d", _video_frame_length);
		if(SS_NoErr != _ua->add_sample_video_packet(packet_ptr))//for sps and pps
		{
			CMemPool::free_video_packet(packet_ptr);
		}
	}
}

void on_recv_packet(unsigned char* data, int length, unsigned long id)
{
	int offset = 0;
	//TRACE("\n<P %d %d>", CRTMPSession::get_video_packet_type(data, length, offset), length);

	if(false)
	{
		FILE* f = fopen("e:\\dp.dat", "ab+");
		fwrite(data, 1, length, f);
		fclose(f);
	}

	{
		unsigned char* dat = data;
		//int length = packet->size;

		int offset = 0;
		NAL_TYPE type =  CRTMPSession::get_video_packet_type(dat, length, offset);
		unsigned long timestamp = timeGetTime();

		if(NAL_SPS == type)
		{
			timestamp = timeGetTime();			

			//sps
			int sps_pos = 0;
			int pps_pos = 0;
			int sei_pos = 0;
			int idr_pos = 0;

			CRTMPSession::find_frame_header4(dat + sps_pos + 4, length - sps_pos - 4, offset);
			pps_pos = sps_pos + offset + 4;

			CRTMPSession::find_frame_header4(dat + pps_pos + 4, length - pps_pos- 4, offset);
			sei_pos = pps_pos + offset + 4;

			CRTMPSession::find_frame_header4(dat + sei_pos + 4, length - sei_pos- 4, offset);
			idr_pos = sei_pos + offset + 4;

			unsigned long t = timeGetTime();

			//sps
			_dh_video_frame_length = pps_pos - sps_pos;
			memcpy(_dh_video_frame, dat + sps_pos, _dh_video_frame_length);
			add_dh_video_frame(_dh_video_frame, _dh_video_frame_length, timestamp, id);
			//TRACE("\n<B %d %d", type, ua->_dh_video_frame_length);
			_dh_video_frame_length = 0;

			//pps
			_dh_video_frame_length = sei_pos - pps_pos;
			memcpy(_dh_video_frame, dat + pps_pos, _dh_video_frame_length);
			add_dh_video_frame(_dh_video_frame, _dh_video_frame_length, timestamp, id);
			//TRACE("\n<C %d %d", type, ua->_dh_video_frame_length);
			_dh_video_frame_length = 0;

			//sei
			_dh_video_frame_length = idr_pos - sei_pos;
			memcpy(_dh_video_frame, dat + sei_pos, _dh_video_frame_length);
			add_dh_video_frame(_dh_video_frame, _dh_video_frame_length, timestamp, id);
			//TRACE("\n<D %d %d", type, ua->_dh_video_frame_length);
			_dh_video_frame_length = 0;

			timestamp = timeGetTime();

			//idr
			_dh_video_frame_length = length - idr_pos;
			memcpy(_dh_video_frame, dat + idr_pos, _dh_video_frame_length);
			add_dh_video_frame(_dh_video_frame, _dh_video_frame_length, timestamp, id);
			//TRACE("\n<E %d %d", type, ua->_dh_video_frame_length);
			_dh_video_frame_length = 0;

			_last_dh_video_type = NAL_SLICE_IDR;

		}
		else if(NAL_SLICE == type)
		{
			//p
			_dh_video_frame_length = length;
			memcpy(_dh_video_frame, dat, _dh_video_frame_length);
			add_dh_video_frame(_dh_video_frame, _dh_video_frame_length, timestamp, id);
			//TRACE("\n<G %d %d", type, ua->_dh_video_frame_length);
			_dh_video_frame_length = 0;

			_last_dh_video_type = NAL_SLICE;
		}
	}
}

int32_t DPSDK_CALLTYPE CDPVideoServerConnect::MediaDataCallback(int32_t nPDLLHandle, int32_t nSeq, int32_t nMediaType, const char* szNodeId, int32_t nParamVal, char* szData, int32_t nDataLen, void* pUserParam)
{
	if(DPSDK_CORE_MEDIATYPE_VIDEO != nMediaType) return 0;

	unsigned long id = (unsigned long)(pUserParam);
	
	//TRACE("\n%d %d %s %d %d", nMediaType, nSeq, szNodeId, (unsigned long)(pUserParam), nDataLen);
	
	//TRACE("\n%d %x %x %x %x %x", nMediaType, szData[40], szData[41], szData[42], szData[43], szData[44]);

	if(40 >= nDataLen)
	{
		TRACE("\n<1SHORT %d %x %x %x %x %x", nMediaType, szData[0], szData[1], szData[2], szData[3], szData[4]);
		return 0;
	}

	{
		unsigned char* dat = (unsigned char*)(szData + 40);
		int length = nDataLen - 40;

		int offset = 0;
		NAL_TYPE type =  CRTMPSession::get_video_packet_type(dat, length, offset);
		unsigned long timestamp = timeGetTime();

		//TRACE("\n<T %d>", type);

		if(NAL_INVALID == type && NAL_INVALID != _last_frame_type)
		{
			//TRACE("\n<I %d>", type);
			dat = (unsigned char*)(szData);
			length = nDataLen;

			memcpy(_frame + _frame_pos, dat, length);
			_frame_pos += length;
		}
		else if(NAL_SLICE == type || NAL_SPS == type)
		{
			//TRACE("\n<P %d>", type);

			if(_frame_pos) on_recv_packet(_frame, _frame_pos, id);

			_frame_pos = 0;
			memcpy(_frame + _frame_pos, dat, length);
			_frame_pos += length;

			_last_frame_type = type;
		}
		else
		{
			TRACE("\nError");
		}

		return 0;

		/*if(NAL_SPS == type)
		{
			timestamp = timeGetTime();			

			//sps
			int sps_pos = 0;
			int pps_pos = 0;
			int sei_pos = 0;
			int idr_pos = 0;

			CRTMPSession::find_frame_header4(dat + sps_pos + 4, length - sps_pos - 4, offset);
			pps_pos = sps_pos + offset + 4;

			CRTMPSession::find_frame_header4(dat + pps_pos + 4, length - pps_pos- 4, offset);
			sei_pos = pps_pos + offset + 4;

			CRTMPSession::find_frame_header4(dat + sei_pos + 4, length - sei_pos- 4, offset);
			idr_pos = sei_pos + offset + 4;

			unsigned long t = timeGetTime();

			//sps
			_dh_video_frame_length = pps_pos - sps_pos;
			memcpy(_dh_video_frame, dat + sps_pos, _dh_video_frame_length);
			add_dh_video_frame(_dh_video_frame, _dh_video_frame_length, timestamp);
			//TRACE("\n<B %d %d", type, ua->_dh_video_frame_length);
			_dh_video_frame_length = 0;

			//pps
			_dh_video_frame_length = sei_pos - pps_pos;
			memcpy(_dh_video_frame, dat + pps_pos, _dh_video_frame_length);
			add_dh_video_frame(_dh_video_frame, _dh_video_frame_length, timestamp);
			//TRACE("\n<C %d %d", type, ua->_dh_video_frame_length);
			_dh_video_frame_length = 0;

			//sei
			_dh_video_frame_length = idr_pos - sei_pos;
			memcpy(_dh_video_frame, dat + sei_pos, _dh_video_frame_length);
			add_dh_video_frame(_dh_video_frame, _dh_video_frame_length, timestamp);
			//TRACE("\n<D %d %d", type, ua->_dh_video_frame_length);
			_dh_video_frame_length = 0;

			timestamp = timeGetTime();

			//idr
			_dh_video_frame_length = length - idr_pos;
			memcpy(_dh_video_frame, dat + idr_pos, _dh_video_frame_length);
			add_dh_video_frame(_dh_video_frame, _dh_video_frame_length, timestamp);
			//TRACE("\n<E %d %d", type, ua->_dh_video_frame_length);
			_dh_video_frame_length = 0;

			_last_dh_video_type = NAL_SLICE_IDR;

		}
		else if(NAL_SLICE == type)
		{
			//p
			_dh_video_frame_length = length;
			memcpy(_dh_video_frame, dat, _dh_video_frame_length);
			add_dh_video_frame(_dh_video_frame, _dh_video_frame_length, timestamp);
			//TRACE("\n<G %d %d", type, ua->_dh_video_frame_length);
			_dh_video_frame_length = 0;

			_last_dh_video_type = NAL_SLICE;
		}

		return;*/
	}

	//if(40 >= nDataLen) return 0;
#if 0
	if(false)
	{
		unsigned char* buf = (unsigned char*)(const_cast<char*>(szData));
		int len = nDataLen;

		if(0 == buf[40] && 0 == buf[41] && 0 == buf[42] && 1 == buf[43])
		{
			buf += 40;
			len -= 40;
		}

		FILE* f = fopen("d:\\dp.dat", "ab+");
		fwrite(buf, 1, len, f);
		fclose(f);

		return 0;
	}

	CUserAgent* ua = SINGLETON(CScheduleServer).fetch_ua((unsigned long)(pUserParam));
	if(NULL == ua) return 0;

	int offset = 0;
	NAL_TYPE type = NAL_INVALID;

	unsigned char* dat = (unsigned char*)(const_cast<char*>(szData));
	int length = nDataLen;
	if(40 < length && 0 == dat[40] && 0 == dat[41] && 0 == dat[42] && 1 == dat[43])
	{
		dat += 40;
		length -= 40;

		type = CRTMPSession::get_video_packet_type(dat, length, offset);
	}
	else
	{
		type = NAL_INVALID;
	}

	
	

	//return 0;
	//TRACE("\nF %d", ua->_dh_video_frame_length);

	if(NAL_INVALID == type)//packet
	{
		if(NAL_INVALID != ua->_last_dh_video_type)
		{
			//memcpy(ua->_dh_video_frame + ua->_dh_video_frame_length, dat, length);
			//ua->_dh_video_frame_length += length;

			ua->_dh_video_frame_length = length + 5;
			ua->_dh_video_frame[0] = 0;
			ua->_dh_video_frame[1] = 0;
			ua->_dh_video_frame[2] = 0;
			ua->_dh_video_frame[3] = 1;
			ua->_dh_video_frame[4] = 0x60 + ua->_last_dh_video_type;
			memcpy(ua->_dh_video_frame + 5, dat, length);
			ua->add_dh_video_frame(ua->_dh_video_frame, ua->_dh_video_frame_length, timestamp);
			//TRACE("\n<H %d %d", type, ua->_dh_video_frame_length);
			ua->_dh_video_frame_length = 0;
		}
	}
	else if(NAL_SPS == type)
	{
		timestamp = timeGetTime();
		/*if(ua->_dh_video_frame_length)
		{
			ua->add_dh_video_frame(ua->_dh_video_frame, ua->_dh_video_frame_length, timeGetTime());
			ua->_dh_video_frame_length = 0;
			//TRACE("\n<A %d %d", type, ua->_dh_video_frame_length);
		}*/

		//sps
		int sps_pos = 0;
		int pps_pos = 0;
		int sei_pos = 0;
		int idr_pos = 0;

		CRTMPSession::find_frame_header4(dat + sps_pos + 4, length - sps_pos - 4, offset);
		pps_pos = sps_pos + offset + 4;

		CRTMPSession::find_frame_header4(dat + pps_pos + 4, length - sps_pos- 4, offset);
		sei_pos = pps_pos + offset + 4;

		CRTMPSession::find_frame_header4(dat + sei_pos + 4, length - sei_pos- 4, offset);
		idr_pos = sei_pos + offset + 4;

		unsigned long t = timeGetTime();

		//sps
		ua->_dh_video_frame_length = pps_pos - sps_pos;
		memcpy(ua->_dh_video_frame, dat + sps_pos, ua->_dh_video_frame_length);
		ua->add_dh_video_frame(ua->_dh_video_frame, ua->_dh_video_frame_length, timestamp);
		//TRACE("\n<B %d %d", type, ua->_dh_video_frame_length);
		ua->_dh_video_frame_length = 0;
		
		//pps
		ua->_dh_video_frame_length = sei_pos - pps_pos;
		memcpy(ua->_dh_video_frame, dat + pps_pos, ua->_dh_video_frame_length);
		ua->add_dh_video_frame(ua->_dh_video_frame, ua->_dh_video_frame_length, timestamp);
		//TRACE("\n<C %d %d", type, ua->_dh_video_frame_length);
		ua->_dh_video_frame_length = 0;		

		//sei
		ua->_dh_video_frame_length = idr_pos - sei_pos;
		memcpy(ua->_dh_video_frame, dat + sei_pos, ua->_dh_video_frame_length);
		ua->add_dh_video_frame(ua->_dh_video_frame, ua->_dh_video_frame_length, timestamp);
		//TRACE("\n<D %d %d", type, ua->_dh_video_frame_length);
		ua->_dh_video_frame_length = 0;

		timestamp = timeGetTime();
		
		//idr
		ua->_dh_video_frame_length = length - idr_pos;
		memcpy(ua->_dh_video_frame, dat + idr_pos, ua->_dh_video_frame_length);
		ua->add_dh_video_frame(ua->_dh_video_frame, ua->_dh_video_frame_length, timestamp);
		//TRACE("\n<E %d %d", type, ua->_dh_video_frame_length);
		ua->_dh_video_frame_length = 0;

		ua->_last_dh_video_type = NAL_SLICE_IDR;

	}
	else if(NAL_SLICE == type)
	{
		timestamp = timeGetTime();

		/*if(ua->_dh_video_frame_length)
		{
			ua->add_dh_video_frame(ua->_dh_video_frame, ua->_dh_video_frame_length, timeGetTime());
			//TRACE("\n<F %d %d", type, ua->_dh_video_frame_length);
			ua->_dh_video_frame_length = 0;
		}*/

		//p
		ua->_dh_video_frame_length = length;
		memcpy(ua->_dh_video_frame, dat, ua->_dh_video_frame_length);
		ua->add_dh_video_frame(ua->_dh_video_frame, ua->_dh_video_frame_length, timestamp);
		//TRACE("\n<G %d %d", type, ua->_dh_video_frame_length);
		ua->_dh_video_frame_length = 0;

		ua->_last_dh_video_type = NAL_SLICE;
	}

	return 0;
	
	if(false)
	{
		char file[256];
		sprintf(file, "%d.dat", (unsigned long)(pUserParam));
		FILE* f = fopen(file, "ab+");
		fwrite(szData + 40, 1, nDataLen - 40, f);
		fclose(f);
	}
#endif
	return 0;
}

RETCODE CDPVideoServerConnect::connect(const REQUEST_INFO& request_info)
{
    if (!_is_init_ok) return RETCODE_REQUEST_SDK_FAIL;



    INT source_uuid = request_info.source_info.uuid;
    //STRING device_ip = request_info.source_info.device_info.ip;
    //INT device_port = request_info.source_info.device_info.port;
    //STRING device_user = request_info.source_info.device_info.user;
    //STRING device_password = request_info.source_info.device_info.password;
    //INT channel = request_info.source_info.channel;

    // �ر���Ƶ����
	//RETCODE ret_code = close_channel(_dpchannel_info_map[source_uuid]);
    //if (ret_code != RETCODE_OK) return ret_code;

    // �豸ע��
	Login_Info_t info = {0};
	memset(& info, 0, sizeof(Login_Info_t));

	memcpy(info.szIp, request_info.source_info.device_info.ip.c_str(), request_info.source_info.device_info.ip.length());
	info.nPort = request_info.source_info.device_info.port;
	memcpy(info.szUsername, request_info.source_info.device_info.user.c_str(), request_info.source_info.device_info.user.length());
	memcpy(info.szPassword, request_info.source_info.device_info.password.c_str(), request_info.source_info.device_info.password.length());
	info.nProtocol = DPSDK_PROTOCOL_VERSION_II;
	info.iType = 1;

	int nRet = DPSDK_Login(_sdk_handler, &info);
	if(0 != nRet)
	{
		return RETCODE_REQUEST_SDK_FAIL;
	}
	
	// �Ƚ�ͨ����
    /*if (channel > net_deviceinfo.byChanNum)
    {
        //PLUGIN_LOG(_packet_callback_ptr, "Channel number error! channel=" << channel << " cout=" << (INT)net_deviceinfo.byChanNum);
        CLIENT_Logout(login_id);
        return RETCODE_REQUEST_PARAMETERS_ERROR;
    }*/

	//_rtmp_session.connect("rtmp://121.41.15.6/hls/123");

	Get_RealStream_Info_t stream_info = {0};
	memset(&stream_info, 0, sizeof(Get_RealStream_Info_t));
	memcpy(stream_info.szCameraId, "1000004$1$0$0", strlen("1000004$1$0$0"));
	stream_info.nRight = DPSDK_CORE_NOT_CHECK_RIGHT;
	stream_info.nStreamType = DPSDK_CORE_STREAMTYPE_MAIN;
	stream_info.nMediaType = DPSDK_CORE_MEDIATYPE_VIDEO;
	stream_info.nTransType = DPSDK_CORE_TRANSTYPE_TCP;
	int seq = -1;

	//nRet = DPSDK_StartRealplayWithCallback(_sdk_handler, seq, &stream_info, SINGLETON(CScheduleServer)._video_wnd, CDPVideoServerConnect::PacketCallback, (void*)(source_uuid));
	nRet = DPSDK_GetRealStream( _sdk_handler, seq, &stream_info, CDPVideoServerConnect::MediaDataCallback, (void*)(source_uuid));
	//nRet = DPSDK_GetRealStreamEx( _sdk_handler, seq, &stream_info, DPSDK_CORE_SC_ASF_STREAM, CDPVideoServerConnect::MediaDataCallback, (void*)(source_uuid));

	// ��������ͨ����Ϣ
	_dpchannel_info_map[source_uuid].source_info = request_info.source_info;
	// �����û�ID
	_dpchannel_info_map[source_uuid].login_id = seq;











    // ����ʵʱ��Ƶ
    /*LONG real_handle = Plugin::invalid_handle;
    if (_dpplugin_config.real_type == Plugin::DPNVR::default_real_type) // ������
    {
        real_handle = CLIENT_RealPlayEx(login_id, channel, NULL, DH_RType_Realplay_0);
    }
    else // ������
    {
        real_handle = CLIENT_RealPlayEx(login_id, channel, NULL, DH_RType_Realplay_1);
    }

    if (real_handle <= 0)
    {
        //PLUGIN_LOG(_packet_callback_ptr, "CLIENT_RealPlayEx() fail! error code=" << CLIENT_GetLastError());
        CLIENT_Logout(login_id);
        return RETCODE_REQUEST_SDK_FAIL;
    }

    // ����ʵʱ��Ƶ���
    _dpchannel_info_map[source_uuid].real_handle = real_handle;

    // ����ʵʱ��Ƶ���ݻص�
    if (!CLIENT_SetRealDataCallBackEx(real_handle, real_data_callback, source_uuid, 0x00000001))
    {
        //PLUGIN_LOG(_packet_callback_ptr, "CLIENT_SetRealDataCallBackEx() fail! error code=" << CLIENT_GetLastError());
        return RETCODE_REQUEST_SDK_FAIL;
    }*/

    return RETCODE_OK;
}

RETCODE CDPVideoServerConnect::disconnect(const REQUEST_INFO& request_info)
{
    INT source_uuid = request_info.source_info.uuid;

	int seq = _dpchannel_info_map[source_uuid].login_id;

	if(!DPSDK_StopRealplayBySeq(_sdk_handler, seq))
		return RETCODE_OK;

	return RETCODE_REQUEST_SDK_FAIL;
	//return close_channel(_dpchannel_info_map[source_uuid]);
}

RETCODE CDPVideoServerConnect::close_channel(DPCHANNEL_INFO& dpchannel_info)
{
	// �ر���Ƶ���ž��
    if (dpchannel_info.real_handle != Plugin::invalid_handle) 
    {
        //CLIENT_StopRealPlayEx(dpchannel_info.real_handle);
        //PLUGIN_LOG(_packet_callback_ptr, "CLIENT_StopRealPlayEx() error code=" << CLIENT_GetLastError());
        dpchannel_info.real_handle = Plugin::invalid_handle;
    }

    // �û�ע��
    if (dpchannel_info.login_id != Plugin::invalid_userid)
    {
        //CLIENT_Logout(dpchannel_info.login_id);
        //PLUGIN_LOG(_packet_callback_ptr, "CLIENT_Logout() error code=" << CLIENT_GetLastError());
        dpchannel_info.login_id = Plugin::invalid_userid;
    }

    return RETCODE_OK;
}

RETCODE CDPVideoServerConnect::fast_update(const REQUEST_INFO& request_info)
{
    INT source_uuid = request_info.source_info.uuid;

    // ����豸�Ƿ�ע��
    if (_dpchannel_info_map[source_uuid].login_id == Plugin::invalid_userid)
    {
        return RETCODE_FAIL;
    }
    
    // ǿ��I֡
    //if (!CLIENT_MakeKeyFrame(_dpchannel_info_map[source_uuid].login_id, _dpchannel_info_map[source_uuid].source_info.channel))
    {
        //PLUGIN_LOG(_packet_callback_ptr, "CLIENT_MakeKeyFrame() fail! error code=" << CLIENT_GetLastError());
        return RETCODE_REQUEST_SDK_FAIL;
    }

    return RETCODE_OK;
}

/*int CDPVideoServerConnect::test()
{
	string url = "rtsp://192.168.0.190:9090/dss/monitor/params?cameraid=1000004%240&substream=1";

	int err = 0;

	AVDictionary * streamOpts = NULL;
	av_dict_set(&streamOpts, "stimeout", "5000000", 0); // 5 seconds timeout.
	av_dict_set(&streamOpts, "rtsp_transport", "tcp", 0);  // ����UDP�������»�����

	AVFormatContext* _format_ctx_ptr = NULL;

	// ���Ը�������ļ���׺�Զ��ж������������
	if (1)
	{
		// Create format context
		_format_ctx_ptr = avformat_alloc_context();
		if (!_format_ctx_ptr) 
		{
			av_dict_free(&streamOpts);
			return -1;
		}

		LARGE_INTEGER pfreq; 
		QueryPerformanceFrequency(&pfreq);
		LARGE_INTEGER ptime; 
		QueryPerformanceCounter(&ptime); 
		g_timeout = ptime.QuadPart + pfreq.QuadPart*5; //Timeout(second)
		_format_ctx_ptr->interrupt_callback = int_cb; 

		err = avformat_open_input(&_format_ctx_ptr, url.c_str(), NULL, &streamOpts);
		if (err < 0)
		{
			char info[1024] = {0};
			av_strerror(err, info, sizeof(info));
			av_dict_free(&streamOpts);
			return -2;
		}

		// Find the stream info.
		err = avformat_find_stream_info(_format_ctx_ptr, NULL);
		if (err >= 0) 
		{
			// Find video stream
			int video_index = -1;
			AVStream * video_stream_ptr = NULL;
			for (unsigned int i=0; i<_format_ctx_ptr->nb_streams; i++)
			{
				if (VideoCodec::is_video_stream(_format_ctx_ptr->streams[i]))
				{
					video_index = i;
					break;
				}
			}

			if (video_index >= 0)
			{
				av_dict_free(&streamOpts);
				return VIDEO_CODEC_OK;
			}
		}
	}

	// Recreate format context
	avformat_close_input(&_format_ctx_ptr);
	_format_ctx_ptr = avformat_alloc_context();
	if (!_format_ctx_ptr) 
	{
		av_dict_free(&streamOpts);
		return VIDEO_CODEC_FAIL;
	}

	LARGE_INTEGER pfreq; 
	QueryPerformanceFrequency(&pfreq);
	LARGE_INTEGER ptime; 
	QueryPerformanceCounter(&ptime); 
	g_timeout = ptime.QuadPart + pfreq.QuadPart*5; //Timeout(second)
	_format_ctx_ptr->interrupt_callback = int_cb; 

	// ����ʹ��264�����ʽ����Ƶ�ļ�
	AVInputFormat * h264_input_fmt_ptr = VideoCodec::find_h264_input_fmt();
	if (h264_input_fmt_ptr)
	{
		err = avformat_open_input(&_format_ctx_ptr, video_file, h264_input_fmt_ptr, &streamOpts);
		if (err < 0)
		{
			char info[1024] = {0};
			av_strerror(err, info, sizeof(info));
			av_dict_free(&streamOpts);
			return VIDEO_CODEC_OPEN_FILE_FAIL;
		}

		// Find the stream info.
		err = avformat_find_stream_info(_format_ctx_ptr, NULL);
		if (err >= 0) 
		{
			av_dict_free(&streamOpts);
			return VIDEO_CODEC_OK;
		}
	}

	av_dict_free(&streamOpts);
	return VIDEO_CODEC_OPEN_FILE_FAIL;
}*/

/*void log_callback(void *ptr, int level, const char *fmt, va_list vargs)
{
	static char message[8192];
	const char *module = NULL;

	if (ptr)
	{
		AVClass *avc = *(AVClass**) ptr;
		module = avc->item_name(ptr);
	}
	vsnprintf_s(message, sizeof(message), fmt, vargs);

	std::cout << "LOG: " << message << std::endl;
}*/


int CDPVideoServerConnect::test()
{
	/*SwsContext *img_convert_ctx;
	AVFormatContext* context = avformat_alloc_context();
	//AVCodecContext* ccontext = avcodec_alloc_context3();
	int video_stream_index;

	av_register_all();
	avformat_network_init();
	//av_log_set_callback(&log_callback);

	string url = "rtsp://192.168.0.190:9090/dss/monitor/params?cameraid=1000004%240&substream=1";

	//open rtsp
	if(avformat_open_input(&context, url.c_str(), NULL, NULL) != 0){
		return EXIT_FAILURE;
	}

	if(avformat_find_stream_info(context,NULL) < 0){
		return EXIT_FAILURE;
	}

	//search video stream
	for(int i =0;i<context->nb_streams;i++){
		if(context->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
			video_stream_index = i;
	}

	AVPacket packet;
	av_init_packet(&packet);

	//open output file
	//AVOutputFormat* fmt = av_guess_format(NULL,"test2.mp4",NULL);
	AVFormatContext* oc = avformat_alloc_context();
	//oc->oformat = fmt;
	//avio_open2(&oc->pb, "test.mp4", AVIO_FLAG_WRITE,NULL,NULL);

	AVStream* stream=NULL;
	int cnt = 0;
	//start reading packets from stream and write them to file
	av_read_play(context);//play RTSP

	AVCodec *codec = NULL;
	codec = avcodec_find_decoder(AV_CODEC_ID_H264);
	if (!codec) exit(1);

	avcodec_get_context_defaults3(ccontext, codec);
	avcodec_copy_context(ccontext,context->streams[video_stream_index]->codec);
	std::ofstream myfile;

	if (avcodec_open2(ccontext, codec) < 0) exit(1);

	img_convert_ctx = sws_getContext(ccontext->width, ccontext->height, ccontext->pix_fmt, ccontext->width, ccontext->height,
		AV_PIX_FMT_RGB24, SWS_BICUBIC, NULL, NULL, NULL);

	int size = avpicture_get_size(AV_PIX_FMT_YUV420P, ccontext->width, ccontext->height);
	uint8_t* picture_buf = (uint8_t*)(av_malloc(size));
	//AVFrame* pic = avcodec_alloc_frame();
	//AVFrame* picrgb = avcodec_alloc_frame();
	int size2 = avpicture_get_size(AV_PIX_FMT_RGB24, ccontext->width, ccontext->height);
	uint8_t* picture_buf2 = (uint8_t*)(av_malloc(size2));
	//avpicture_fill((AVPicture *) pic, picture_buf, AV_PIX_FMT_YUV420P, ccontext->width, ccontext->height);
	//avpicture_fill((AVPicture *) picrgb, picture_buf2, AV_PIX_FMT_RGB24, ccontext->width, ccontext->height);

	while(av_read_frame(context,&packet)>=0 && cnt <1000)
	{//read 100 frames

		std::cout << "1 Frame: " << cnt << std::endl;
		if(packet.stream_index == video_stream_index){//packet is video
			std::cout << "2 Is Video" << std::endl;
			if(stream == NULL)
			{//create stream in file
				std::cout << "3 create stream" << std::endl;
				stream = avformat_new_stream(oc,context->streams[video_stream_index]->codec->codec);
				avcodec_copy_context(stream->codec,context->streams[video_stream_index]->codec);
				stream->sample_aspect_ratio = context->streams[video_stream_index]->codec->sample_aspect_ratio;
			}
			int check = 0;
			packet.stream_index = stream->id;
			std::cout << "4 decoding" << std::endl;
			int result = avcodec_decode_video2(ccontext, pic, &check, &packet);
			std::cout << "Bytes decoded " << result << " check " << check << std::endl;
			if(cnt > 100)//cnt < 0)
			{
				sws_scale(img_convert_ctx, pic->data, pic->linesize, 0, ccontext->height, picrgb->data, picrgb->linesize);
				std::stringstream name;
				name << "test" << cnt << ".ppm";
				myfile.open(name.str());
				myfile << "P3 " << ccontext->width << " " << ccontext->height << " 255\n";
				for(int y = 0; y < ccontext->height; y++)
				{
					for(int x = 0; x < ccontext->width * 3; x++)
						myfile << (int)(picrgb->data[0] + y * picrgb->linesize[0])[x] << " ";
				}
				myfile.close();
			}
			cnt++;
		}
		av_free_packet(&packet);
		av_init_packet(&packet);
	}
	//av_free(pic);
	//av_free(picrgb);
	av_free(picture_buf);
	av_free(picture_buf2);

	av_read_pause(context);
	avio_close(oc->pb);
	avformat_free_context(oc);

	return (EXIT_SUCCESS);*/
	return 0;
}
