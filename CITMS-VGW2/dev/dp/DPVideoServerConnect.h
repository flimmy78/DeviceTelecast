#ifndef _DPVIDEOSERVERCONNECT_H
#define _DPVIDEOSERVERCONNECT_H

#include "Packet.h"
#include "TypeDef.h"
#include "RetCode.h"

#include "./dpsdk/DPSDK_Core.h"
#include "./dpsdk/DPSDK_Ext.h"
#include "./dpsdk/DPSDK_Core_Error.h"

// ��ƽ̨SDK
#pragma comment(lib, "../dev/dp/dpsdk/DPSDK_Core.lib")
#pragma comment(lib, "../dev/dp/dpsdk/DPSDK_Ext.lib")
#pragma comment(lib, "WS2_32.lib")

#define VIDEO_PROTOCOL_MAINSTREAM	0
#define VIDEO_PROTOCOL_CHILDSTREAM  1

namespace ScheduleServer
{
    namespace Plugin
    {
        namespace DPNVR
        {
            const INT default_real_type = 0;        // ȱʡʵʱ��Ƶ��������    
            const INT default_wait_time = 3000;     // ȱʡ�豸���ӵȴ�ʱ��(3000����)
        }

		const INT invalid_userid = -1;
		const INT invalid_handle = -1;
    };

    // �󻪲��������Ϣ
    typedef struct _DPPLUGIN_CONFIG
    {
        INT real_type;  // ʵʱ��Ƶ��������(Ĭ��������DH_RType_RealPlay)
        INT wait_time;  // �豸���ӵȴ�ʱ��(Ĭ��3000����)
        
        _DPPLUGIN_CONFIG(void) : real_type(Plugin::DPNVR::default_real_type), wait_time(Plugin::DPNVR::default_wait_time)
        {
        }
    } DPPLUGIN_CONFIG;

    // ��ͨ��������Ϣ
    typedef struct _DPCHANNEL_INFO
    {
        STREAMSOURCE_INFO source_info;          // ��������ͨ����Ϣ

        LONG login_id;                          // �豸ע��ID
        LONG real_handle;                       // ��Ƶ���Ӿ��
        LONG voice_handle;                      // �����Խ����

        PACKET_DATA packet_data;                // ý�����ݰ�
        UINT sequence;                          // �������ݰ����
        
        _DPCHANNEL_INFO(void) : login_id(), 
            real_handle(Plugin::invalid_handle), voice_handle(Plugin::invalid_handle),
            sequence(0)
        {
            // ��ʼ�����ݰ�������Ϣ
            init_packet_info(packet_data.info);
        }
    } DPCHANNEL_INFO;

    //
    // ���豸���빦����
    //
    class CDPVideoServerConnect
    {
    public:
        CDPVideoServerConnect();//IPacketCallbackPtr packet_callback_ptr = NULL);
        virtual ~CDPVideoServerConnect(void);

        // �رմ��豸����
        void uninit(void);

        // ��Ƶ����
        RETCODE connect(const REQUEST_INFO& request_info);

        // �Ͽ���Ƶ����
        RETCODE disconnect(const REQUEST_INFO& request_info);

        // ǿ��I֡
        RETCODE fast_update(const REQUEST_INFO& request_info);

        // ���ݰ��ص�
        void data_callback(DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, int bMark, DWORD source_uuid);

        // ����������Ϣ
        void config(const DPPLUGIN_CONFIG& dpplugin_config)
        {
            _dpplugin_config = dpplugin_config;
        };

        // �豸�Ͽ�ʱ�ص�
        void device_disconnect_callback(LONG lLoginID, char *pchDVRIP, LONG nDVRPort);

        // �豸��������ʱ�ص�
        void device_reconnect_callback(LONG lLoginID, char *pchDVRIP, LONG nDVRPort);

    private:
        // �ر�ͨ��
        RETCODE close_channel(DPCHANNEL_INFO& dpchannel_info);

    public:
        static CDPVideoServerConnect* global_connector;

    private:
        // ��SDK��ʼ���ɹ���־
        BOOL _is_init_ok;

        // �󻪲��������Ϣ
        DPPLUGIN_CONFIG _dpplugin_config;

        // ���ݰ��ص�����ָ��
        //IPacketCallbackPtr _packet_callback_ptr;

        // ͨ����Ϣ�б�
        std::map<INT, DPCHANNEL_INFO> _dpchannel_info_map;

	private:
		int test();

	private:
		int32_t _sdk_handler;

	private://fym
		static void DPSDK_CALLTYPE PacketCallback(int32_t nPDLLHanlde, int32_t nSeq, int StreamType, const char *Data, int DataLen, const char *DecoderTag, void *UserData);
		static int32_t DPSDK_CALLTYPE MediaDataCallback(int32_t nPDLLHandle, int32_t nSeq, int32_t nMediaType, const char* szNodeId, int32_t nParamVal, char* szData, int32_t nDataLen, void* pUserParam);

    };
}

#endif