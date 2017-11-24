#ifndef INCLUDED_DPSDK_CORE_ERROR_H
#define INCLUDED_DPSDK_CORE_ERROR_H

#include "DPSDK_Core_Define.h"

#define CFL_ERROR_SUCCESS						200						// �ɹ�������ֵ
#define CLIENT_ERROR_BASE						420						// �ͻ��˴�����ֵ
#define SERVER_ERROR_BASE						520						// ���������ֵ
#define DSS_ERROR_BASE							720						// ����������ֵ
#define DSS_ERROR_CODE_BASE						1000000					// �����������ʼ
#define DSS_DMS_BASE							1000					// DMS ��������ʼ
#define DSS_VMS_BASE							2000					// VMS ��������ʼ
#define DSS_RTSP_BASE							3000					// RTSP ��������ʼ
#define DSS_ALARM_BASE							4000					// ALARM ��������ʼ
#define DSS_MS_BASE								5000					// MS ��������ʼ
#define DSS_PCS_BASE							6000					// PCS ��������ʼ
#define DSS_FMS_BASE							7000					// FMS ��������ʼ
#define DSS_ANA_BASE							8000					// ANA ��������ʼ
#define PSS_ERROR_CODE_BASE						1050000

//��Ϣ������
typedef enum
{
	//<0 ͬ�����ش���
	DPSDK_RET_SYNC_FAIL                     = -1,

	DPSDK_RET_SUCCESS                       = 0,			// �ɹ�																   
	DPSDK_RET_SERIALIZE_PDU_FAILED          = 1,			// Э�����ʧ��
	DPSDK_RET_SENDDATA_FAILED               = 2,			// ���ݷ���ʧ��
	DPSDK_RET_NET_CONNECT_FAILED            = 3,			// ����Զ��ʧ��
	DPSDK_RET_ALREADY_LOGIN                 = 4,			// ��¼�Ѵ���
	DPSDK_RET_ALREADY_LOGOUT                = 5,			// �ѵǳ�
	DPSDK_RET_SERIALIZE_XML_FAILED          = 6,			// Xml����ʧ��
	DPSDK_RET_NODE_NO_RIGHT                 = 7,			// �޲���Ȩ��	
	DPSDK_RET_UNKNOW_DEVICE                 = 8,			// δ֪�豸
	DPSDK_RET_UNKNOW_CHANNEL                = 9,			// δ֪ͨ��
	DPSDK_RET_DEVICE_OFFLINE                = 10,			// �豸����
	DPSDK_RET_RTSP_CONNECT_FAILED           = 11,			// rtsp����ʧ��
	DPSDK_RET_RTP_LISTEN_FAILED             = 12,			// rtp����ʧ��
	DPSDK_RET_RTP_CONNECT_FAILED            = 13,			// rtp����ʧ��
	DPSDK_RET_PARSE_TRANSPORT_FAILED        = 14,			// rtsp�����˿�ʧ��
	DPSDK_RET_ALREADY_CANCELED              = 15,			// �����ѱ�ȡ��
	DPSDK_RET_UNKNOWN_SESSION               = 16,			// ��Ч��session fixme:����������ͳһΪ��Ӧ��
	//talk���									   
	DPSDK_RET_TALK_INNVALIDPARAM            = 17,			// �Խ���������
	DPSDK_RET_TALK_NOT_SUPPORT              = 18,			// �Խ���֧��									   
	DPSDK_RET_DMSSESSION_NOT_FOUND          = 19,			// û�ҵ���Ӧ��dmsSession
	//alarm���									   
	DPSDK_RET_ADSSESSION_NOT_FOUND          = 20,			// δ�ҵ�ADS
	DPSDK_RET_ADSSESSION_NOT_LOGIN          = 21,			// δ��¼�ɹ�ADS
	DPSDK_RET_DATABASE_NO_RECORD            = 22,			// û���ҵ�ALARM��ؼ�¼
	DPSDK_RET_ALARMTYPE_NOT_MATCH           = 23,			// �������Ͳ�ƥ��
	//�ط�										   
	DPSDK_RET_PLAYBACK_SESSION_NOT_FOUND    = 24,			// �޷��ҵ��طŻỰ
	DPSDK_RET_PLAYBACK_UNKNOW_PLAYTYPE      = 25,			// �޷����ֲ�������
	DPSDK_RET_PLAYBACK_NETSDK_SEEK_FAIL     = 26,			// ����SDK��seek����ʧ��
	DPSDK_RET_PLAYBACK_SEEK_SIZE_ERROR      = 27,			// �طŶ�λ��size����
	DPSDK_RET_PLAYBACK_SEEK_TIME_ERROR      = 28,			// �طŶ�λ��ʱ�����
	DPSDK_RET_PLAYBACK_DEVICE_NOT_FOUND     = 29,			// �ط�ʱû���ҵ���Ҫ���豸
	DPSDK_RET_PLAYBACK_PLAY_REPEAT          = 30,			// ��ͨ��ֻ����ط�һ·
	DPSDK_RET_INVALID_CONFIGTYPE            = 31,			// ��������Ϣ�����Ͳ�֧��
	DPSDK_RET_UNSUPPORTED_STREAM            = 32,			// ���������Ͳ�֧��
	DPSDK_RET_PLAYBACK_NOTFIND_DEV          = 33,			// �豸��Ϣδ�ҵ�
	DPSDK_RET_PLAYBACK_PARAM                = 34,			// �طŲ�������
	DPSDK_RET_PLAYBACK_PARAM_CAMERA         = 35,			// �ط�δ֪����ͷ
	DPSDK_RET_FTPSERVER_NOT_FIND            = 36,			// FTP������û�ҵ�
	DPSDK_RET_FTPCURL_ERROR                 = 37,			// ����curl���ش���
	DPSDK_RET_FTPCURL_LOCALFILE_NOT_OPEN    = 38,			// ����curl����δ�ҵ������ļ�
	DPSDK_RET_FTPCURL_LOCALFILE_NOT_READ    = 39,			// ����curl���ش򿪱����ļ�����
	DPSDK_RET_FTPCURL_FTPFILE_ERROR         = 40,			// ����curl���ز���Զ���ļ�����
	DPSDK_RET_FTPCURL_FREE_ERROR            = 41,			// ����curl�����ͷų���
	DPSDK_RET_PCS_ERROR                     = 42,           // PCS��������
	DPSDK_RET_PES_ERROR                     = 43,           // PES��������
	DPSDK_RET_PES_NOT_LOGIN                 = 44,			// δ��½��PES
	DPSDK_RET_PES_ENCODE_AHSOTCMD_FAILED    = 45,			// ���������������ʧ��
	DPSDK_RET_PES_ENCODE_DCTRL_FAILED       = 46,           // �Ž��������ʧ��
	DPSDK_RET_PES_ENCODE_PGRID_FAILED       = 47,           // �����������ʧ��

	DPSDK_RET_CHANNEL_EMPTY                 = 48,			// ͨ����Ϊ��
	DPSDK_RET_MSG_EMPTY                     = 49,			// ������ϢΪ��
	DPSDK_RET_MSG_INVALID_CMD               = 50,			// δ�������Ϣ����
	DPSDK_RET_DECODE_PDU_FAILED             = 51,			// Э�����ʧ��
	DPSDK_RET_SENDDATA_EMPTY                = 52,			// ��������Ϊ��
	DPSDK_RET_PESSESSION_NOT_FOUND          = 53,			// û�ҵ���Ӧ��pesSession
	DPSDK_RET_ALARMREPORT_NEW_FAILED        = 54,			// ������Ϣ���ڴ�����ʧ��
	DPSDK_RET_PCS_NOT_LOGIN                 = 55,			// δ��½��PCS
	DPSDK_RET_RTSPMDL_NOT_FIND              = 56,			// û�ҵ���Ӧ��RTSPMDL
	DPSDK_RET_RTSPMSG_INVALID_CMD           = 57,			// δ�����RTSP��Ϣ����
	DPSDK_RET_LOAD_XML                      = 58,			// ����Xmlʧ��

	//����ģ��ex
	DPSDK_RET_CONFIGEX_LOGIN_FAIL           = 59,			// �豸��½ʧ��
	DPSDK_RET_CONFIGEX_LOGINOUT_FAIL        = 60,			// �豸�ǳ�ʧ��

	//����netsdk�Ĵ���
	DPSDK_RET_NETSDK_ERROR                         = 61,
	DPSDK_RET_DEVCONFIG_STRUCT_UNABLE_OPERATOR     = 62,	// �ýṹ��֧�ָò���
	DPSDK_RET_LOCAL_INVALID_USERNAME               = 63,    // ��Ч�ı����û���
	DPSDK_RET_LOCAL_INVALID_PASSWORD               = 64,    // ��Ч�ı�������

	//���񷵻ش���δ����
	DPSDK_RET_CMS_RET_ERROR                 = 65,			// CMS ���ش���
	DPSDK_RET_DMS_RET_ERROR                 = 66,			// DMS ���ش���
	DPSDK_RET_PCS_RET_ERROR                 = 67,			// PCS ���ش���
	DPSDK_RET_RTSP_RET_ERROR                = 68,			// RTSP ���ش���

	DPSDK_RET_CMS_ERR_NOT_FOUND             = 69,			// CMS ���ش��� -- δ�ҵ�

	DPSDK_RET_RTSP_DISCONNECTED             = 70,           // RTSP���ӶϿ�
	
	DPSDK_CORE_BEGIN                        = 1000,
	DPSDK_CORE_ERROR_NOT_SUPPORT,				// ��֧��
	DPSDK_CORE_ERROR_GET_MEMORY_FAIL,			// ��ȡ�ڴ�ʧ��
	DPSDK_CORE_ERROR_WITHOUT_CREATE,			// û�д���
	DPSDK_CORE_ERROR_CREATE_FAIL,				// ����ʧ��
	DPSDK_CORE_ERROR_INIT_FAIL,					// ��ʼ��ʧ��
	DPSDK_CORE_ERROR_UINIT_FAIL,				// ����ʼ��ʧ��
	DPSDK_CORE_ERROR_WITHOUT_INIT,				// û�г�ʼ��
	DPSDK_CORE_ERROR_INVALID_HANDLE,			// ��Ч�ľ��
	DPSDK_CORE_ERROR_INVALID_PARAM,				// ��Ч�Ĳ���
	DPSDK_CORE_ERROR_TIMEOUT,					// ������ʱ
	DPSDK_CORE_ERROR_SYNCFUN_ERROR,				// ͬ�����ô���
	DPSDK_CORE_ERROR_SERIES,					// ���л�ʧ��
	DPSDK_CORE_ERROR_FOUND_FAIL,				// ����ʧ��
	DPSDK_CORE_ERROR_SIZE_ZERO,					// ��СΪ��
	DPSDK_CORE_ERROR_PARSE_ALARM_ENABLE_FAIL,	// ������������ʧ��
	DPSDK_CORE_ERROR_GET_FREEPORT_FAIL,			// ��ȡ����Portʧ��
	DPSDK_CORE_ERROR_INVALID_SEQ,               // ��Ч��SEQ
	DPSDK_CORE_ERROR_WITHOUT_LOGIN,             // û�е�¼
	DPSDK_CORE_ERROR_WITHOUT_LOADGROUP,         // û�м���֯��Ϣ
	DPSDK_CORE_ERROR_ERROR_LEN,					// ���ȴ���
	DPSDK_CORE_ERROR_RANGE_OVER,				// ��ΧԽ��
	DPSDK_CORE_ERROR_CAPTURE_FAIL,				// ץͼʧ��
	DPSDK_CORE_ERROR_OPEN_FILE_FAIL,			// ���ļ�ʧ��
	DPSDK_CORE_ERROR_SAVE_FILE_FAIL,			// �����ļ�ʧ��
	DPSDK_CORE_ERROR_VIDEO_NOT_PLAYING,               // ��û�п�ʼ������Ƶ
	DPSDK_CORE_ERROR_STARTRECORD_FAIL,			// ¼��ʵʱ��Ƶʧ��
	DPSDK_CORE_ERROR_STOPRECORD_FAIL,			// ֹͣ¼����Ƶʧ��
	DPSDK_CORE_ERROR_SETOSDTXT_FAIL,			// ����osd��Ϣʧ��   
	DPSDK_CORE_ERROR_CLEANUP_OSDTXT_FAIL,       // ���osd��Ϣʧ��
	DPSDK_CORE_ERROR_OPENWINDOW_FAIL,			// ����ʧ��(Ŀǰ�ݶ����4��)
	DPSDK_CORE_ERROR_GETDEVICEINFO_FAIL,		// ��ȡ�豸��Ϣʧ��
	DPSDK_CORE_ERROR_STREAMCONVERTOR_FAIL,      // ����ת��⺯��ʧ��
	DPSDK_CORE_ERROR_PLAYSDK_FAIL,              // ���ò��ſ⺯��ʧ��  
	DPSDK_CORE_ERROR_STREAMANALYSER_FAIL,       // �������������⺯��ʧ��
	DPSDK_CORE_ERROR_CANCELED,                  // ��Ϊȡ������
	DPSDK_CORE_ERROR_NONE_LOGIC_ORG,			// û��ҵ����
	DPSDK_CORE_ERROR_GET_LOGIC_ID,				// ��ȡҵ����ָ���ڵ��� �豸����ͨ��ID����
	DPSDK_CORE_ERROR_OPENWINDOW_NOT_BIGSCREEN,	// ����ʧ��(�����ں���)
	DPSDK_CORE_ERROR_CREATE_JNI_ERROR = 1999,	//����JNI����ʧ��
	DPSDK_CORE_END = 2000,

	DPSDK_RET_END = 5000,

	SERVER_RET_CMS_ERR_BEGIN            = DSS_ERROR_CODE_BASE,						// CMS���ؿ�ʼ����������ֵ�ж�
	SERVER_RET_CMS_ERR_QUERY_PU_SUCCESS,											// ��ѯȫ��¼��ʱ,ֻ��ǰ�˲�ѯ�ɹ�
	SERVER_RET_CMS_ERR_QUERY_CENTER_SUCCESS,										// ��ѯȫ��¼��ʱ,ֻ�����Ĳ�ѯ�ɹ�

	SERVER_RET_CMS_CLIENT_ERROR_BEGIN   = SERVER_RET_CMS_ERR_BEGIN + CLIENT_ERROR_BASE,	// CMS�ͻ���Э�鷵�ؿ�ʼ����������ֵ�ж�
	SERVER_RET_CMS_ERR_NO_USER_ID,													// �û�ID������
	SERVER_RET_CMS_ERR_NO_USER_NAME_TO_ID,											// ���û���ƥ�䲻��ID
	SERVER_RET_CMS_ERR_NO_USER_NAME,												// �û���������
	SERVER_RET_CMS_ERR_PASSWORD_INVALID,											// ������Ч
	SERVER_RET_CMS_ERR_INVALID_USER_ID,												// ��Ч���û�ID
	SERVER_RET_CMS_ERR_USER_LOCKED,													// �û�������
	SERVER_RET_CMS_ERR_SESSION_EXIST,												// �û��Ѿ����ڵ�¼�Ự
	SERVER_RET_CMS_ERR_NO_SESSION,													// �Ự������
	SERVER_RET_CMS_ERR_SERVER_REGISTERED,											// �����Ѿ�ע��
	SERVER_RET_CMS_ERR_SERVER_NOT_REGISTER,											// ���ܷ���û��ע��
	SERVER_RET_CMS_ERR_INVALID_CAMERA_ID,											// ����ͷid��Ч
	SERVER_RET_CMS_ERR_NO_DEVICE,													// �Ҳ����豸
	SERVER_RET_CMS_ERR_MEDIA_SESSION_EXIST,											// ý��Ự�Ѵ���
	SERVER_RET_CMS_ERR_GRANT_SESSION_EXIST,											// ��Ȩ�Ự�Ѵ���
	SERVER_RET_CMS_ERR_NO_CAMERA_ROW,												// �Ҳ�������ͷ��
	SERVER_RET_CMS_ERR_UNKNOWN_TYPE,												// ��Ч������ֵ
	SERVER_RET_CMS_ERR_TOO_MANY_GROUP_COUNT,										// �û���������̫��
	SERVER_RET_CMS_ERR_TOO_MANY,													// ����̫��
	SERVER_RET_CMS_ERR_EXIST_HIGH_USER,												// ���ڸ߼����û� add by fengjian 2012.8.8
	SERVER_RET_CMS_CLIENT_ERROR_END = SERVER_RET_CMS_ERR_BEGIN + CLIENT_ERROR_BASE + 100,

	SERVER_RET_CMS_SERVER_ERROR_BEGIN   = SERVER_RET_CMS_ERR_BEGIN + SERVER_ERROR_BASE,	// CMS����Э�鷵�ؿ�ʼ����������ֵ�ж�
	SERVER_RET_CMS_ERR_NO_CONNECTION,												// ���Ӳ�����
	SERVER_RET_CMS_ERR_INVALID_SERVER,												// δ��ϵͳ�еǼǵķ���
	SERVER_RET_CMS_ERR_NO_DOMAIN,													// �����򲻴���
	SERVER_RET_CMS_ERR_NO_SERVER_BEAN,												// ������󲻴���
	SERVER_RET_CMS_ERR_NO_MTS_TO_USE,												// û��MTS����
	SERVER_RET_CMS_ERR_SESSION_DELETE,												// �Ự�Ѿ����
	SERVER_RET_CMS_ERR_SERVER_RECONNECT,											// ���ܷ�����������
	SERVER_RET_CMS_ERR_ADD_CAMERA_FAILED,											// �������ͷʧ��
	SERVER_RET_CMS_ERR_ADD_CLIENT_FAILED,											// ��ӿͻ���ʧ��
	SERVER_RET_CMS_ERR_DATABASE_ACCESS_FAILED,										// ���ݿ����ʧ��
	SERVER_RET_CMS_ERR_DATABASE_NO_RECORD,											// ���ݿ�û�м�¼
	SERVER_RET_CMS_ERR_DATA_TOO_LONG,												// ����̫����
	SERVER_RET_CMS_ERR_NO_GROUPS_OF_USER,											// û���ҵ��û�����������
	SERVER_RET_CMS_ERR_QUERY_RECORD_FAILED,											// ��ѯ¼��ʧ��
	SERVER_RET_CMS_ERR_OTHER_USER_PLAYBACK,											// �����û��ڻطŸ�����ͷ
	SERVER_RET_CMS_ERR_REACH_PU_PLAYBACK_LIMIT,										// �ﵽǰ�˻طŵ�����
	SERVER_RET_CMS_ERR_NO_DMS_TO_USE,												// û��DMS����
	SERVER_RET_CMS_ERR_DEV_GRANT_CHANGED,											// �豸��Ȩ���ĵ���������
	SERVER_RET_CMS_ERR_ADD_DVR_FAILED,												// ���DVRʧ��
	SERVER_RET_CMS_ERR_GRANT_FAILED,												// ��Ȩ��DMSʧ��
	SERVER_RET_CMS_ERR_SS_PLAYBACK_FAILED,											// SS�ط�ʧ��
	SERVER_RET_CMS_ERR_REACH_SYSTEM_LIMIT,											// �ﵽϵͳ����
	SERVER_RET_CMS_ERR_INVALID_DEVICE_PROVIDER,										// ��Ч���豸����
	SERVER_RET_CMS_ERR_NO_URL,														// û������URL
	SERVER_RET_CMS_ERR_NO_SS_TO_USE,						 						// û��SS����
	SERVER_RET_CMS_ERR_PU_QUERY_TIMEOUT,					 						// ǰ�˲�ѯ��ʱ
	SERVER_RET_CMS_ERR_PU_QUERY_RECORD_FAILED,										// ǰ�˲�ѯ¼��ʧ��
	SERVER_RET_CMS_ERR_NO_MTS_FOR_DEVICE,											// û�к�����豸�����MTS
	SERVER_RET_CMS_ERR_DEVICE_IN_TALKING,											// �豸���ڽ��������Խ�
	SERVER_RET_CMS_ERR_DEVICE_NOT_TALKING,											// �豸û���ڽ��������Խ�
	SERVER_RET_CMS_ERR_ENCODE_PDU,													// CMS��׼��Ӧ��ʱ�򣬽���Encode����ʧ��
	SERVER_RET_CMS_ERR_DECODE_PDU,													// CMS��׼��Ӧ��ʱ�򣬽���Decode����ʧ��
	SERVER_RET_CMS_ERR_NOT_FOUND_LOWER_DOMAIN,										// û���ҵ��¼���
	SERVER_RET_CMS_ERR_NOT_LOGIN_LOWER_DOMAIN,										// δ��½�¼���
	SERVER_RET_CMS_ERR_NO_RIGHT,													// ��Ȩ��
	SERVER_RET_CMS_ERR_QUERY_ALARM_FAILED,											// ��ѯ����ʧ��
	SERVER_RET_CMS_ERR_DEIVCE_OFFLINE,												// �豸������
	SERVER_RET_CMS_ERR_LOWER_DOMAIN_EXCEPTION,										// �¼����쳣
	SERVER_RET_CMS_ERR_ALARM_PRE_RECORD_OPENED,										// ����Ԥ¼�Ѿ���
	SERVER_RET_CMS_ERR_RECONNECT_DEVICE,											// ���ܷ������������豸
	SERVER_RET_CMS_ERR_SEND_FUN_SVR_REQ_FAIL,										// ���ܷ�������������ʧ��

	//add by fengjian 2012.8.7
	SERVER_RET_CMS_ERR_CU_START_RECORD_FAIL,										// ��ʼ¼��ʧ��
	SERVER_RET_CMS_ERR_CU_RECORING_NOW,												// ����¼��
	SERVER_RET_CMS_ERR_CU_STOP_RECORD_FAIL,											// ֹͣ¼��ʧ��
	SERVER_RET_CMS_ERR_CU_OTHERUSER_RECORDING,										// �����û�����¼��
	SERVER_RET_CMS_ERR_CU_START_RECORD_RUNNING = DSS_ERROR_CODE_BASE + 566,			// ��ʼ¼��ʧ�ܣ�������
	SERVER_RET_CMS_ERR_CU_START_RECORD_LIMITE,										// ��ʼ¼��ʧ�ܣ�����ֹ
	SERVER_RET_CMS_ERR_CU_START_RECORD_NO_SS,										// ��ʼ¼��ʧ�ܣ�û�п��õ�SS
	SERVER_RET_CMS_ERR_NO_PES_TO_USE,												// û�п��õ�PES������ 
	//add end																		 
	SERVER_RET_CMS_ERR_UNKNOWN_PROTOCOL,											// ��֧�ֵ�Э������
	SERVER_RET_CMS_ERR_CONFIG_FILE_TIMEOUT,											// �������ļ�����
	SERVER_RET_CMS_ERR_NO_BOLCK,													// �޿��õ�block
	SERVER_RET_CMS_ERR_END = SERVER_RET_CMS_ERR_BEGIN + 1000,						// CMS���ؽ���


	SERVER_RET_DMS_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_DMS_BASE,					    // DMS���ؿ�ʼ����������ֵ�ж�
	SERVER_RET_DMS_ERR_HAS_NO_RIGHT = SERVER_RET_DMS_ERR_BEGIN + 401,					// û��Ȩ��
	SERVER_RET_DMS_CLIENT_ERROR_BEGIN = SERVER_RET_DMS_ERR_BEGIN + CLIENT_ERROR_BASE,	// DMS�ͻ���Э�鷵�ؿ�ʼ����������ֵ�ж�
	SERVER_RET_DMS_ERR_NO_PRIVILEGE,													// û��Ȩ��
	SERVER_RET_DMS_CLIENT_ERROR_END = SERVER_RET_DMS_ERR_BEGIN + CLIENT_ERROR_BASE + 100,
	
	SERVER_RET_DMS_SERVER_ERROR_BEGIN  = SERVER_RET_DMS_ERR_BEGIN + SERVER_ERROR_BASE,	// DMS����Э�鷵�ؿ�ʼ����������ֵ�ж�
	SERVER_RET_DMS_ERR_PTZ_FAILED,														// ��̨�ڲ����Ƴ���
	SERVER_RET_DMS_ERR_CONFIG_SET_FAILED,												// �豸�����ڲ����Ƴ���
	SERVER_RET_DMS_ERR_CONFIG_GET_FAILED,												// �豸�����ڲ����Ƴ���
	SERVER_RET_DMS_ERR_CAMERA_OCCUPY,													// ����ͷ�������û�����
	SERVER_RET_DMS_ERR_PTZ_ACCESS_FAILED,												// ����̨Э�̹���ģ���������ʧ��
	SERVER_RET_DMS_ERR_TCP_COMM_NO_CLIENT,												// �û�����û�а󶨵���Ȩ�Ŀͻ���
	SERVER_RET_DMS_ERR_CLIENT_UNIT_NOT_FOUND,											// û���ҵ�û����ӹ��Ŀͻ���
	SERVER_RET_DMS_ERR_DEVICE_NOT_FOUND,												// �豸û�ҵ�
	SERVER_RET_DMS_ERR_PRIVILEGE_NOT_FOUND,												// û���ҵ���Ȩ��Ϣ
	SERVER_RET_DMS_ERR_UNKNOWN_COMMAND,													// δ֪����
	SERVER_RET_DMS_ERR_OCCUPY_BY_HIGHER_USER,											// ���߼��û�ռ��
	SERVER_RET_DMS_ERR_NORMAL_LOCK_FAILED,												// ��ҪServer����Lockʧ�ܴ���
	SERVER_RET_DMS_ERR_OCCUPY_BY_OTHER_USER,											// �������û�ռ��
	SERVER_RET_DMS_ERR_NORMAL_UNLOCK_FAILED,											// ��ҪServer����UnLockʧ�ܴ���
	SERVER_RET_DMS_ERR_NO_DEVICE,														// û���豸
	SERVER_RET_DMS_ERR_NO_RIGHT,														// û��Ȩ��
	SERVER_RET_DMS_ERR_NOT_FOUND_LOWER_DOMAIN,											// û���ҵ��¼���
	SERVER_RET_DMS_ERR_NOT_LOGIN_LOWER_DOMAIN,											// û�е�¼�¼���
	SERVER_RET_DMS_ERR_QUERY_DIAGNOSIS_ID,												// ��ѯ��Ƶ���IDʧ��
	SERVER_RET_DMS_ERR_QUERY_DIAGNOSIS_TYPE_COUNT,										// ��ѯ��Ƶ���������Ŀʧ��
	SERVER_RET_DMS_ERR_QUERY_DIAGNOSIS_INFO,											// ��ѯ��Ƶ�����Ϣʧ��
	SERVER_RET_DMS_ERR_STOP_QUERY_DIAGNOSIS_INFO,										// ֹͣ��Ƶ�����Ϣ��ѯʧ��
	SERVER_RET_DMS_ERR_START_QUERY_PERSON_COUNT,										// ��ʼ��ѯ����ͳ����Ϣʧ��
	SERVER_RET_DMS_ERR_QUERY_PERSON_COUNT,												// ��ѯ����ͳ����Ϣʧ��
	SERVER_RET_DMS_ERR_STOP_QUERY_PERSON_COUNT,											// ֹͣ����ͳ����Ϣ��ѯʧ��
	SERVER_RET_DMS_ERR_END = SERVER_RET_DMS_ERR_BEGIN + 1000,						    // DMS���ؽ���

	SERVER_RET_VMS_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_VMS_BASE,                
	SERVER_RET_VMS_SERVER_ERROR_BEGIN  = SERVER_RET_VMS_ERR_BEGIN + SERVER_ERROR_BASE,	// DMS����Э�鷵�ؿ�ʼ����������ֵ�ж�
	SERVER_RET_VMS_ERR_FAILED = SERVER_RET_VMS_SERVER_ERROR_BEGIN,						// ʧ��-����ԭ��
	SERVER_RET_VMS_ERR_ID_ALREADY_EXIST,												// NVD ID�Ѵ���
	SERVER_RET_VMS_ERR_INVALID_ID,														// ��Ч��ID
	SERVER_RET_VMS_ERR_REACH_LIMIT,														// �ﵽ����
	SERVER_RET_VMS_ERR_END = SERVER_RET_VMS_ERR_BEGIN + 1000,						    // DMS���ؽ���


	SERVER_RET_RTSP_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_RTSP_BASE,  
	SERVER_RET_RTSP_ERR_SETUP_FAILED = SERVER_RET_RTSP_ERR_BEGIN + 503,					// Rtsp����ʧ��
	SERVER_RET_RTSP_SERVER_ERROR_BEGIN  = SERVER_RET_RTSP_ERR_BEGIN + SERVER_ERROR_BASE,// DMS����Э�鷵�ؿ�ʼ����������ֵ�ж�
	SERVER_RET_RTSP_ERR_RECONNECT_DEVICE,												// ���������豸
	SERVER_RET_RTSP_ERR_END = SERVER_RET_RTSP_ERR_BEGIN + 1000,						    // DMS���ؽ���

	SERVER_RET_ALARM_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_ALARM_BASE + DSS_ERROR_BASE,                
	SERVER_RET_ALARM_ERR_URL,															// ��Ч��URL
	SERVER_RET_ALARM_ERR_RES,															// ��Ч������
	SERVER_RET_ALARM_ERR_MDL_TYPE,														// ��Ч�ĵ�Ԫ����
	SERVER_RET_ALARM_ERR_SCHEME_INDEX,													// ��Ч��Ԥ������
	SERVER_RET_ALARM_ERR_SCHEME_TYPE,													// ��Ч��Ԥ������
	SERVER_RET_ALARM_ERR_SCHEME_STRING,													// Ԥ���ַ�������ʧ��
	SERVER_RET_ALARM_ERR_ALARM_NODE,													// ��Ч�ı����ڵ�
	SERVER_RET_ALARM_ERR_END = SERVER_RET_ALARM_ERR_BEGIN + 1000,					    // DMS���ؽ���


	SERVER_RET_MS_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_MS_BASE,                
	SERVER_RET_MS_CLIENT_ERROR_BEGIN = SERVER_RET_MS_ERR_BEGIN + CLIENT_ERROR_BASE,
	SERVER_RET_MS_ERR_ALREADY_LOGIN,													// �Ѿ���¼
	SERVER_RET_MS_ERR_INVALID_SESSION_ID,												// ��Ч�ĻỰID
	SERVER_RET_MS_ERR_NOT_LOGIN,														// δ��¼
	SERVER_RET_MS_ERR_INVALID_CONNECTION,												// ��Ч����
	SERVER_RET_MS_ERR_INVALID_DEV_TYPE,													// ��Ч���豸����
	SERVER_RET_MS_ERR_INVALID_CAMERA_ID,												// ��Ч������ͷid
	SERVER_RET_MS_ERR_CAMERA_SESSION_EXIST,												// ����ͷ�Ѿ���ӹ�
	SERVER_RET_MS_ERR_NO_CAMERA_SESSION,												// ����ͷ�Ự������
	SERVER_RET_MS_ERR_FIND_SAME_TOKEN,													// �ҵ���ͬ��token
	SERVER_RET_MS_ERR_UNKNOWN_RECORD_TYPE,												// �޷�ʶ���¼������
	SERVER_RET_MS_ERR_INVALID_FILE_NAME,												// ��Ч��¼���ļ�����
	SERVER_RET_MS_ERR_INVALID_TIME_VALUE,												// ��Ч��¼��ʱ��ֵ
	SERVER_RET_MS_ERR_NOT_FOUND_SESSION,												// û���ҵ��Ự
	SERVER_RET_MS_ERR_INVALID_RTSP_URL,													// ��Ч��RTSP URL
	SERVER_RET_MS_ERR_PLAN_EXIST,														// �ƻ��Ѿ�����
	SERVER_RET_MS_CLIENT_ERROR_END = SERVER_RET_MS_CLIENT_ERROR_BEGIN + 100,

	SERVER_RET_MS_SERVER_ERROR_BEGIN = SERVER_RET_MS_ERR_BEGIN + SERVER_ERROR_BASE,
	SERVER_RET_MS_ERR_DEV_NOT_LOGIN,													// �豸��δ��¼
	SERVER_RET_MS_ERR_SDK_OPERATE_FAILED,												// sdk����ʧ��
	SERVER_RET_MS_ERR_SESSION_USE_OUT,													// �Ự����
	SERVER_RET_MS_ERR_RTSP_CONNECT_FAILED,												// rtsp����ʧ��
	SERVER_RET_MS_ERR_RTP_LISTEN_FAILED,												// RTP����ʧ��
	SERVER_RET_MS_ERR_RTSP_SETUP_FAILED,												// RTSP Setup����ʧ��
	SERVER_RET_MS_ERR_RTSP_PLAY_FAILED,													// RTSP PLAY����ʧ��
	SERVER_RET_MS_ERR_ADD_RTP_SESSION_FAILED,											// ���RTP SESSION��serverbaseʧ��
	SERVER_RET_MS_ERR_DISK_SPACE_NOT_ENOUGH,											// ���̿ռ䲻��
	SERVER_RET_MS_ERR_OPEN_FILE_FAILED,													// �ļ���ʧ��
	SERVER_RET_MS_ERR_NOT_FOUND_RTSP_CLIENT,											// �Ҳ���RTSP�ͻ�������
	SERVER_RET_MS_ERR_RTSP_DISCONNECTED,												// RTSP���ӶϿ�
	SERVER_RET_MS_ERR_RECORD_QUERY_TIMEOUT,												// ¼���ѯ��ʱ
	SERVER_RET_MS_ERR_SDK_CALLBACK_INVALID_DATA,										// sdk �������ݲ���ȷ
	SERVER_RET_MS_ERR_SNAP_STORE_PATH_INVALID,											// ���õ�SS��SNAP�洢·��������
	SERVER_RET_MS_ERR_SNAP_STORE_FILE_FAILED,											// SS�ڴ洢�ļ�ʱ�����ʧ��
	SERVER_RET_MS_ERR_SNAP_ENCODE_FAILED,												// SS�ڱ���ظ�pduʱ��ʧ��
	SERVER_RET_MS_ERR_IFRAME_2_BMP,														// SS��ת��I֡��BMPʱ��ʧ��
	SERVER_RET_MS_ERR_DUPLICATE_PLAN_FOUND,												// �ظ���PlanId����
	SERVER_RET_MS_ERR_SDK_CALLBACK_TIMEOUT,												// SDK����Callback��ʱ��û�з�������																						   
	SERVER_RET_MS_ERR_NOT_FOUND_SESSION_ID,												// δ�ҵ�camera_session_id
	SERVER_RET_MS_ERR_INVALID_STREAM_TYPE,												// �Ƿ�����������
	SERVER_RET_MS_ERR_ADD_LIVECHANNEL_FAILED,											// ���ֱ��Ƶ��ʧ��
	SERVER_RET_MS_ERR_GET_TALKDECODE_FAILED,											// ��ȡ�Խ���ʽʧ��
	SERVER_RET_MS_ERR_LOGIN_DEV_FAILED,													// ��½�����豸ʧ��
	SERVER_RET_MS_ERR_NOT_MATCH_AUDIO_TYPE,												// ��Ƶ��ʽ��ƥ��
	SERVER_RET_MS_ERR_NOT_FOUND_DISK,													// δ�ҵ�����
	SERVER_RET_MS_ERR_NOT_FOUND_RECORD_PLAN,											// δ�ҵ�¼��ƻ�
	SERVER_RET_MS_SERVER_ERROR_END = SERVER_RET_MS_SERVER_ERROR_BEGIN + 100,
	SERVER_RET_MS_ERR_END = SERVER_RET_MS_ERR_BEGIN + 1000,								 // MS���ؽ���

	SERVER_RET_PCS_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_PCS_BASE,						// PCS����Э�鷵�ؿ�ʼ����������ֵ�ж�
	SERVER_RET_PCS_ERR_NOT_FOUND = SERVER_RET_PCS_ERR_BEGIN + 404,						// �����豸δ�·�
	SERVER_RET_PCS_ERR_NOT_ACCEPTABLE = SERVER_RET_PCS_ERR_BEGIN + 406,					// �������ģ�����PTS����ʧ��
	SERVER_RET_PCS_ERR_DEVICE_OFFLINE = SERVER_RET_PCS_ERR_BEGIN + 710,					// �豸����
	SERVER_RET_PCS_ERR_DOMIAN_OFFLINE = SERVER_RET_PCS_ERR_BEGIN + 713,					// �¼�������
	SERVER_RET_PCS_ERR_PTS_CANNOT_PING = SERVER_RET_PCS_ERR_BEGIN + 714,				// �ϼ������¼�PTSʧ��
	SERVER_RET_PCS_ERR_NO_ACK = SERVER_RET_PCS_ERR_BEGIN + 715,							// ��Ӧ��
	SERVER_RET_PCS_ERR_END = SERVER_RET_PCS_ERR_BEGIN + 1000,							// PCS���ؽ���

	SERVER_RET_FMS_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_FMS_BASE,						// FMS���ؿ�ʼ
	SERVER_RET_FMS_ERR_RTMP_CLIENT_POOL_ALREADY_EXIST,									// RTMP client���Ѿ�����
	SERVER_RET_FMS_ERR_NO_FREE_RTMPCLIENT,												// RTMP Client������û�п��еĵ�ַ
	SERVER_RET_FMS_ERR_STARTSTREAM,														// ����StartStreamʧ��
	SERVER_RET_FMS_ERR_ADDMEDIA,														// ����AddMediaʧ��
	SERVER_RET_FMS_ERR_DELMEDIA,														// ����DelMediaʧ��
	SERVER_RET_FMS_ERR_STOPSTREAM,														// ����StopStreamʧ��
	SERVER_RET_FMS_ERR_END = SERVER_RET_FMS_ERR_BEGIN + 1000,							// FMS���ؽ���

	SERVER_RET_ANA_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_ANA_BASE,						// ANA���ؿ�ʼ
	SERVER_RET_ANA_ERR_CREATE,															// ���������������ANA_CreateStreamʧ��
	SERVER_RET_MP3_ENC_INIT_FAILED,                                                     // MP3������ʼ��ʧ��
	SERVER_RET_ANA_ERR_END = SERVER_RET_ANA_ERR_BEGIN + 1000,							// FMS���ؽ���

	DPSDK_CORE_ERROR_NO_RECORD_FILES,													// û��¼���ļ�
	DPSDK_CORE_ERROR_JSON_RETURN_FALSE,													// jsonЭ�鷵�ص�result:false
	DPSDK_CORE_ERROR_OSD_TO0_LONG,														// OSD�ַ���̫��

	SERVER_RET_JD_ERR_BEGIN = 1010000,													// ������Ȩ���ؿ�ʼ
	SERVER_RET_JD_ERR_END = 1011000,													// ������Ȩ���ؽ���
}dpsdk_retval_e;




#endif