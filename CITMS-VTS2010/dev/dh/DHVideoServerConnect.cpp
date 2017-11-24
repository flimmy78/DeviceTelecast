#include <iostream>
#include <string>
#include <sstream>
#include <time.h>

#include "StdAfx.h"
#include "DHVideoServerConnect.h"
#include "DateTime.h"

#include "ScheduleServer.h"

using namespace ScheduleServer;

CDHVideoServerConnect* CDHVideoServerConnect::global_connector = NULL;

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
void CALLBACK real_data_callback(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize, LONG lParam, DWORD dwUser)
{
    if (!CDHVideoServerConnect::global_connector) return;

    CDHVideoServerConnect::global_connector->data_callback(REAL_VIDEO_DATA, pBuffer, dwBufSize, 1, dwUser);
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
void CALLBACK voice_data_callback(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser)
{
    if (!CDHVideoServerConnect::global_connector) return;

    if(byAudioFlag == 1)
    {
        CDHVideoServerConnect::global_connector->data_callback(REAL_AUDIO_DATA, (BYTE *)pRecvDataBuffer, dwBufSize, 1, dwUser);
    }
}

// ----------------------------------------------------------------------
// ������: CDHVideoServerConnect::data_callback
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
void CDHVideoServerConnect::data_callback(DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, int bMark, DWORD source_uuid)
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

    std::map<INT, DHCHANNEL_INFO>::iterator iter = _dhchannel_info_map.find(source_uuid);
    if (iter == _dhchannel_info_map.end()) return;

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
void CALLBACK device_disconnect_callback(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser)
{
    if(dwUser == 0) return;

    CDHVideoServerConnect *dhconnect_ptr = (CDHVideoServerConnect *)dwUser;
    dhconnect_ptr->device_disconnect_callback(lLoginID, pchDVRIP, nDVRPort);
}

void CDHVideoServerConnect::device_disconnect_callback(LONG lLoginID, char *pchDVRIP, LONG nDVRPort)
{
    //PLUGIN_LOG(_packet_callback_ptr, "device disconnect! ip=" << pchDVRIP << " port=" << nDVRPort);
}

//�豸��������ʱ�ص�����
void CALLBACK device_reconnect_callback(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser)
{
    if(dwUser == 0) return;

    CDHVideoServerConnect *dhconnect_ptr = (CDHVideoServerConnect *)dwUser;
    dhconnect_ptr->device_reconnect_callback(lLoginID, pchDVRIP, nDVRPort);
}

void CDHVideoServerConnect::device_reconnect_callback(LONG lLoginID, char *pchDVRIP, LONG nDVRPort)
{
	//PLUGIN_LOG(_packet_callback_ptr, "device reconnect! ip=" << pchDVRIP << " port=" << nDVRPort);
}

// ----------------------------------------------------------------------
// ������: CDHVideoServerConnect::CDHVideoServerConnect
// ����: fuym
// ����: ���캯��
// ����: 
//   [IPacketCallbackPtr packet_callback_ptr] ���ݰ��ص�����ָ��
// ----------------------------------------------------------------------
CDHVideoServerConnect::CDHVideoServerConnect()//IPacketCallbackPtr packet_callback_ptr)
{
    _is_init_ok = FALSE;

    // �������ݰ��ص�����ָ��
    //_packet_callback_ptr = packet_callback_ptr;

    global_connector = this;

    // DVR��ʼ��
    if (CLIENT_Init(::device_disconnect_callback, (DWORD)this))
    {
        // ��ȡSDK�汾��Ϣ
        DWORD sdk_version = CLIENT_GetSDKVersion();
        //PLUGIN_LOG(_packet_callback_ptr, "sdk version=" << sdk_version);

        //���ö�������
       CLIENT_SetAutoReconnect(::device_reconnect_callback, (DWORD)this);

        //�������ӵȴ�ʱ��
        CLIENT_SetConnectTime(_dhplugin_config.wait_time, 3);

        _is_init_ok = TRUE; 
    }
    else
    {
        //PLUGIN_LOG(_packet_callback_ptr, "CLIENT_Init() fail! error code=" << CLIENT_GetLastError());
    }
}

// ----------------------------------------------------------------------
// ������: CDHVideoServerConnect::~CDHVideoServerConnect
// ����: fuym
// ����: ��������
// ����: 
//   [void] 
// ----------------------------------------------------------------------
CDHVideoServerConnect::~CDHVideoServerConnect(void)
{   
}

// ----------------------------------------------------------------------
// ������: CDHVideoServerConnect::uninit
// ����: fuym
// ����: �رմ��豸����
// ����ֵ: 
//   [void] 
// ����: 
//   [void] 
// ----------------------------------------------------------------------
void CDHVideoServerConnect::uninit(void)
{
    // ������ݰ��ص�����ָ��
    //_packet_callback_ptr = NULL;

    // �ر�����ͨ��
    for (std::map<INT, DHCHANNEL_INFO>::iterator iter = _dhchannel_info_map.begin();
         iter != _dhchannel_info_map.end();
         iter++)
    {
        close_channel(iter->second);
    }

    if (_is_init_ok)
    {
        CLIENT_Cleanup();
    }
}

RETCODE CDHVideoServerConnect::connect(const REQUEST_INFO& request_info)
{
    if (!_is_init_ok) return RETCODE_REQUEST_SDK_FAIL;

    INT source_uuid = request_info.source_info.uuid;

    STRING device_ip = request_info.source_info.device_info.ip;
    INT device_port = request_info.source_info.device_info.port;
    STRING device_user = request_info.source_info.device_info.user;
    STRING device_password = request_info.source_info.device_info.password;
    INT channel = request_info.source_info.channel;

    // �ر���Ƶ����
    RETCODE ret_code = close_channel(_dhchannel_info_map[source_uuid]);
    if (ret_code != RETCODE_OK) return ret_code;

    // �豸ע��
    NET_DEVICEINFO net_deviceinfo;
    INT err_code = 0;
    LONG login_id = CLIENT_Login((char *)device_ip.c_str(), device_port, (char *)device_user.c_str(), (char *)device_password.c_str(), &net_deviceinfo, &err_code);
    if (login_id <= 0)
    {
        //PLUGIN_LOG(_packet_callback_ptr, "CLIENT_Login() fail! error code=" << err_code);
        return RETCODE_REQUEST_SDK_FAIL;
    }

    // ��������ͨ����Ϣ
    _dhchannel_info_map[source_uuid].source_info = request_info.source_info;

    // �����û�ID
    _dhchannel_info_map[source_uuid].login_id = login_id;
    
    // �Ƚ�ͨ����
    if (channel > net_deviceinfo.byChanNum)
    {
        //PLUGIN_LOG(_packet_callback_ptr, "Channel number error! channel=" << channel << " cout=" << (INT)net_deviceinfo.byChanNum);
        CLIENT_Logout(login_id);
        return RETCODE_REQUEST_PARAMETERS_ERROR;
    }

    // ����ʵʱ��Ƶ
    LONG real_handle = Plugin::invalid_handle;
    if (_dhplugin_config.real_type == Plugin::DHDVR::default_real_type) // ������
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
    _dhchannel_info_map[source_uuid].real_handle = real_handle;

    // ����ʵʱ��Ƶ���ݻص�
    if (!CLIENT_SetRealDataCallBackEx(real_handle, real_data_callback, source_uuid, 0x00000001))
    {
        //PLUGIN_LOG(_packet_callback_ptr, "CLIENT_SetRealDataCallBackEx() fail! error code=" << CLIENT_GetLastError());
        return RETCODE_REQUEST_SDK_FAIL;
    }

    return RETCODE_OK;
}

RETCODE CDHVideoServerConnect::disconnect(const REQUEST_INFO& request_info)
{
    INT source_uuid = request_info.source_info.uuid;
    return close_channel(_dhchannel_info_map[source_uuid]);
}

RETCODE CDHVideoServerConnect::close_channel(DHCHANNEL_INFO& dhchannel_info)
{
	// �ر���Ƶ���ž��
    if (dhchannel_info.real_handle != Plugin::invalid_handle) 
    {
        CLIENT_StopRealPlayEx(dhchannel_info.real_handle);
        //PLUGIN_LOG(_packet_callback_ptr, "CLIENT_StopRealPlayEx() error code=" << CLIENT_GetLastError());
        dhchannel_info.real_handle = Plugin::invalid_handle;
    }

    // �û�ע��
    if (dhchannel_info.login_id != Plugin::invalid_userid)
    {
        CLIENT_Logout(dhchannel_info.login_id);
        //PLUGIN_LOG(_packet_callback_ptr, "CLIENT_Logout() error code=" << CLIENT_GetLastError());
        dhchannel_info.login_id = Plugin::invalid_userid;
    }

    return RETCODE_OK;
}

RETCODE CDHVideoServerConnect::fast_update(const REQUEST_INFO& request_info)
{
    INT source_uuid = request_info.source_info.uuid;

    // ����豸�Ƿ�ע��
    if (_dhchannel_info_map[source_uuid].login_id == Plugin::invalid_userid)
    {
        return RETCODE_FAIL;
    }
    
    // ǿ��I֡
    if (!CLIENT_MakeKeyFrame(_dhchannel_info_map[source_uuid].login_id, _dhchannel_info_map[source_uuid].source_info.channel))
    {
        //PLUGIN_LOG(_packet_callback_ptr, "CLIENT_MakeKeyFrame() fail! error code=" << CLIENT_GetLastError());
        return RETCODE_REQUEST_SDK_FAIL;
    }

    return RETCODE_OK;
}

/*int CDHVideoServerConnect::test()
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


int CDHVideoServerConnect::test()
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
