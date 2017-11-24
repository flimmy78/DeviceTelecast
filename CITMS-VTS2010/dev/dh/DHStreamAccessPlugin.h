#ifndef _DHSTREAMACCESSPLUGIN_H_        
#define _DHSTREAMACCESSPLUGIN_H_ 

#pragma once

//���DLL
#define DLL_EXPORTS

#include "StdAfx.h"
#include "DHVideoServerConnect.h"

namespace ScheduleServer
{
	namespace Plugin
    {
        namespace DHDVR
        {
            const string module_name = "PLUGIN.DH"; // ���ģ������
            const string module_version = "1.0";    // ����汾��
        }
    };

    class CDHStreamAccessPlugin
    {
    public:
        CDHStreamAccessPlugin(void);
        ~CDHStreamAccessPlugin(void);

        // �������
        virtual void config(void);

        // ���ģ���ʼ��
        virtual void init(void);

        // ���ģ��ж��
        virtual void uninit(void);

        // ����豸����
        virtual DEVICE_TYPE get_device_type(void);

        // ý��������
        virtual RETCODE access_stream(const REQUEST_INFO& request_info, 
            const CHAR * in_data_ptr,
            ULONG in_data_length,
            CHAR * out_data_ptr,
            ULONG& out_data_length);

    private:
        STRING _config_file;                        // ��������ļ�
        DHPLUGIN_CONFIG _dhplugin_config;           // �󻪲��������Ϣ
        CDHVideoServerConnect* _dhconnect_ptr;      // ���豸���빦�ܶ���ָ��
    };
}

#endif  // _DHSTREAMACCESSPLUGIN_H_         
