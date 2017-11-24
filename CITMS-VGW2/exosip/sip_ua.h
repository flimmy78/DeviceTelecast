#ifndef _SIP_UA_H_
#define _SIP_UA_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#define SEND_NAT_PROBE_MSG WM_USER + 100

#include <osip_mt.h>

namespace SIP_UA
{
	//�¼����ͣ���UserAgent.h��sip_ua.h��Ӧ����һ��
	typedef enum
	{
		SIP_INTIVE = 0,//�յ�����UA����
		SIP_HANGUP,//�����б�����UA�ܽӻ�ͨ���У����������У��Է�UA�����Ҷ�
		SIP_MSG,//�յ�����UA��Message��Ϣ
		SIP_ANSWERED,//��������UA��Է�����
		SIP_NOTIFY,//��������UA NOTIFY��Ϣ
		SIP_REG_FAIL,//ע��ʧ��
		SIP_Unknown//δ֪
	}
	SIP_EVENT_TYPE;

	//������
	typedef enum
	{
		SIP_ERROR_NOERROR = 0//�޴���

	}
	SIP_ERROR_CODE;	

	//SIPͨ���¼��ص�
	//ua_idΪ�Է�UA��ID
	//typeΪʱ������
	//��typeΪSIP_MESSAGEʱattachmentΪ��Ϣ����,����attachmentΪ���ַ���
	typedef void (*EventCallBackFunc)(const char* from, const char* to, const SIP_EVENT_TYPE& type, const char* attachment);

	extern EventCallBackFunc _event_callback_func;

	extern char* _proxy;
	extern char* _contact;
	extern char* _fromuser;

	extern char* _local_ip;
	extern unsigned short _local_port;
	extern char* _server_ip;
	extern unsigned short _server_port;
	
	extern char* _username;
	extern char* _password;

	extern int _regid;
	extern int _expiry;
	extern int _auth;

	extern bool _stop_event_thread;
	extern struct osip_thread* _event_thread;

	extern char* _peer_uri;//�Է�UA

	extern bool _auto_answer;

	extern int _call_id;
	extern int _dialog_id;
	extern int _transaction_id;

	//����SIPUA(��ʼ��������Ϣ����)
	extern bool start(const char* username, const char* password,
					const char* local_ip, const unsigned short local_port,
					const char* server_ip, const unsigned short server_port,
					bool by_tcp);

	extern void shutdown();

	//����SIP�¼��ص�����
	extern void set_callback_func(EventCallBackFunc func);

	//��SIP������ע��
	extern void sip_register(int expires);

	//����UA
	extern void call(const char* ua_id);

	//�Ƿ������Զ�����,enableΪ����
	extern void auto_answer(bool enable);

	//����Ӧ��
	//���ڷ��Զ�Ӧ������µ���
	extern void answer();

	//�Ҷ�ͨ��,������������
	//Ϊ����,����Ӧ���Ҷ�
	//Ϊ����,����δӦ�������Ҷ�
	//Ϊ����,Ӧ���Ҷ�
	//Ϊ����,�ܾ�����
	extern void hangup();

	//��UA����Message��Ϣ,contentΪ��Ϣ����
	extern void message(const char* ua_id, const char* content);

}
#endif//_SIP_UA_H_