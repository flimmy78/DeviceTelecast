#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "Config.h"

namespace ScheduleServer
{
    // ý��������豸���Ͷ���
    // ��Ҫ��ƽ̨���ݿ��豸���Ͷ��屣��һ�£�
    // ����豸�����޸ģ���Ҫͬʱ���±�����Ӧ�Ĳ����
    typedef INT DEVICE_TYPE;
    typedef enum
    {
        COMMONCAMERATYPE = 0,                           
        HKCAMERATYPE = 1,                                           // ��ý��1.0�����豸���Ͷ���(����)
        
        DHCAMERATYPE = 3,                                           // ��
        
        HKCARCAMERATYPE = 10,                                       // ��������
        HKPCCAMERATYPE = 11,                                        // ����PC
        
    };

    // ý���������Ͷ���
    typedef enum
    {
        SYSHEAD_DATA = 0,                                           // ϵͳͷ����
        REAL_VIDEO_DATA,                                            // ʵʱ��Ƶ����
        REAL_AUDIO_DATA,                                            // ʵʱ��Ƶ����
        REAL_VIDEO_IFRAME_DATA = 10,                                // ʵʱ��ƵI֡����
        TEXT_DATA,                                                  // �ı���������
        IMAGE_DATA,                                                 // ͼ����������
        FAKE_DATA,                                                  // α���ݰ�    
        UNKNOWN_DATA                                                // δ֪��������
    } DATA_TYPE;

    // ��ý�幦������������Ͷ���
    typedef enum
    {
        REAL_START = 0,                                             // ��ʼʵʱ��Ƶ����
        REAL_STOP,                                                  // ֹͣʵʱ��Ƶ����(��ý���ڲ�ʹ��)
        REAL_FASTUPDATE,                                            // ����I֡
        REAL_SNAPSHOT,                                              // ��ȡ����

        VOICE_START = 10,                                           // ��ʼ�����Խ�
        VOICE_STOP,                                                 // ֹͣ�����Խ�
        VOICE_CLIENT_DATA,                                          // ���Ϳͻ�����������

        RECORD_DOWNLOAD_START = 20,                                 // ��ʼ¼������
        RECORD_DOWNLOAD_STOP,                                       // ֹͣ¼������
        RECORD_REVIEW_START,                                        // ��ʼ¼��ط�
        RECORD_REVIEW_STOP,                                         // ֹͣ¼��ط�
        RECORD_REVIEW_PLAY_PAUSE,                                   // ��ͣ¼��ط� 
        RECORD_REVIEW_PLAY_RESUME,                                  // �ָ�¼��ط�

        DONOTHING                                                   // ȱʡ��ý�幦������                                       
    } REQUEST_OPERATION;

    // �ͻ�����Ϣ�ṹ����
    typedef struct _CLIENT_INFO 
    {
        STRING uuid;                                                // �ͻ���Ψһ��ʶ
        STRING ip;                                                  // �ͻ�������ʹ��IP��ַ
        STRING mac;                                                 // �ͻ�������ʹ��MAC��ַ
        INT port;                                                   // �˿ں�
        STRINGLIST ip_list;                                         // �ͻ���IP��ַ�б�   
        STRING proxy;                                               // ����������

        // ȱʡ���캯��
        _CLIENT_INFO() : uuid(""), ip(""), mac(""), port(0), proxy("")
        {
            ip_list.clear();
        }
    } CLIENT_INFO, *CLIENT_INFO_PTR;

    // �ͻ�����Ϣ�б����Ͷ���
    typedef std::list<CLIENT_INFO> CLIENT_INFO_LIST;

    // �豸������Ϣ�ṹ����
    typedef struct _DEVICE_INFO  
    {
        STRING uuid;                                                // �豸Ψһ��ʶ
        INT type;                                                   // �豸���� 
        STRING version;                                             // �汾��
        STRING ip;                                                  // �豸IP��ַ
        UINT port;                                                  // �豸�˿ں�
        STRING mac;                                                 // �豸MAC��ַ
        STRING monitor_proxy;                                       // �豸����ǰ�˷���������
        STRING alarm_proxy;                                         // �豸������������������
        UINT channel_start;                                         // �豸ͨ����ʼֵ(������ý��1.0���ݿ��1��ʼ���)
        UINT channel_count;                                         // �豸ͨ����    
        STRING user;                                                // �û���
        STRING password;                                            // ���� 
        BOOL reconnect_flag;                                        // �豸����������ʶ

        // ȱʡ���캯��
        _DEVICE_INFO() : uuid(""), 
            type(0), version(""), 
            ip(""), port(0), mac(""),
            monitor_proxy(""), alarm_proxy(""),
            channel_start(1), channel_count(0),
            user(""), password(""), reconnect_flag(TRUE)
        {
        }
    } DEVICE_INFO, *DEVICE_INFO_PTR;

    // �豸������Ϣ�б����Ͷ���
    typedef std::list<DEVICE_INFO> DEVICE_INFO_LIST;

    // ¼�����������Ϣ�ṹ����
    typedef struct _RECORD_INFO 
    {
        STRING uuid;                                                // ¼�������ʶ
        STRING user_uuid;                                           // ¼���ļ�ʹ����ID
        STRINGLIST file_list;                                       // ¼���ļ��б�
        STRING file_ex;                                             // ��չ¼���ļ���(¼�񱸷�ʱʹ��)
        INT file_type;                                              // ¼���ļ�����(���ݲ�ͬ�豸SDK��¼���ļ����͵Ķ��岻ͬ)
        BOOL by_time;                                               // ��ʱ��ط�/���ر�־
        STRING begin_time;                                          // DVR¼��ط�/������ʼʱ��(DVR¼��ط�/����ʹ��)
        STRING end_time;                                            // DVR¼��ط�/���ؽ���ʱ��(DVR¼��ط�/����ʹ��)
        BOOL loop;                                                  // ¼��ѭ�����ű�־
        BOOL download;                                              // ¼�����ر�־
        INT offset;                                                 // ¼��ط���ʼλ��(�ٷֱ�)

        // ȱʡ���캯��
        _RECORD_INFO() : uuid(""), user_uuid(""), file_ex(""), file_type(0),
            by_time(FALSE), begin_time(""), end_time(""),
            loop(FALSE), download(FALSE), offset(0)
        {
            file_list.clear();
        }
    } RECORD_INFO, *RECORD_INFO_PTR;

    // ý��Դ��Ϣ�ṹ����
    typedef struct _STREAMSOURCE_INFO 
    {
        INT uuid;                                                   // ý��Դ��ʶ
        INT channel;                                                // ����ͨ��(�����Խ���¼��ط�/����ʹ������ͨ��)
        DEVICE_INFO device_info;                                    // �豸��Ϣ
        //RECORD_INFO record_info;                                    // ¼�����������Ϣ
        
        // ȱʡ���캯��
        _STREAMSOURCE_INFO() : uuid(INVALID_ID), channel(0)
        {
        }
    } STREAMSOURCE_INFO, *STREAMSOURCE_INFO_PTR;

    // ý��Դ��Ϣ�б����Ͷ���
    typedef std::vector<STREAMSOURCE_INFO> STREAMSOURCE_INFO_LIST;

    // ��ý�幦������ṹ����
    typedef struct _REQUEST_INFO 
    {
		REQUEST_OPERATION operation;                                // ��ý�幦�������������
		STREAMSOURCE_INFO source_info;                              // ý��Դ��Ϣ

        // ȱʡ���캯��
        _REQUEST_INFO() : operation(DONOTHING)//, is_relay(FALSE), is_storage(FALSE)
        {
            //proxy_list.clear();
            //context.clear();
        }
    } REQUEST_INFO, *REQUEST_INFO_PTR;

    // ��ý�幦�������б����Ͷ���
    typedef std::list<REQUEST_INFO> REQUEST_INFO_LIST;

	//////////////////////////////////////////////////////////////////////////
	typedef struct tagLiveCastRequest
	{
		//string band;
		//string type;
		string url;

		tagLiveCastRequest() : /*band(""), type(""),*/ url("")
		{
		}

		~tagLiveCastRequest()
		{
		}

		bool operator < (tagLiveCastRequest const& _request) const
		{
			if(url < _request.url)
				return true;

			return false;
		}
	}
	LiveCastRequest;

	typedef struct tagLiveCastResponse
	{
		string num;
		string url;//hls
		string url2;//rtmp
		string expire;

		tagLiveCastResponse() : num(""), url(""), url2(""), expire("")
		{
		}

		~tagLiveCastResponse()
		{
		}

		bool operator < (tagLiveCastResponse const& _response) const
		{
			if(url < _response.url)
				return true;

			return false;
		}
	}
	LiveCastResponse;

	typedef struct tagVODRequest
	{
		string url;

		tagVODRequest() : url("")
		{
		}

		~tagVODRequest()
		{
		}

		bool operator < (tagVODRequest const& _request) const
		{
			if(url < _request.url)
				return true;

			return false;
		}
	}
	VODRequest;

	typedef struct tagVODResponse
	{
		string num;
		string url;//hls
		string url2;//rtmp
		string duration;

		tagVODResponse() : num(""), url(""), url2(""), duration("")
		{
		}

		~tagVODResponse()
		{
		}

		bool operator < (tagVODResponse const& _response) const
		{
			if(url < _response.url)
				return true;

			return false;
		}
	}
	VODResponse;
}

#endif // _TYPEDEF_H_
