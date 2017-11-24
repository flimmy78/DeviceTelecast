#ifndef _RETCODE_H_         
#define _RETCODE_H_ 

#include "Config.h"

namespace ScheduleServer
{
    // ��ý����񷵻�ֵ���Ͷ���
    typedef enum
    {
        RETCODE_OK = 0,                                             // ��������ɹ�
        RETCODE_FAIL,                                               // ��������ʧ��
        RETCODE_EXCEPTION,                                          // �쳣����
        RETCODE_MEMORY_FAIL,                                        // �ڴ����ʧ��

        RETCODE_REQUEST_PARAMETERS_ERROR,                           // ���������������
        RETCODE_REQUEST_SDK_FAIL,                                   // �������SDKʧ��
        RETCODE_REQUEST_NOT_IMPLEMENT,                              // ������δʵ��    
        RETCODE_REQUEST_NOT_SUPPORT,                                // �����ܲ�֧��

        RETCODE_MODULE_LOAD_FAIL,                                   // �������ʧ��
        RETCODE_MODULE_UNLOAD_FAIL,                                 // ���ж��ʧ��
        RETCODE_MODULE_NOT_FOUND,                                   // δ�ҵ����
        RETCODE_MODULE_NOT_IDLE,                                    // ��������ڿ���״̬
        RETCODE_MODULE_ALREADY_LOAD,                                // ����Ѿ�����
        RETCODE_DEVICE_NOT_SUPPORT,                                 // �豸���Ͳ�֧��

        RETCODE_ACCESS_CHECKIN,                                     // ͨ������
        RETCODE_ACCESS_CHECKOUT,                                    // ͨ���Ͽ�����
        RETCODE_ACCESS_FAIL,                                        // ͨ������ʧ��
        RETCODE_ACCESS_MAX,                                         // ͨ���������Ѵﵽ���ֵ

        RETCODE_ACCESS_LOGIN_PASSWORD_ERROR,                        // �豸ע���������
        RETCODE_ACCESS_LOGIN_REGIST_FAIL,                           // �豸ע��ʧ��
        RETCODE_ACCESS_NETWORK_FAIL_CONNECT,                        // ���ӷ�����ʧ��

        RETCODE_ACCESS_RECORDFILE_ERROR,                            // ¼���ļ�����

        RETCODE_RTSPSERVER_MODULE_NOT_FOUND,                        // δ�ҵ�RTSPЭ��ջ���       
        RETCODE_RTSPSERVER_ERROR,                                   // RTSPЭ��ջ���ܵ���ʧ��       

        RETCODE_COMMUNICATOR_ERROR,                                 // ICEͨ��������
        RETCODE_DBPROXY_ERROR,                                      // ���ݿ�������
        RETCODE_REGPROXY_ERROR,                                     // ƽ̨ע��������    
        RETCODE_MONITORPROXY_ERROR,                                 // ǰ�˷������������    
        RETCODE_ALARMPROXY_ERROR,                                   // �����������������    

        RETCODE_DBPROXY_QUERY_FAIL,                                 // ���ݿ��ѯʧ��

        RETCODE_SERVER_NOT_REGIST,                                  // ��ý�������δע��    

        RETCODE_UNKNOWN_ERROR                                       // δ֪����    
    } RETCODE;

    typedef struct 
    {
        RETCODE ret_code;
        STRING message;
    } RETINFO;

    const STRING DEFAULT_ERROR_MESSAGE = "δ֪����";

    const RETINFO global_retinfo_list[] = {
        {RETCODE_OK,                                                "��������ɹ�"},
        {RETCODE_FAIL,                                              "��������ʧ��"},
        {RETCODE_EXCEPTION,                                         "�쳣����"},
        {RETCODE_MEMORY_FAIL,                                       "�ڴ����ʧ��"},

        {RETCODE_REQUEST_PARAMETERS_ERROR,                          "���������������"},
        {RETCODE_REQUEST_SDK_FAIL,                                  "�������SDKʧ��"},
        {RETCODE_REQUEST_NOT_IMPLEMENT,                             "������δʵ��"},    
        {RETCODE_REQUEST_NOT_SUPPORT,                               "�����ܲ�֧��"},

        {RETCODE_MODULE_LOAD_FAIL,                                  "�������ʧ��"},
        {RETCODE_MODULE_UNLOAD_FAIL,                                "���ж��ʧ��"},
        {RETCODE_MODULE_NOT_FOUND,                                  "δ�ҵ����"},
        {RETCODE_MODULE_NOT_IDLE,                                   "��������ڿ���״̬"},
        {RETCODE_MODULE_ALREADY_LOAD,                               "����Ѿ�����"},
        {RETCODE_DEVICE_NOT_SUPPORT,                                "�豸���Ͳ�֧��"},

        {RETCODE_ACCESS_CHECKIN,                                    "ͨ������"},
        {RETCODE_ACCESS_CHECKOUT,                                   "ͨ���Ͽ�����"},
        {RETCODE_ACCESS_FAIL,                                       "ͨ������ʧ��"},
        {RETCODE_ACCESS_MAX,                                        "ͨ���������Ѵﵽ���ֵ"},

        {RETCODE_ACCESS_LOGIN_PASSWORD_ERROR,                       "�豸ע���������"},
        {RETCODE_ACCESS_LOGIN_REGIST_FAIL,                          "�豸ע��ʧ��"},
        {RETCODE_ACCESS_NETWORK_FAIL_CONNECT,                       "���ӷ�����ʧ��"},

        {RETCODE_ACCESS_LOGIN_PASSWORD_ERROR,                       "�豸ע���������"},
        {RETCODE_ACCESS_LOGIN_REGIST_FAIL,                          "�豸ע��ʧ��"},

        {RETCODE_ACCESS_RECORDFILE_ERROR,                           "¼���ļ�����"},

        {RETCODE_RTSPSERVER_MODULE_NOT_FOUND,                       "δ�ҵ�RTSPЭ��ջ���"},       
        {RETCODE_RTSPSERVER_ERROR,                                  "RTSPЭ��ջ���ܵ���ʧ��"},       

        {RETCODE_COMMUNICATOR_ERROR,                                "ICEͨ��������"},
        {RETCODE_DBPROXY_ERROR,                                     "���ݿ�������"},
        {RETCODE_REGPROXY_ERROR,                                    "ƽ̨ע��������"},    
        {RETCODE_MONITORPROXY_ERROR,                                "ǰ�˷������������"},
        {RETCODE_ALARMPROXY_ERROR,                                  "�����������������"},

        {RETCODE_DBPROXY_QUERY_FAIL,                                "���ݿ��ѯʧ��"},

        {RETCODE_SERVER_NOT_REGIST,                                 "��ý�������δע��"},

        {RETCODE_UNKNOWN_ERROR,                                     "δ֪����"}
    };
}

#endif  // _RETCODE_H_      
