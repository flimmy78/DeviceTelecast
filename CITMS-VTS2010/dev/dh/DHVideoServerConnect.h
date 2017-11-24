#ifndef _DHVIDEOSERVERCONNECT_H
#define _DHVIDEOSERVERCONNECT_H

#include "Packet.h"
#include "TypeDef.h"
#include "RetCode.h"

#include "./dhsdk/dhnetsdk.h"

// ���豸SDK
#pragma comment(lib, "../dev/dh/dhsdk/dhnetsdk.lib")
#pragma comment(lib, "WS2_32.lib")

#define VIDEO_PROTOCOL_MAINSTREAM	0
#define VIDEO_PROTOCOL_CHILDSTREAM  1

namespace ScheduleServer
{
    namespace Plugin
    {
        namespace DHDVR
        {
            const INT default_real_type = 0;        // ȱʡʵʱ��Ƶ��������    
            const INT default_wait_time = 3000;     // ȱʡ�豸���ӵȴ�ʱ��(3000����)
        }

		const INT invalid_userid = -1;
		const INT invalid_handle = -1;
    };

    // �󻪲��������Ϣ
    typedef struct _DHPLUGIN_CONFIG
    {
        INT real_type;  // ʵʱ��Ƶ��������(Ĭ��������DH_RType_RealPlay)
        INT wait_time;  // �豸���ӵȴ�ʱ��(Ĭ��3000����)
        
        _DHPLUGIN_CONFIG(void) : real_type(Plugin::DHDVR::default_real_type), wait_time(Plugin::DHDVR::default_wait_time)
        {
        }
    } DHPLUGIN_CONFIG;

    // ��ͨ��������Ϣ
    typedef struct _DHCHANNEL_INFO
    {
        STREAMSOURCE_INFO source_info;          // ��������ͨ����Ϣ

        LONG login_id;                          // �豸ע��ID
        LONG real_handle;                       // ��Ƶ���Ӿ��
        LONG voice_handle;                      // �����Խ����

        PACKET_DATA packet_data;                // ý�����ݰ�
        UINT sequence;                          // �������ݰ����
        
        _DHCHANNEL_INFO(void) : login_id(), 
            real_handle(Plugin::invalid_handle), voice_handle(Plugin::invalid_handle),
            sequence(0)
        {
            // ��ʼ�����ݰ�������Ϣ
            init_packet_info(packet_data.info);
        }
    } DHCHANNEL_INFO;

    //
    // ���豸���빦����
    //
    class CDHVideoServerConnect
    {
    public:
        CDHVideoServerConnect();//IPacketCallbackPtr packet_callback_ptr = NULL);
        virtual ~CDHVideoServerConnect(void);

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
        void config(const DHPLUGIN_CONFIG& dhplugin_config)
        {
            _dhplugin_config = dhplugin_config;
        };

        // �豸�Ͽ�ʱ�ص�
        void device_disconnect_callback(LONG lLoginID, char *pchDVRIP, LONG nDVRPort);

        // �豸��������ʱ�ص�
        void device_reconnect_callback(LONG lLoginID, char *pchDVRIP, LONG nDVRPort);

    private:
        // �ر�ͨ��
        RETCODE close_channel(DHCHANNEL_INFO& dhchannel_info);

    public:
        static CDHVideoServerConnect* global_connector;

    private:
        // ��SDK��ʼ���ɹ���־
        BOOL _is_init_ok;

        // �󻪲��������Ϣ
        DHPLUGIN_CONFIG _dhplugin_config;

        // ���ݰ��ص�����ָ��
        //IPacketCallbackPtr _packet_callback_ptr;

        // ͨ����Ϣ�б�
        std::map<INT, DHCHANNEL_INFO> _dhchannel_info_map;

	private:
		int test();
    };
}

#endif