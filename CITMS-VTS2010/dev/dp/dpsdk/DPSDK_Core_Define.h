#ifndef INCLUDED_DPSDK_CORE_DEFINE_H
#define INCLUDED_DPSDK_CORE_DEFINE_H

/***************************************************************************************
										�궨��
***************************************************************************************/

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef INOUT
#define INOUT
#endif

#ifndef NULL
#define NULL 0
#endif

#ifdef _WIN32
// ����class�ؼ��ֺ��棬�Լ��������߱��������ǰ��
#define DPSDK_DLL_DEPRECATED	__declspec(deprecated)
#else
#define DPSDK_DLL_DEPRECATED	__attribute__ ((deprecated))
#endif // #ifdef WIN32

#ifdef _WIN32

	#ifdef DPSDK_EXPORTS
		#define DPSDK_DLL_API extern "C" __declspec(dllexport)
	#else
		#define DPSDK_DLL_API extern "C" __declspec(dllimport)
	#endif

	#define DPSDK_CALLTYPE				__stdcall
	#define DPSDK_CALL_METHOD			__stdcall  //__cdecl

	#ifndef _WIN32_WINNT
		#define _WIN32_WINNT 0x0502
	#endif	

	#ifndef __int8_t_defined
		#define __int8_t_defined
		typedef signed char			int8_t;
		typedef unsigned char		uint8_t;
		typedef short int			int16_t;
		typedef unsigned short int	uint16_t;
		typedef int					int32_t;
		typedef unsigned int		uint32_t;
		typedef __int64				int64_t;
		typedef unsigned __int64	uint64_t;
	#endif
#else//fixme: delete these defs
	//	#include <stdio.h>
	#include <string.h> // memset(), linux platform need this
	#include <stddef.h> // NULL
	#include <stdint.h> // int8_t
	//	#include <errno.h>

	#define DPSDK_DLL_API extern "C"
	#define DPSDK_CALLTYPE
	#define DPSDK_CALL_METHOD

	#define WORD		unsigned short
	#define DWORD		unsigned int
	#define LONG		int
	#define LONGINT		long int
	#define DWORDINT	long int
	#define LPDWORD		DWORD*
	#define BOOL		int
	#define TRUE		1
	#define FALSE		0
	#define BYTE		unsigned char
	#define UINT		unsigned int
	#define HDC			void*
	#define HWND		void*
	#define LPVOID		void*
	//	#define NULL		0
	#define LLONG		long
	#define INT64		long long
	#define LDWORD		long 

	#ifndef MAX_PATH
	#define MAX_PATH	260
	#endif
#endif

#define DPSDK_CORE_LEN                          16
#define DPSDK_CORE_IP_LEN						48						// Զ��IP��ַ����
#define DPSDK_CORE_USER_NAME_LEN				64						// �豸��½�û�������
#define DPSDK_CORE_PASSWORD_LEN					64						// ���볤��
#define DPSDK_CORE_REC_FILENAME_LEN				64						// ¼���ļ�������
#define DPSDK_CORE_DEV_ID_LEN					64						// �豸ID����
#define	DPSDK_CORE_AREA_ID_LEN                  50                      // ���䳤��
#define DPSDK_CORE_AREA_NAME_LEN                256                     // �������Ƴ���
#define DPSDK_CORE_MSG_LEN				       (4*1024)				    // ��Ϣ�ϱ���Ϣ����
#define DPSDK_CORE_REC_DISKID_LEN				64						// ¼�����ID����
#define DPSDK_CORE_CHL_ID_LEN					64						// ͨ��ID����
#define DPSDK_CORE_TASK_LEN                     1024*1024               // ������Ϣ
#define DPSDK_TAG_URL_LEN						1024                    // Url�ĳ���
#define DPSDK_CORE_POINT_COUNT					300						// Ԥ�õ�����
#define DPSDK_CORE_POINT_NAME_LEN               32                      // Ԥ�õ����Ƴ���'
#define DPSDK_CORE_POINT_TIME_LEN               32                      // Ԥ�õ�ʱ�䳤��
#define DPSDK_CORE_ALARM_MSG_LEN				(4*1024)				// ������ѯ�����Ϣ����
#define DPSDK_CORE_ALARM_TITLE_LEN				256			      		// ������ѯ���title����
#define DPSDK_CORE_DEFAULT_TIMEOUT				10000                   // Ĭ�ϳ�ʱ ��λ����
#define DPSDK_CORE_DGROUP_DGPNAME_LEN			256						// ��֯���Ƴ���
#define DPSDK_CORE_DGROUP_DGPCODE_LEN			128						// ��֯Code����
#define DPSDK_CORE_28181_SN_LENGTH				64						// SN����
#define	MAX_CONFIG_NUM			                32			            // ÿ����̨�����������
#define MAX_TIME_SCHEDULE_NUM			        8			            // ʱ���Ԫ�ظ���
#define MAX_REC_TSECT			                6					    // ¼��ʱ��θ���
#define DPSDK_CORE_TIME_LENGTH					32					 	// ʱ�䴮����
#define DPSDK_CORE_DGROUP_DEVICENAME_LEN		256						// �豸���Ƴ���
#define DPSDK_CORE_FILEPATH_LEN					256						// �ļ�·������
#define DPSDK_CORE_IMG_PATH_LEN			    	256						// ͼƬ�ļ�·������
#define DPSDK_CORE_BAY_IMG_NUM					6						// ͼƬ��Ŀ
#define DPSDK_CORE_IMG_URL					    1024					// �ͻ���http�����URL �ĳ���
#define DPSDK_CORE_DGROUP_CHNNAME_LEN           256                     // �豸ͨ�����Ƴ���
#define DPSDK_CORE_POS_ID_LEN                   50                      // �ص�λ�����Ƴ���
#define DPSDK_CORE_POS_NAME_LEN                 256                     // �ص����Ƴ���
#define DPSDK_CORE_ORG_CODE_LEN				    128                     // ��֯�ڵ㳤��
#define DPSDK_CORE_ORG_NAME_LEN                 256                     // ��֯���Ƴ���
#define DPSDK_CORE_ORG_SN_LEN                   256                     // ��֯�ڵ�Ψһ��
#define DPSDK_CORE_ORG_TYPE_LEN                 16                      // ��֯�ڵ�����
#define DPSDK_CORE_ORG_GPS_LEN                  64                      // ��֯�ڵ㾭��
#define DPSDK_CORE_ORG_MEMO_LEN                 1024                    // ��֯�ڵ�����
#define DPSDK_CORE_DIRECT_LEN                   4                       // ������
#define DPSDK_CORE_CAR_RECORD_ID_LEN            128                     // ��¼ID
#define DPSDK_CORE_OPT_NOTE_LEN                 256                     // ��ע����
#define DPSDK_CORE_TIME_LEN                     128                     // ʱ�䣨����Ϊ��λ������
#define DPSDK_CORE_COORDINATE_LEN               4                       // �������곤��
#define DPSDK_CORE_PERSON_CODE_LEN              256                     // ���֤ID
#define DPSDK_CORE_PERSON_NAME_LEN              256                     // ��Ա���Ƴ���
#define DPSDK_CORE_PERSON_DEPTCODE_LEN          128                     // �������ų���
#define DPSDK_CORE_PERSON_SN_LEN                256                     // ��ԱΨһ��ų���
#define DPSDK_CORE_PERSON_TYPE_LEN              16                      // ��Ա���ͳ���
#define DPSDK_CORE_PERSON_OFFICE_LEN            256                     // ��Ա�칫�ص�  
#define DPSDK_CORE_PERSON_MOBILENUM_LEN         64                      // ��Ա�ƶ��绰
#define DPSDK_CORE_PERSON_VIRTUALNUM_LEN        64                      // ��Ա����̺�
#define DPSDK_CORE_PERSON_STATE_LEN             16                      // ��Ա״̬ 
#define DPSDK_CORE_CAR_CODE_LEN                 50                      // ����code
#define DPSDK_CORE_CAR_COLOR_LEN                16                      // ������ɫ10
#define DPSDK_CORE_CAR_TYPE_LEN                 16                      // ��������10
#define DPSDK_CORE_CAR_MODEL_LEN                256                     // ����Ʒ���ͺ�50
#define DPSDK_CORE_CAR_SIZE_LEN                 64                      // �����ߴ�50     
#define DPSDK_CORE_CAR_VIN_LEN                  64                      // ���ܺ�50
#define DPSDK_CORE_ENG_NO_LEN                   64                      // �����50
#define DPSDK_CORE_REGIST_LEN                   64                      // ����ע���50
#define DPSDK_CORE_REGIST_DATE_LEN              32                      // ע������20
#define DPSDK_CORE_CAR_PICPATH_LEN              256                     // ������Ƭ·��255
#define DPSDK_CORE_CAR_PLATENO_LEN              64                      // ���ƺ���50
#define DPSDK_CORE_CAR_PLATECOLOR_LEN           16                      // ������ɫ10
#define DPSDK_CORE_CAR_PLATETYPE_LEN            16                      // ��������10
#define DPSDK_CORE_CAR_OWNERNAME_LEN            256                     // ҵ������50                  
#define DPSDK_CORE_CAR_OWNERPHONE_LEN           64                      // ҵ���绰50                     
#define DPSDK_CORE_DEPTCODE_LEN                 128                     // ����code
#define DPSDK_CORE_DBID_LEN                     32                      // ���ݿ�������ID����
#define DH_MAX_CORE_LANE_NUM                    8                       // ��ͨ����״̬�����֧��8����
#define DPSDK_PIP_SCREEN_NUM					4						// ����������Ŀ ���л���������
#define DPSDK_PIP_SCREEN_PIXEL					8192					// ����������Ŀ NVD������ֵ
#define DPSDK_CORE_MEM_LEN						1024					// ��ע��Ϣ����
#define DPSDK_CORE_IVS_EVENT_NAME_LEN			32						// �����¼����Ƴ���
#define DPSDK_CORE_TVWALL_NAME_LEN				256                     // ����ǽ���Ƴ���

#define DPSDK_CORE_BAY_IP_LEN					64                      // IP����              
#define DPSDK_CORE_CAR_NUM_LENGTH				32
#define DPSDK_CORE_BAY_IMG_NUM					6
#define DPSDK_CORE_BAY_URL_LEN					1024

//���ض���������
#define DPSDK_CORE_KANGTEER_GROUP_DATA			1024
#define DPSDK_CORE_KANGTEER_DATA				256

//����������������
#define DPSDK_CORE_QUERY_PIC_MAXCOUT			256			//һ�β�ѯͼƬ��������
#define DPSDK_CORE_TIMESTR_LEN					64			//ʱ���ַ�������					


#define DPSDK_CORE_OSDTEMPLAT_CONTENT_LEN		256			//��Ϣģ�峤��
//���ڲ��ظ澯����
#define DPSDK_CORE_BAY_ORG_LEN                  256         //���ػ���
#define DPSDK_CORE_BAY_SURVERY_LEN              128         //������Ϣͨ�ó���
#define DPSDK_CORE_BAY_PHONE_LEN                32          //���ظ澯�绰ͨ�ó���
#define DPSDK_CORE_BAY_MAN_LEN                  16          //����

#define DPSDK_CORE_CASE_CODE_LEN				64			// �������
#define DPSDK_CORE_CASE_NAME_LEN				64			// ��������
#define DPSDK_CORE_CASE_ADDR_LEN				256			// ������ַ
#define DPSDK_CORE_CASE_MEMO_LEN				256			// ������ע
#define DPSDK_CORE_FILE_PATH_LEN				512			// �ļ�Ŀ¼
#define DPSDK_CORE_FILE_MEMO_LEN				512			// �ļ�����
#define DPSDK_CORE_GPS_LEN						50			// GPS��Ϣ
#define DPSDK_CORE_FILE_TYPE_LEN				32			// ������Ϣ

#define T_IYUV									3		    ///< ��Ƶ���ݣ�i420��ʽ������˳��"Y0-Y1-...","U0-U1-..","V0-V1-..."
#define T_YV12									4			///< ��Ƶ���ݣ�yv12��ʽ������˳��"Y0-Y1-..."."V0-V1-...","U0-U1-.."

#define DPSDK_CORE_AREA_ID_MAXLEN				32
#define DPSDK_CORE_AREA_ATTR_MAXLEN				32
#define DPSDK_CORE_AREA_NAME_MAXLEN				64
#define DPSDK_CORE_AREA_WEEK_DAYS				7
#define DPSDK_CORE_DRIVER_ID_LEN				64			// ���ر���˾��ID����
#define DPSDK_CORE_AREA_DB_LEN					32			// ���ر�����γ�ȳ���
#define DPSDK_CORE_AREA_CODE_LEN				64			// ���ر���˾��ID����
#define DPSDK_CORE_ALARMCODE_LEN				64			// ����code����

#define DPSDK_CORE_SCHEME_NAME_LEN				256			// Ԥ���ļ�������
#define DPSDK_CORE_SCHEME_DESC_LEN				512			// Ԥ����������

#define DPSDK_CORE_TEMPLATE_NAME_LEN			64			// ʱ��ģ�����Ƴ���
#define DPSDK_CORE_TEMPLATE_REMARK_LEN			256			// ʱ��ģ��˵������
#define DPSDK_CORE_TEMPLATE_FLAG_LEN			512			// ʱ��ģ����Ϣ����

#define DPSDK_CORE_RFID_LABEL					32			// RFID������̽���ǩ�ͳ��õ��ӱ�ǩ����
#define DPSDK_CORE_CHAR_LEN_32					32
#define DPSDK_CORE_CHAR_LEN_64					64
#define DPSDK_CORE_CHAR_LEN_256					256
#define DPSDK_CHAR_256							256

typedef struct S3GFlowInfo
{
	char szDevId[DPSDK_CORE_DEV_ID_LEN];					//�豸id
	uint32_t		nUsedFlow;								//��ʹ������
	uint32_t		nAllFlow;								//ȫ������
	S3GFlowInfo()
	{
		nUsedFlow = 0;
		nAllFlow = 0;
	}
}S3G_Flow_Info_t;

typedef enum
{
	CALL_TYPE_SINGLE_CALL,			// ����
	CALL_TYPE_GROUP_CALL,			// ���
	CALL_TYPE_VT_CALL,				// ���ӶԽ�
}dpsdk_call_type_e;


// ����ҵ��״̬
typedef enum
{
	CALL_STATUS_PREPARED,			//׼��
	CALL_STATUS_REQTOSCS,			//��SCS����
	CALL_STATUS_CALLING,			//������
	CALL_STATUS_RECVING,			//������
	CALL_STATUS_CEASED,				//�����ͷ�
}dpsdk_call_status_e;

typedef enum
{
	DPSDK_IPPROTO_UDP = 1,	    //UDP
	DPSDK_IPPROTO_TCP,			//TCP
}dpsdk_ipproto_type_e;
typedef struct tagDPSDK_CreateParam
{
	dpsdk_ipproto_type_e	eSipProto;		//�û�id��ʶ��
	char					szSCAgent[512];					// SCAgent���ã�Ĭ��ΪDSSCClient��������ΪAPPClient
}DPSDK_CreateParam_t;


/**�����豸������Ϣ�ص���������
@param IN                                    nPDLLHandle              SDK���
@param IN                                    pRetInfo						CMS���͵�3G������Ϣ
@param IN                                    pUserParam               �û�����
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDK3GFlowInfoCallback)( IN int32_t nPDLLHandle,
														   IN S3G_Flow_Info_t* p3GInfo, 
														   IN void* pUserParam );

/***************************************************************************************
 @ �궨�����
***************************************************************************************/


/***************************************************************************************
 @ ���Ͷ���
***************************************************************************************/

// SDK����
typedef enum
{
	DPSDK_CORE_SDK_SERVER						= 1,					 //����ģʽʹ��
}dpsdk_sdk_type_e;

// SDK״̬����
typedef enum
{
	DPSDK_CORE_STATUS_SERVER_ONLINE				= 1,					 //��������֪ͨ
	DPSDK_CORE_STATUS_SERVER_OFFLINE            = 2,					 //��������֪ͨ
}dpsdk_status_type_e;

// ��־�ȼ�
typedef enum
{
	DPSDK_LOG_LEVEL_DEBUG						= 2,					// ����
	DPSDK_LOG_LEVEL_INFO						= 4,					// ��Ϣ
	DPSDK_LOG_LEVEL_ERROR						= 6,					// ����
}dpsdk_log_level_e;

// Э��汾
typedef enum
{
	DPSDK_PROTOCOL_VERSION_I					= 1,					// һ��Э��
	DPSDK_PROTOCOL_VERSION_II					= 2,					// ����Э��
}dpsdk_protocol_version_e;

// �豸״̬
typedef enum
{
	DPSDK_DEV_STATUS_UNKNOW						= 0,                         // δ֪״̬
	DPSDK_DEV_STATUS_ONLINE						= 1,					     // ����
	DPSDK_DEV_STATUS_OFFLINE					= 2,					     // ����

	// ����
	DPSDK_CORE_DEVICE_STATUS_ONLINE				= DPSDK_DEV_STATUS_ONLINE,
	DPSDK_CORE_DEVICE_STATUS_OFFLINE            = DPSDK_DEV_STATUS_OFFLINE,
}dpsdk_dev_status_e, dpsdk_device_status_type_e;

// ��Ԫ����
typedef enum
{
	DPSDK_DEV_UNIT_UNKOWN,		                                        // δ֪
	DPSDK_DEV_UNIT_ENC,			                                        // ����
	DPSDK_DEV_UNIT_DEC,			                                        // ����
	DPSDK_DEV_UNIT_ALARMIN,		                                        // ��������
	DPSDK_DEV_UNIT_ALARMOUT,	                                        // �������
	DPSDK_DEV_UNIT_TVWALLIN,	                                        // TvWall����
	DPSDK_DEV_UNIT_TVWALLOUT,	                                        // TvWall���
	DPSDK_DEV_UNIT_DOORCTRL,	                                        // �Ž�
	DPSDK_DEV_UNIT_VOICE,	                                          	// �Խ�
}dpsdk_dev_unit_type_e;

// �ڵ�����
typedef enum
{
	DPSDK_CORE_NODE_DEP,												// ��֯
	DPSDK_CORE_NODE_DEV,												// �豸
	DPSDK_CORE_NODE_CHANNEL,											// ͨ��
}dpsdk_node_type_e;

typedef enum
{
	OPTTYPE_UNKOWN				             	= 0,					// 
	OPTTYPE_LOGIN,										             	// ��¼ 
	OPTTYPE_LOGOUT,										            	// �ǳ�
	OPTTYPE_REAL,									            		// ʵʱ��Ƶ
	OPTTYPE_PTZ,										            	// ��̨
	OPTTYPE_PLAYBACK,													// �ط�
	OPTTYPE_DOWNLOAD,													// ����
	OPTTYPE_LOCALRECORD,												// ����¼��
	OPTTYPE_QUERYRECORD,												// ��ѯ¼��
	OPTTYPE_ARM,														// ������������
	OPTTYPE_DISARM,														// ������������
}dpsdk_log_optType_e;
// ��ȡ�ڵ�����
typedef enum
{
	DPSDK_CORE_GEN_GETGROUP_OPERATION_ALL		= -1,					 // ��ȡ����
	DPSDK_CORE_GEN_GETGROUP_OPERATION_SELF		= 0,					 // ��ȡ����
	DPSDK_CORE_GEN_GETGROUP_OPERATION_CHILD		= 1,					 // ��ȡ�ӽڵ�
}dpsdk_getgroup_operation_e;

// �ڵ�ı�֪ͨ����
typedef enum
{
	DPSDK_CORE_CHANGE_UNDEFINE					= 0,					 // δ����
	DPSDK_CORE_CHANGE_ADD_DEV					= 1,					 // �����豸			
	DPSDK_CORE_CHANGE_MODIFY_DEV				= 2,					 // �޸��豸
	DPSDK_CORE_CHANGE_DEL_DEV					= 3,					 // ɾ���豸
	DPSDK_CORE_CHANGE_ADD_ORG					= 4,					 // ������֯
	DPSDK_CORE_CHANGE_MODIFY_ORG				= 5,					 // �޸���֯ 
	DPSDK_CORE_CHANGE_DELETE_ORG				= 6,					 // ɾ����֯ 
}dpsdk_change_type_e;

// �ڵ�ı�֪ͨ����
typedef enum
{
	DPSDK_CORE_ORG_CHANGE_UNDEFINE					= 0,					 // δ����
	DPSDK_CORE_ORG_CHANGE_ADD_DEV					= 1,					 // �����豸
	DPSDK_CORE_ORG_CHANGE_MODIFY_DEV				= 2,					 // �޸��豸
	DPSDK_CORE_ORG_CHANGE_DEL_DEV					= 3,					 // ɾ���豸
	DPSDK_CORE_ORG_CHANGE_ADD_ORG					= 4,					 // ������֯
	DPSDK_CORE_ORG_CHANGE_MODIFY_ORG				= 5,					 // �޸���֯ 
	DPSDK_CORE_ORG_CHANGE_DELETE_ORG				= 6,					 // ɾ����֯ 

	DPSDK_CORE_ORG_CHANGE_USER_ROLE                 =7,                      //�û���ɫ���
	DPSDK_CORE_ORG_CHANGE_ROLE_ORG                  =8,                      // ��ɫ��֯���
	DPSDK_CORE_ORG_CHANGE_LOGIC_ORG                 =9,                      // �߼���֯���
	DPSDK_CORE_ORG_CHANGE_CHANNEL_RIGHT             =10,                     // ͨ��Ȩ�ޱ��
	DPSDK_CORE_ORG_CHANGE_CODEINFO                  =11,                     // �ڵ�<ͨ�����豸>������֯��������
}dpsdk_org_change_type_e;



// ����ͷ����
typedef enum
{
	CAMERA_TYPE_NORMAL                          = 1,		             // ǹ��
	CAMERA_TYPE_SD                              = 2,           			 // ���
	CAMERA_TYPE_HALFSD                          = 3,                 	 // ����
}dpsdk_camera_type_e;

// �豸��������
typedef enum
{
	DPSDK_CORE_DEVICE_FACTORY_UNDEFINE			= 0,					 // δ����
	DPSDK_CORE_DEVICE_FACTORY_DAHUA				= 1,					 // ��			
	DPSDK_CORE_DEVICE_FACTORY_HIK				= 2,					 // ����
	DPSDK_CORE_DEVICE_FACTORY_H264				= 16,					 // ����
	DPSDK_CORE_DEVICE_FACTORY_H3C				= 17,					 // ����
	DPSDK_CORE_DEVICE_FACTORY_XC				= 18,					 // �Ų�
	DPSDK_CORE_DEVICE_FACTORY_LIYUAN			= 19,					 // ��Ԫ
	DPSDK_CORE_DEVICE_FACTORY_BIT				= 20,					 // ����
	DPSDK_CORE_DEVICE_FACTORY_H3TS				= 21,					 // ����ts��
	DPSDK_CORE_DEVICE_FACTORY_TIANSHI			= 36,					 // �����ϴ��ĺ�����
}dpsdk_device_factory_type_e;

//�Ƿ���Ȩ��
typedef enum
{
	DPSDK_CORE_CHECK_RIGHT						= 0,					// ���
	DPSDK_CORE_NOT_CHECK_RIGHT					= 1,					// �����
}dpsdk_check_right_e;

// ��������
typedef enum
{
	DPSDK_CORE_STREAMTYPE_MAIN					= 1,					// ������
	DPSDK_CORE_STREAMTYPE_SUB					= 2,					// ������
}dpsdk_stream_type_e;

// ý������
typedef enum
{
	DPSDK_CORE_MEDIATYPE_VIDEO					= 1,					 // ��Ƶ
	DPSDK_CORE_MEDIATYPE_AUDIO					= 2,					 // ��Ƶ
	DPSDK_CORE_MEDIATYPE_ALL					= 3,					 // ��Ƶ + ��Ƶ
}dpsdk_media_type_e;

// ��������
typedef enum
{
	DPSDK_CORE_TRANSTYPE_UDP					= 0,					 // UDP
	DPSDK_CORE_TRANSTYPE_TCP					= 1,					 // TCP
}dpsdk_trans_type_e;

//�������������
typedef enum
{
	DPSDK_CORE_TRACKIDTYPE_PS			= 501,							// PS��
	DPSDK_CORE_TRACKIDTYPE_ORIG	        = 601,							// ������ԭʼ֡
	DPSDK_CORE_TRACKIDTYPE_DH			= 701,							// ��֡
	DPSDK_CORE_TRACKIDTYPE_DHSTD		= 801,							// �󻪱�׼֡
	DPSDK_CORE_TRACKIDTYPE_TS			= 901,							// TS��
	DPSDK_CORE_TRACKIDTYPE_RTP			= 101,							// RTP��׼��
}dpsdk_trackid_type_e;

//��������Ƶ�ֱ�������
typedef enum
{
	DPSDK_CORE_RESOLUTION_1080P			= 1,							// 1080P
	DPSDK_CORE_RESOLUTION_130M	        = 2,							// 130M
	DPSDK_CORE_RESOLUTION_720P			= 3,							// 720P
	DPSDK_CORE_RESOLUTION_D1		    = 4,							// D1
	DPSDK_CORE_RESOLUTION_CIF			= 5,							// CIF
	DPSDK_CORE_RESOLUTION_QCIF			= 6,							// QCIF
	DPSDK_CORE_RESOLUTION_VGA			= 7,							// VGA
	DPSDK_CORE_RESOLUTION_QVGA			= 8,							// QVGA
}dpsdk_resolution_type_e;

//��Ƶ�����ʽ
typedef enum
{
	DPSDK_CORE_VIDEOCODEC_H264			= 1,							// h264
	DPSDK_CORE_VIDEOCODEC_MPEG4	        = 2,							// mpeg4
	DPSDK_CORE_VIDEOCODEC_JPEG			= 3,							// jpeg
}dpsdk_videocodec_type_e;

//����ת������
typedef enum
{
	DPSDK_CORE_SC_NONE = -1,
	DPSDK_CORE_SC_TS,      
	DPSDK_CORE_SC_PS,		
	DPSDK_CORE_SC_RTP,     
	DPSDK_CORE_SC_MP4_FILE,		
	DPSDK_CORE_SC_GDPS,    
	DPSDK_CORE_SC_GAYSPS,  
	DPSDK_CORE_SC_FLV_FILE,
	DPSDK_CORE_SC_ASF_FILE,
	DPSDK_CORE_SC_ASF_STREAM,
	DPSDK_CORE_SC_FLV_STREAM
}dpsdk_stream_convertor_type_e;

// ��Ƶ����
typedef enum{
	Talk_Coding_Default                         = 0,		             //default
	Talk_Coding_PCM                             = 1,		             //PCM
	Talk_Coding_G711a,			                                         //G711a
	Talk_Coding_AMR,			                                         //AMR
	Talk_Coding_G711u,			                                         //G711u
	Talk_Coding_G726,			                                         //G726
	Talk_Coding_AAC                             = 8,                     //add by fengjian 2012.8.8
	Talk_Coding_G722                            = 101,		             //G722 �����豸ʹ��
	Talk_Coding_G711_MU,		                                         //G711 ����ʹ��
}dpsdk_audio_type_e;

//λ��
typedef enum
{
	Talk_Audio_Bits_8                           = 8,
	Talk_Audio_Bits_16                          = 16,
}dpsdk_talk_bits_e;					

//������
typedef enum
{
	Talk_Audio_Sam_8K                           = 8000,
	Talk_Audio_Sam_16K                          = 16000,
	Talk_Audio_Sam_8192                         = 8192,
	Talk_Audio_Sam_48k							= 48000,
}Talk_Sample_Rate_e;			


///
typedef enum{
	Talk_Type_Device                            = 1,	                 //�豸
	Talk_Type_Channel		                                             //ͨ��
}dpsdk_talk_type_e;

// ͼƬ����
typedef enum
{
	DPSDK_CORE_PIC_FORMAT_BMP					= 0,					 // BMP
	DPSDK_CORE_PIC_FORMAT_JPEG					= 1,					 // JPEG
}dpsdk_pic_type_e;

// ¼��Դ����
typedef enum
{
	DPSDK_CORE_PB_RECSOURCE_ALL					= 1,					 // ����
	DPSDK_CORE_PB_RECSOURCE_DEVICE				= 2,	    			 // �豸¼��
	DPSDK_CORE_PB_RECSOURCE_PLATFORM			= 3,					 // ƽ̨¼��
}dpsdk_recsource_type_e;

// ¼������
typedef enum
{
	DPSDK_CORE_PB_RECORD_UNKONWN				= 0,					 // ȫ��¼��
	DPSDK_CORE_PB_RECORD_MANUAL					= 1,					 // �ֶ�¼��
	DPSDK_CORE_PB_RECORD_ALARM					= 2,					 // ����¼��
	DPSDK_CORE_PB_RECORD_MOTION_DETECT			= 3,					 // �ƶ����
	DPSDK_CORE_PB_RECORD_VIDEO_LOST				= 4,					 // ��Ƶ��ʧ
	DPSDK_CORE_PB_RECORD_VIDEO_SHELTER			= 5,					 // ��Ƶ�ڵ�
	DPSDK_CORE_PB_RECORD_TIMER					= 6,					 // ��ʱ¼��
	DPSDK_CORE_PB_RECORD_ALL_DAY				= 7,					 // ȫ��¼��
	CENTER_DISK_FULL							= 36,				     // Ӳ����
	CENTER_DISK_FAULT							= 37,				 	 // Ӳ�̹���
}dpsdk_record_type_e;

// ¼������������
typedef enum
{
	DPSDK_CORE_PB_MODE_NORMAL					= 1,					 // �ط�
	DPSDK_CORE_PB_MODE_DOWNLOAD 				= 2,					 // ����
}dpsdk_pb_mode_e;

// ¼�����ط��ٶ�
typedef enum
{
	DPSDK_CORE_PB_NORMAL						= 8,						  // 1����
	DPSDK_CORE_PB_FAST2							= DPSDK_CORE_PB_NORMAL * 2,   // 2����
	DPSDK_CORE_PB_FAST4							= DPSDK_CORE_PB_NORMAL * 4,   // 4����
	DPSDK_CORE_PB_FAST8							= DPSDK_CORE_PB_NORMAL * 8,   // 8����
	DPSDK_CORE_PB_FAST16						= DPSDK_CORE_PB_NORMAL * 16,  // 16����
	DPSDK_CORE_PB_SLOW2							= DPSDK_CORE_PB_NORMAL / 2,   // 1/2����
	DPSDK_CORE_PB_SLOW4							= DPSDK_CORE_PB_NORMAL / 4,   // 1/4����
	DPSDK_CORE_PB_SLOW8							= DPSDK_CORE_PB_NORMAL / 8,   // 1/8����
}dpsdk_playback_speed_e;

// ��̨�����������			
typedef enum
{
	DPSDK_CORE_PTZ_GO_UP						= 1,					 // ��
	DPSDK_CORE_PTZ_GO_DOWN                      = 2,					 // ��
	DPSDK_CORE_PTZ_GO_LEFT 						= 3,					 // ��
	DPSDK_CORE_PTZ_GO_RIGHT 					= 4,					 // ��
	DPSDK_CORE_PTZ_GO_LEFTUP 					= 5,					 // ����
	DPSDK_CORE_PTZ_GO_LEFTDOWN 					= 6,					 // ����
	DPSDK_CORE_PTZ_GO_RIGHTUP 					= 7,					 // ����
	DPSDK_CORE_PTZ_GO_RIGHTDOWN 				= 8,					 // ����
}dpsdk_ptz_direct_e;

// ��̨ͼ���������
typedef enum
{	
	DPSDK_CORE_PTZ_ADD_ZOOM                      = 0,					 // �䱶+ 
	DPSDK_CORE_PTZ_ADD_FOCUS                     = 1,					 // �佹+
	DPSDK_CORE_PTZ_ADD_APERTURE                  = 2,					 // ��Ȧ+
	DPSDK_CORE_PTZ_REDUCE_ZOOM 					 = 3,					 // �䱶-
	DPSDK_CORE_PTZ_REDUCE_FOCUS 				 = 4,					 // �佹-
	DPSDK_CORE_PTZ_REDUCE_APERTURE 				 = 5,					 // ��Ȧ-
}dpsdk_camera_operation_e;

// ��̨������
typedef enum
{
	DPSDK_CORE_PTZ_CMD_LOCK						= 1,					 // ������ǰ����ͷ
	DPSDK_CORE_PTZ_CMD_UNLOCK_ONE 				= 2,					 // ������ǰ����ͷ
	DPSDK_CORE_PTZ_CMD_UNLOCK_ALL 				= 3,					 // ���������û���������������ͷ
}dpsdk_ptz_locktype_e;

// ��̨Ԥ�õ��������
typedef enum
{
	DPSDK_CORE_PTZ_PRESET_LOCATION				= 1,					 // Ԥ�õ㶨λ
	DPSDK_CORE_PTZ_PRESET_ADD					= 2,					 // Ԥ�õ�����
	DPSDK_CORE_PTZ_PRESET_DEL					= 3,					 // Ԥ�õ�ɾ��
}dpsdk_ptz_prepoint_cmd_e;

// ��̨��չ��������
typedef enum 
{
	DPSDK_CORE_PTZ_START_AUTO_ROUND				= 39,					// ��ʼˮƽ��ת
	DPSDK_CORE_PTZ_STOP_AUTO_ROUND				= 40,					// ֹͣˮƽ��ת

	DPSDK_CORE_PTZ_SET_LEFT_SCAN_RANGE			= 41,					// ������߽�
	DPSDK_CORE_PTZ_SET_RIGHT_SCAN_RANGE			= 42,					// �����ұ߽�
	DPSDK_CORE_PTZ_START_SCAN					= 43,					// ��ʼ��ɨ
	DPSDK_CORE_PTZ_STOP_SCAN					= 44,					// ֹͣ��ɨ

	DPSDK_CORE_PTZ_SET_MODLE_START				= 45,					// ����Ѳ����ʼ
	DPSDK_CORE_PTZ_SET_MODLE_CANCEL				= 46,					// ����Ѳ������
	DPSDK_CORE_PTZ_RUN_MODLE					= 47,					// ����Ѳ��
	DPSDK_CORE_PTZ_STOP_MODLE					= 48,					// ֹͣѲ��
	DPSDK_CORE_PTZ_CLEAR_MODLE					= 49,					// ���Ѳ��

	DPSDK_CORE_PTZ_UPDOWN						= 50,					// ��ת����

	DPSDK_CORE_PTZ_OPEN_ASSISTANT_POINT			= 52,					// �������ؿ�
	DPSDK_CORE_PTZ_CLOSE_ASSISTANT_POINT		= 53,					// �������ع�

	DPSDK_CORE_PTZ_OPEN_IPC_MENU				= 54,					// �򿪲˵�
	DPSDK_CORE_PTZ_CLOSE_IPC_MENU				= 55,					// �رղ˵�
	DPSDK_CORE_PTZ_MENU_ASSURE					= 56,					// �˵�ȷ��
	DPSDK_CORE_PTZ_MENU_CALCEL					= 57,					// �˵�ȡ��
	DPSDK_CORE_PTZ_MENU_UP						= 58,					// �˵���
	DPSDK_CORE_PTZ_MENU_DOWN					= 59,					// �˵���
	DPSDK_CORE_PTZ_MENU_LEFT					= 60,					// �˵���
	DPSDK_CORE_PTZ_MENU_RIGHT					= 61,					// �˵���
}dpsdk_ptz_extend_cmd_e;

typedef enum{
	Talk_Protocol_Auto=0,
	Talk_Protocol_TCP,
	Talk_Protocol_UDP,
	Talk_Protocol_END,
}Talk_Protocol_Type_e;				//��Ƶ������Э��

// ��������
typedef enum
{
	DPSDK_CORE_ALARM_TYPE_Unknown				= 0,				     // δ֪
	DPSDK_CORE_ALARM_TYPE_VIDEO_LOST,									 // ��Ƶ��ʧ
	DPSDK_CORE_ALARM_TYPE_EXTERNAL_ALARM,								 // �ⲿ����
	DPSDK_CORE_ALARM_TYPE_MOTION_DETECT,								 // �ƶ����
	DPSDK_CORE_ALARM_TYPE_VIDEO_SHELTER,								 // ��Ƶ�ڵ�
	DPSDK_CORE_ALARM_TYPE_DISK_FULL,									 // Ӳ����
	DPSDK_CORE_ALARM_TYPE_DISK_FAULT,									 // Ӳ�̹���
	DPSDK_CORE_ALARM_TYPE_FIBER,										 // ���˱���
	DPSDK_CORE_ALARM_TYPE_GPS,											 // GPS��Ϣ
	DPSDK_CORE_ALARM_TYPE_3G,											 // 3G
	DPSDK_CORE_ALARM_TYPE_STATUS_RECORD,								 // �豸¼��״̬
	DPSDK_CORE_ALARM_TYPE_STATUS_DEVNAME,								 // �豸��
	DPSDK_CORE_ALARM_TYPE_STATUS_DISKINFO,								 // Ӳ����Ϣ
	DPSDK_CORE_ALARM_TYPE_IPC_OFF,										 // ǰ��IPC����
	DPSDK_CORE_ALARM_TYPE_DEV_DISCONNECT			= 16,					//�豸���߱���

	//��������ȼ����Ŀ 
	DPSDK_CORE_ALARM_POWER_INTERRUPT				= 17,					// �е��жϱ��� 
	DPSDK_CORE_ALARM_POWER_ENABLED					= 18,					// �е����ñ��� 
	DPSDK_CORE_ALARM_INFRARED_DETECT				= 19,					// ����̽�ⱨ�� 
	DPSDK_CORE_ALARM_GAS_OVER_SECTION				= 20,					// ȼ��Ũ�ȳ������� 
	DPSDK_CORE_ALARM_FLOW_OVER_SECTION				= 21,					// ˲ʱ������������ 
	DPSDK_CORE_ALARM_TEMPERATURE_OVER_SECTION		= 22,					// �¶ȳ������� 
	DPSDK_CORE_ALARM_TEMPERATURE_UNDER_SECTION		= 23,					// �¶ȵ������� 
	DPSDK_CORE_ALARM_PRESSURE_OVER_SECTION			= 24,					// ѹ���������� 
	DPSDK_CORE_ALARM_PRESSURE_UNDER_SECTION			= 25,					// ѹ����������

	DPSDK_CORE_ALARM_STATIC_DETECTION				= 26,					// ��̬��� 
	DPSDK_CORE_ALARM_REMOTE_EXTERNAL_ALARM			= 28,					// Զ���ⲿ����

	//�Ž�
	DPSDK_CORE_ALARM_DOOR_BEGIN				     = 40,		    	     // �Ž��豸������ʼ
	DPSDK_CORE_ALARM_FORCE_CARD_OPENDOOR		 = 41,				     // в��ˢ������
	DPSDK_CORE_ALARM_VALID_PASSWORD_OPENDOOR	 = 42,				     // �Ϸ����뿪��
	DPSDK_CORE_ALARM_INVALID_PASSWORD_OPENDOOR	 = 43,				     // �Ƿ����뿪��
	DPSDK_CORE_ALARM_FORCE_PASSWORD_OPENDOOR	 = 44,				     // в�����뿪��
	DPSDK_CORE_ALARM_VALID_FINGERPRINT_OPENDOOR	 = 45,			         // �Ϸ�ָ�ƿ���
	DPSDK_CORE_ALARM_INVALID_FINGERPRINT_OPENDOOR	= 46,				 // �Ƿ�ָ�ƿ���
	DPSDK_CORE_ALARM_FORCE_FINGERPRINT_OPENDOOR	 = 47,				     // в��ָ�ƿ���

	DPSDK_CORE_ALARM_TYPE_VALID_CARD_READ		 = 51,				     // �Ϸ�ˢ��/����
	DPSDK_CORE_ALARM_TYPE_INVALID_CARD_READ,							 // �Ƿ�ˢ��/����
	DPSDK_CORE_ALARM_TYPE_DOOR_MAGNETIC_ERROR,							 // �Ŵű���
	DPSDK_CORE_ALARM_TYPE_DOOR_BREAK,									 // ���ű����Ϳ��ų�ʱ����
	DPSDK_CORE_ALARM_TYPE_DOOR_ABNORMAL_CLOSED,							 // �ŷ������ر�
	DPSDK_CORE_ALARM_TYPE_DOOR_NORMAL_CLOSED,							 // �������ر�
	DPSDK_CORE_ALARM_TYPE_DOOR_OPEN,									 // �Ŵ�

	DPSDK_CORE_ALARM_DOOR_OPEN_TIME_OUT_BEG		= 60,
	DPSDK_CORE_ALARM_DOOR_OPEN_TIME_OUT_END		= 70,

	//��������
	ALARM_TYPE_ALARMHOST_BEGIN			= 80,
	DPSDK_CORE_ALARM_TYPE_ALARM_CONTROL_ALERT	= 81,				     // ������������
	DPSDK_CORE_ALARM_TYPE_FIRE_ALARM,									 // ��
	DPSDK_CORE_ALARM_TYPE_ZONE_DISABLED,								 // ����ʧЧ
	DPSDK_CORE_ALARM_TYPE_BATTERY_EMPTY,								 // ���û��
	ALARM_TYPE_AC_OFF					= 85,					// �е�Ͽ�-�豸����
	ALARM_TYPE_ALARMHOST_END			= 90,	

	DPSDK_CORE_ALARM_FILESYSTEM				    = 100,					 // �ļ�ϵͳ
	DPSDK_CORE_ALARM_RAID_FAULT,										 // raid����
	DPSDK_CORE_ALARM_RECORDCHANNELFUNCTION_ABNORMAL,					 // ¼��ͨ�������쳣
	DPSDK_CORE_SVR_HARDDISK_STATUS,										 // Ӳ��״̬
	DPSDK_CORE_ALARM_RECORD_REPAIR,										 // ¼��ȫ -P3.0

	//begin������������
	ELECTRIC_WIRE_SHOCK					= 109,					// ��������
	ELECTRIC_WIRE_INTERRUPT				= 110,					// �����ϵ�
	ELECTRIC_WIRE_SHORT_CIRCUIT			= 111,					// ������·
	ELECTRIC_WIRE_BREAKDOWN				= 112,					// ��������
	ELECTRIC_WIRE_VOLTAGE_LOW			= 113,					// ������ѹ��
	//end
	ALARM_TYPE_RECORD_WRITE_FAIL		= 114,					// ¼��д��ʧ��

	//����������������begin add by hu_wenjuan
	ELECTRIC_ALARM_BEGIN_EX                         = 115, 
	ELECTRIC_BREAK_CIRCUIT                          = 115,                                  // ������· 
	ELECTRIC_SENSE_ALARM                            = 116,                                  // �������б��� 
	ELECTRIC_ALARM_END_EX                           = 150,                                  
	//����������������end 

	ALARM_VTT_URGENCY                   = 160,                  // VTT�豸������ť����

	//-M����ر������������
	DPSDK_CORE_ALARM_MOTOR_BEGIN					= 200,
	DPSDK_CORE_ALARM_OVERSPEED_OCCURE				= 201, 			     // ���ٱ�������
	DPSDK_CORE_ALARM_OVERSPEED_DISAPPEAR,  								 // ���ٱ�����ʧ
	DPSDK_CORE_ALARM_DRIVEROUT_DRIVERALLOW,								 // ʻ������
	DPSDK_CORE_ALARM_DRIVERIN_DRIVERALLOW,								 // ʻ������
	DPSDK_CORE_ALARM_DRIVEROUT_FORBIDDRIVE,								 // ʻ��������
	DPSDK_CORE_ALARM_DRIVERIN_FORBIDDRIVE,								 // ʻ�������
	DPSDK_CORE_ALARM_DRIVEROUT_LOADGOODS,								 // ʻ��װ����
	DPSDK_CORE_ALARM_DRIVERIN_LOADGOODS,								 // ʻ��װ����
	DPSDK_CORE_ALARM_DRIVEROUT_UNLOADGOODS,								 // ʻ��ж����
	DPSDK_CORE_ALARM_DRIVERIN_UNLOADGOODS,								 // ʻ��ж����
	DPSDK_CORE_ALARM_CAR_OVER_LOAD,										 // ����
	DPSDK_CORE_ALARM_SPEED_SOON_ZERO,									 // ��ɲ��
	DPSDK_CORE_ALARM_3GFLOW,											 // 3G����
	DPSDK_CORE_ALARM_AAC_POWEROFF,										 // ACC�ϵ籨��
	DPSDK_CORE_ALARM_SPEEDLIMIT_LOWERSPEED,								 // ���ٱ��� LowerSpeed
	DPSDK_CORE_ALARM_SPEEDLIMIT_UPPERSPEED,								 // ���ٱ��� UpperSpeed 
	DPSDK_CORE_ALARM_VEHICLEINFOUPLOAD_CHECKIN,							 // �����Զ�����Ϣ�ϴ� CheckIn
	DPSDK_CORE_ALARM_VEHICLEINFOUPLOAD_CHECKOUT,						 // �����Զ�����Ϣ�ϴ� CheckOut
	ALARM_CAR_OPEN_DOOR 				= 219,                			 // ���ű���
	ALARM_URGENCY						= 220,							 // ��������
	ALARM_DEV_VOICE_EX     				= 229,    				// �豸�������󱨾�
	DPSDK_CORE_ALARM_GAS_LOWLEVEL					= 236,				 // �ͺı���
	DPSDK_CORE_ALARM_MOTOR_END						= 300,

	//���ܱ���
	DPSDK_CORE_ALARM_IVS_ALARM_BEGIN				= 300,				 // �����豸����������dhnetsdk.h������+300��DMS��������ӣ�
	DPSDK_CORE_ALARM_IVS_ALARM,											 // �����豸����
	DPSDK_CORE_ALARM_CROSSLINEDETECTION,								 // �������¼�
	DPSDK_CORE_ALARM_CROSSREGIONDETECTION ,								 // �������¼�
	DPSDK_CORE_ALARM_PASTEDETECTION,									 // �����¼�
	DPSDK_CORE_ALARM_LEFTDETECTION,										 // ��Ʒ�����¼�
	DPSDK_CORE_ALARM_STAYDETECTION,										 // ͣ���¼�
	DPSDK_CORE_ALARM_WANDERDETECTION,									 // �ǻ��¼�
	DPSDK_CORE_ALARM_PRESERVATION,										 // ��Ʒ��ȫ�¼�
	DPSDK_CORE_ALARM_MOVEDETECTION,										 // �ƶ��¼�
	DPSDK_CORE_ALARM_TAILDETECTION,										 // β���¼�
	DPSDK_CORE_ALARM_RIOTERDETECTION,									 // �����¼�
	DPSDK_CORE_ALARM_FIREDETECTION,										 // ���¼�
	DPSDK_CORE_ALARM_SMOKEDETECTION,									 // �������¼�
	DPSDK_CORE_ALARM_FIGHTDETECTION,									 // ��Ź�¼�
	DPSDK_CORE_ALARM_FLOWSTAT,											 // ����ͳ���¼�
	DPSDK_CORE_ALARM_NUMBERSTAT,										 // ����ͳ���¼�
	DPSDK_CORE_ALARM_CAMERACOVERDDETECTION,								 // ����ͷ�����¼�
	DPSDK_CORE_ALARM_CAMERAMOVEDDETECTION,								 // ����ͷ�ƶ��¼�
	DPSDK_CORE_ALARM_VIDEOABNORMALDETECTION,							 // ��Ƶ�쳣�¼�
	DPSDK_CORE_ALARM_VIDEOBADDETECTION,									 // ��Ƶ���¼�
	DPSDK_CORE_ALARM_TRAFFICCONTROL,									 // ��ͨ�����¼�
	DPSDK_CORE_ALARM_TRAFFICACCIDENT,									 // ��ͨ�¹��¼�
	DPSDK_CORE_ALARM_TRAFFICJUNCTION,									 // ��ͨ·���¼�
	DPSDK_CORE_ALARM_TRAFFICGATE,										 // ��ͨ�����¼�
	DPSDK_CORE_ALARM_TRAFFICSNAPSHOT,									 // ��ͨץ���¼�
	DPSDK_CORE_ALARM_FACEDETECT,										 // ��������¼� 
	DPSDK_CORE_ALARM_TRAFFICJAM,										 // ��ͨӵ���¼�

	DPSDK_CORE_ALARM_TRAFFIC_RUNREDLIGHT			= 0x00000100 + 300,	 // ��ͨΥ��-������¼�
	DPSDK_CORE_ALARM_TRAFFIC_OVERLINE				= 0x00000101 + 300,	 // ��ͨΥ��-ѹ�������¼�
	DPSDK_CORE_ALARM_TRAFFIC_RETROGRADE				= 0x00000102 + 300,	 // ��ͨΥ��-�����¼�
	DPSDK_CORE_ALARM_TRAFFIC_TURNLEFT				= 0x00000103 + 300,	 // ��ͨΥ��-Υ����ת
	DPSDK_CORE_ALARM_TRAFFIC_TURNRIGHT			    = 0x00000104 + 300,	 // ��ͨΥ��-Υ����ת
	DPSDK_CORE_ALARM_TRAFFIC_UTURN					= 0x00000105 + 300,	 // ��ͨΥ��-Υ�µ�ͷ
	DPSDK_CORE_ALARM_TRAFFIC_OVERSPEED				= 0x00000106 + 300,	 // ��ͨΥ��-����
	DPSDK_CORE_ALARM_TRAFFIC_UNDERSPEED				= 0x00000107 + 300,	 // ��ͨΥ��-����
	DPSDK_CORE_ALARM_TRAFFIC_PARKING				= 0x00000108 + 300,	 // ��ͨΥ��-Υ��ͣ��
	DPSDK_CORE_ALARM_TRAFFIC_WRONGROUTE				= 0x00000109 + 300,	 // ��ͨΥ��-����������ʻ
	DPSDK_CORE_ALARM_TRAFFIC_CROSSLANE				= 0x0000010A + 300,	 // ��ͨΥ��-Υ�±��
	DPSDK_CORE_ALARM_TRAFFIC_OVERYELLOWLINE			= 0x0000010B + 300,	 // ��ͨΥ��-ѹ����
	DPSDK_CORE_ALARM_TRAFFIC_DRIVINGONSHOULDER		= 0x0000010C + 300,	 // ��ͨΥ��-·����ʻ�¼�  
	DPSDK_CORE_ALARM_TRAFFIC_YELLOWPLATEINLANE		= 0x0000010E + 300,	 // ��ͨΥ��-���Ƴ�ռ���¼�
	DPSDK_CORE_ALARM_CROSSFENCEDETECTION			= 0x0000011F + 300,	 // ��ԽΧ���¼�
	DPSDK_CORE_ALARM_ELECTROSPARKDETECTION			= 0X00000110 + 300,	 // ����¼�
	DPSDK_CORE_ALARM_TRAFFIC_NOPASSING				= 0x00000111 + 300,	 // ��ͨΥ��-��ֹͨ���¼�
	DPSDK_CORE_ALARM_ABNORMALRUNDETECTION			= 0x00000112 + 300,	 // �쳣�����¼�
	DPSDK_CORE_ALARM_RETROGRADEDETECTION			= 0x00000113 + 300,	 // ��Ա�����¼�
	DPSDK_CORE_ALARM_INREGIONDETECTION				= 0x00000114 + 300,	 // �����ڼ���¼�
	DPSDK_CORE_ALARM_TAKENAWAYDETECTION				= 0x00000115 + 300,	 // ��Ʒ�����¼�
	DPSDK_CORE_ALARM_PARKINGDETECTION				= 0x00000116 + 300,	 // �Ƿ�ͣ���¼�
	DPSDK_CORE_ALARM_FACERECOGNITION				= 0x00000117 + 300,	 // ����ʶ���¼�
	DPSDK_CORE_ALARM_TRAFFIC_MANUALSNAP				= 0x00000118 + 300,	 // ��ͨ�ֶ�ץ���¼�
	DPSDK_CORE_ALARM_TRAFFIC_FLOWSTATE				= 0x00000119 + 300,	 // ��ͨ����ͳ���¼�
	DPSDK_CORE_ALARM_TRAFFIC_STAY					= 0x0000011A + 300,	 // ��ͨ�����¼�
	DPSDK_CORE_ALARM_TRAFFIC_VEHICLEINROUTE			= 0x0000011B + 300,	 // �г�ռ���¼�
	DPSDK_CORE_ALARM_MOTIONDETECT					= 0x0000011C + 300,	 // ��Ƶ�ƶ�����¼�
	DPSDK_CORE_ALARM_LOCALALARM						= 0x0000011D + 300,	 // �ⲿ�����¼�
	DPSDK_CORE_ALARM_PRISONERRISEDETECTION			= 0X0000011E + 300,	 // ���������������¼�
	DPSDK_CORE_ALARM_IVS_B_ALARM_END,									 // ���ϱ�����ΪIVS_B����ı������ͣ���SDK���
	DPSDK_CORE_ALARM_VIDEODIAGNOSIS					= 0X00000120 + 300,	 // ��Ƶ��Ͻ���¼�
	DPSDK_CORE_ALARM_IVS_V_ALARM                    =  DPSDK_CORE_ALARM_VIDEODIAGNOSIS,	// 
	DPSDK_CORE_ALARM_IVS_RFID_INFO					= 0x00000166 + 300,  // RFID�����߼����Ϣ�¼�

	//�������ܱ���start
	DPSDK_CORE_ALARM_IVS_AUDIO_ABNORMALDETECTION    = 0x00000126 + 300,		// �����쳣���
	DPSDK_CORE_ALARM_CLIMB_UP						= 0x00000128 + 300,		// �ʸ߼�� 
	DPSDK_CORE_ALARM_LEAVE_POST  					= 0x00000129 + 300,		// ��ڼ��
	//�������ܱ���End

	DPSDK_CORE_ALARM_IVS_ALARM_END					= 1000,				 // �����豸�������͵ķ�ΧΪ300-1000
	DPSDK_CORE_ALARM_OSD,												 // osd��Ϣ
	DPSDK_CORE_ALARM_CROSS_INFO,										 // ʮ��·��

	DPSDK_CORE_ALARM_CLIENT_ALARM_BEGIN				= 1100,				 // �ͻ���ƽ̨������ʼ
	DPSDK_CORE_ALARM_CLIENT_DERELICTION,								 // �������[��ͨ�¼�-������]
	DPSDK_CORE_ALARM_CLIENT_RETROGRADATION,								 // ���� [��ͨ�¼�]
	DPSDK_CORE_ALARM_CLIENT_OVERSPEED,									 // ����  [��ͨ�¼�]
	DPSDK_CORE_ALARM_CLIENT_LACK_ALARM,									 // Ƿ��  [��ͨ�¼�]
	DPSDK_CORE_ALARM_CLIENT_FLUX_COUNT,									 // ����ͳ��[��ͨ�¼�]
	DPSDK_CORE_ALARM_CLIENT_PARKING,									 // ͣ�����[��ͨ�¼�]
	DPSDK_CORE_ALARM_CLIENT_PASSERBY,									 // ���˼��[��ͨ�¼�]
	DPSDK_CORE_ALARM_CLIENT_JAM,										 // ӵ�¼��[��ͨ�¼�]
	DPSDK_CORE_ALARM_CLIENT_AREA_INBREAK,								 // ������������
	DPSDK_CORE_ALARM_CLIENT_ALARM_END				= 1200,				 // �ͻ���ƽ̨��������

	ALARM_SYSTEM_BEGIN					= 1200,					// ����ϵͳ�ı���
	ALARM_HOST_TEMPRATURER				= 1201,					// �����¶ȹ���
	ALARM_RAID_LOAD						= 1202,					// raid����
	ALARM_SERVER_AUTO_MIGRATE			= 1203,					// �������Զ�Ǩ��
	ALARM_SERVER_MANUAL_MIGRATE			= 1204,					// �������ֶ�Ǩ��
	ALARM_SERVER_STATUS_CHANGE			= 1205,					// ������״̬��� 
	ALARM_MASTER_TO_BACKUP				= 1206,					// ˫���ȱ������б���
	ALARM_BACKUP_TO_MASTER				= 1207,					// ˫���ȱ�����������
	ALARM_BACKUP_ABNORMAL				= 1208,					// ˫���ȱ���������
	ALARM_BACKUP_NORMAL					= 1209,					// ˫���ȱ��������ϻָ�
	ALARM_SYSTEM_END					= 1300,

	// -E ��Ƶ������� ����12�ֱ�������
	ALARM_VQDS_VIDEO_LOST				= 1500,					// ��Ƶ�������-��Ƶ��ʧ
	ALARM_VQDS_HIGHBRIGHT				= 1501,					// �����Ⱦ���
	ALARM_VQDS_HIGHBRIGHT_RED			= 1502,					// �����Ⱥ�ɫ����
	ALARM_VQDS_LOWBRIGHT				= 1503,					// �����Ⱦ���
	ALARM_VQDS_LOWBRIGHT_RED			= 1504,					// �����Ⱥ�ɫ����
	ALARM_VQDS_CONTRAST					= 1505,					// �ԱȶȾ���
	ALARM_VQDS_CONTRAST_RED				= 1506,					// �ԱȶȺ�ɫ����
	ALARM_VQDS_CLARITY					= 1507,					// �����Ⱦ���
	ALARM_VQDS_CLARITY_RED				= 1508,					// �����Ⱥ�ɫ����
	ALARM_VQDS_COLOR_OFFSET				= 1509,					// ɫ��ƫ���
	ALARM_VQDS_COLOR_OFFSET_RED			= 1510,					// ƫɫ��ɫ����
	ALARM_VQDS_DIAGNOSE_FAIL			= 1511,					// ��Ƶ�������ʧ��

	ALARM_ALARMHOST_MEDICAL				 = 1604,				 // ҽ�Ʊ���
	ALARM_ALARMHOST_URGENCY				 = 1605,				 // ����������������
	ALARM_ALARMHOST_CATCH				 = 1606,				 // Ю�ֱ���
	ALARM_ALARMHOST_MENACE_SLIENCE       = 1607,				 // ������в
	ALARM_ALARMHOST_PERIMETER            = 1608,				 // �ܽ籨��
	ALARM_ALARMHOST_DEFENCEAREA_24H		 = 1609,				 // 24Сʱ��������
	ALARM_ALARMHOST_DEFENCEAREA_DELAY	 = 1610,				 // ��ʱ��������
	ALARM_ALARMHOST_DEFENCEAREA_INITIME  = 1611,				 // ��ʱ��������
	ALARM_ALARMHOST_BREAK				 = 1612,				 // ����
	ALARM_ALARMHOST_AUX_OVERLOAD         = 1613,                 // AUX����
	ALARM_ALARMHOST_AC_POWDOWN			 = 1614,                 // ���������
	ALARM_ALARMHOST_BAT_DOWN			 = 1615,                 // ���Ƿѹ
	ALARM_ALARMHOST_SYS_RESET			 = 1616,                 // ϵͳ��λ
	ALARM_ALARMHOST_PROGRAM_CHG          = 1617,                 // ��ص���
	ALARM_ALARMHOST_BELL_CUT			 = 1618,                 // ���ű��жϻ��·
	ALARM_ALARMHOST_PHONE_ILL			 = 1619,                 // �绰�жϻ�ʧЧ
	ALARM_ALARMHOST_MESS_FAIL			 = 1620,				 // ͨѶʧ��
	ALARM_ALARMHOST_WIRELESS_PWDOWN		 = 1621,				 // ����̽����Ƿѹ
	ALARM_ALARMHOST_SIGNIN_FAIL			 = 1622,				 // ��¼ʧ��
	ALARM_ALARMHOST_ERR_CODE			 = 1623,				 // ���������½
	ALARM_ALARMHOST_MANAUL_TEST			 = 1624,				 // �ֶ�����
	ALARM_ALARMHOST_CYCLE_TEST			 = 1625,				 // ���ڲ���
	ALARM_ALARMHOST_SVR_REQ				 = 1626,				 // ��������
	ALARM_ALARMHOST_BUF_RST				 = 1627,				 // �������帴λ
	ALARM_ALARMHOST_CLR_LOG				 = 1628,				 // �����־
	ALARM_ALARMHOST_TIME_RST			 = 1629,				 // ����ʱ�临λ
	ALARM_ALARMHOST_NET_FAIL			 = 1630,				 // �������
	ALARM_ALARMHOST_IP_CONFLICT			 = 1631,				 // IP��ͻ
	ALARM_ALARMHOST_KB_BREAK			 = 1632,				 // ���̷���
	ALARM_ALARMHOST_KB_ILL               = 1633,				 // ��������
	ALARM_ALARMHOST_SENSOR_O			 = 1634,				 // ̽������·
	ALARM_ALARMHOST_SENSOR_C			 = 1635,				 // ̽������·
	ALARM_ALARMHOST_SENSOR_BREAK		 = 1636,				 // ̽��������
	ALARM_FIRE_ALARM					 = 1637,				 // ����������

	//�Ӿ���������end
	ALARM_POWER_MAJORTOSPARE			= 1640,					// ����Դ�б��õ�Դ
	ALARM_POWER_SPARETOMAJOR			= 1641,					// ���õ�Դ������Դ
	ALARM_ENCODER_ALARM					= 1642,					// ���������ϱ���
	ALARM_DEVICE_REBOOT					= 1643,					// �豸��������
	ALARM_DISK							= 1644,					// Ӳ�̱���
	ALARM_NET_ABORT_WIRE				= 1645,					// ����������ϱ���
	ALARM_NET_ABORT_WIRELESS			= 1646,					// ����������ϱ���
	ALARM_NET_ABORT_3G					= 1647,					// 3G������ϱ���
	ALARM_MAC_CONFLICT					= 1648,					// MAC��ͻ
	ALARM_POWER_OFF_BACKUP				= 1649,					// ���õ�Դ����
	ALARM_CHASSISINTRUDED				= 1650,					// ��������	
	ALARM_PSTN_BREAK_LINE				= 1651,					// PSTN���߱���
	ALARM_CALL_ALARM_HOST				= 1652,					// �绰���������豸����
	ALARM_CALL_ALARM_HOST_CHN			= 1653,					// �绰��������ͨ������
	ALARM_RCEMERGENCY_CALL				= 1654,					// ��������δ֪�¼�
	ALARM_RCEMERGENCY_CALL_KEYBOARD_FIRE = 1655,				// ����������������
	ALARM_RCEMERGENCY_CALL_KEYBOARD_DURESS = 1656,				// ��������������в��
	ALARM_RCEMERGENCY_CALL_KEYBOARD_ROBBER = 1657,				// ���������������˾�
	ALARM_RCEMERGENCY_CALL_KEYBOARD_MEDICAL = 1658,				// ��������������ҽ��
	ALARM_RCEMERGENCY_CALL_KEYBOARD_EMERGENCY = 1659,			// ������������������
	ALARM_RCEMERGENCY_CALL_WIRELESS_EMERGENCY = 1660,			// ��������ң��������
	ALARM_LOCK_BREAK					= 1661,					// ����
	ALARM_ACCESS_CTL_OPEN				= 1662, 				// ��Ƶ���������쳣����
	// ������Ӫƽ̨����end

	//����(PE)����-(SCS_ALARM_SWITCH_START ȡ��ֱ������SCS�����ĵ�)
	//ϵͳ���̶������ӱ�������ALARM_SCS_BEGIN
	//�����������ɿ�
	ALARM_SCS_SWITCH_START				= 1800,
	ALARM_SCS_INFRARED,											// �������澯
	ALARM_SCS_SMOKE,											// �̸и澯
	ALARM_SCS_WATER,                							// ˮ���澯
	ALARM_SCS_COMPRESSOR,           							// ѹ�������ϸ澯
	ALARM_SCS_OVERLOAD,             							// ���ظ澯
	ALARM_SCS_BUS_ANOMALY,          							// ĸ���쳣
	ALARM_SCS_LIFE,                 							// �����澯
	ALARM_SCS_SOUND,                							// �����澯
	ALARM_SCS_TIME,                 							// ʱ�Ӹ澯
	ALARM_SCS_FLOW_LOSS,            							// ������ʧ�澯
	ALARM_SCS_FUSING,               							// �۶ϸ澯
	ALARM_SCS_BROWN_OUT,            							// ����澯
	ALARM_SCS_LEAKING,              							// ©ˮ�澯
	ALARM_SCS_JAM_UP,               							// �����澯
	ALARM_SCS_TIME_OUT,             							// ��ʱ�澯
	ALARM_SCS_REVERSE_ORDER,        							// ����澯
	ALARM_SCS_NETWROK_FAILURE,      							// ����ʧ�ܸ澯
	ALARM_SCS_UNIT_CODE_LOSE,       							// �����붪ʧ�澯
	ALARM_SCS_UNIT_CODE_DISMATCH,   							// �����벻ƥ��澯
	ALARM_SCS_FAULT,                							// ���ϸ澯
	ALARM_SCS_UNKNOWN,              							// δ֪�澯
	ALARM_SCS_CUSTOM,               							// �Զ���澯
	ALARM_SCS_NOPERMISSION,         							// ��Ȩ�޸澯
	ALARM_SCS_INFRARED_DOUBLE,      							// ����˫���澯
	ALARM_SCS_ELECTRONIC_FENCE,     							// ����Χ���澯
	ALARM_SCS_UPS_MAINS,            							// �е������е��쳣
	ALARM_SCS_UPS_BATTERY,          							// �����������쳣
	ALARM_SCS_UPS_POWER_SUPPLY,     							// UPS���������·����
	ALARM_SCS_UPS_RUN_STATE,        							// UPS����UPS����
	ALARM_SCS_UPS_LINE_STYLE,       							// UPS����Ϊ����ʽUPS��  ��Ϊ��ʽ
	ALARM_SCS_XC,                   							// С��
	ALARM_SCS_DRQ,                  							// ��·��
	ALARM_SCS_GLDZ,                 							// ���뵶բ
	ALARM_SCS_JDDZ,                								// �ӵص�բ
	ALARM_SCS_IN_END,											// ��ע�����ֵ�����ð�����Ϊ�ж�ֵ��ֻ���˵�������������ɿء�������
	//��Ϊ�������ġ����������ɿء�û�п�ʼ�����ALARM_SCS_DOOR_START

	//���������ɿأ���ע���������ALARM_SCS_DOOR_SWITCH���������ΪBEGIN��
	ALARM_SCS_DOOR_SWITCH				= 1850,					// �Ž����������ظ澯
	ALARM_SCS_UPS_SWITCH,										// UPS���ظ澯,
	ALARM_SCS_DBCB_SWITCH,          							// ���񿪹ظ澯
	ALARM_SCS_ACDT_SWITCH,          							// �յ����ظ澯
	ALARM_SCS_DTPW_SWITCH,          							// ֱ����Դ���ظ澯
	ALARM_SCS_LIGHT_SWITCH,         							// �ƹ���������ظ澯
	ALARM_SCS_FAN_SWITCH,           							// ���ȿ��������ظ澯
	ALARM_SCS_PUMP_SWITCH,          							// ˮ�ÿ��ظ澯
	ALARM_SCS_BREAKER_SWITCH,       							// ��բ���ظ澯
	ALARM_SCS_RELAY_SWITCH,         							// �̵������ظ澯
	ALARM_SCS_METER_SWITCH,        								// ����ظ澯
	ALARM_SCS_TRANSFORMER_SWITCH,   							// ��ѹ�����ظ澯
	ALARM_SCS_SENSOR_SWITCH,        							// ���������ظ澯
	ALARM_SCS_RECTIFIER_SWITCH,     							// �������澯
	ALARM_SCS_INVERTER_SWITCH,      							// ������澯
	ALARM_SCS_PRESSURE_SWITCH,      							// ѹ�����ظ澯
	ALARM_SCS_SHUTDOWN_SWITCH,      							// �ػ��澯
	ALARM_SCS_WHISTLE_SWITCH,	   								// ���Ѹ澯
	ALARM_SCS_SWITCH_END,
	//ģ����
	ALARM_SCS_ANALOG_START				= 1880,
	ALARM_SCS_TEMPERATURE,										// �¶ȸ澯
	ALARM_SCS_HUMIDITY,             							// ʪ�ȸ澯
	ALARM_SCS_CONCENTRATION,        							// Ũ�ȸ澯
	ALARM_SCS_WIND,                 							// ���ٸ澯
	ALARM_SCS_VOLUME,               							// �����澯
	ALARM_SCS_VOLTAGE,              							// ��ѹ�澯
	ALARM_SCS_ELECTRICITY,          							// �����澯
	ALARM_SCS_CAPACITANCE,          							// ���ݸ澯
	ALARM_SCS_RESISTANCE,           							// ����澯
	ALARM_SCS_CONDUCTANCE,          							// �絼�澯
	ALARM_SCS_INDUCTANCE,           							// ��и澯
	ALARM_SCS_CHARGE,               							// ������澯
	ALARM_SCS_FREQUENCY,            							// Ƶ�ʸ澯
	ALARM_SCS_LIGHT_INTENSITY,      							// ����ǿ�ȸ澯(��)
	ALARM_SCS_PRESS,                							// ���澯����ţ�٣�ǧ������
	ALARM_SCS_PRESSURE,             							// ѹǿ�澯����������ѹ��
	ALARM_SCS_HEAT_TRANSFER,        							// ���ȸ澯����ÿƽ�ף�
	ALARM_SCS_THERMAL_CONDUCTIVITY, 							// �ȵ��澯��kcal/(m*h*��)��
	ALARM_SCS_VOLUME_HEAT,          							// �����ȸ棨kcal/(kg*��)��
	ALARM_SCS_HOT_WORK,             							// �ȹ��澯��������
	ALARM_SCS_POWER,                							// ���ʸ澯���ߣ�
	ALARM_SCS_PERMEABILITY,         							// ��͸�ʸ澯��������
	ALARM_SCS_PROPERTION,										// ������������ѹ������ȣ��������أ����ص�λΪ%�� 
	ALARM_SCS_ENERGY,											// ���ܣ���λΪJ��
	ALARM_SCS_ANALOG_END,
	//ALARM_SCS_END,

	ALARM_IP_DEV_TALK					= 1907,					// IP�豸�Խ�����

	ALARM_TYPE_UNIFY_BEGIN				= 1908,					// ��������ͳһ��������Ҫ��EnumCenterRecType����
	ALARM_VOICE_EXCEPTION				= 1909,					// ��Ƶ�쳣����	
	ALARM_TYPE_UNIFY_END,										// ��������ͳһ��������Ҫ��EnumCenterRecType����

	//EVS������������
	ALARM_NO_DISK                       = 1916,					// ��Ӳ�̱��� 
	ALARM_DOUBLE_DEV_VERSION_ABNORMAL   = 1917,					// ˫���豸�����뱸��֮��汾��Ϣ��һ���쳣�¼� 
	ALARM_DCSSWITCH                     = 1918,					// �����л��¼�/��Ⱥ�л����� 
	ALARM_DEV_RAID_FAILED               = 1919,					// �豸RAID���󱨾� 
	ALARM_DEV_RAID_DEGRADED             = 1920,					// �豸RAID�������� 
	ALARM_BUF_DROP_FRAME                = 1921,					// ¼�񻺳�����֡����

	AE_ALARM_TYPE_BEGIN					= 2000,
	ALARM_DOOR_MAGNETISM				= 2200,					// �Ŵ�
	ALARM_PASSIVE_INFRARED				= 2201,					// ��������
	ALARM_GAS							= 2202,					// ����
	ALARM_INITIATIVE_INFRARED			= 2203,					// ��������
	ALARM_GLASS_CRASH					= 2204,					// ��������
	ALARM_EXIGENCY_SWITCH				= 2205,					// ��������
	ALARM_SHAKE							= 2206,					// ��
	ALARM_BOTH_JUDGE					= 2207,					// ˫��������+΢����
	ALARM_THREE_TECHNIC					= 2208,					// ������
	ALARM_CALL_BUTTON					= 2209,      			// ���а�ť
	ALARM_SENSE_OTHER					= 2210,	    			// ����
	AE_ALARM_TYPE_END					= 2400,

	//begin�𶯹��˱�������
	ALARM_TYPE_VIBRATIONFIBER_BEGIN     = 2601,					// �𶯹���1
	ALARM_VIBRATIONFIBER_SNLALARM,                              // ���������� 
	ALARM_VIBRATIONFIBER_BOXALARM,                              // ���غб��� 
	ALARM_VIBRATIONFIBER_INVALIDZONE,                           // ����ʧЧ1106 
	ALARM_VIBRATIONFIBER_SIGNAL_OFF,                            // �����ź�Դֹͣ 
	ALARM_VIBRATIONFIBER_FIBRE_BREAK,                           // ���˶Ͽ�
	ALARM_TYPE_VIBRATIONFIBER_END		= 2700,					// �𶯹���5
	//end
	//Ѳ������
	ALARM_PATROL_BEGIN					 = 2701,
	ALARM_PATROL_EXCEPTION				 = 2702,				// Ѳ���쳣���� 
	ALARM_PATROL_END					 = 2800,
	// -FԤ���������ͣ��Զ��屨��
	ALARM_TYPE_USERDEFINE_BEGIN			 = 3101,
	ALARM_TYPE_USERDEFINE_END			 = 3130,

	// ������Ӫƽ̨����չ�Զ��屨������
	ALARM_TYPE_USERDEFINEEX_BEGIN		 = 3201,
	ALARM_TYPE_USERDEFINEEX_END			 = 4200,

	ALARM_NODE_ACTIVE					= 4201,					// �����л�����
	ALARM_ISCSI_STATUS					= 4202,					// ISCSI�洢״̬�������
	ALARM_OUTDOOR_STATIC				= 4203,

	ALARM_FALLING						= 4204,					// �����¼����� 
	ALARM_ITC_OUTSIDE_CARNUM			= 4205,					// ������ⲿ������
	ALARM_POS_TRANING_MODE				= 4206,					//POS��ѵ��ģʽ����
	ALARM_REFUND_OVER_QUOTA				= 4207,					//�˻��޶��
	ALARM_SWING_CARD_FREQUENTLY			= 4208,					//��Ա��Ƶ�����ֱ���
	ALARM_SIGNLE_COST_OVER_QUOTA		= 4209,					//���۵��ʳ����

	//DSS-H���ӶԽ��豸���ڻ�������������������
	ALARM_SENSE_BEGIN					= 4299,
	ALARM_SENSE_DOOR                    = 4300,                 //�Ŵ�
	ALARM_SENSE_PASSIVEINFRA            = 4301,                 //��������
	ALARM_SENSE_GAS                     = 4302,                 //����
	ALARM_SENSE_SMOKING                 = 4303,                 //�̸�
	ALARM_SENSE_WATER                   = 4304,                 //ˮ��
	ALARM_SENSE_ACTIVEFRA               = 4305,                 //��������
	ALARM_SENSE_GLASS                   = 4306,                 //��������
	ALARM_SENSE_EMERGENCYSWITCH         = 4307,                 //��������
	ALARM_SENSE_SHOCK                   = 4308,                 //��
	ALARM_SENSE_DOUBLEMETHOD            = 4309,                 //˫��(����+΢��)
	ALARM_SENSE_THREEMETHOD             = 4310,                 //������
	ALARM_SENSE_TEMP                    = 4311,                 //�¶�
	ALARM_SENSE_HUMIDITY                = 4312,                 //ʪ��
	ALARM_SENSE_WIND                    = 4313,                 //����
	ALARM_SENSE_CALLBUTTON              = 4314,                 //���а�ť
	ALARM_SENSE_GASPRESSURE             = 4315,                 //����ѹ��
	ALARM_SENSE_GASCONCENTRATION        = 4316,                 //ȼ��Ũ��
	ALARM_SENSE_GASFLOW                 = 4317,                 //��������
	ALARM_SENSE_OIL                     = 4319,                 //������⣬���͡����͵ȳ������ͼ��
	ALARM_SENSE_MILEAGE                 = 4320,                 //��������
	ALARM_SENSE_URGENCYBUTTON           = 4321,                 //������ť
	ALARM_SENSE_STEAL                   = 4322,                 //����
	ALARM_SENSE_PERIMETER               = 4323,                 //�ܽ�
	ALARM_SENSE_PREVENTREMOVE           = 4324,                 //����
	ALARM_SENSE_DOORBELL                = 4325,                 //����
	ALARM_SENSE_LOCK_LOCKKEY            = 4326,                 //����Կ�ױ���
	ALARM_SENSE_LOCK_LOWPOWER           = 4327,                 //�����͵�ѹ����
	ALARM_SENSE_LOCK_PREVENTREMOVE      = 4328,                 //��������
	ALARM_SENSE_LOCK_FORCE		        = 4329,                 //����в�ȱ���
	ALARM_SENSE_END						= 4399,

	ALARM_STORAGE_BEGIN					= 4400,
	ALARM_IO_QUEUE_FULL					= 4401,					// ���̶�д�߸���
	ALARM_DISK_DESTROY					= 4402,					// �����쳣
	ALARM_IPSAN_OFF_LINE				= 4403,					// IPSan����
	ALARM_NO_DISK_STORAGE				= 4404,					// û�д���			
	ALARM_GET_STREAM_ERROR				= 4405,					// ȡ��������
	ALARM_STORAGE_END					= 4499,

	//DSSH����ڿ��ں�����������������
	ALARM_TRAFFIC_SUSPICIOUSCAR         = 4501,

	//�󻪳���ڿ��ƻ���������
	ALARM_SLUICE_BEGIN								= 4502,
	ALARM_SLUICE_IC_CARD_STATUS_LOWCARD				= 4503,					//�����ٿ�����
	ALARM_SLUICE_IC_CARD_STATUS_NOCARD				= 4504,					//�����޿�����
	ALARM_SLUICE_IC_CARD_STATUS_FULLCARDS			= 4505,					//���俨������
	ALARM_SLUICE_CAR_DETECTOR_STATE_OFFLINE			= 4506,					//���������߱���
	ALARM_SLUICE_CAR_DETECTOR_STATE_LOOPOFFLINE		= 4507,					//�ظ���Ȧ���߱���
	ALARM_SLUICE_LED_DEV_STATE_OFFLINE				= 4508,					//LED���߱���
	ALARM_SLUICE_SWIPING_CARD_DEV_STATE_OFFLINE		= 4509,					//���ˢ������߱���
	ALARM_SLUICE_DELIVE_CARD_DEV_OFFLINE			= 4510,					//����ˢ������߱���
	ALARM_SLUICE_SPEAK_DEV_STATUS					= 4511,					//�Խ��¼�����
	ALARM_SLUICE_END								= 4550,

	//DSSH�����ɷѻ���������
	ALARM_SELFPAY_BEGIN								= 4551,
	ALARM_SELFPAY_NOPAPER							= 4552,//ȱֽ
	ALARM_SELFPAY_NOCASH50							= 4553,
	ALARM_SELFPAY_NOCASH20							= 4554,
	ALARM_SELFPAY_NOCASH10							= 4555,
	ALARM_SELFPAY_NOCASH1							= 4556,
	ALARM_SELFPAY_NOCOIN							= 4557,
	ALARM_SELFPAY_LOCKMONEY							= 4558,//����
	ALARM_SELFPAY_DISMANTLE							= 4559,//����
	ALARM_SELFPAY_UNPACK							= 4560,//����
	ALARM_SELFPAY_UNKONWN							= 4561,//ֽ�Ҳ�ʶ��
	ALARM_SELFPAY_END								= 4580,

	//�ͻ���IP�Խ�����
	ALARM_IP_DEV_BEGIN = 4700,
	ALARM_IP_DEV_CALLIN = 4701,									//�ֻ�����
	ALARM_IP_DEV_CALLOUT = 4702,								//����
	ALARM_IP_DEV_END = 4800,

	//�ֻ�APP��������
	ALARM_MOBILEAPP_BEGIN									= 4900,
	ALARM_MOBILEAPP_GPS										= 4901,		//�ֻ�APP�ϴ�GPS
	ALARM_MOBILEAPP_ONE_CLICK								= 4902,		//�ֻ�APPһ������
	ALARM_MOBILEAPP_MANUAL_ADD								= 4903,		//�ֻ�APP�ֶ���ӱ���
	ALARM_MOBILEAPP_END										= 5000,

	//APS����ͳ�Ʊ���
	ALAMR_PEOPLE_COUNTING_BEGIN								= 5001,
	ALARM_PEOPLE_UPPER_LIMIT								= 5002,		//��������
	ALARM_PEOPLE_LOWER_LIMIT								= 5003,		//��������
	ALARM_INFLUX_UPPER_LIMIT								= 5004,		//���������꣨����
	ALARM_OUTFLUX_UPPER_LIMIT								= 5005,		//���������꣨����
	ALARM_DENSITY_UPPER_LIMIT								= 5006,		//�ܶȱ���
	ALARM_SCENE_EXCEPTION									= 5007,		//�����쳣����
	ALAMR_PEOPLE_COUNTING_END								= 5100,

	ALARM_HEATIMG_TEMPER							= 5120,		//�ȳ�����µ��¶��쳣����
	ALARM_FIRE_WARNING								= 5121,		//�ȳ����Ż�㱨��

	//�ͻ��˻������豸���Ʊ���
	ALARM_STB_BEGIN									= 5200,		
	ALARM_STB_FIRE									= 5201,		//��
	ALARM_STB_CRIME									= 5202,		//�˾�
	ALARM_STB_EMERGENCY								= 5203,		//��������
	ALARM_STB_OTHER									= 5204,		//��������
	ALARM_STB_END									= 5250,

	//-C/-P��������Ԥ��
	ALARM_DSSC_BEGIN								=	5300,
	ALARM_PATIENTDETECTION_TYPE_CROSS_REGION		=	ALARM_DSSC_BEGIN + 1,	// �������򱨾��������ǲ����뿪������������������
	ALARM_PATIENTDETECTION_TYPE_LIGHT_OFF			=	ALARM_DSSC_BEGIN + 2,	// ������Ʊ�Ϩ��
	ALARM_PATIENTDETECTION_TYPE_STOP_DETECTION		=	ALARM_DSSC_BEGIN + 3,	// ���������ټ�ز���
	ALARM_PATIENTDETECTION_TYPE_START_DETECTION		=	ALARM_DSSC_BEGIN + 4,	// ��ʼ����
	ALARM_DSSC_END									=	5400,

	ALARM_U700_BEGIN								= 5401,
	ALARM_VTA_INSPECTION							= ALARM_U700_BEGIN + 1, // VTA������Ѳ�챨��
	ALARM_VTA_OVERSPEED								= ALARM_U700_BEGIN + 2, // VTA���������ٱ���
	ALARM_VTA_INSPECTION_SWING_CARD					= ALARM_U700_BEGIN + 3, //VTAѲ��ˢ��
	ALARM_VTA_PATROL_SWING_CARD						= ALARM_U700_BEGIN + 4, //VTAѲ��ˢ��
	ALARM_U700_END = 5500,

	ALARM_REMOTE_CAMERA_STATE						= 5501,				//�����豸���״̬�ϱ�����
	ALARM_SHANGHAI_JIHENG							= 5502,				//�Ϻ������ϱ�����
	ALARM_CHANNEL_TALK								= 5506,				//ͨ���Խ�����


	//�¶����������屨�������
	ALARM_NEW_SCS_BEGIN								= 8000,
	ALARM_NEW_SCS_END								= 9999,
	
}dpsdk_alarm_type_e;

typedef enum
{
	OP_FTP_TYPE_UNKNOW		=0,
	OP_FTP_TYPE_DOWN		=0x01,           //����
	OP_FTP_TYPE_UP			=0x02,           //�ϴ�
	OP_FTP_TYPE_DELETE		=0x03,           //ɾ��
}dpsdk_operator_ftp_type_e; 

// ͼƬ������ݻص�����
typedef enum
{
	DPSDK_CORE_PICINFO_RECIVE,										     // �յ�ͼƬ��Ϣ
	DPSDK_CORE_PICDATA_RECIVE,										     // ͼƬ���ݽ���
	DPSDK_CORE_PICDATA_OVER,										     // һ��ͼƬ���ݽ���
}dpsdk_picdata_notify_e;


// ������������
typedef enum
{
	ALARM_EVENT_OCCUR								= 1,				 // ����
	ALARM_EVENT_DISAPPEAR,												 // ��ʧ
}dpsdk_event_type_e;

// ������������
typedef enum
{
	ALARM_DEALWITH_PENDING							= 1,			      // ������
	ALARM_DEALWITH_RESOLVE							= 2,				  // �ѽ��
	ALARM_DEALWITH_SUGGESTTED						= 4,				  // ��
	ALARM_DEALWITH_IGNORED							= 8,			      // ����	
	ALARM_DEALWITH_UNPROCESSED						= 16				  // δ���
}dpsdk_alarm_dealwith_e;


typedef enum
{
	//DPSDK_CORE_ORG_NODE_TYPE_ALL			        = 0,				   // ��ѯȫ����1~4����ʱ���ṩ
	DPSDK_CORE_ORG_NODE_TYPE_GROUP			        = 1,				   // ��֯
	DPSDK_CORE_ORG_NODE_TYPE_DEPARTMENT		        = 2,			       // ����
	DPSDK_CORE_ORG_NODE_TYPE_MONITOR_AREA	        = 3,				   // �������
	DPSDK_CORE_ORG_NODE_TYPE_ADM_AREA		        = 4,				   // ����Ͻ��

	DPSDK_CORE_ORG_NODE_TYPE_PERSION		        = 5,				   // ��Ա
	DPSDK_CORE_ORG_NODE_TYPE_CHNDEPREL		        = 6,				   // ͨ��-���Ź����� 
	DPSDK_CORE_ORG_NODE_TYPE_DEPAREAREL		        = 7,				   // ����-Ͻ��������   
}dpsdk_org_node_e;

typedef enum
{
	DSST_GROUP_CHANGE_UNKNOW                        = 0,
	DSST_GROUP_CHANGE_ORG_ADDED,
	DSST_GROUP_CHANGE_ORG_CHANGED,							                // ��֯�ڵ���֪ͨ
	DSST_GROUP_CHANGE_ORG_DELETED,
	DSST_GROUP_CHANGE_PERSON_ADDED,
	DSST_GROUP_CHANGE_PERSON_CHANGED,						                // ��Ա��Ϣ���
	DSST_GROUP_CHANGE_PERSON_DELETED,
	DSST_GROUP_CHANGE_CAR_ADDED,
	DSST_GROUP_CHANGE_CAR_CHANGED,							                // ������Ϣ���
	DSST_GROUP_CHANGE_CAR_DELETED,
}dpsdk_dsst_change_type_e;

//ѹ����ʽ��ȡ��֯�ṹ
typedef enum
{
	DPSDK_CORE_GET_DEVINFO_BY_UNCOMPRESS = 0,		// ���÷�ѹ����ʽ��ȡ�豸��Ϣ
	DPSDK_CORE_GET_DEVINFO_BY_COMPRESSED = 1,		// ����ѹ����ʽ��ȡ�豸��Ϣ
}dpsdk_get_devinfo_compress_type_e;

// ����ǽ���ָ�����
typedef enum
{
	Screen_Split_1		                            = 1,
	Screen_Split_4	                            	= 4,
	Screen_Split_9		                            = 9,
	Screen_Split_16		                            = 16,
}tvwall_screen_split_caps;

//��ǽģʽ,����������Ŀ
typedef enum
{
	DPSDK_CORE_TVWALL_GENERAL						= 0,					//��ͨģʽ
	DPSDK_CORE_TVWALL_PIP,													//���л�ģʽ
}dpsdk_tvwall_pip_e;

//Ftp��������
typedef enum
{
	OP_ROMOTE_FILE_TYPE_DOWN			= 01,//����
	OP_ROMOTE_FILE_TYPE_UP				= 02,//�ϴ�
	OP_ROMOTE_FILE_TYPE_DELETE			= 03,//ɾ��
}dpsdk_operator_remote_file_type_e;

// ʵʱ��������
typedef enum
{
	DPSDK_CORE_STREAM_ALL		= 0,		// 0-ȫ��
	DPSDK_CORE_STREAM_MAIN		= 1,		// 1-������
	DPSDK_CORE_STREAM_SUB,					// 2-������
	DPSDK_CORE_STREAM_THIRD,				// 3-������
	DPSDK_CORE_STREAM_SIGNAL	= 5,		// 5-M60�����ź�
}dpsdk_encdev_stream_e;

typedef enum
{
	DPSDK_MDL_UNKNOW = -1, //δ֪ģ��
	DPSDK_MDL_APP,
	DPSDK_MDL_CMS,
	DPSDK_MDL_PCS,
	DPSDK_MDL_DMS,
	DPSDK_MDL_ADS,
	DPSDK_MDL_TRAN,	//��תģ��
	DPSDK_MDL_RTSP,
	DPSDK_MDL_FTP,
	DPSDK_MDL_PEC,
	DPSDK_MDL_MGR,
	DPSDK_MDL_AREA,
	DPSDK_MDL_CMS_FORSNVD,
	DPSDK_MDL_SCS,
	DPSDK_MDL_COUNT,   //ģ������
}dpsdk_mdl_type_e;	//Ĭ������

// JSON ��������
typedef enum
{
	GENERALJSON_TRAN_UNKNOW = -1,
	GENERALJSON_TRAN_REQUEST,
	GENERALJSON_TRAN_RESPONSE,
	GENERALJSON_TRAN_NOTIFY,
	GENERALJSON_TRAN_COUNT,
}generaljson_trantype_e;

//ͨ����֯�ڵ���Ϣ
typedef struct tagOrgInfo
{
	IN char                             szCode[DPSDK_CORE_ORG_CODE_LEN];		  // ͨ�ýڵ����
	IN char                             szName[DPSDK_CORE_ORG_NAME_LEN];		  // ͨ�ýڵ�����
	IN char                             szSN[DPSDK_CORE_ORG_SN_LEN];			  // ͨ�ýڵ�Ψһ��
	IN char                             szType[DPSDK_CORE_ORG_TYPE_LEN];		  // ͨ�ýڵ�����
	IN char                             szGpsX[DPSDK_CORE_ORG_GPS_LEN];			  // ͨ�ýڵ㾭��
	IN char                             szGpsY[DPSDK_CORE_ORG_GPS_LEN];			  // ͨ�ýڵ�γ��
	IN char                             szMemo[DPSDK_CORE_ORG_MEMO_LEN];		  // ͨ�ýڵ�����
	uint32_t	                        domainId;		                          // ��ID
	uint32_t	                        state;			                          // ״̬
}Org_Info_t;

// ��ȡ��֯����������Ϣ
typedef struct tagGetOrgCountInfo 
{
	IN char								szCoding[DPSDK_CORE_ORG_CODE_LEN];         // �ڵ�code
	OUT uint32_t						nGroupCount;						       // ��֯����
}Get_Org_Count_Info_t;

// ��ȡ��֯������Ϣ
typedef struct tagGetOrgInfo 
{
	IN char								szCoding[DPSDK_CORE_ORG_CODE_LEN];	       // �ڵ�code
	IN uint32_t							nOrgCount;							       // ��֯����
	OUT Org_Info_t*						pOrgInfo;							       // ��֯��Ϣ�����ⲿ���������ΪNULL��ֻ���ظ���
}Get_Org_Info_t; 

// ��¼��Ϣ
typedef struct tagLoginInfo
{
    char								szIp[DPSDK_CORE_IP_LEN];					// ����IP,����������
	uint32_t							nPort;										// ����˿�
    char								szUsername[DPSDK_CORE_USER_NAME_LEN];		// �û���
	char								szPassword[DPSDK_CORE_PASSWORD_LEN];		// ����
	dpsdk_protocol_version_e			nProtocol;									// Э������
	uint32_t							iType;										// ��½���ͣ�1ΪPC�ͻ���, 2Ϊ�ֻ��ͻ���
	char								szCheckBit[DPSDK_CORE_IP_LEN];				// �ֻ��ͻ��˵�½ƽ̨ʱУ���루һ��Ϊ�ֻ��ţ�
}Login_Info_t;

// ��֯��Ϣ
typedef struct tagDepInfo 
{
	char								szCoding[DPSDK_CORE_DGROUP_DGPCODE_LEN];	// �ڵ�code
	char								szDepName[DPSDK_CORE_DGROUP_DGPNAME_LEN];	// �ڵ�����
	int									nDepSort;									// ��֯����
}Dep_Info_t; 

// ��֯��Ϣ(��չ)
typedef struct tagDepInfoEx 
{
	char								szCoding[DPSDK_CORE_DGROUP_DGPCODE_LEN];	// �ڵ�code
	char								szDepName[DPSDK_CORE_DGROUP_DGPNAME_LEN];	// �ڵ�����
	char								szModifyTime[DPSDK_CORE_TIME_LEN];			// �ڵ��޸�ʱ��
	char								szSN[DPSDK_CORE_ORG_SN_LEN];				// Ψһ��ʶ��
	char								szMemo[DPSDK_CORE_MEM_LEN];					// ��ע��Ϣ ������Ӫƽ̨
	int									nDepType;									// ��֯�ڵ����� ������Ӫƽ̨
	int									nDepSort;									// ��֯����
	int									nChargebooth;								// �շ�ͤ��־
	int									nDepExtType;								// ��֯�ڵ���չ����
}Dep_Info_Ex_t; 

// �豸���ͣ���Ҫ��webͳһ
typedef enum
{
	DEV_TYPE_ENC_BEGIN			= 0,		// �����豸
	DEV_TYPE_DVR				= DEV_TYPE_ENC_BEGIN + 1,			// DVR
	DEV_TYPE_IPC				= DEV_TYPE_ENC_BEGIN + 2,			// IPC
	DEV_TYPE_NVS				= DEV_TYPE_ENC_BEGIN + 3,			// NVS
	DEV_TYPE_MCD				= DEV_TYPE_ENC_BEGIN + 4,			// MCD
	DEV_TYPE_MDVR				= DEV_TYPE_ENC_BEGIN + 5,			// MDVR
	DEV_TYPE_NVR				= DEV_TYPE_ENC_BEGIN + 6,			// NVR
	DEV_TYPE_SVR				= DEV_TYPE_ENC_BEGIN + 7,			// SVR
	DEV_TYPE_PCNVR				= DEV_TYPE_ENC_BEGIN + 8,			// PCNVR��PSS�Դ���һ��С�ͷ���
	DEV_TYPE_PVR				= DEV_TYPE_ENC_BEGIN + 9,			// PVR
	DEV_TYPE_EVS				= DEV_TYPE_ENC_BEGIN + 10,			// EVS
	DEV_TYPE_MPGS				= DEV_TYPE_ENC_BEGIN + 11,			// MPGS
	DEV_TYPE_SMART_IPC			= DEV_TYPE_ENC_BEGIN + 12,			// SMART_IPC
	DEV_TYPE_SMART_TINGSHEN		= DEV_TYPE_ENC_BEGIN + 13,			// ͥ������
	DEV_TYPE_SMART_NVR			= DEV_TYPE_ENC_BEGIN + 14,			// SMART_NVR
	DEV_TYPE_PRC				= DEV_TYPE_ENC_BEGIN + 15,			// ������
	DEV_TYPE_JT808				= DEV_TYPE_ENC_BEGIN + 18,			// ����JT808
	DEV_TYPE_ALARM_STUB_VTA     = DEV_TYPE_ENC_BEGIN + 25,          // VTA

	DEV_TYPE_ENC_END,

	DEV_TYPE_TVWALL_BEGIN		= 100,
	DEV_TYPE_BIGSCREEN			= DEV_TYPE_TVWALL_BEGIN + 1,		// ����
	DEV_TYPE_TVWALL_END,

	DEV_TYPE_DEC_BEGIN			= 200,		// �����豸
	DEV_TYPE_NVD				= DEV_TYPE_DEC_BEGIN + 1,			// NVD
	DEV_TYPE_SNVD				= DEV_TYPE_DEC_BEGIN + 2,			// SNVD
	DEV_TYPE_UDS				= DEV_TYPE_DEC_BEGIN + 5,			// UDS
	DEV_TYPE_DEC_END,

	DEV_TYPE_MATRIX_BEGIN		= 300,		// �����豸
	DEV_MATRIX_M60				= DEV_TYPE_MATRIX_BEGIN	+ 1,		// M60
	DEV_MATRIX_NVR6000			= DEV_TYPE_MATRIX_BEGIN + 2,		// NVR6000
	DEV_TYPE_MATRIX_END,

	DEV_TYPE_IVS_BEGIN			= 400,		// �����豸
	DEV_TYPE_ISD				= DEV_TYPE_IVS_BEGIN + 1,			// ISD ������
	DEV_TYPE_IVS_B				= DEV_TYPE_IVS_BEGIN + 2,			// IVS-B ��Ϊ��������
	DEV_TYPE_IVS_V				= DEV_TYPE_IVS_BEGIN + 3,			// IVS-V ��Ƶ������Ϸ���
	DEV_TYPE_IVS_FR				= DEV_TYPE_IVS_BEGIN + 4,			// IVS-FR ����ʶ�����
	DEV_TYPE_IVS_PC				= DEV_TYPE_IVS_BEGIN + 5,			// IVS-PC ������ͳ�Ʒ���
	DEV_TYPE_IVS_M				= DEV_TYPE_IVS_BEGIN + 6,			// IVS_M ���Ӹ������ܺ�
	DEV_TYPE_IVS_PC_BOX			= DEV_TYPE_IVS_BEGIN + 7,			// IVS-PC ���ܺ� 
	DEV_TYPE_IVS_B_BOX			= DEV_TYPE_IVS_BEGIN + 8,			// IVS-B ���ܺ�
	DEV_TYPE_IVS_M_BOX			= DEV_TYPE_IVS_BEGIN + 9,			// IVS-M ����
	DEV_TYPE_IVS_PRC			= DEV_TYPE_IVS_BEGIN + 10,			// ������
	DEV_TYPE_IVS_END,

	DEV_TYPE_BAYONET_BEGIN		= 500,		// -C����豸
	DEV_TYPE_CAPTURE			= DEV_TYPE_BAYONET_BEGIN + 1,		// �����豸
	DEV_TYPE_SPEED				= DEV_TYPE_BAYONET_BEGIN + 2,		// �����豸
	DEV_TYPE_TRAFFIC_LIGHT		= DEV_TYPE_BAYONET_BEGIN + 3,		// ������豸
	DEV_TYPE_INCORPORATE		= DEV_TYPE_BAYONET_BEGIN + 4,		// һ�廯�豸
	DEV_TYPE_PLATEDISTINGUISH	= DEV_TYPE_BAYONET_BEGIN + 5,		// ����ʶ���豸
	DEV_TYPE_VIOLATESNAPPIC		= DEV_TYPE_BAYONET_BEGIN + 6,		// Υͣ����豸
	DEV_TYPE_PARKINGSTATUSDEV	= DEV_TYPE_BAYONET_BEGIN + 7,		// ��λ����豸
	DEV_TYPE_ENTRANCE			= DEV_TYPE_BAYONET_BEGIN + 8,		// ������豸
	DEV_TYPE_VIOLATESNAPBALL	= DEV_TYPE_BAYONET_BEGIN + 9,		// Υͣץ�����
	DEV_TYPE_THIRDBAYONET		= DEV_TYPE_BAYONET_BEGIN + 10,		// �����������豸
	DEV_TYPE_ULTRASONIC			= DEV_TYPE_BAYONET_BEGIN + 11,		// ��������λ�����
	DEV_TYPE_FACE_CAPTURE		= DEV_TYPE_BAYONET_BEGIN + 12,		// ����ץ���豸
	DEV_TYPE_ITC_SMART_NVR		= DEV_TYPE_BAYONET_BEGIN + 13,		// ��������NVR�豸
	DEV_TYPE_BAYONET_END,

	DEV_TYPE_ALARM_BEGIN		= 600,		// �����豸
	DEV_TYPE_ALARMHOST			= DEV_TYPE_ALARM_BEGIN + 1,			// ��������
	DEV_TYPE_ALARM_END,

	DEV_TYPE_DOORCTRL_BEGIN		= 700,
	DEV_TYPE_DOORCTRL_DOOR		= DEV_TYPE_DOORCTRL_BEGIN + 1,		// �Ž�
	DEV_TYPE_DOORCTRL_END,

	DEV_TYPE_PE_BEGIN			= 800,
	DEV_TYPE_PE_PE				= DEV_TYPE_PE_BEGIN + 1,			// ����
	DEV_TYPE_PE_AE6016			= DEV_TYPE_PE_BEGIN + 2,			// AE6016�豸
	DEV_TYPE_PE_NVS				= DEV_TYPE_PE_BEGIN + 3,			// ���������ܵ�NVS�豸
	DEV_TYPE_PE_END,

	DEV_TYPE_VOICE_BEGIN		= 900,		// ip�Խ�
	DEV_TYPE_VOICE_MIKE			= DEV_TYPE_VOICE_BEGIN + 1,
	DEV_TYPE_VOICE_NET			= DEV_TYPE_VOICE_BEGIN + 2,
	DEV_TYPE_VOICE_END,

	DEV_TYPE_IP_BEGIN			= 1000,		// IP�豸��ͨ�����������豸��
	DEV_TYPE_IP_SCNNER			= DEV_TYPE_IP_BEGIN + 1,			// ɨ��ǹ
	DEV_TYPE_IP_SWEEP			= DEV_TYPE_IP_BEGIN + 2,			// �ذ�
	DEV_TYPE_IP_POWERCONTROL	= DEV_TYPE_IP_BEGIN + 3,			// ��Դ������
	DEV_TYPE_IP_END,

	DEV_TYPE_MULTIFUNALARM_BEGIN= 1100,		// �๦�ܱ�������
	DEV_TYPE_VEDIO_ALARMHOST	= DEV_TYPE_MULTIFUNALARM_BEGIN + 1,	// ��Ƶ��������
	DEV_TYPE_MULTIFUNALARM_END,

	DEV_TYPE_SLUICE_BEGIN		= 1200,
	DEV_TYPE_SLUICE_DEV			= DEV_TYPE_SLUICE_BEGIN + 1,		// ����ڵ�բ�豸
	DEV_TYPE_SLUICE_PARKING		= DEV_TYPE_SLUICE_BEGIN + 2,		// ͣ������բ�豸
	DEV_TYPE_SLUICE_STOPBUFFER	= DEV_TYPE_SLUICE_BEGIN + 3,		// ��Ƶ������
	DEV_TYPE_SLUICE_END,

	DEV_TYPE_ELECTRIC_BEGIN		= 1300,
	DEV_TYPE_ELECTRIC_DEV		= DEV_TYPE_ELECTRIC_BEGIN + 1,		// �����豸
	DEV_TYPE_ELECTRIC_END,

	DEV_TYPE_LED_BEGIN			= 1400,
	DEV_TYPE_LED_DEV			= DEV_TYPE_LED_BEGIN + 1,			// LED���豸
	DEV_TYPE_LED_END,

	DEV_TYPE_VIBRATIONFIBER_BEGIN	= 1500,		
	DEV_TYPE_VIBRATIONFIBER_DEV	= DEV_TYPE_VIBRATIONFIBER_BEGIN + 1,// �𶯹����豸 
	DEV_TYPE_VIBRATIONFIBER_END,

	DEV_TYPE_PATROL_BEGIN		= 1600,		
	DEV_TYPE_PATROL_DEV			= DEV_TYPE_PATROL_BEGIN + 1,		// Ѳ�����豸
	DEV_TYPE_PATROL_SPOT		= DEV_TYPE_PATROL_BEGIN + 2,		// Ѳ�����豸
	DEV_TYPE_PATROL_END,

	DEV_TYPE_SENTRY_BOX_BEGIN	= 1700,		
	DEV_TYPE_SENTRY_BOX_DEV		= DEV_TYPE_SENTRY_BOX_BEGIN + 1,	// ��λ���豸
	DEV_TYPE_SENTRY_BOX_END,

	DEV_TYPE_COURT_BEGIN		= 1800,		
	DEV_TYPE_COURT_DEV			= DEV_TYPE_COURT_BEGIN + 1,			// ͥ���豸
	DEV_TYPE_COURT_END,

	DEV_TYPE_VIDEO_TALK_BEGIN	= 1900,
	DEV_TYPE_VIDEO_TALK_VTNC	= DEV_TYPE_VIDEO_TALK_BEGIN + 1, 
	DEV_TYPE_VIDEO_TALK_VTO		= DEV_TYPE_VIDEO_TALK_BEGIN + 2,  
	DEV_TYPE_VIDEO_TALK_VTH		= DEV_TYPE_VIDEO_TALK_BEGIN + 3,  
	DEV_TYPE_VIDEO_TALK_END,

	DEV_TYPE_BROADCAST_BEGIN	= 2000,
	DEV_TYPE_BROADCAST_ITC_T6700R = DEV_TYPE_BROADCAST_BEGIN + 1,	// ITC_T6700R�㲥�豸
	DEV_TYPE_BROADCAST_END,

	DEV_TYPE_VIDEO_RECORD_SERVER_BEGIN = 2100,
	DEV_TYPE_VIDEO_RECORD_SERVER_BNVR	= DEV_TYPE_VIDEO_RECORD_SERVER_BEGIN + 1, // BNVR�豸
	DEV_TYPE_VIDEO_RECORD_SERVER_OE	= DEV_TYPE_VIDEO_RECORD_SERVER_BEGIN + 2, // �����豸(operation equipment)
	DEV_TYPE_VIDEO_RECORD_SERVER_END,

}dpsdk_dev_type_e;

// �豸��Ϣ
typedef struct tagDeviceInfo 
{
	char								szId[DPSDK_CORE_DEV_ID_LEN];				// �豸ID
	char								szName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];	// ����
	char								szUser[DPSDK_CORE_USER_NAME_LEN];			// �û���
	char								szPassword[DPSDK_CORE_PASSWORD_LEN];		// ����
	char								szIP[DPSDK_CORE_IP_LEN];					// �豸IP
	int									nPort;										// �豸�˿�
	dpsdk_device_factory_type_e			nFactory;									// ��������
	dpsdk_dev_status_e					nStatus;									// �豸״̬
	int									nEncChannelChildCount;						// ������ͨ������
	dpsdk_dev_type_e					nType;										// �豸����
}Device_Info_t; 

#if 1
typedef struct tagDeviceInfoEx 
{
	char								szId[DPSDK_CORE_DEV_ID_LEN];				// �豸ID
	char								szName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];	// ����
	dpsdk_device_factory_type_e			nFactory;									// ��������//dsl::DStr   szManfac;					// ������
	int                                 szModel;					                // ģʽ
	char								szUser[DPSDK_CORE_USER_NAME_LEN];			// �û���
	char								szPassword[DPSDK_CORE_PASSWORD_LEN];		// ����
	char								szIP[DPSDK_CORE_IP_LEN];					// �豸IP
	dpsdk_dev_type_e                    nDevType;						            // �豸type
	int									nPort;										// �豸�˿�
	int                             	szLoginType;				                // ��½����
	char	                            szRegID[DPSDK_CORE_DEV_ID_LEN];				// ����ע���豸ID
	int			                        nProxyPort;					                // ����˿�
	int			                        nUnitNum;					                // ��Ԫ��Ŀ--���ھ����豸��������
	dpsdk_dev_status_e					nStatus;									// �豸״̬
	char                                szCN[DPSDK_CORE_DEV_ID_LEN];				// �豸���к�
	char	                            szSN[DPSDK_CORE_DEV_ID_LEN];   	 		    // ��������SN
	uint64_t                            nRight;						                // Ȩ����Ϣ(ֻ��IP�Խ��豸�еĻ�Ͳ����)
	char                                szDevIP[DPSDK_CORE_IP_LEN];					// �豸��ʵIP
	int                                 nDevPort;					                // �豸��ʵport
	char                                dev_Maintainer[DPSDK_CORE_USER_NAME_LEN];   // �豸��ϵ��
	char                                dev_MaintainerPh[DPSDK_CORE_USER_NAME_LEN]; // �豸��ϵ�˺���
	char                                dev_Location[DPSDK_CORE_POS_NAME_LEN];      // �豸����λ��
	char                                desc[DPSDK_CORE_OPT_NOTE_LEN];              // �豸���� 
	int									nEncChannelChildCount;						// ������ͨ������
	int									iAlarmInChannelcount;						// ��������ͨ������
	int									nSort;									    // ��֯����
	char								szCallNum[DPSDK_CORE_IP_LEN];				// �豸���к���
}Device_Info_Ex_t; 
#endif

// ����ͨ����Ϣ
typedef struct tagEncChannelInfo 
{
	dpsdk_camera_type_e	                nCameraType;		                        // ���ͣ��μ�CameraType_e
	char								szId[DPSDK_CORE_DEV_ID_LEN];				// ͨ��ID:�豸ID+ͨ����
	char								szName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];	// ����
	int									nSort;										// ��֯����
}Enc_Channel_Info_t; 

// ��̨�豸ͨ����Ϣ
typedef struct tagPtzChannelInfo 
{
	INOUT char                          szCameralID[DPSDK_CORE_CHL_ID_LEN];         // �豸ID
	OUT   bool                          bResult;                                        // ��ͨ�����Ƿ��ĳɹ�
}Ptz_Channel_Info_t; 

// ����ͨ����Ϣ ��չ
typedef struct tagEncChannelInfoEx 
{
	dpsdk_camera_type_e	                nCameraType;		                        // ���ͣ��μ�CameraType_e
	char								szId[DPSDK_CORE_LEN*4];				// ͨ��ID:�豸ID+ͨ����
	char								szName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];	// ����
	uint64_t                            nRight;                                     // Ȩ����Ϣ
	int                                 nChnlType;                                  // ͨ������
	int                                 nStatus;
	char                                szChnlSN[DPSDK_CORE_LEN*4];			// ��������SN
    char                                szLatitude[DPSDK_CORE_LEN*4];		// γ��
	char                                szLongitude[DPSDK_CORE_LEN*4];		// ����
	char                                szMulticastIp[DPSDK_CORE_IP_LEN];		// �鲥IP
	int                                 nMulticastPort;		// �鲥�˿�
}Enc_Channel_Info_Ex_t;
// �ּ�������֯������Ϣ
typedef struct tagLoadDepInfo 
{
	IN char								szCoding[DPSDK_CORE_DGROUP_DGPCODE_LEN];	// �ڵ�code
	IN dpsdk_getgroup_operation_e		nOperation;									// ��ȡ�ڵ�����
}Load_Dep_Info_t; 

// ��ȡ��֯����������Ϣ
typedef struct tagGetDepCountInfo 
{
	IN char								szCoding[DPSDK_CORE_DGROUP_DGPCODE_LEN];	// �ڵ�code
	OUT uint32_t						nDepCount;									// ��֯����
	OUT uint32_t						nDeviceCount;								// �豸����
	OUT uint32_t                        nChannelCount;                              //ͨ������
}Get_Dep_Count_Info_t; 

// ��ȡ��֯������Ϣ
typedef struct tagGetDepInfo 
{
	IN char								szCoding[DPSDK_CORE_DGROUP_DGPCODE_LEN];	// �ڵ�code
	IN uint32_t							nDepCount;									// ��֯����
	OUT Dep_Info_t*						pDepInfo;									// ��֯��Ϣ�����ⲿ���������ΪNULL��ֻ���ظ���
	IN uint32_t							nDeviceCount;								// �豸����
	OUT Device_Info_Ex_t*				pDeviceInfo;								// �豸��Ϣ
}Get_Dep_Info_t; 

// ��ȡ��֯������Ϣ
typedef struct tagGetDepInfoEx 
{
	IN char								szCoding[DPSDK_CORE_DGROUP_DGPCODE_LEN];	// �ڵ�code
	INOUT uint32_t						nDepCount;									// ��֯����
	OUT Dep_Info_t*						pDepInfo;									// ��֯��Ϣ�����ⲿ���������ΪNULL��ֻ���ظ���
	INOUT uint32_t						nDeviceCount;								// �豸����
	OUT Device_Info_Ex_t*				pDeviceInfo;								// �豸��Ϣ
	INOUT uint32_t						nChannelCount;                              // ͨ������
	OUT Enc_Channel_Info_Ex_t*			pEncChannelnfo;								// ͨ����Ϣ
}Get_Dep_Info_Ex_t;

//���ӵ�ͼ����������Ϣ
typedef struct tagConfigEmapAddrInfo
{
	OUT char			                szIP[DPSDK_CORE_IP_LEN];		            // ���ӵ�ͼ����IP��ַ
	OUT int								nPort;										// ���ӵ�ͼ����˿ں�
}Config_Emap_Addr_Info_t;

// ��ȡ����ͨ��������Ϣ
typedef struct tagGetChannelInfo 
{
	IN char								szDeviceId[DPSDK_CORE_DEV_ID_LEN];			// �豸ID
	IN uint32_t							nEncChannelChildCount;						// ͨ������
	OUT Enc_Channel_Info_t*				pEncChannelnfo;								// ͨ����Ϣ
}Get_Channel_Info_t;

// ��ȡ����ͨ��������Ϣ
typedef struct tagGetDepChannelInfo 
{
	IN char								szCoding[DPSDK_CORE_DGROUP_DGPCODE_LEN];	// �ڵ�code
	IN uint32_t							nEncChannelChildCount;						// ͨ������
	OUT Enc_Channel_Info_t*				pEncChannelnfo;								// ͨ����Ϣ
}Get_Dep_Channel_Info_t;

// ��ȡͨ��������Ϣ
typedef struct tagGetChannelInfoEx 
{
	IN char								szDeviceId[DPSDK_CORE_DEV_ID_LEN];			// �豸ID
	IN uint32_t							nEncChannelChildCount;						// ͨ������
	OUT Enc_Channel_Info_Ex_t*			pEncChannelnfo;								// ͨ����Ϣ
}Get_Channel_Info_Ex_t;

// ��ȡ�豸֧����������
typedef struct tagGetDevStreamTypeInfo
{
	IN char								szDeviceId[DPSDK_CORE_DEV_ID_LEN];			// �豸ID
	IN int								nUnitNo;									// ��Ԫ���
	OUT dpsdk_stream_type_e				nStreamType;								// ֧�ֵ���������
}Get_Dev_StreamType_Info_t;

// ��ȡ������Ϣ
typedef struct tagGetRealStreamInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	dpsdk_check_right_e					nRight;										// �Ƿ���Ȩ��
	dpsdk_stream_type_e					nStreamType;								// ��������
	dpsdk_media_type_e					nMediaType;									// ý������
	dpsdk_trans_type_e					nTransType;									// ��������
}Get_RealStream_Info_t;

// ��Ƶ֡��Ϣ
typedef struct tagFrameInfo
{
	long                                nWidth;			                            // ͼ���ȣ���λpixel����ƵĬ��Ϊ0
	long                                nHeight;                                    // ͼ��߶ȣ���λpixel����ƵĬ��Ϊ0
	long                                nStamp;			                            // ʱ����Ϣ����λms
	long                                nType;				                        // �������ͣ�T_IYUV, T_YV12, Please refer to the macro definition.
	long                                nFrameRate;		                            // ͼ��֡λ�� Image frame bit when encoding.
}Frame_Info;

// ��ȡ������Ϣ
typedef struct tagGetTalkStreamInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// �豸ID��ͨ��ID
	dpsdk_audio_type_e                  nAudioType;                                 // ��Ƶ����		  
    dpsdk_talk_type_e                   nTalkType;                                  // �豸���ͣ�ͨ�����豸��
	dpsdk_talk_bits_e					nBitsType;								    // λ��
	Talk_Sample_Rate_e					nSampleType;								// ����������
	dpsdk_trans_type_e					nTransType;									// ��������
}Get_TalkStream_Info_t;


// ����������Ϣ
typedef struct tagGetCallStreamInfo
{
	dpsdk_call_type_e					nCallType;									//��������
	char								szSendChnlId[DPSDK_CORE_CHL_ID_LEN];		//����ͨ��
	char								szRecvChnlId[DPSDK_CORE_CHL_ID_LEN];		//����ͨ��
	char								szRtpServIP[DPSDK_CORE_IP_LEN];				//TRP����IP
	int									nRtpPort;									//TRP����˿�
	int									nCallID;									//����ID
	int									nDlgID;										//�ỰID
	int									nTid;										//T ID
}Get_InviteCall_Info_t;

// 
typedef struct tagAudioUserParam
{
	void*                                objectPoint;								// ��Ƶ¼����ȡ�û�����

	tagAudioUserParam(void)
	{
		objectPoint = NULL;
	}
}AudioUserParam_t;

// ����¼����Ϣ
typedef struct tagSingleRecordInfo
{
	uint32_t							nFileIndex;									// �ļ�����
	dpsdk_recsource_type_e				nSource;									// ¼��Դ����
	dpsdk_record_type_e					nRecordType;								// ¼������
	uint64_t							uBeginTime;									// ��ʼʱ��
	uint64_t							uEndTime;									// ����ʱ��
	uint64_t							uLength;									// �ļ���С
}Single_Record_Info_t;

// ¼����Ϣ
typedef struct tagRecordInfo
{
	IN char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	IN uint32_t							nBegin;										// ¼����ʼ
	IN uint32_t							nCount;										// ����¼����
	OUT uint32_t						nRetCount;									// ʵ�ʷ��ظ���
	OUT Single_Record_Info_t*			pSingleRecord;								// ¼���¼��Ϣ
}Record_Info_t;

// ���ļ���ȡ¼��������Ϣ
typedef struct tagGetRecordStreamFileInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	dpsdk_check_right_e					nRight;										// �Ƿ���Ȩ��
	dpsdk_pb_mode_e						nMode;										// ¼������������
	
	uint32_t							nFileIndex;									// �ļ�����
	uint64_t							uBeginTime;									// ������ʼ
	uint64_t							uEndTime;									// ���Ž���
}Get_RecordStream_File_Info_t;

// ��ʱ���ȡ¼��������Ϣ
typedef struct tagGetRecordStreamTimeInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	dpsdk_check_right_e					nRight;										// �Ƿ���Ȩ��
	dpsdk_pb_mode_e						nMode;										// ¼������������

	dpsdk_recsource_type_e				nSource;									// ¼��Դ����                  
	uint64_t							uBeginTime;									// ��ʼʱ�� 
	uint64_t							uEndTime;									// ����ʱ��
}Get_RecordStream_Time_Info_t;

// �������ļ�����¼��
typedef struct tagGetRecordLocalInfo
{
	char								szFilePath[DPSDK_CORE_FILEPATH_LEN];		// �ļ�·��
}Get_Record_Local_Info_t;

// ��ѯ¼����Ϣ
typedef struct tagQueryRecordInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	dpsdk_check_right_e					nRight;										// �Ƿ���Ȩ��
	dpsdk_recsource_type_e				nSource;									// ¼��Դ����
	dpsdk_record_type_e					nRecordType;								// ¼������
	uint64_t							uBeginTime;									// ��ʼʱ��
	uint64_t							uEndTime; 									// ����ʱ��
}Query_Record_Info_t;

// ��̨���������Ϣ
typedef struct tagPtzDirectInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	dpsdk_ptz_direct_e					nDirect;									// ��̨�����������
	uint32_t							nStep;										// ����	
	bool								bStop;										// �������ֹͣ��true�����ƣ�false
}Ptz_Direct_Info_t;

// ��̨���������Ϣ
typedef struct tagPtzOperationInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	dpsdk_camera_operation_e			nOperation;									// ��̨������Ʋ���
	uint32_t							nStep;										// ����	
	bool								bStop;										// �������ֹͣ��true�����ƣ�false
}Ptz_Operation_Info_t;

// ��̨��ά��λ������Ϣ
typedef struct tagPtzSitInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	int32_t							pointX;										// ����ֵX
	int32_t							pointY;										// ����ֵY
	int32_t							pointZ;										// ����ֵZ	
	int32_t                         type;                                       // 1--���ٶ�λ, 2--��ȷ��λ
}Ptz_Sit_Info_t;

// ��̨����������Ϣ
typedef struct tagPtzLockInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	dpsdk_ptz_locktype_e				nLock;										// ����/��������
}Ptz_Lock_Info_t;

// ��̨��������Ϣ Ŀǰ�����ƹ� ��ˢ ����
typedef struct tagPtzOpenCommandInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	bool								bOpen;										// ����
}Ptz_Open_Command_Info_t;

//��̨��λ������Ϣ
typedef struct tagPtzSitAlarmInfo
{
	char                                szDevId[DPSDK_CORE_CHL_ID_LEN];             // �豸ID
	int                                 nChannelID;                                 // ͨ���� 
	int                                 nPTZPan;                                    // ��̨ˮƽ�˶�λ�ã���Ч��Χ��[0,3600] 
	int                                 nPTZTilt;                                   // ��̨��ֱ�˶�λ�ã���Ч��Χ��[-1800,1800] 
	int                                 nPTZZoom;                                   // ��̨��Ȧ�䶯λ�ã���Ч��Χ��[0,128] 
	uint8_t                             bState;                                     // ��̨�˶�״̬, 0-δ֪1-�˶�2-���� 
	uint8_t                             bAction;                                    // ��̨������-Ԥ�õ㣬-��ɨ��-Ѳ����-Ѳ����-ˮƽ��ת 
	uint8_t                             bFocusState;                                // ��̨�۽�״̬, 0-δ֪, 1-�˶�״̬, 2-���� 
	uint8_t                             bEffectiveInTimeSection;                    // ��ʱ�����Ԥ�õ�״̬�Ƿ���Ч 	//�����ǰ�ϱ���Ԥ�õ���ʱ����ڵ�Ԥ�õ㣬��Ϊ���������Ϊ 
	int                                 nPtzActionID;                               // Ѳ��ID�� 
	uint32_t                            dwPresetID;                                 // ��̨����Ԥ�õ��� 
	float                               fFocusPosition;                             // �۽�λ�� 
	uint8_t                             bZoomState;                                 // ��̨ZOOM״̬��-δ֪��-ZOOM��-���� 
}Ptz_Sit_Alarm_Info;

// ��Ƶͼ������
typedef struct tagVideoColorInfo
{
	int32_t								nBrightness;								// ����,Ĭ��64;��Χ0-128
	int32_t								nContrast;									// �Աȶ�,Ĭ��64;��Χ0-128
	int32_t								nSaturation;								// ���Ͷ�,Ĭ��64;��Χ0-128
	int32_t								nHue;										// ɫ��,Ĭ��64;��Χ0-128
}Video_Color_Info_t;

// ��ȡʵʱ��URL��Ϣ
typedef struct tagGetRealStreamUrlInfo
{
	IN char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	IN dpsdk_stream_type_e				nStreamType;								// ��������
	IN dpsdk_media_type_e				nMediaType;									// ý������
	IN dpsdk_trans_type_e				nTransType;									// ��������
	OUT char							szUrl[DPSDK_TAG_URL_LEN];					// URL��Ϣ
}Get_RealStreamUrl_Info_t;

//��ȡ����ý����URL��Ϣ
typedef struct tagGetExternalRealStreamUrlInfo
{
	IN char			                    szCameraId[DPSDK_CORE_CHL_ID_LEN];		    // ͨ��ID
	IN dpsdk_stream_type_e	            nStreamType;					            // ��������
	IN dpsdk_media_type_e	            nMediaType;						            // ý������
	IN dpsdk_trans_type_e	            nTransType;						            // ��������
	IN dpsdk_trackid_type_e             nTrackId;                                   // ���ID
	IN bool                             bUsedVCS;                                   // ��ҪVCSת��
	IN dpsdk_videocodec_type_e          nVcsVideocodec;                             // ����ת������Ƶ�����ʽ, bUsedVCSΪ1��Ч
	IN dpsdk_resolution_type_e          nVcsResolution;                             // ��������Ƶ�ֱ��ʣ�bUsedVCSΪ1��Ч
	IN uint32_t                         nVcsfps;                                    // ������֡�ʣ�bUsedVCSΪ1��Ч
	IN uint32_t                         nVcsbps;                                    // ���������ʣ�bUsedVCSΪ1��Ч
	OUT char			                szUrl[DPSDK_TAG_URL_LEN];		            // URL��Ϣ
}Get_ExternalRealStreamUrl_Info_t;

// ����Ԥ�õ���Ϣ
typedef struct tagPtzSinglePrepointInfo
{
	uint32_t							nCode;										// Ԥ�õ���
	char								szName[DPSDK_CORE_POINT_NAME_LEN];			// ����
}Ptz_Single_Prepoint_Info_t;

// ����Ԥ�õ�ʱ����Ϣ
typedef struct tagTimePtzSinglePrepointInfo
{
	uint32_t							nCode;										// Ԥ�õ���
	char								szName[DPSDK_CORE_POINT_NAME_LEN];			// ����
	char					    	    szBeginTime[DPSDK_CORE_POINT_TIME_LEN];	    // ��ʼʱ��
	char					    	    szEndTime[DPSDK_CORE_POINT_TIME_LEN];	    // ����ʱ��
}Ptz_Single_Time_Prepoint_Info_t;


// ��̨Ԥ�õ���Ϣ
typedef struct tagPtzPrepointInfo
{
	IN  char							szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	OUT uint32_t						nCount;										// Ԥ�õ�����
	OUT Ptz_Single_Prepoint_Info_t		pPoints[DPSDK_CORE_POINT_COUNT];			// Ԥ�õ���Ϣ
}Ptz_Prepoint_Info_t;

// ʱ�������̨Ԥ�õ���Ϣ
typedef struct tagPtzTimePrepointInfo
{
	IN  char							szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	OUT uint32_t						nCount;										// Ԥ�õ�����
	OUT Ptz_Single_Time_Prepoint_Info_t	pPoints[DPSDK_CORE_POINT_COUNT];			// Ԥ�õ���Ϣ
}Ptz_Time_Prepoint_Info_t;

// ��̨Ԥ�õ������Ϣ
typedef struct tagPtzPrepointOperationInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	dpsdk_ptz_prepoint_cmd_e			nCmd;										// Ԥ�õ��������
	Ptz_Single_Prepoint_Info_t			pPoints;									// Ԥ�õ���Ϣ
}Ptz_Prepoint_Operation_Info_t;

// ��ʱ��̨������Ϣ
typedef struct tagPtzTimeTaskInfotInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	char                         		szBuf[DPSDK_CORE_TASK_LEN];					// Ԥ�õ���Ϣ
}Ptz_Time_Task_Info_t;

// ��ʱ�����Ϣ����̨Ԥ�õ������Ϣ
typedef struct tagPtzTimePrepointOperationInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	dpsdk_ptz_prepoint_cmd_e			nCmd;										// Ԥ�õ��������
	Ptz_Single_Time_Prepoint_Info_t		pPoints;									// Ԥ�õ���Ϣ
}Ptz_Time_Prepoint_Operation_Info_t;

// ��ʱ�����Ϣ����̨Ԥ�õ���Ϣ
typedef struct tagPrepointTime
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	Ptz_Single_Time_Prepoint_Info_t		pPoints;									// Ԥ�õ���Ϣ
}Ptz_Prepoint_Time_t;

// ��̨��չ������Ϣ
typedef struct tagPtzExtendCommandInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	dpsdk_ptz_extend_cmd_e				nCmd;										// ��չ����
	int32_t								nParam;										// ����
}Ptz_Extend_Command_Info_t;

// �����̨������Ϣ
typedef struct tagPtzParamInfo
{
	int									nPositionX;							// ��̨ˮƽ�˶�λ��,��Ч��Χ��[0,3600]
	int									nPositionY;							// ��̨��ֱ�˶�λ��,��Ч��Χ��[-1800,1800]
	int									nPositionZoom;						// ��̨��Ȧ�䶯λ��,��Ч��Χ��[0,128]
	double								fSpeedPositionX;					// ��̨ˮƽ��������,��һ����-1~1			
	double								fSpeedPositionY;					// ��̨��ֱ��������,��һ����-1~1
	double								fSpeedZoom;							// ��̨��Ȧ�Ŵ���,��һ����0~1
}Ptz_Param_t;

// �����������Ϣ
typedef struct tagChannelViewInfo
{
	int		   nDistance;						   // ���Ӿ���, ��λ:�� 
	int        nAngelH;                            // ˮƽ���ӽǶ�, 0~1800, ��λ:ʮ��֮һ�� 
	int        nAzimuthH;                          // ˮƽ��λ�Ƕ�, 0~3600, ��λ:ʮ��֮һ�� 
	int        nInclinationH;                      // ˮƽ��б�Ƕ�, -900~900, ��λ:ʮ��֮һ��
}Channel_View_Info_t;

// ��ȡ�ϱ���������Ϣ
typedef struct tagGetPeopleCount
{
	IN  char						    szBeginTime[DPSDK_CORE_TIME_LENGTH];		// ��ʼʱ��             
	IN  char						    szEndTime[DPSDK_CORE_TIME_LENGTH];			// ����ʱ��
	OUT uint32_t						nEnterCount;								// ��������
	OUT uint32_t						nExitCount;									// ��ȥ����
}Get_People_Count_t;

// ������������
typedef struct tagAlarmSingleEnableInfo
{
	char								szAlarmDevId[DPSDK_CORE_DEV_ID_LEN];		// �����豸ID
	int32_t								nVideoNo;									// ��Ƶͨ�� ��Ƶ��صı��� -1��������ͨ��
	int32_t								nAlarmInput;								// ��������ͨ�� ����������صı��� -1��������ͨ��
	dpsdk_alarm_type_e					nAlarmType;									// ��������
}Alarm_Single_Enable_Info_t;

// ��������
typedef struct tagAlarmEnableInfo
{
	uint32_t							nCount;										// �������ظ���
	Alarm_Single_Enable_Info_t*			pSources;									// ��������
}Alarm_Enable_Info_t;

// ������������(����������������豸���ñ���)
typedef struct tagAlarmSingleEnableByDepInfo
{
	char								szAlarmDepartmentCode[DPSDK_CORE_DEV_ID_LEN];	// �����豸��������
	int32_t								nVideoNo;									    // ��Ƶͨ�� ��Ƶ��صı��� -1��������ͨ��
	int32_t								nAlarmInput;								    // ��������ͨ�� ����������صı��� -1��������ͨ��
	dpsdk_alarm_type_e					nAlarmType;									    // ��������
}Alarm_Single_Enable_By_Dep_Info_t;

// ��������(����������������豸���ñ���)
typedef struct tagAlarmEnableByDepInfo
{
	uint32_t							nCount;										// �������ظ���
	Alarm_Single_Enable_By_Dep_Info_t*	pSources;							        // ��������
}Alarm_Enable_By_Dep_Info_t;

// ��ѯ������Ϣ
typedef struct tagAlarmQueryInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	uint64_t							uStartTime;									// ��ʼʱ��
	uint64_t							uEndTime;									// ����ʱ��
	dpsdk_alarm_type_e					nAlarmType;									// ��������
}Alarm_Query_Info_t;

// ����������Ϣ
typedef struct tagSingleAlarmInfo
{
	dpsdk_alarm_type_e					nAlarmType;									// ��������
	dpsdk_event_type_e					nEventType;									// �¼�״̬
	char								szDevId[DPSDK_CORE_DEV_ID_LEN];				// �����豸ID
	uint32_t							uChannel;									// ����ͨ��
	uint64_t							uAlarmTime;									// ����ʱ��
	dpsdk_alarm_dealwith_e				nDealWith;									// �������
	char								szPicUrl[DPSDK_CORE_IMG_PATH_LEN];			// ����ͼƬurl
	char								szSwLabel[DPSDK_CORE_RFID_LABEL];			// ������̽���ǩ
	char								szElecLabel[DPSDK_CORE_RFID_LABEL];			// ���õ��ӱ�ǩ
}Single_Alarm_Info_t;

// ������Ϣ
typedef struct tagAlarmInfo
{
	IN uint32_t							nCount;										// ����¼����
	OUT uint32_t						nRetCount;									// ʵ�ʷ��ظ���
	OUT Single_Alarm_Info_t*			pAlarmInfo;									// ������Ϣ
}Alarm_Info_t;

// �ͻ��˱����ϱ���Ϣ
typedef struct tagClientAlarmInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ����ͨ��ID
	dpsdk_alarm_type_e					enAlarmType;								// ��������
	dpsdk_event_type_e					enStatus;									// �¼�״̬
	uint64_t							uAlarmTime;									// ����ʱ��
	char								szMsg[DPSDK_CORE_ALARM_MSG_LEN];			// ������Ϣ
}Client_Alarm_Info_t;


// ��������ǽ��Ϣ
typedef struct tagTvWallInfo
{
	uint32_t							nTvWallId;									// ����ǽID
	uint32_t							nState;										// ����״̬
	char								szName[DPSDK_CORE_TVWALL_NAME_LEN];			// ����
}TvWall_Info_t;

// ����ǽ�б���Ϣ
typedef struct tagTvWallListInfo
{
	IN	uint32_t						nCount;										// ����ǽ����
	OUT	TvWall_Info_t*					pTvWallInfo;								// ����ǽ��Ϣ
}TvWall_List_Info_t;

// ����ǽ����Ϣ
typedef struct tagTvWallScreenInfo
{
	uint32_t							nScreenId;									// ��ID
	char								szName[DPSDK_CORE_TVWALL_NAME_LEN];			// ����
	char								szDecoderId[DPSDK_CORE_DEV_ID_LEN];			// ������ID
	float								fLeft;										// ��߾�
	float								fTop;										// �ϱ߾�
	float								fWidth;										// ���
	float								fHeight;									// �߶�
	bool								bBind;										// �Ƿ�󶨽�����
	bool								bCombine;									// �Ƿ��ں���
}TvWall_Screen_Info_t;

// ����ǽ������Ϣ
typedef struct tagTvWallLayoutInfo
{
	IN	uint32_t						nTvWallId;									// ����ǽID
	IN	uint32_t						nCount;										// ������
	OUT	TvWall_Screen_Info_t*			pScreenInfo;								// ����Ϣ
}TvWall_Layout_Info_t;


// ����ǽ���ָ�ָ�󴰿�ID��0��ʼ�������ң����ϵ������ε�����ʹ�����Լ�ά����
typedef struct tagTvWallScreenSplit
{
	IN	uint32_t						nTvWallId;									// ����ǽID
	IN	uint32_t						nScreenId;									// ��ID
	IN	tvwall_screen_split_caps		enSplitNum;									// �ָ�����
}TvWall_Screen_Split_t;

// ����ǽ��������Ϣ
typedef struct tagTvWallScreenOpenWindow
{
	IN	uint32_t						nTvWallId;									// ����ǽID
	IN	uint32_t						nScreenId;									// ��ID
	IN	float							fLeft;										// ������߾�
	IN	float							fTop;										// �����ϱ߾�
	IN	float							fWidth;										// ���ڿ��
	IN	float							fHeight;									// ���ڸ߶�

	OUT	uint32_t						nWindowId;									// ����ID
	OUT	uint32_t						nZorder;									// ����Z��
}TvWall_Screen_Open_Window_t;

// ����ǽ�������ƶ�
typedef struct tagTvWallScreenMoveWindow
{
	IN	uint32_t						nTvWallId;									// ����ǽID
	IN	uint32_t						nScreenId;									// ��ID
	IN	uint32_t						nWindowId;									// ����ID
	IN	float							fLeft;										// ������߾�
	IN	float							fTop;										// �����ϱ߾�
	IN	float							fWidth;										// ���ڿ��
	IN	float							fHeight;									// ���ڸ߶�
}TvWall_Screen_Move_Window_t;

// ����ǽ���ش���Ϣ
typedef struct tagTvWallScreenCloseWindow
{
	IN	uint32_t						nTvWallId;									// ����ǽID
	IN	uint32_t						nScreenId;									// ��ID
	IN	uint32_t						nWindowId;									// ����ID
}TvWall_Screen_Close_Window_t;

// ����ǽ�������ö�
typedef struct tagTvWallScreenSetTopWindow
{
	IN	uint32_t						nTvWallId;									// ����ǽID
	IN	uint32_t						nScreenId;									// ��ID
	IN	uint32_t						nWindowId;									// ����ID
}TvWall_Screen_Set_Top_Window_t;

// ����ǽ������������ƵԴ
typedef struct tagSetTvWallScreenWindowSource
{
	IN	uint32_t						nTvWallId;									// ����ǽID
	IN	uint32_t						nScreenId;									// ��ID
	IN	uint32_t						nWindowId;									// ����ID
	IN	char							szCameraId[DPSDK_CORE_CHL_ID_LEN];			// ͨ��ID
	IN	dpsdk_stream_type_e				enStreamType;								// ��������
	IN	uint64_t						nStayTime;									// ͣ��ʱ��
}Set_TvWall_Screen_Window_Source_t;

// ����ǽ�����ڹر���ƵԴ
typedef struct tagTvWallScreenCloseSource
{
	IN	uint32_t						nTvWallId;									// ����ǽID
	IN	uint32_t						nScreenId;									// ��ID
	IN	uint32_t						nWindowId;									// ����ID(������ID=-1���ʾ�رո��������д��ڵ���ƵԴ)
}TvWall_Screen_Close_Source_t;

//����������Ŀ�������Ƿ�Ϊ���л���
typedef struct tagPicInPicInfo
{
	int							        nScreenID;								    //��ID
	float						        fLeftPercent;								//������ 0~1֮���ֵ
	float						        fTopPercent;								//������ 0~1֮���ֵ
	float						        fRightPercent;								//������ 0~1֮���ֵ ��>��
	float						        fBottomPercent;								//������ 0~1֮���ֵ ��>��
	int							        nBigChnNum;									//�󴰿ں� ��ֵ��ȡֵ��ΧΪ����1��0~15����2��16~19����3��20~23����4��24~27��
	int							        nSmallChnNum;								//С���ں� ��ֵ��ȡֵ��ΧΪ����1��0~15����2��16~19����3��20~23����4��24~27��
	dpsdk_tvwall_pip_e                  enPIP;										//�Ƿ���û��л�����               
}Pic_In_Pic_Info_t;

//����������Ŀ���л���ǽ���Ʋ���
typedef struct tagPipTvWallScreenInfo
{
	IN	uint32_t						nTvWallId;									// ����ǽID

	IN	Pic_In_Pic_Info_t				picInPicInfo[DPSDK_PIP_SCREEN_NUM];			//���л���ǽ��Ϣ
}Pip_TvWall_Screen_Info_t;

typedef struct tagTvWallSubTvInfo
{
	uint32_t							nTvWallId;
	uint32_t							nScreenId;
}TvWall_SubTv_Info_t;

// Υ�±������ݽṹ��Ϣ
typedef struct tagTrafficAlarmInfo
{
	char			                    szCameraId[DPSDK_CORE_CHL_ID_LEN];		    // ͨ��ID
	char			                    nPtsIp[DPSDK_CORE_BAY_IP_LEN];				// pts����
	char			                    nPtsIpy[DPSDK_CORE_BAY_IP_LEN];		        // pts����
	int32_t				                nPicPort;								    // pic����port
	int32_t				                nPicPorty;								    // pic����port
	dpsdk_alarm_type_e	                type;								        // Υ������
	char			                    szCarNum[DPSDK_CORE_CAR_NUM_LENGTH];		// ����
	int32_t				                nLicentype;							        // ������ɫ����
	int32_t				                nCarColor;								    // ������ɫ
	int32_t				                nCarLogo;								    // ��������
	int32_t				                nWay;									    // ������
	char			                    szPicUrl[DPSDK_CORE_BAY_IMG_NUM][DPSDK_CORE_BAY_URL_LEN];	// ͼƬURL
	uint32_t		                    nPicGroupStoreID;						    // ͼƬ��洢ID
	int32_t				                bNeedStore;									// �Ƿ������ 0��������� 1�������
	int32_t				                bStored;									// �Ƿ��Ѵ��� 0��δ���� 1���Ѵ���int	
	int32_t				                nAlarmLevel;								// ��������
	int32_t				                nAlarmTime;                                 // ��������ʱ��,����Ϊ�룬ֵΪtime(NULL)ֵ

	//�����ֶ�
	int32_t								nChannel;                                  // ͨ��
	char								szDeviceId[DPSDK_CORE_DEV_ID_LEN];         // �豸ID
	char								szDeviceName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];// �豸���� 
	char								szDeviceChnName[DPSDK_CORE_DGROUP_CHNNAME_LEN]; // ͨ������
	int32_t								nCarType;                                  // ������
	int32_t								nCarSpeed;                                 // ����
	int32_t								nCarLen;                                   // �����ȵ�λ
	int32_t								nCardirect;                                // �г�����
	int32_t								nMaxSpeed;                                 // �����ٶ�
	int32_t								nMinSpeed;                                 // ��������ٶ�
	int32_t								nRtPlate[DPSDK_CORE_COORDINATE_LEN];       // ��������
}Traffic_Alarm_Info_t;

// ��ͨ�����ϱ����ݽṹ��Ϣ
typedef struct tagTrafficFlowInfo
{
	char                                szChannelId[DPSDK_CORE_CHL_ID_LEN];	        // ͨ�����
	char                                szDirect[DPSDK_CORE_DIRECT_LEN];            // �����ţ����ֵ��
	uint16_t                            nInterval;                                  // �ϱ��������λ��
	uint16_t                            nTrafficFlow;		                        // ��ͨ�������������豸���յ����������ݣ�Υ��Ҳ�������ڣ�	
	uint64_t                            nTime;                                      // �ϱ�ʱ�䣬1970������
}TrafficFlow_Info_t;

// ÿ��������ͨ����״̬
typedef struct tagTrafficFlowLaneState
{
	uint64_t                            nDateTime;                                   // �����ϱ�ʱ�� UTCʱ��
	uint32_t                            nDetectorID;                                 // ��⳵�����
	uint32_t                            nVolume;                                     // ��ͨ������/��λʱ�䣩С������
	uint32_t                            nFlowRate;                                   // ���ʣ���/Сʱ��С������
	float                               nAverageSpeed;                               // ƽ���ٶȣ�����/Сʱ��
	float                               fTimeOccupancy;                              // ƽ��ʱ��ռ���ʣ�%��
	float                               nTimeHeadway;                                // ��ͷʱ�ࣨ�룩
	float                               nLength;                                     // ƽ���������ף�
	float                               nBackOfQueue;                                // �Ŷӳ��ȣ��ף�
	float                               nTravelTime;                                 // ����ʱ�䣨�룩
	float                               nDelay;                                      // �����룩��##
	uint32_t                            nMotoVehicles;                               // ΢�ͳ���ͨ������/��λʱ�䣩
	uint32_t                            nSmallVehicles;                              // С����ͨ������/��λʱ�䣩
	uint32_t                            nMediumVehicles;                             // �г���ͨ������/��λʱ�䣩
	uint32_t                            nLargeVehicles;                              // �󳵽�ͨ������/��λʱ�䣩
	uint32_t                            nLongVehicles;                               // �ش󳵽�ͨ������/��λʱ�䣩
	uint32_t                            nState;                                      // ״ֵ̬��1-��������,2-��������ָ�,3-����,4-������С,5-������С�ָ�
	uint32_t                            nFlow;                                       // ����ֵ����λ����
	uint32_t                            nPeriod;                                     // ����ֵ��Ӧ��ͳ��ʱ��
	uint32_t                            nDrivingDir;                                 // ��ʻ�����������С����У����������豸�����Խ��Խ�� /���У����������豸�����Խ��ԽԶ
	int32_t                             nDirection;                                  // ��������
	int32_t                             nPeriodBySeconds;                            //����Ϊ��λ������
}TrafficFlow_Lane_State;


// �豸��ͨ�����ϱ���ϸ��Ϣ���ݽṹ
typedef struct tagDevTrafficFlowInfo
{
	char                                szChannelId[DPSDK_CORE_CHL_ID_LEN];          // ͨ�����
	char                                szDirect[DPSDK_CORE_DIRECT_LEN];             // �����ţ����ֵ��
	uint16_t                            nTrafficLaneNum;                             // ��ͨ��������
	TrafficFlow_Lane_State              LaneState[DH_MAX_CORE_LANE_NUM];             // ������ͨ����״̬,���֧��8������
}DevTrafficFlow_Info_t;

//���������ϱ�������Ϣ
typedef struct tagSubscribeTrafficFlowInfo
{   
	int32_t                             nChnlCount;                                  // ����ͨ��������
	int32_t                             nInterval;                                   // ����ͨ���ϱ��������λ��
	Enc_Channel_Info_t*                 pEncChannelnfo;                              // ͨ����Ϣ
	int32_t                             nSubscribeFlag;                              // ���ı�ǡ�0:ȡ�����ģ�1������
}Subscribe_Traffic_Flow_Info_t;

//������̨״̬������Ϣ
typedef struct tagSubscribePtzSitAlarmInfo
{
	int32_t                             nChnlCount;                                 //����ͨ��������
	Ptz_Channel_Info_t*                 pPtzChannelnfo;                             // ͨ����Ϣ
	int32_t                             nSubscribeFlag;                             //���ı�ǡ�0:ȡ�����ģ�1������
}Subscribe_Ptz_SitAlarmInfo_t;

// ����Υ��ͼƬ��Ϣ
typedef struct tagTrafficViolationInfo
{
	char                                szRecordId[DPSDK_CORE_CAR_RECORD_ID_LEN];    // ��¼ID
	char	                            szDeviceId[DPSDK_CORE_DEV_ID_LEN];		     // �豸ID
	int32_t		                        nChannel;					                 // ͨ��
	char                                szChannelId[DPSDK_CORE_CHL_ID_LEN];     	 // ͨ�����
	int32_t	                            ntype;						                 // Υ�±������� ��EnumCarRule ö�ٶ���	
	char	                            szDeviceName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];	// �豸����,UTF8����
	char	                            szDeviceChnName[DPSDK_CORE_DGROUP_CHNNAME_LEN];	// ͨ������,UTF8����	
	char	                            szCarNum[DPSDK_CORE_CAR_NUM_LENGTH];		 // ���ƺ��룬UTF8����
	int32_t		                        nCarNumType;				                 // ��������
	int32_t		                        nCarNumColor;				                 // ������ɫ
	int32_t	                    	    nCarColor;					                 // ������ɫ
	int32_t                             nCarType;					                 // ������
	int32_t		                        nCarLogo;					                 // ��������
	int32_t		                        nWay;						                 // ������
	int32_t		                        nCarSpeed;					                 // ����
	int32_t		                        nCarLen;					                 // �����ȣ���λcm,���ܳ���4λ
	int32_t		                        nCardirect;					                 // �г�����
	int32_t		                        nMaxSpeed;					                 // �����ٶ�,���ڳ����ж�
	int32_t		                        nMinSpeed;					                 // ��������ٶ�,���ڳ����ж�
	char   	                            szCapturedate[DPSDK_CORE_TIME_LEN];		     // ��ȷ����,�� 2013-09-25 12:04:08
	char	                            szOptNote[DPSDK_CORE_OPT_NOTE_LEN];			 // ��ע��Ϣ
	int32_t                             nPicNum;                                     // ͼƬ���������֧��6��
	char                                szPicName[DPSDK_CORE_BAY_IMG_NUM][DPSDK_CORE_FILEPATH_LEN]; // ͼƬ�ļ����������֧��6�š����Ϊ�գ�����PTS���ɡ�
	int32_t 	                        nRtPlate[DPSDK_CORE_COORDINATE_LEN];	     // ��������,left,top, right, bottom,���ܳ���4λ		
	int32_t                             nDataSource;				                 // ������Դ,���ܳ���2λ
}Traffic_Violation_Info_t;

typedef struct tagDeptAreaRelation
{
	char                                szDeptCode[DPSDK_CORE_ORG_CODE_LEN];         // ���Žڵ����
	char                                szAreaCode[DPSDK_CORE_ORG_CODE_LEN];         // Ͻ���ڵ����
}DeptArea_Relation_t;

typedef struct tagGetDeptAreaRelation
{
	IN  uint32_t						nCount;                                      // ����Ͻ����ϵ��¼��
	OUT DeptArea_Relation_t*			pDeptAreaRelation;				             // ����Ͻ����ϵ�����ⲿ���������ΪNULL��ֻ���ظ���
}Get_DeptArea_Relation_t;

//��ȡ������Ա������Ϣ

typedef struct tagPersonInfo
{    
	IN char                             szCode[DPSDK_CORE_PERSON_CODE_LEN];          // ��Ա����
	IN char                             szName[DPSDK_CORE_PERSON_NAME_LEN];          // ��Ա����
	IN char                             szDeptCode[DPSDK_CORE_PERSON_DEPTCODE_LEN];  // ��Ա�������ű���
	IN char                             szSN[DPSDK_CORE_PERSON_SN_LEN];              // ��ԱΨһ���
	IN char                             szType[DPSDK_CORE_PERSON_TYPE_LEN];          // ��Ա����
	IN char                             szOffice[DPSDK_CORE_PERSON_OFFICE_LEN];      // ��Ա�칫�ص�
	IN char                             szMobileNum[DPSDK_CORE_PERSON_MOBILENUM_LEN];// ��Ա�ƶ��绰
	IN char                             szVirtualNum[DPSDK_CORE_PERSON_VIRTUALNUM_LEN];// ��Ա����̺�
	IN char                             szState[DPSDK_CORE_PERSON_STATE_LEN];        // ��Ա״̬
}Person_Info_t;

typedef struct tagGetPersonInfo
{
	IN char								szDeptCoding[DPSDK_CORE_PERSON_DEPTCODE_LEN];// ����code
	IN uint32_t							nPersonCount;						         // ������Ա����
	OUT Person_Info_t*					pPersonInfo;						         // ��Ա��Ϣ�����ⲿ���������ΪNULL��ֻ���ظ���
}Get_Person_Info_t;

//������Ϣ
typedef struct tagCarInfo 
{
	char	                            szOwenerCode[DPSDK_CORE_DGROUP_DGPCODE_LEN]; // ������֯Code
	char	                            szCode[DPSDK_CORE_CAR_CODE_LEN];	         // ����code
	char                                szColor[DPSDK_CORE_CAR_COLOR_LEN];           // ������ɫ
	char                                szType[DPSDK_CORE_CAR_TYPE_LEN]; 	         // ��������
	char                                szModel[DPSDK_CORE_CAR_MODEL_LEN];	         // ����Ʒ���ͺ�
	int32_t                             nApprovedSeating;	                         // �˶�������
	char                                szSize[DPSDK_CORE_CAR_SIZE_LEN];             // �����ߴ� ��������ߣ���λ������
	char                                szVin[DPSDK_CORE_CAR_VIN_LEN];               // ���ܺ�
	char                                szEngineNo[DPSDK_CORE_ENG_NO_LEN];           // �����
	char                                szPicPath[DPSDK_CORE_CAR_PICPATH_LEN];       // ������Ƭ·�� 255
	char	                            szPlateNo[DPSDK_CORE_CAR_PLATENO_LEN];       // ���ƺ���
	char                                szSecondPlateNo[DPSDK_CORE_CAR_PLATENO_LEN]; // �ڶ����ƺ�
	char	                            szPlateColor[DPSDK_CORE_CAR_PLATECOLOR_LEN]; // ������ɫ
	char	                            szPlateType[DPSDK_CORE_CAR_PLATETYPE_LEN];	 // ��������								                           // ��������
	char                                szPlateRegistered[DPSDK_CORE_REGIST_LEN];    // ����ע���
	char                                szRegisterDate[DPSDK_CORE_REGIST_DATE_LEN];  // ע������
	char                                szOwnerName[DPSDK_CORE_CAR_OWNERNAME_LEN];   // ҵ������
	char                                szOwnerPhone[DPSDK_CORE_CAR_OWNERPHONE_LEN]; // ҵ���绰
	int32_t	                            nState;									     // ����״̬
	//char	                            szGPSCode[DPSDK_CORE_CAR_GPSCODE_LEN];	 	 // GPS���
}Car_Info_t;

//��ȡ���ų���������Ϣ
typedef struct tagGetCarInfo
{
	IN char								szDeptCoding[DPSDK_CORE_DEPTCODE_LEN];       // ����code
	IN uint32_t							nCarCount;							         // ���ų�������
	OUT Car_Info_t*					    pCarInfo;							         // ������Ϣ�����ⲿ���������ΪNULL��ֻ���ظ���
}Get_Car_Info_t;

//���Ŀ��ڹ���(���������)��Ϣ������Ϣ
typedef struct tagSubscribeBayCarInfo
{   
	int32_t                             nChnlCount;                                  // ����ͨ��������
	Enc_Channel_Info_t*                 pEncChannelnfo;                              // ͨ����Ϣ
	int32_t                             nSubscribeFlag;                              // ���ı�ǡ�0:ȡ�����ģ�1������
}Subscribe_Bay_Car_Info_t;

//���ڹ�����Ϣ
/* 
������ɫ��
		 0 �� 
		 1 �� 
		 2 �� 
		 3 �� 
		 4 �� 
		 100 ���� 

������ɫ��
		 0 �� 
		 1 �� 
		 2 �� 
		 3 �� 
		 4 �� 
		 5 �� 
		 6 �� 
		 7 �� 
		 8 �� 
		 9 �� 
		 10 �� 
		 11 �� 
		 100 ���� 

�������ͣ�
		 0 δ֪ 
		 1 С������ 
		 2 �������� 
		 3 ʹ������ 
		 4 ������� 
		 5 �������� 
		 6 �⼮���� 
		 7 �������� 
		 8 ������ 
		 9 �ҳ� 
		 10 ������ 
		 11 ��ʱ��ʻ�� 
		 12 �������� 
		 13 ����Ħ�г� 
		 14 ��ͨĦ�г� 
		 15 ���Ħ�г� 
		 16 ������ 
		 17 ������ 
		 18 Ħ�г� 
		 19 �ͳ� 
		 20 ����� 
		 21 �л��� 
		 22 �γ� 
		 23 ����� 
		 24 С���� 
		 256 �ǻ����� 
		 257 ���г� 
		 258 ���ֳ� 
		 512 ���� 
		 513 ���ó� 

�������ͣ�
		 0 δ֪ 
		 1 ���ƺ��� 
		 2 ���� 
		 3 ˫���β�� 
		 4 ���� 
		 5 �侯�� 
		 6 ���Ӻ��� 
		 7 ����˫�� 
		 8 �۰��������� 
		 9 ���������� 
		 10 ���Ժ��� 
		 11 ũ���� 
		 12 ʹ�ݺ��� 
		 13 Ħ�г����� 
		 14 ���������� 
		 15 �������� 
		 16 ���� 
		 17 ˽�ҳ� 
		 18 ���� 
		 19 �񺽺��� 
		 20 ���� 

Υ�����ͣ�
		 0  ���ֳ��� 
		 1  ���� 
		 2  ������ 
		 3  ���� 
		 4  ����� 
		 5  ����������ʻ 
		 6  ѹ�� 
		 7  ������ʻ 
		 8  �ǻ������� 
		 10  ������Υ�������־ָʾ 
		 30  Υ����ת 
		 31  Υ����ת 
		 32  Υ�µ�ͷ 
		 33  Υ��ͣ�� 
		 34  Υ�±�� 
		 35  ѹ���� 
		 36  ��ͨӵ�� 
		 37  ��ͨ���� 
		 38  ���Ƴ�ռ�� 
		 39  �г�ռ�� 
		 40  �ֶ�ץ�� 
		 41  ռ�ù��������¼� 
		 42  Υ�µ����¼� 
		 43  ���Ƶ��¼� 
		 44  ��λ�г��¼� 
		 45  ��λ�޳��¼� 
		 46  ���� 
		 47  ��绰 
		 48  ��ϵ��ȫ�� 
		 49  �ڵ����� 
		 50  ������Υ��ͣ�� 
		 51  ��ͨ�������¼� 
		 52  ��ͨ�����¼� 
		 53  ���п��� 
		 54  ���� 
		 55  �������������� 
		 56  ���޳����¼� 
		 57  ѹֹͣ���¼� 
		 58  ·����ʻ�¼� 
		 59  ��ֹͨ���¼� 
		 60  �����������¼� 
		 61  ����ǰ��Ա� 
		 62  ���� 
		 63  ���˴���� 
		 64  ����Υ�� 
		 65  ���̼�� 
		 99  δ֪ 

�������:
		 0 ������ 
		 1 ���� 
		 2 ���� 
		 3 ������ 
		 4 ���������� 
		 5 �������� 
		 6 ���������� 
		 7 �����򶫱� 

ͼƬ���ͣ�
		 0 ��ͨ 
		 1 �ϳ� 
		 2 ��ͼ,����СͼƬ 
		 3 ��ʻԱͼƬ 
		 4 ����ͼƬ 
*/
typedef struct tagBayCarInfo
{
	char                                szDeviceId[DPSDK_CORE_DEV_ID_LEN];            //�豸ID
	int32_t                             nDevChnId;                                    //ͨ����
	char                                szChannelId[DPSDK_CORE_CHL_ID_LEN];           //ͨ��ID
	char                                szDeviceName[DPSDK_CORE_DGROUP_DEVICENAME_LEN]; //�豸����
	char                                szDeviceChnName[DPSDK_CORE_DGROUP_CHNNAME_LEN]; //ͨ������
	char                                szCarNum[DPSDK_CORE_CAR_NUM_LENGTH];          //���ƺ�
	int32_t                             nCarNumType;                                  //��������
	int32_t                             nCarNumColor;                                 //������ɫ
	int32_t                             nCarSpeed;                                    //����
	int32_t                             nCarType;                                     //������
	int32_t                             nCarColor;                                    //����ɫ
	int32_t                             nCarLen;                                      //����
	int32_t                             nCarDirect;                                   //�г�����
	int32_t                             nWayId;                                       //������
	uint64_t							lCaptureTime;                                 //ץͼʱ�䣬��ȷ�����뼶
	unsigned long                       lPicGroupStoreID;                             //ͼƬ�����ID 
	int32_t                             nIsNeedStore;                                 //ͼƬ���Ƿ���Ҫ���� 0������Ҫ 1����Ҫ
	int32_t                             nIsStoraged;                                  //ͼƬ���Ƿ��Ѿ����� 0��δ��ɴ��� 1���ѳɹ����̣�������Ŀǰδʹ��
	char                                szCaptureOrg[DPSDK_CORE_DGROUP_DGPNAME_LEN];  //ͨ������
	char                                szOptOrg[DPSDK_CORE_DGROUP_DGPNAME_LEN];      //���ػ���
	char                                szOptUser[DPSDK_CORE_PERSON_NAME_LEN];        //������Ա
	char                                szOptNote[DPSDK_CORE_OPT_NOTE_LEN];           //��ע��Ϣ
	char                                szImg0Path[DPSDK_CORE_IMG_PATH_LEN];          //ͼƬ·��
	char                                szImg1Path[DPSDK_CORE_IMG_PATH_LEN];
	char                                szImg2Path[DPSDK_CORE_IMG_PATH_LEN];
	char                                szImg3Path[DPSDK_CORE_IMG_PATH_LEN];
	char                                szImg4Path[DPSDK_CORE_IMG_PATH_LEN];
	char                                szImg5Path[DPSDK_CORE_IMG_PATH_LEN]; 

	char								szImgPlatePath[DPSDK_CORE_IMG_PATH_LEN];		//����СͼƬ����
	int									icarLog;										//��������
	int									iPlateLeft;
	int									iPlateRight;
	int									iPlateTop;
	int									iPlateBottom;
}Bay_Car_Info_t;

//���ڲ��ظ澯��Ϣ
typedef struct tagBayWantedAlarmInfo
{
	char            szCameraId[DPSDK_CORE_CHL_ID_LEN];         //ͨ��ID
	int32_t         nChannel;                                  //ͨ����
	char			szDeviceId[DPSDK_CORE_DEV_ID_LEN]; 	       //�豸ID��DVR+ͨ����
	char			szPtsIp[DPSDK_CORE_BAY_IP_LEN];	            //pts����
	char			szPtsIpy[DPSDK_CORE_BAY_IP_LEN];	        //pts����
	int32_t			ulPicPort;                                  //pic����port
	int32_t			ulPicPorty;                                 //pic����port
		
	//������Ϣ
	char			szSurveyId[DPSDK_CORE_DEV_ID_LEN];	        //����ID
	char			szSurveryOrg[DPSDK_CORE_BAY_ORG_LEN];       //���ػ���
	char			szArrestOrg[DPSDK_CORE_BAY_SURVERY_LEN];    //ͨ������
	char			szUserName[DPSDK_CORE_BAY_SURVERY_LEN];     //��ǰ���صĲ���Ա
	int32_t			nAlart;								        //��������
	int32_t		    nSurlevel;						            //���صȼ�
	int32_t			nState;								        //����״̬
	int32_t			nCartype;						            //��������
	char			szCartypeName[DPSDK_CORE_BAY_SURVERY_LEN];  //������������
	char			szCarNum[DPSDK_CORE_BAY_SURVERY_LEN];		//����
	int32_t		    nLicentype;							        //������ɫ����
	char		    szCarlicenName[DPSDK_CORE_BAY_SURVERY_LEN]; //������ɫ����
	int32_t			nCarnotype;							        //��������
	char			szCarnotypeName[DPSDK_CORE_BAY_SURVERY_LEN];//������������

	int32_t			nCarcolor;								    //������ɫ
	char			szCarpower[DPSDK_CORE_BAY_SURVERY_LEN];		//��������
	int32_t			nCarlen;								    //����������
	char			szFrameno[DPSDK_CORE_BAY_SURVERY_LEN];		//���ܺ�
	int32_t			nBckcolor;								    //���Ƶ�ɫ

	int32_t			nSurType;								    //��������
	uint64_t		nBegindate;
	uint64_t		nEnddate;

	char			szIdentify[DPSDK_CORE_BAY_SURVERY_LEN];		//�������֤
    char			szOwnName[DPSDK_CORE_BAY_SURVERY_LEN];		//��������
	char			szOwnAddr[DPSDK_CORE_BAY_SURVERY_LEN];		//������ַ
	char			szOwnPhone[DPSDK_CORE_BAY_SURVERY_LEN];		//�����绰
	char			szDescirbe[DPSDK_CORE_BAY_SURVERY_LEN];		//����
	char			szOrderlyPhone[DPSDK_CORE_BAY_PHONE_LEN];	//���ص�λֵ��绰
	char			szLinkMan[DPSDK_CORE_BAY_MAN_LEN];			//������ϵ��
	char			szLinkManPhone[DPSDK_CORE_BAY_PHONE_LEN];   //������ϵ�˵绰
	char			szOriUrl[DPSDK_CORE_IMG_URL];				//����ԭʼͼƬ

	//������Ϣ
	char			szPicUrl[DPSDK_CORE_BAY_IMG_NUM][DPSDK_CORE_IMG_URL];//ͼƬURL
	uint32_t		ulPicGroupStoreID;					        //ͼƬ��洢ID
	int32_t			bNeedStore;						            //�Ƿ������ 0��������� 1�������
	int32_t			bStored;							        //�Ƿ��Ѵ��� 0��δ���� 1���Ѵ���
	int32_t			nCarLogo;							        //��������

	int32_t			nAlarmLevel;						        //���ر�������
	uint32_t		ulAlarmTime;							    //��������ʱ��,����Ϊ�룬ֵΪtime(NULL)ֵ
	int32_t			nDeviceType;						        //�豸���͡�1��������2��������
	int32_t         nLightColor;                                //���̵�״̬��0 δ֪,1 �̵�,2 ���,3 �Ƶ�

}Bay_WantedAlarm_Info_t;


//��������ϱ���Ϣ
typedef struct tagAreaDetectInfo
{
	char                                szAreaId[DPSDK_CORE_AREA_ID_LEN];                // ����ID 50
	char                                szAreaName[DPSDK_CORE_AREA_NAME_LEN];            // �������� 256
	char                                szStartDevId[DPSDK_CORE_DEV_ID_LEN];             // ��ʼ�豸ID
	uint32_t                            nStartChnNum;                                    // ��ʼ��ͨ����
	char                                szStartChnId[DPSDK_CORE_CHL_ID_LEN];             // ��ʼ��ͨ��ID 
	char                                szStartDevName[DPSDK_CORE_DGROUP_CHNNAME_LEN];   // ��ʼ���豸��,UTF8����
	char                                szStartDevChnName[DPSDK_CORE_DGROUP_CHNNAME_LEN];// ��ʼ��ͨ����,UTF8����
	uint64_t                            nStartCapTime;                                   // ��ʼ��ͨ��ʱ��
	uint32_t                            nStartCarSpeed;                                  // ��ʼ��ͨ���ٶ�
	char                                szStartPosId[DPSDK_CORE_POS_ID_LEN];             // ��ʼ�㿨��ID
	char                                szStartPosName[DPSDK_CORE_POS_NAME_LEN];		 // ��ʼ�㿨����
	char                                szEndDevId[DPSDK_CORE_DEV_ID_LEN];               // ��ֹ���豸ID
	uint32_t                            nEndChnNum;                                      // ��ֹ��ͨ����
	char                                szEndChnId[DPSDK_CORE_CHL_ID_LEN];               // ��ֹ��ͨ��ID 
	char                                szEndDevName[DPSDK_CORE_DGROUP_CHNNAME_LEN];     // ��ֹ���豸��,UTF8����
	char                                szEndDevChnName[DPSDK_CORE_DGROUP_CHNNAME_LEN];  // ��ֹ��ͨ����,UTF8����
	uint64_t                            nEndCapTime;                                     // ��ֹ��ͨ��ʱ��
	uint32_t                            nEndCarSpeed;                                    // ��ֹ��ͨ���ٶ�
	char                                szEndPosId[DPSDK_CORE_POS_ID_LEN];               // ��ֹ�㿨��ID
	char                                szEndPosName[DPSDK_CORE_POS_NAME_LEN];           // ��ֹ�㿨����
	uint32_t                            nAreaRange;                                      // �������
	uint32_t                            nMinSpeed;                                       // ·���������� 
	uint32_t                            nMaxSpeed;                                       // ·���������� 
	char                                szCarNum[DPSDK_CORE_CAR_NUM_LENGTH];             // ���ƺ��룬UTF8����
	uint32_t                            nCarNumType;                                     // ��������
	uint32_t                            nCarNumColor;                                    // ������ɫ
	uint32_t                            nCarColor;                                       // ������ɫ
	uint32_t                            nCarType;                                        // ������
	uint32_t                            nCarLogo;                                        // ��������
	uint32_t                            nCarAvgSpeed;                                    // ����ƽ���ٶ�
	uint32_t                            nIsIllegalSpeed;                                 // �Ƿ��ٻ����
	uint32_t                            nPicNum;                                         // ͼƬ���������֧��6��
	char                                szPicName[DPSDK_CORE_BAY_IMG_NUM][DPSDK_CORE_FILEPATH_LEN]; // ͼƬ�ļ����������֧��6�š�
	uint32_t                            nRtPlate[DPSDK_CORE_COORDINATE_LEN];             // ��������,left,top, right, bottom,���ܳ���4λ
	char                                szCarPlatePicURL[256];                           // ����СͼƬURL
}Area_Detect_Info_t;

///< ��ȡ�鲥 ip:port 
typedef struct tagCamStream
{
	char	camid[DPSDK_CORE_CHL_ID_LEN];
	long	limit;
	char	decosderIp[DPSDK_CORE_IP_LEN];
	char	channel[DPSDK_CORE_CHL_ID_LEN];
	char	param[DPSDK_CORE_CHL_ID_LEN];		// ���ز���
}CamStream_Tnfo_t;

///< ͨ��������IP��ͨ���Ż�ȡ����ǽ��Ӧ������Ϣ
typedef struct tagQueryTvWallInfo{
	char	devip[DPSDK_CORE_CHL_ID_LEN];		// ��Ҫ��ȡ�Ľ�����IP
	char	devid[DPSDK_CORE_DEV_ID_LEN];		// �豸ID
	long	port_;								// �����豸�˿ں�
	long	channel_;							// ��Ҫ��ȡ�Ľ�����ͨ����
	char	camid[DPSDK_CORE_DEV_ID_LEN];		// ��Ҫ����ƵԴ���豸ID
	char	camgip[DPSDK_CORE_IP_LEN];			// ��Ҫ��ȡ�Ľ������鲥IP
	long	camport;							// ��Ҫ��ȡ�Ľ������鲥�˿ں�
	long	tvwallid_;							// ����ǽ���
	long	screenid_;							// ��Ļ���
	long	wndid_;								// ���ڱ��
	bool	bgood_;								// �Ƿ��ȡ�ɹ�
}QueryTvWall_Info_t;

//�����¼���Ϣ
typedef struct tagOneIssueInfo
{
	char szStatName[DPSDK_CORE_KANGTEER_DATA];
	char szUseClass[DPSDK_CORE_KANGTEER_DATA];
	char szContent[DPSDK_CORE_KANGTEER_DATA];
	char szIssueName[DPSDK_CORE_KANGTEER_DATA];
	char szDeviceID[DPSDK_CORE_KANGTEER_DATA];
	char szBeginTime[DPSDK_CORE_KANGTEER_DATA];
	char szEndTime[DPSDK_CORE_KANGTEER_DATA];
	char szWorkCompany[DPSDK_CORE_KANGTEER_DATA];
	char szLinkMan[DPSDK_CORE_KANGTEER_DATA];
	char szLinkMethod[DPSDK_CORE_KANGTEER_DATA];
	char szAllowJob[DPSDK_CORE_KANGTEER_DATA];
}One_Issue_Info_t;

//�¼���Ϣ
typedef struct tagIssueInfo
{
	One_Issue_Info_t oneIssueInfo[DPSDK_CORE_KANGTEER_GROUP_DATA];
	int nSize;
}Issue_Info_t;

//����ͼƬ��Ϣ
typedef struct tagOneFtpPicInfo
{
	char szDevId[DPSDK_CORE_DEV_ID_LEN];			//����ͷID
	int  nChlNo;									//ͨ����
	char szCapTime[DPSDK_CORE_TIMESTR_LEN];			//ץͼʱ��
	char szFtpPath[DPSDK_CORE_FILEPATH_LEN];		//Ftp����ͼƬ·��
}One_Ftp_Pic_Info_t;

//ͼƬ��Ϣ
typedef struct tagFtpPicInfo
{
	One_Ftp_Pic_Info_t oneFtpPicInfo[DPSDK_CORE_QUERY_PIC_MAXCOUT];			//����ͼƬ��Ϣ
	int nSize;																//ͼƬ����
}Ftp_Pic_Info_t;

typedef struct OpeOSDTemplatInfo
{
	uint32_t					nTemplateId;
	uint32_t					nMsgType;												// 1:OSD��Ϣ��2������
	uint32_t					nOpeType;												// 1����� 2���޸� 3��ɾ��
	char						szMessage[DPSDK_CORE_OSDTEMPLAT_CONTENT_LEN];			// ��Ϣ����
	char						szName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];
	char						szMemo[DPSDK_CORE_OSDTEMPLAT_CONTENT_LEN];
}Ope_OSD_Templat_Info_t;

typedef struct SearchHistoryOSDInfo
{
	uint32_t					nBeginTime;
	uint32_t					nEndTime;
	uint32_t					nMsgType;								// 1:OSD��Ϣ��2������
	char						szDevId[DPSDK_CORE_DEV_ID_LEN];			// �豸id
}Search_History_OSDInfo_t;

typedef struct SendOSDInfo
{
	char						szDevId[DPSDK_CORE_DEV_ID_LEN];							// �豸id
	char						szMessage[DPSDK_CORE_OSDTEMPLAT_CONTENT_LEN];			// ��Ϣ����
}Send_OSDInfo_t;

typedef struct SendSMSInfo
{
	int							nUserId;												// �û�id
	int64_t						nTime;													// ʱ��
	char						szDevId[DPSDK_CORE_DEV_ID_LEN];							// �豸id
	char						szDevName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];			// �豸����
	char						szMessage[DPSDK_CORE_OSDTEMPLAT_CONTENT_LEN];			// ��Ϣ����
	char						szSMSNo[DPSDK_CORE_OSDTEMPLAT_CONTENT_LEN];				// ��Ϣ�绰����
}Send_SMS_Info_t;

//��Դ��Ϣ�ϴ���Ϣ
typedef struct tagSaveFileInfo
{
	char								szCaseCode[DPSDK_CORE_CASE_CODE_LEN];		// �������
	char								szCaseName[DPSDK_CORE_CASE_NAME_LEN];		// ��������
	char								szStartData[DPSDK_CORE_TIME_LEN];			// ������ʼ yyyy-mm-dd hh:mi:ss
	char								szEndData[DPSDK_CORE_TIME_LEN];				// �������� yyyy-mm-dd hh:mi:ss
	char								szCaseAddr[DPSDK_CORE_CASE_ADDR_LEN];		// ������ַ
	char								szCaseMemo[DPSDK_CORE_CASE_MEMO_LEN];		// ������ע
	char								szFilePath[DPSDK_CORE_FILE_PATH_LEN];		// �ļ�Ŀ¼
	char								szFileMemo[DPSDK_CORE_FILE_MEMO_LEN];		// �ļ�����
	char								szGpsX[DPSDK_CORE_GPS_LEN];					// �ϴ��ļ�����
	char								szGpsY[DPSDK_CORE_GPS_LEN];					// �ϴ��ļ�γ��
	int									nFileType;									// �ļ����� 1ͼ�� 2��Ƶ 3����
	char								szImageType[DPSDK_CORE_FILE_TYPE_LEN];		// ͼƬ�ļ���ʽ JPEG/BMP/GIF/PNG/Other
	int									nImageWidth;								// ͼƬ��� 0-8192
	int									nImageHeigth;								// ͼƬ�߶� 0-8192
	char								szVideoFlowType[DPSDK_CORE_FILE_TYPE_LEN];	// �������� PS/TS/DHAV/Other
	char								szVideoEncode[DPSDK_CORE_FILE_TYPE_LEN];	// �����ʽ H264/JPEG4/Other

	char								szLocalPath[DPSDK_CORE_FILE_PATH_LEN];		// �����ļ�·��
}Save_File_Info;

//AsyncLoadDGroupInfo���ݸ�Thread����Ϣ
typedef struct tagAsyncThreadInfo
{
	int   nSeq;
	int   nTimeout;
	void* pDLLDpsdk;
	void* pFun;
	void* pUserParam;
}Async_Thread_Info_t;

//��Ƶ����ṹ��
struct ShareVideoInfo
{
	char	szCameraId[DPSDK_CORE_CHL_ID_LEN];		//����ͷID
	int		nType;									//1��Ƶ��2��Ƶ��3��Ƶ����Ƶ
	int		nSubStream;								//�������͡�1��������2������
	int		nIsMobile;								//�����ʾ�ֻ��ͻ�������
	uint64_t	nPlanId;							//¼��ƻ�ID
	uint64_t	nPlaybacktime;						//�ط�ʱ��
};

typedef struct tagDataAnalysisInfo
{
	tagDataAnalysisInfo()
	{
		pFun = NULL;
		nProviderType = 0;
		hHandle = NULL;
		pTSStreamParseDH = NULL;
	}
	~tagDataAnalysisInfo()
	{
	}

	void* pFun;
	int nProviderType;
	void* hHandle;
	void* pTSStreamParseDH;
}Data_Analysis_Info_t;

typedef struct tagStreamConvertorInfo
{
	void* pDLLDpsdk;
	void* pFun;
	void* hSCHandle;
	int   nSeq;
	int   nMediaType;
	char  szNodeId[DPSDK_CORE_DEV_ID_LEN];
	int   paramVal;
}Stream_Convertor_Info_t;


typedef struct tagTalkParam
{
	dpsdk_talk_type_e talkType;
	dpsdk_audio_type_e audioType; 
	dpsdk_talk_bits_e audioBit;
	Talk_Sample_Rate_e sampleRate; 
	dpsdk_trans_type_e transMode;

}Talk_Param_t;

typedef enum
{	// ������������������������
	CONTROL_ERROR = 0,			// �������ʹ���
	CONTROL_DEV_ARM,			// ����豸����-1
	CONTROL_DEV_DISARM,			// ����豸����-2
	CONTROL_DEV_ARM_HOME,		// �ڼҲ���-3
	CONTROL_DEV_ARM_OUT,		// �������-4
	CONTROL_CHL_BYPASS,			// ���ͨ����·-5
	CONTROL_CHL_DISBYPASS,		// ���ͨ��ȡ����·-6
	CONTROL_CHL_ARM_CLEAR,		// ���ͨ������-7
}dpsdk_AlarmhostOperator_e;

typedef enum
{	// ��������״̬����
	ALARMHOSE_STATUS_ERROR = 0,			// ״̬���ʹ���
	ALARMHOSE_STATUS__DEV_ARM,			// ����豸����-1
	ALARMHOSE_STATUS__DEV_DISARM,		// ����豸����-2
	ALARMHOSE_STATUS__CHL_BYPASS,		// ���ͨ����·-3
	ALARMHOSE_STATUS__CHL_DISBYPASS,	// ���ͨ��ȡ����·-4
	ALARMHOSE_STATUS__DEV_IN_ARM,		// ����豸�ڼҲ���-5 add by djm 20131219
	ALARMHOSE_STATUS__DEV_OUT_ARM,		// ����豸�������-6 add by djm 20131219
}dpsdk_videoalarmhost_status_type_e;

typedef enum
{
	AHOST_OPERATE_DEVICE			= 1,		// �豸 ��/����
	AHOST_OPERATE_CHANNEL			= 2,		// ͨ�� ��/����
	AHOST_OPERATE_CHANNEL_ALARMOUT	= 3,		// �������ͨ������
}dpsdk_netalarmhost_operator_e;

typedef enum
{
	AHOST_CMD_TYPE,
	AHOST_CMD_ENABLE = 1,						// ������������
	AHOST_CMD_DISABLE,							// ������������
	AHOST_CMD_BYPASS,							// ����������·
	AHOST_CMD_CANCELKBLIGHT,					// ȡ������ָʾ����ʾ
	AHOST_CMD_ALARMMODE,						// ���ñ�������ȡ���������Զ��Ļ��ǿͻ����ֶ�ȡ��
	AHOST_CMD_CANCELALARM,						// ȡ�������ϱ�
	AHOST_CMD_ALARMOUT_ON,						// �����������ͨ����
	AHOST_CMD_ALARMOUT_OFF,						// �����������ͨ���ر�
	AHOST_CMD_DOOR_OPEN,						// �Ž�ͨ������
	AHOST_CMD_DOOR_CLOSE,						// �Ž�ͨ���ر�
	AHOST_CMD_DOOR_AUTO,						// �Ž�ͨ���Զ�
	AHOST_CMD_DOOR_ALWAYS_OPEN,					// �Ž�ͨ������
	AHOST_CMD_DOOR_ALWAYS_CLOSE,				// �Ž�ͨ������
}dpsdk_netalarmhost_cmd_e;

typedef struct tagUserInfo
{
	int		iUserId;					// �û�id
	int		iUserLevel;					// �û��ȼ�
	bool	iUserOperFlag;				// true����Աfalse��ҵ�ͻ�
	char	szCoding[128];              // �û�������֯
	char	szCodeName[256];            // �û�������֯����

}DPSDK_UserInfo_t;

// ��������ͨ����Ϣ
typedef struct tagAlarmInChannelInfo 
{
	char								szId[DPSDK_CORE_DEV_ID_LEN];				// ͨ��ID:�豸ID+ͨ����
	char								szName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];	// ����
	uint64_t                            nRight;                                     // Ȩ����Ϣ
	int                                 nChnlType;                                  // ͨ������
	int                                 nStatus;
}AlarmIn_Channel_Info_t; 

// ��ȡ��������ͨ��������Ϣ
typedef struct tagGetAlarmInChannelInfo 
{
	IN char								szDeviceId[DPSDK_CORE_DEV_ID_LEN];			// �豸ID
	IN uint32_t							nAlarmInChannelCount;						// ͨ������
	OUT AlarmIn_Channel_Info_t*			pAlarmInChannelnfo;							// ͨ����Ϣ
}Get_AlarmInChannel_Info_t;

typedef struct tagdpsdkAHostDefenceStatus
{
	char szNodeID[DPSDK_CORE_DEV_ID_LEN];		// �����ڵ�ID
	int  nAlarm;								// 0��ʾδ���� 1104��ʾ���� 1105��ʾ�� 1106��ʾ��
	int  nUndefendAlarm;						// 0��ʾû��δ�������� 83��ʾδ��������������24Сʱ��������ֲ���������δ����������������� ������Ҫ����һ�£�
	bool bByPass;								// true=��·, false=δ��·
	bool bDefend;								// true=����, false=����

}dpsdk_AHostDefenceStatus_t;

typedef enum
{  
	AHOST_TYPE_NONE			= 0,
	AHOST_TYPE_STAY			= 1,				// ���ز���
	AHOST_TYPE_BYPASS,							// ������·
}dpsdk_netalarmhost_report_type_e;

typedef struct tagPhoneSubscribeAlarm
{
	int         iUserId;				//�û�ID
	char        szPhoneId[256];			//�ֻ�ID,�ֻ����͵ı�־
	int         iAppId;					//Ӧ�ó�����
	char        szPush_type[64];		//�ֻ�����
	int         iIs_subscribe;			//�Ƿ���; 1-����, 0-ȡ������
	char        szLanguage[32];			//����
	char        szTimefmt[32];			//ʱ���ʽ��

	int         iDbOper;				//db��������. 1-����, 2-����, 3-��ѯ

}dpsdk_phone_subscribe_alarm_t;

//����ҵ������
typedef enum
{
	BAY_MONITOR_CAR = 1,		//����
	BAY_MONITOR_FACE = 2,		//����
}dpsdk_bay_monitor_e;

typedef enum
{
	AREATYPE_UNKOWN			= 0x00,		//δ֪
	AREATYPE_SPEEDLIMIT		= 0x01,		//������
	AREATYPE_DRIVERALLOW	= 0x02,		//��ʻ��
	AREATYPE_FORBIDDRIVE	= 0x04,		//������
	AREATYPE_LOADGOODS		= 0x08,		//������
	AREATYPE_UNLOADGOODS	= 0x10,		//�ﵽ��
}dpsdk_area_type_e;

typedef struct tagAreaPoint
{
	double dwLongitude;				//����
	double dwLatidude;				//γ��
}Area_Point_t;

typedef struct tagAreatimePeriod
{
	char szBeginTime[32];				// ��ʼʱ��
	char szEndTime[32];					// ����ʱ��
}Area_Time_Period_t;

typedef struct tagAreatimeWeekdays
{
	int days;
	Area_Time_Period_t* arryAlarmtimePeriod;
	int nAlarmtimePeriodCount;
}Area_Time_Weekdays_t;

// ����Χ������ʱ���
typedef struct tagAreaTime
{
	int enable;												// ʱ�������ʹ��,1��ʾ���ã�0��ʾ������
	Area_Time_Weekdays_t areatimeWeekdays[DPSDK_CORE_AREA_WEEK_DAYS];	// ������һ���ʱ���
}Area_Time_t;

//����Χ����Ϣ
typedef struct tagAreaInfo
{
	dpsdk_area_type_e nAreaType;						//Χ������
	char strAreaAttr[DPSDK_CORE_AREA_ATTR_MAXLEN];			//Χ������
	char strAreaName[DPSDK_CORE_AREA_NAME_MAXLEN];			//Χ������
	int nSpeedLimit;							//����
	int nNumMax;								//�������
	Area_Point_t* arryAreaPoints;
	int nAreaPointsCount;

	Area_Time_t	stuAlarmTime;					
}Area_Info_t;

typedef struct tagPeccancyAlarmInfo
{
	int					areaId;								// Χ��ID   3.0����
	int					areatype;							// Χ������
	int					currrentSpeed;						// ��ǰ�ٶ�
	int					maxSpeed;						    // ����ֵ
	char				driverId[DPSDK_CORE_DRIVER_ID_LEN];		// ˾������
	char				deviceId[DPSDK_CORE_DEV_ID_LEN];			// �豸ID
	int					alarmType;							// ��������
	int64_t				alarmTime;							// ��������ʱ��,����Ϊ�룬ֵΪtime(NULL)ֵ
	char				message[DPSDK_CORE_ALARM_MSG_LEN];		// ��ע��Ϣ
	int					diffSpeed;							// ��ǰ�ٶ�������ֵ�Ĳ�
	int					diffAlarmTime;						// ��ǰ����ʱ��-�ϴα���ʱ�䣨�룩
	char				areaCode[DPSDK_CORE_AREA_CODE_LEN];		// Χ����
	char				dbLongitude[DPSDK_CORE_AREA_DB_LEN];		// ����
	char				dbLatitude[DPSDK_CORE_AREA_DB_LEN];		// γ��
	int					alarmStat;							// ����״̬
	int					channelSeq;							// ͨ�����
	char				deviceName[DPSDK_CORE_DEV_ID_LEN];		// �豸����
	char				alarmID[DPSDK_CORE_ALARMCODE_LEN];		// ����id��guid
}Peccancy_Alarm_t;

// Ԥ��״̬
typedef enum
{
	ALARM_SCHEME_STATUS_CLOSE			= 0,				// �ر�
	ALARM_SCHEME_STATUS_OPEN,								// ��
}dpsdk_alarmScheme_status_e;

// Ԥ���б���Ϣ
typedef struct tagAlarmSchemeInfo
{
	dpsdk_alarmScheme_status_e	status;									// Ԥ��״̬
	uint32_t					id;										// Ԥ�����ݿ�id
	char						schemeName[DPSDK_CORE_SCHEME_NAME_LEN];	// Ԥ������
	uint32_t					templateId;								// Ԥ��ʱ��ģ��ID
	char						desc[DPSDK_CORE_SCHEME_DESC_LEN];		// Ԥ������

}AlarmSchemeInfo_t;

// Ԥ���ļ���Ϣ
typedef struct tagAlarmSchemeFileInfo
{
	dpsdk_alarmScheme_status_e	status;									// Ԥ��״̬
	uint32_t					id;										// Ԥ�����ݿ�id
	char						schemeName[DPSDK_CORE_SCHEME_NAME_LEN];	// Ԥ������
	uint32_t					templateId;								// Ԥ��ʱ��ģ��ID
	char						desc[DPSDK_CORE_SCHEME_DESC_LEN];		// Ԥ������
	char*						data;									// Ԥ������
	uint32_t					len;									// Ԥ�����ݳ���

}AlarmSchemeFileInfo_t;

// ����ģ����Ϣ
typedef struct tagTimeTemplateInfo
{
	uint32_t 	id;												// ���
	char		name[DPSDK_CORE_TEMPLATE_NAME_LEN];				// ģ������
	char		remark[DPSDK_CORE_TEMPLATE_REMARK_LEN];			// ʱ��ģ���˵��
	char		flag[DPSDK_CORE_TEMPLATE_FLAG_LEN];				// �������ȫ��ġ�������һ������

}TimeTemplateInfo_t;

// cms��Ϣ֪ͨ����
typedef enum
{
	ALARM_MSGTYPE_UnKnown				= 0,				// δ֪
	ALARM_MSGTYPE_TIMETEMPLATE_ADD,							// ʱ��ģ�����
	ALARM_MSGTYPE_TIMETEMPLATE_UPDATE,						// ʱ��ģ�����
	ALARM_MSGTYPE_TIMETEMPLATE_DELETE,						// ʱ��ģ��ɾ��
	ALARM_MSGTYPE_ALARMSCHEME_ADD,							// ����Ԥ�����
	ALARM_MSGTYPE_ALARMSCHEME_UPDATE,						// ����Ԥ������
	ALARM_MSGTYPE_ALARMSCHEME_DELETE,						// ����Ԥ��ɾ��
}dpsdk_alarm_msgType_e;

typedef struct tagAlarmSchemeChgInfo
{
	dpsdk_alarm_msgType_e	type;							// ��Ϣ����,Ԥ��֪ͨ��ʱ��ģ��֪ͨʹ��
	uint64_t				id;								// ���ݿ�id,Ԥ��֪ͨʹ��
	uint64_t				nParam1;						// �޸�Ԥ��֪ͨʱ��ʾʱ��ģ��id
	uint64_t				nParam2;						// �޸�Ԥ��֪ͨʱ��ʾԤ������
	char					szMsg[2048];					// �޸�Ԥ��֪ͨʱ��ʾ�޸���ip;ʱ��ģ���������ɾ���������ʹ��str���ͱ�ʶid
}AlarmSchemeChg_t;

typedef struct tagDataChangeInfo
{
	int64_t			nParam1;
	int64_t			nParam2;
	char			szMsg1[1024*3];
	char			szMsg2[1024*3];
}DataChange_t;

typedef struct tagDPSDKParam
{
	char	szUserIdFlag[64];		//�û�id��ʶ��
}DPSDKParam_t;

typedef struct tagPerson_Count_Info
{
	int			nChannelID;									// ͳ��ͨ����
	char		szRuleName[DPSDK_CORE_IVS_EVENT_NAME_LEN];	// ��������
	uint32_t	nStartTime;									// ��ʼʱ��
	uint32_t	nEndTime;									// ����ʱ��
	uint32_t	nEnteredSubTotal;							// ��������С��
	uint32_t	nExitedSubtotal;							// ��ȥ����С��
	uint32_t	nAvgInside;									// ƽ����������(��ȥ��ֵ)
	uint32_t	nMaxInside;									// ���������
}Person_Count_Info_t;

typedef struct tagSingleChnlIdInfo
{
	char	szChnlId[DPSDK_CORE_CHL_ID_LEN];
}Single_ChnlId_Info_t;

// ���غŹ���ͨ��ID��Ϣ
typedef struct tagChnlIdBySiteCodeInfo
{
	int						nSiteCode;				// ���غ�
	int						nChnlIdCount;			// ͨ��ID����
	Single_ChnlId_Info_t*	pSingleChnlIdInfo;		// ͨ��ID�б�
	tagChnlIdBySiteCodeInfo()
	{
		nSiteCode = 0;
		nChnlIdCount = 0;
		pSingleChnlIdInfo = NULL;
	}
	~tagChnlIdBySiteCodeInfo()
	{
		nSiteCode = 0;
		nChnlIdCount = 0;
		if(pSingleChnlIdInfo != NULL)
		{
			delete [] pSingleChnlIdInfo;
			pSingleChnlIdInfo = NULL;
		}
	}
}ChnlIdBySiteCode_Info_t;
//Prisonģ��ṹ�嶨�� begin

// ��¼ʵʱ״̬��Ϣ
typedef struct tagDevBurnerCDStateInfo
{
	//char								szName[DPSDK_CORE_TVWALL_NAME_LEN];
	uint32_t				m_burnerId;											// ��¼��ID, ID��0��ʼ
	uint32_t				m_burnerState;										// ��¼��״̬ 0�����Կ�¼ 1����¼�����Ͳ��ԣ���һ���ǹ����豸 
																				// 2��δ�ҵ���¼�� 3�������������ڿ�¼ 4����¼�����ڷǿ���״̬�����ڱ��ݡ���¼��ط���
	uint32_t				m_romType;											// ��Ƭ���� 0�����ļ�ϵͳ 1���ƶ�Ӳ�̻�U�� 2������
	uint32_t				m_operateType;										// �������� 0������ 1�����ڱ����� 2�����ڿ�¼�� 3�����ڽ��й��̻ط�
	uint32_t				m_processState;										// ����״̬ 0��ֹͣ����� 1����ʼ 2������ 3���� 4�����ڳ�ʼ��
	uint32_t				m_startTime;										// ��ʼʱ��
	uint32_t				m_elapseTime;										// �ѿ�¼ʱ��
	uint32_t				m_totalSpace;										// ����������
	uint32_t				m_remainSpace;										// ����ʣ������
	uint32_t				m_burned;											// �ѿ�¼����
	uint32_t				m_channelMask;										// ��¼��ͨ������
	uint32_t				m_emMode;											// ��¼ģʽ0-BURN_MODE_SYNC,1-BURN_MODE_TURN,2-BURN_MODE_CYCLE
	uint32_t				m_emPack;											// ��¼����ʽ0-DHAV,1-BURN_PACK_PS...

}Dev_Burner_CDState_Info_t;

// ��ȡ��¼ʵʱ״̬��Ϣ����
typedef struct tagDevBurnerCDStateRequest
{
	char				deviceId[DPSDK_CORE_DEV_ID_LEN];			// �豸ID
	uint32_t			burnerId;									//���̿�¼��ID (id��0��ʼ����)

}Dev_Burner_CDState_Request_t;

// ��ȡ��¼ʵʱ״̬��Ϣ�ظ�
typedef struct tagDevBurnerCDStateReponse
{
	Dev_Burner_CDState_Info_t  stuDevBurnerStateInfo;

}Dev_Burner_CDState_Reponse_t;

//��¼��������
typedef enum
{
	Cmd_StartBurn = 1,															// ��ʼ��¼
	Cmd_PauseBurn,																// ��ͣ��¼
	Cmd_ContinueBurn,															// ������¼
	Cmd_StopBurn,																// ֹͣ��¼
	Cmd_ChangeCD,																// �ֶ�����
}Core_EnumControlBurnerCmd;

// ��ȡ��¼ʵʱ״̬��Ϣ����
typedef struct tagControlDevBurnerRequest
{
	char						deviceId[DPSDK_CORE_DEV_ID_LEN];			// �豸ID
	Core_EnumControlBurnerCmd   cmd;										//��������
	int							channelMask;								//ͨ������    ��1��ͨ��Ϊ1����2��ͨ���ǣ�1<<1;��3����1<<2
	int							burnerMask;									//��¼������  1��ʾ����1��2����2��3˫����
	//ͥ�����
	int							emMode;										//��¼ģʽ    0-BURN_MODE_SYNC,1-BURN_MODE_TURN,2-BURN_MODE_CYCLE
	int							emPack;										//��¼����ʽ  0-DHAV,1-BURN_PACK_PS...

}Control_Dev_Burner_Request_t;

//��¼Ƭͷ
typedef struct tagDevBurnerInfoHeader
{
	char					m_deviceId[DPSDK_CORE_CHAR_LEN_32];					// �豸ID
	char					m_password[DPSDK_CORE_CHAR_LEN_64];					//  ��������
	char					m_caseId[DPSDK_CORE_CHAR_LEN_64];					// 1.�������
	char					m_trialSeq[DPSDK_CORE_CHAR_LEN_256];				// 2.�������/��Ѷ���
	char					m_caseUnderTaker[DPSDK_CORE_CHAR_LEN_256];			// 3.�참��Ա
	char					m_caseDep[DPSDK_CORE_CHAR_LEN_256];					// 4.�참��λ	
	char					m_caseReason[DPSDK_CORE_CHAR_LEN_256];				// 5.��������
	char					m_caseReferPerson[DPSDK_CORE_CHAR_LEN_256];			// 6.�永��Ա
	char					m_caseRemark[DPSDK_CORE_CHAR_LEN_256];				// 7.����ע
	char					m_caseRecordName[DPSDK_CORE_CHAR_LEN_256];			// 8.¼������
	char					m_RecordNum[DPSDK_CORE_CHAR_LEN_64];				// 9.���̱��
	char					m_recordPerson[DPSDK_CORE_CHAR_LEN_256];			// 10.��¼��
	bool					m_dataCheckOsdEn;									// 11.���̿�¼����У������/����ʹ��
	bool					m_AttachFileEn;										// 12.�����ļ�ʹ��
	bool					m_multiBurnerDataCheck;								// 13.�����һ����У��ʹ��
	uint32_t				m_multiBurnerDataCheckSpeed;						// 14.У���ٶ�У���ٶ� 0 ���٣�ͷβ����У�飩,1 �������������У�飩,2 ���� ��ȫ������У�飩,Ĭ��0
}DevBurnerInfoHeader_t;

//��Ѷ��������
typedef struct tagTrialFormAttrName
{
	char					m_caseIdAttr[DPSDK_CORE_CHAR_LEN_32];				// �������
	char					m_trialSeqAttr[DPSDK_CORE_CHAR_LEN_32];			// �������/��Ѷ���
	char					m_caseUnderTakerAttr[DPSDK_CORE_CHAR_LEN_32];		// �참��Ա
	char					m_caseDepAttr[DPSDK_CORE_CHAR_LEN_32];				// �참��λ
	char					m_caseReasonAttr[DPSDK_CORE_CHAR_LEN_32];			// ��������
	char					m_caseReferPersonAttr[DPSDK_CORE_CHAR_LEN_32];		// �永��Ա
	char					m_caseRemarkAttr[DPSDK_CORE_CHAR_LEN_32];			// ����ע
	char					m_caseRecordNameAttr[DPSDK_CORE_CHAR_LEN_32];		// ¼������
	char					m_trialObjNameAttr[DPSDK_CORE_CHAR_LEN_32];			// ����Ѷ������
	char					m_trialObjSexAttr[DPSDK_CORE_CHAR_LEN_32];			// ����Ѷ���Ա�
	char					m_trialObjIDAttr[DPSDK_CORE_CHAR_LEN_32];			// ����Ѷ�����֤����
	char					m_trialObjNationAttr[DPSDK_CORE_CHAR_LEN_32];		// ����
	char					m_trialObjBirthdayAttr[DPSDK_CORE_CHAR_LEN_32];		// ��������
	char					m_trialObjHomeAddrAttr[DPSDK_CORE_CHAR_LEN_32];		// סַ
	char					m_trialObjWorkUnitsAttr[DPSDK_CORE_CHAR_LEN_32];	// ������λ
	char					m_trialObjTelephoneAttr[DPSDK_CORE_CHAR_LEN_32];	// ��ϵ�绰
	char					m_CDIDAttr[DPSDK_CORE_CHAR_LEN_32];					// ���̱��
	char					m_recordPersonAttr[DPSDK_CORE_CHAR_LEN_32];			// ��¼��
	char					m_caseAssistantAttr[DPSDK_CORE_CHAR_LEN_32];		// Э���참��Ա--������Ϣ�������Ǳ�����
	char					m_trialObjAgeAttr[DPSDK_CORE_CHAR_LEN_32];			// ����--��ѯ������Ϣ-�������Ǳ�����
}TrialFormAttrName_t;

//����������Ϣ
typedef struct tagSingleDiskInfo
{
	int						nDiskId;											//Ӳ��ID����0��ʼ��
	uint32_t				uVolume;											//Ӳ������
	uint32_t				uFreeSpace;											//ʣ������
	unsigned char			diskState;											//����λ��ֵ��ʾӲ�����ͣ�����Ϊ��0 ��д������ 1 ֻ�������� 2 ������������ý�������� 3 ���������� 4 ����������������λ��ֵ��ʾӲ�̵�״̬��0-����,1-�,2-����
	unsigned char			diskNum;											//Ӳ�̺�
	unsigned char			subareaNum;											//������
	unsigned char			signal;												//��ʶ�� 0���� 1 Զ��
}Single_Disk_Info_t;

//�豸������Ϣ
typedef struct tagDiskInfo
{
	char					szDevId[DPSDK_CORE_DEV_ID_LEN];						//�豸ID
	int						nDiskInfoSize;										//������Ϣ����
	Single_Disk_Info_t*		pDiskInfoList;										//������Ϣ�б�

	tagDiskInfo()
	{
		nDiskInfoSize = 0;
		pDiskInfoList = NULL;
	}

	~tagDiskInfo()
	{
		nDiskInfoSize = 0;
		if(pDiskInfoList)
		{
			delete [] pDiskInfoList;
			pDiskInfoList = NULL;
		}
	}
}Device_Disk_Info_t;

//Prisonģ��ṹ�嶨�� end


//Pecģ��ṹ�嶨�� begin

//�Ž������������,��Э�鶨����ͬ
typedef enum
{
	CORE_DOOR_CMD_PROGARM,
	CORE_DOOR_CMD_OPEN			= 5,				// ����
	CORE_DOOR_CMD_CLOSE			= 6,				// ����
	CORE_DOOR_CMD_ALWAYS_OPEN,						// �ų���
	CORE_DOOR_CMD_ALWAYS_CLOSE,						// �ų���
	CORE_DOOR_CMD_HOLIDAY_MAG_OPEN,					// ���չ����ų���
	CORE_DOOR_CMD_HOLIDAY_MAG_CLOSE,				// ���չ����ų���
	CORE_DOOR_CMD_RESET,							// ��λ
	CORE_DOOR_CMD_HOST_ALWAYS_OPEN,					// ���������µ��Ž�ͨ��������
	CORE_DOOR_CMD_HOST_ALWAYS_CLOSE,				// ���������µ��Ž�ͨ��������
}Core_EnumSetDoorCmd;

// �ſ�������
typedef struct tagSetDoorCmdRequest
{
	char						szCameraId[DPSDK_CORE_DEV_ID_LEN];			// ͨ��ID
	Core_EnumSetDoorCmd		    cmd;										//��������
	int64_t						start;										//ͨ��ʼʱ��
	int64_t						end;										//����ʱ��

}SetDoorCmd_Request_t;

// ͨ����Ϣ
typedef struct tagChannelBaseInfo 
{
	char								szName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];	// ����
}ChannelBase_Info_t;

// ��Ƶ�����ظ�
typedef struct tagGetLinkResourceResponce
{
	char*		pXmlData;
	uint32_t	nLen;

}GetLinkResource_Responce_t;

typedef enum
{
	Door_Close,
	Door_Open,
	Door_DisConn,
}dpsdk_door_status_e;

//Pecģ��ṹ�嶨�� end

//��Ⱥ�Խ��ṹ�嶨��

//StartCall���صĶԽ�����
typedef struct tagStartCallResponse
{
	int					returnValue;							// ƽ̨���صĴ����룬0����ɹ�������ʧ��
	int					seq;									// ���ڹرպ��е�seq
	uint32_t			sessionId;								// �����Խ��ỰId
	char				szGroupId[DPSDK_CORE_CHL_ID_LEN];		// �豸ID��ͨ��ID
	char				strSendChnlID[DPSDK_CORE_CHL_ID_LEN];	// ����ͨ��ID
	char				strRecvChnlID[DPSDK_CORE_CHL_ID_LEN];	// ����ͨ��ID
	char				rtpServIP[DPSDK_CORE_IP_LEN];			// Զ��RTP IP
	int					rtpPort;								// Զ��RTP�˿�
	int					talkMode;								// �Խ�ģʽ 0�Խ� 1�㲥��������
	int					audioType;								// 1 PCM��2 G.711��3 G.723��4 G.726��5 G.729
	int					audioBit;								// ��ʵ�ʵ�ֵ��ʾ����8λ ����ֵΪ8
	uint32_t			sampleRate;								// �����ʣ���16k ����ֵΪ16000	
	int					transMode;								// 1 tcp,2 udp;

	//SCS���أ�����ʱ��ʹ��
	int					cmsaudioType;							// 1 PCM��2 G.711��3 G.723��4 G.726��5 G.729
	int					cmsaudioBit;							// ��ʵ�ʵ�ֵ��ʾ����8λ ����ֵΪ8
	uint32_t			cmssampleRate;							// �����ʣ���16k ����ֵΪ16000
	int					callId;
	int					dlgId;
}StartCallParam_t;

//InviteCall���صĶԽ�����
typedef struct tagInviteCallResponse
{
	int					audioType;							// 1 PCM��2 G.711��3 G.723��4 G.726��5 G.729
	int					audioBit;							// ��ʵ�ʵ�ֵ��ʾ����8λ ����ֵΪ8
	uint32_t			sampleRate;							// �����ʣ���16k ����ֵΪ16000	
	char				rtpServIP[DPSDK_CORE_IP_LEN];
	int					rtpPort;
	dpsdk_call_type_e	nCallType;							//�������ͣ������������
	char				groupID[DPSDK_CORE_CHL_ID_LEN];		//������ID�����ʱΪ��ID������ʱΪID#IP
	char				callerID[DPSDK_CORE_CHL_ID_LEN];	//������ID
	char				sendChnlID[DPSDK_CORE_CHL_ID_LEN];	//����ͨ��������ʱ�Ż��õ�
	char				recvChnlID[DPSDK_CORE_CHL_ID_LEN];	//����ͨ������������Ҫ����
	int					callId;
	int					dlgId;
	int                 tid;
}InviteCallParam_t;

//��Ƶ�ɼ�����
typedef struct tagAudioRecrodParam
{
	dpsdk_audio_type_e		audioType;								// 1 PCM��2 G.711��3 G.723��4 G.726��5 G.729
	dpsdk_talk_bits_e		audioBit;								// ��ʵ�ʵ�ֵ��ʾ����8λ ����ֵΪ8
	Talk_Sample_Rate_e		sampleRate;								// �����ʣ���16k ����ֵΪ16000
}AudioRecrodParam_t;

//��Ⱥ�Խ��ṹ�嶨�� end

//���ӶԽ��ṹ�嶨�� begin

//����Խ�����
typedef struct tagInviteVtCallParam
{
	int					audioType;						// 1 PCM��G.711��G.723��G.726��G.729
	int					audioBit;						// ��ʵ�ʵ�ֵ��ʾ����λ����ֵΪ
	uint32_t			sampleRate;						// �����ʣ���k ����ֵΪ
	char				rtpServIP[DPSDK_CORE_IP_LEN];	// Զ��RTP IP
	int					rtpAPort;						// ��Ƶ�˿�
	int					rtpVPort;						// ��Ƶ�˿�
	dpsdk_call_type_e	nCallType;						// �������ͣ������������
	char				szUserId[DPSDK_CORE_CHL_ID_LEN];						// ������ID
	int					callId;
	int					dlgId;
	int                 tid;
}InviteVtCallParam_t;

//����֪ͨ����
typedef struct tagRingInfo
{
	char		szUserId[DPSDK_CORE_CHL_ID_LEN];				// �豸ID��ͨ��ID
	int			callId;
	int			dlgId;
	int			tid;
}RingInfo_t;

//���ӶԽ�״̬��æ֪ͨ����
typedef struct tagBusyVtCall
{
	char		szUserId[DPSDK_CORE_CHL_ID_LEN];				// �豸ID��ͨ��ID
	int			callId;
	int			dlgId;
}BusyVtCallInfo_t;

//���ӶԽ�Ӧ�����
typedef struct tagStartVtCallResponse
{
	int					videoPort;						// ������Ƶ�˿�
	int					audioPort;						// ������Ƶ�˿�
	char				rtpServIP[DPSDK_CORE_IP_LEN];	// Զ��RTP IP
	int					rtpAPort;						// Զ��RTP��Ƶ�˿�
	int					rtpVPort;						// Զ��RTP��Ƶ�˿�
	int					talkMode;						// �Խ�ģʽ0�Խ�1�㲥��������
	int					audioType;						// 1 PCM��G.711��G.723��G.726��G.729
	int					audioBit;						// ��ʵ�ʵ�ֵ��ʾ����λ����ֵΪ
	uint32_t			sampleRate;						// �����ʣ���k ����ֵΪ	
	int					callId;
	int					dlgId;
}StartVtCallParam_t;


//��Ⱥ�Խ��ṹ�嶨�� end

typedef enum
{
	LOG_INFO,  //��Ϣ
	LOG_DEBUG,	//����
	LOG_ERROR,	//����	
}dpsdk_log_type_e;

// ý������ҵ����� 
typedef enum
{
	DPSDK_MEDIA_INVALID,
	DPSDK_MEDIA_REAL =1, //ʵʱ
	DPSDK_MEDIA_PLAYBACK =2,//�ط�
	DPSDK_MEDIA_TALK,
	DPSDK_MEDIA_BAY,
	DPSDK_MEDIA_CALL,
	DPSDK_MEDIA_BROADCAST,
}dpsdk_media_func_e;


/***************************************************************************************
 @ ���Ͷ������
***************************************************************************************/



/***************************************************************************************
 @ �ص���������
***************************************************************************************/

/** DPSDK ״̬�ص�.
 @param   IN									nPDLLHandle				SDK���
 @param   IN									nStatus					1 �������� 2�������
 @param   IN 									pUserParam				�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKStatusCallback)( IN int32_t nPDLLHandle, 
														IN int32_t nStatus, 
														IN void*   pUserParam );

/** OSD��Ϣģ��ص�.
 @param   IN									nPDLLHandle				SDK���
 @param   IN									pXML              �ص���Ϣ
 @param   IN									nLen					XML�ַ�����
 @param   IN 									pUserParam				�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 @remark									
*/
typedef int32_t(DPSDK_CALLTYPE *fDPSDKOSDTemplatCallback)( IN int32_t nPDLLHandle,
														  IN char* pXML,
														  IN int32_t nLen,
														  IN void* pUserParam  );

/** OSD��Ϣģ��ص�.
 @param   IN									nPDLLHandle				SDK���
 @param   IN									pXML              �ص���Ϣ
 @param   IN									nLen					XML�ַ�����
 @param   IN 									pUserParam				�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 @remark									
*/
typedef int32_t(DPSDK_CALLTYPE *fDPSDKHistoryOSDCallback)( IN int32_t nPDLLHandle,
														  IN char* pXML,
														  IN int32_t nLen,
														  IN void* pUserParam  );

/** DPSDK �豸�޸Ļص�.
 @param   IN									nPDLLHandle				SDK���
 @param   IN									nChangeType				�ο�dpsdk_change_type_e
 @param   IN									szDeviceId              �豸Id
 @param   IN									szDepCode               ��֯Code
 @param   IN									szNewOrgCode            ����֯Code   
 @param   IN 									pUserParam				�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKDeviceChangeCallback)( IN int32_t  nPDLLHandle, 
															  IN uint32_t nChangeType, 
															  IN const char* szDeviceId, 
															  IN const char* szDepCode, 
															  IN const char* szNewOrgCode,
															  IN void* pUserParam );

/** DPSDK ����֯�豸����ص�.
 @param   IN									nPDLLHandle				SDK���
 @param   IN									nOrgChangeType				�ο�dpsdk_org_change_type_e
 @param   IN									szOrgCode				��֯ID�����ID�ԡ�|���ָ�
 @param   IN 									pUserParam				�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKOrgDevChangeNewCallback)( IN int32_t  nPDLLHandle, 
															  IN uint32_t nChangeType,
															  IN const char* szOrgCode,
															  IN void* pUserParam );

/** DPSDK �豸�޸Ļص�. 
 @param   IN									nPDLLHandle				SDK���
 @param   IN									nChangeType				�ο�dpsdk_dsst_change_type_e
 @param   IN									nCount                  �¼�¼����
 @param   IN									pOrgInfo                �޸ĵ��¼�¼
 @param   IN 									pUserParam				�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKOrgChangeCallback)( IN int32_t nPDLLHandle, 
														   IN uint32_t nChangeType, 
														   IN uint32_t nCount, 
														   IN Org_Info_t* pOrgInfo,
														   IN void* pUserParam );

/** DPSDK ��Ա�޸Ļص�.
 @param   IN									nPDLLHandle				SDK���
 @param   IN									pNodeType				�ο�dpsdk_dsst_change_type_e
 @param   IN									nCount                  �¼�¼����
 @param   IN									pPersonInfo             �޸ĵ��¼�¼
 @param   IN 									pUserParam				�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKPersonChangeCallback)( IN int32_t nPDLLHandle, 
															  IN uint32_t nChangeType, 
															  IN uint32_t nCount, 
															  IN Person_Info_t* pPersonInfo,
															  IN void* pUserParam );

/** DPSDK �����޸Ļص�.
 @param   IN									nPDLLHandle				SDK���
 @param   IN									pNodeType				�ο�dpsdk_org_node_e
 @param   IN									szOrgCode               ԭ��֯code
 @param   IN									pCarInfo                �޸ĵ��¼�¼
 @param   IN 									pUserParam				�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKCarChangeCallback)( IN int32_t nPDLLHandle, 
                                                           IN uint32_t nChangeType, 
                                                           IN const char* szCode, 
														   IN Car_Info_t* pCarInfo,
														   IN void* pUserParam );


/** ý�����ݻص�.
 @param   IN									nPDLLHandle				SDK���
 @param   IN									nSeq					��Ӧ����ʱ���ص�Seq
 @param   IN									nMediaType				ý�����ͣ��ο�dpsdk_media_type_e
 @param	  IN									szNodeId				���ݶ�Ӧ��ͨ��/�豸ID
 @param	  IN 									nParamVal				��չֵ;mediaTypeΪrealʱ��ΪstreamType;
 @param	  IN 									szData					ý��������
 @param   IN 									nDataLen				���ݳ��� 
 @param   IN 									pUserParam				�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fMediaDataCallback)( IN int32_t nPDLLHandle,
													  IN int32_t nSeq, 
													  IN int32_t nMediaType, 
													  IN const char* szNodeId, 
													  IN int32_t nParamVal, 
													  IN char* szData, 
													  IN int32_t nDataLen,
													  IN void* pUserParam );

/** ý�����ݻص�.
 @param   IN									nPDLLHandle				SDK���
 @param   IN									nSeq					��Ӧ����ʱ���ص�Seq
 @param   IN									nMediaType				ý�����ͣ��ο�dpsdk_media_type_e
 @param	  IN									szNodeId				���ݶ�Ӧ��ͨ��/�豸ID
 @param	  IN 									nParamVal				��չֵ;mediaTypeΪrealʱ��ΪstreamType;
 @param	  IN 									szData					ý��������
 @param   IN 									nDataLen				���ݳ��� 
 @param   IN 									pUserParam				�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fMediaDataByAnalysisCallback)( IN int32_t nPDLLHandle,
													  IN int32_t nSeq, 
													  IN int32_t nMediaType, 
													  IN const char* szNodeId, 
													  IN int32_t nParamVal,
													  IN bool bHead,
													  IN char* szData, 
													  IN int32_t nDataLen,
													  IN void* pUserParam );


/** �����ص�.
 @param   IN									nPDLLHandle				SDK���
 @param   IN									szAlarmId               ����Id
 @param   IN									nDeviceType             �豸����
 @param   IN									szCameraId              ͨ��Id
 @param   IN									szDeviceName            �豸����
 @param   IN									szChannelName           ͨ������
 @param   IN									szCoding                ����
 @param   IN									szMessage               ������Ϣ����ͨ������Ϣ���ݣ�
 @param   IN									nAlarmType              �������ͣ��ο�dpsdk_alarm_type_e
 @param   IN									nEventType              �����������ͣ��ο�dpsdk_event_type_e
 @param   IN									nLevel                  �����ȼ�
 @param   IN									nTime                   ����ʱ��
 @param   IN									pAlarmData              �������ݣ����ܱ���ʹ�ã�
 @param   IN									nAlarmDataLen           �������ݳ���
 @param   IN									pPicData                ͼƬ����
 @param   IN									nPicDataLen             ͼƬ���ݳ���
 @param   IN									pUserParam              �û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKAlarmCallback)( IN int32_t nPDLLHandle,
													   IN const char* szAlarmId, 
													   IN uint32_t nDeviceType,
													   IN const char* szCameraId,
													   IN const char* szDeviceName,
													   IN const char* szChannelName,
													   IN const char* szCoding,
													   IN const char* szMessage,
													   IN uint32_t nAlarmType,
													   IN uint32_t nEventType,
													   IN uint32_t nLevel,
													   IN int64_t nTime,
													   IN char* pAlarmData,
													   IN uint32_t nAlarmDataLen,
													   IN char* pPicData,
													   IN uint32_t nPicDataLen,
													   IN void* pUserParam);


/** �±����ص�.
 @param   IN									nPDLLHandle				SDK���
 @param   IN									szAlarmId               ����Id
 @param   IN									nDeviceType             �豸����
 @param   IN									szDeviceId				�豸ID
 @param   IN									nChannelNo				ͨ����
 @param   IN									szDeviceName            �豸����
 @param   IN									szChannelName           ͨ������
 @param   IN									szCoding                ����
 @param   IN									szMessage               ������Ϣ����ͨ������Ϣ���ݣ�
 @param   IN									nAlarmType              �������ͣ��ο�dpsdk_alarm_type_e
 @param   IN									nEventType              �����������ͣ��ο�dpsdk_event_type_e
 @param   IN									nLevel                  �����ȼ�
 @param   IN									nTime                   ����ʱ��
 @param   IN									pAlarmData              �������ݣ����ܱ���ʹ�ã�
 @param   IN									nAlarmDataLen           �������ݳ���
 @param   IN									pPicData                ͼƬ����
 @param   IN									nPicDataLen             ͼƬ���ݳ���
 @param   IN									pUserParam              �û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKNewAlarmCallback)(int32_t nPDLLHandle,
														const char* szAlarmId, 
														uint32_t nDeviceType,
														const char* szDeviceId,
														uint32_t nChannelNo, 
														const char* szDeviceName,
														const char* szChannelName,
														const char* szCoding,
														const char* szMessage,
														uint32_t nAlarmType,
														uint32_t nEventType,
														uint32_t nLevel,
														int64_t nTime,
														char* pAlarmData,
														uint32_t nAlarmDataLen,
														char* pPicData,
														uint32_t nPicDataLen,
														void* pUserParam);

/** �豸״̬�ص�.
 @param   IN									nPDLLHandle		        SDK���
 @param   IN									szDeviceId              �豸ID��DVR+ͨ����
 @param   IN									nStatus		            �ο�dpsdk_device_status_type_e
 @param   IN 									pUserParam		        �û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKDevStatusCallback)( int32_t nPDLLHandle, 
														   const char* szDeviceId,
														   int32_t nStatus, 
														   void* pUserParam );

/** ͨ��״̬�ص�.

*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKNVRChnlStatusCallback)( IN int32_t nPDLLHandle, 
															  IN const char* szChnlId,
															  IN int32_t nStatus, 
															  IN void* pUserParam );

/** ͼƬ���ݻص���������
 @param	  IN	                                nPDLLHandle				SDK���
 @param   IN	                                session					��Ӧ����ʱ���ص�session
 @param	  IN	                                nodeId					���ݶ�Ӧ��ͨ��/�豸ID
 @param	  IN	                                pData					ͼƬ������
 @param	  IN	                                dataLen					���ݳ��� 
 @param	  IN	                                pUserParam				�û�����
 @param	  IN	                                notify_e				ͼƬ��������
*/
//typedef int32_t (DPSDK_CALLTYPE *fDPSDKPicDataCallback)( IN int32_t nPDLLHandle, 
//														   IN int session, 
//														   IN const char* nodeId, 
//														   IN char* pData, 
//														   IN int dataLen, 
//														   IN void* pUserParam, 
//														   IN dpsdk_picdata_notify_e enNotify);	// fixme::��ö��������Ҫ���¶���

/** ����Υ���ϱ��ص���������
 @param	  IN	                                nPDLLHandle				 SDK���
 @param	  IN	                                pRetInfo				 ��Ӧ����ʱ���ص�session
 @param	  IN	                                pUserParam				 �û�����
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKTrafficAlarmCallback)( IN int32_t nPDLLHandle, 
															  IN Traffic_Alarm_Info_t* pRetInfo, 
															  IN void* pUserParam );

/** �����ϱ��ص���������
 @param	  IN	                                nPDLLHandle			     SDK���
 @param	  IN	                                pRetInfo				 ��Ӧ����ʱ���ص�session
 @param	  IN	                                pUserParam				 �û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKGetTrafficFlowCallback)( IN int32_t nPDLLHandle, 
																IN TrafficFlow_Info_t* pRetInfo,
																IN void* pUserParam );

/** ��������״̬�ϱ��ص���������
    @param IN                                   nPDLLHandle              SDK���
    @param IN                                   pRetInfo                 ��Ӧ����ʱ���ص�������Ϣ
    @param IN                                   pUserParam               �û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKGetDevTrafficFlowCallback)( IN int32_t nPDLLHandle,
																   IN DevTrafficFlow_Info_t* pRetInfo, 
																   IN void* pUserParam );


 
/** ���ڹ�����Ϣ�ϱ��ص���������
    @param IN                                    nPDLLHandle              SDK���
    @param IN                                    pRetInfo                 ��Ӧ����ʱ���ص�������Ϣ
    @param IN                                    pUserParam               �û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKGetBayCarInfoCallback)( IN int32_t nPDLLHandle,
															   IN Bay_Car_Info_t* pRetInfo, 
															   IN void* pUserParam );

/** ���ڹ�����Ϣ�ϱ��ص���������
    @param IN                                    nPDLLHandle              SDK���
    @param IN                                    pUserParam               �û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
	@remark	����������ο�Bay_Car_Info_t
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKGetBayCarInfoCallbackEx)(int32_t nPDLLHandle,
																const char*	szDeviceId,
																int32_t	nDeviceIdLen,
																int32_t	nDevChnId,
																const char* szChannelId,
																int32_t nChannelIdLen,
																const char*	szDeviceName,
																int32_t	nDeviceNameLen,
																const char*	szDeviceChnName,
																int32_t	nChanNameLen,
																const char*	szCarNum,
																int32_t nCarNumLen,
																int32_t	nCarNumType,
																int32_t	nCarNumColor,
																int32_t	nCarSpeed,
																int32_t	nCarType,
																int32_t	nCarColor,
																int32_t	nCarLen,
																int32_t	nCarDirect,
																int32_t	nWayId,
																uint64_t	lCaptureTime,
																unsigned long	lPicGroupStoreID,
																int32_t	nIsNeedStore,
																int32_t	nIsStoraged,
																const char*	szCaptureOrg,
																int32_t	nCaptureOrgLen,
																const char*	szOptOrg,
																int32_t	nOptOrgLen,
																const char*	szOptUser,
																int32_t	nOptUserLen,
																const char*	szOptNote,
																int32_t	nOptNoteLen,
																const char*	szImg0Path,
																int32_t	nImg0PathLen,
																const char*	szImg1Path,
																int32_t	nImg1PathLen,
																const char*	szImg2Path,
																int32_t	nImg2PathLen,
																const char*	szImg3Path,
																int32_t	nImg3PathLen,
																const char*	szImg4Path,
																int32_t	nImg4PathLen,
																const char*	szImg5Path,
																int32_t	nImg5PathLen,
																const char*	szImgPlatePath,
																int32_t	nImgPlatePathLen,
																int32_t	icarLog,
																int32_t	iPlateLeft,
																int32_t	iPlateRight,
																int32_t	iPlateTop,
																int32_t	iPlateBottom, 
															    void* pUserParam );

/** ��������ϱ��ص���������
    @param IN                                    nPDLLHandle              SDK���
    @param IN                                    pRetInfo                 ��Ӧ����ʱ���ص�������Ϣ
    @param IN                                    pUserParam               �û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKGetAreaSpeedDetectCallback)( IN int32_t nPDLLHandle,
																	IN Area_Detect_Info_t* pRetInfo, 
																	IN void* pUserParam );

/** �¼��ϱ��ص���������
    @param IN                                    nPDLLHandle              SDK���
    @param IN                                    pIssueInfo               �¼��ϱ���Ϣ
    @param IN                                    pUserParam               �û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKIssueCallback)( IN int32_t nPDLLHandle,
													  IN Issue_Info_t* pIssueInfo, 
													  IN void* pUserParam );

/** FtpͼƬ�ص���������
    @param IN                                    nPDLLHandle              SDK���
    @param IN                                    pFtpPicInfo               �¼��ϱ���Ϣ
    @param IN                                    pUserParam               �û�����
*/
// typedef int32_t (DPSDK_CALLTYPE *fDPSDKFtpPicCallback)( IN int32_t nPDLLHandle,
// 														IN Ftp_Pic_Info_t* pFtpPicInfo, 
// 														IN void* pUserParam );

/** ��̨��λ������Ϣ�ص�
	@param	IN	int32_t nPDLLHandle								        SDK���
    @param	IN	 pRetInfo										        ��̨��Ϣ
	@param	IN	void* pUserParam							            �û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKPtzSitAlarmInfoCallback)( IN int32_t nPDLLHandle, 
															     IN Ptz_Sit_Alarm_Info* pRetInfo,
																 IN void* pUserParam );	

/** ���ڲ��ظ澯�ϱ��ص���������
 @param	  IN	                                nPDLLHandle		       SDK���
 @param	  IN	                                pRetInfo				 ��Ӧ����ʱ���ص�session
 @param	  IN	                                pUserParam			 �û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKBayWantedAlarmCallback)( IN int32_t nPDLLHandle, 
															       IN Bay_WantedAlarm_Info_t* pRetInfo, 
															       IN void* pUserParam );

/** �ļ������ص���������
 @param	  IN	                                 nPDLLHandle			 SDK���
 @param	  IN	                                 szLocalFile			 �����ļ�·��
 @param	  IN	                                 szRemoteFile			 Զ���ļ�·��
 @param	  IN	                                 optype					 ��������
 @param	  IN	                                 progress				 ��������
 @param	  IN	                                 pUserParam				 �û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKOperatorRemoteFileCallback)( IN int32_t nPDLLHandle,
																    IN char* szLocalFile,
																	IN char* szRemoteFile,
																	IN dpsdk_operator_remote_file_type_e optype,														
																	IN int32_t progress,
																	IN void* pUserParam );

/** �첽������֯�ṹ�ص�.
 @param   IN									 nRet				      ����LoadDGroupInfo�ķ���ֵ
 @param   IN                                     nGroupLen                ��LoadDGroupInfo�ɹ���nGroupLenΪGroupInfo�ַ����ĳ���
 @remark									
*/
typedef void (DPSDK_CALLTYPE *fAsyncLoadDGroupInfoCallback)( IN int32_t nPDLLHandle,
																IN int32_t nRet,
																IN int32_t nGroupLen,
																IN void* pUserParam);

/** ��Ƶ������Ϣ�ص�
 @param   IN                                    nPDLLHandle               SDK���
 @param   IN                                    pVideoInfo                �������Ƶ����
 @param   IN                                    nVideoCount               ��Ƶ����
 @param   IN                                    szMsg                     ����ʱ���ӵ���Ϣ
 @param   IN                                    nSrcUserId                �����˵�userId
 @param   IN                                    szSrcUserName             �����˵��û���
 @param   IN                                    pUserParam                �û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKShareVideoCallback)( IN int32_t nPDLLHandle, 
													   IN ShareVideoInfo* pVideoInfo,
													   IN int32_t nVideoCount,
													   IN const char* szMsg, 
													   IN int32_t nSrcUserId,
													   IN const char* szSrcUserName,
													   IN void* pUserParam );

/** �����Խ���Ϣ���ص���������
 @param	  IN	                                nPDLLHandle		    SDK���
 @param	  IN	                                nAudioType			��Ƶ����
 @param	  IN	                                nAudioBit			λ��
 @param	  IN	                                nSampleRate			������
 @param	  IN	                                nTransMode			��������
 @param	  IN	                                pUserParam			�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKTalkParamCallback)(  IN int32_t nPDLLHandle,
														 	IN int32_t nTalkType,
															IN int32_t nAudioType, 
															IN int32_t nAudioBit,
															IN int32_t nSampleRate, 
															IN int32_t nTransMode,
															IN void* pUserParam );

/** �����豸Զ��ץ�Ļص�
 @param   IN           nPDLLHandle               SDK���
 @param   IN           szCameraId                ͨ��ID
 @param   IN           szFullPath                �ļ�ȫ·����
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKRemoteDeviceSnapCallback) (int32_t nPDLLHandle,
																  const char* szCameraId,
																  const char* szFullPath,
																  void *pUser);

/** �첽ִ��ʵʱԤ����Ƶ�Ľ���ص�
 @param   IN      nPDLLHandle       SDK���
 @param   IN      nRealFlag         �� StartRealplayAsync���ص�nRealFlagһ��
 @param   IN      nSeq              ��Ϊ���������Ĳ������� �� DPSDK_StopRealplayBySeq
 @param   IN      nRet              ������
 @param   IN      pUserParam        �û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKStartRealplayCallback) (int32_t nPDLLHandle,
															   int32_t nRealFlag,
															   int32_t nSeq,
															   int32_t nRet,
															   void* pUserParam);

/** ��Ƶ��������������/��·״̬�ص�
 @param	  IN	                                nPDLLHandle		    SDK���
 @param	  IN	                                szDeviceId			�豸Id
 @param	  IN	                                nChannelNO			ͨ���ţ��豸����ͨ������-1
 @param	  IN	                                nStatus				״̬���ο�dpsdk_videoalarmhost_status_type_e
 @param	  IN	                                pUserParam			�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 ��Ƶ���������ڿͻ��˵�½��ʱ��DMS���ϱ�״̬���ͻ��˲�����֪ͨ�����ͻ��ˡ�
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKVideoAlarmHostStatusCallback)(  IN int32_t nPDLLHandle,
														 	IN char*   szDeviceId,
															IN int32_t nChannelNO, 
															IN int32_t nStatus,
															IN void* pUserParam );

/** ���籨������������/��·״̬�ص�
 @param	  IN	                                nPDLLHandle		    SDK���
 @param	  IN	                                szDeviceId			������ʱ���豸Id;��·/ȡ����·ʱ��ͨ��id
 @param	  IN	                                nRType				�ϱ����ͣ��ο�dpsdk_netalarmhost_report_type_e��1������2��·
 @param	  IN	                                nOperType			�������ͣ��ο�dpsdk_netalarmhost_operator_e��1�豸������2ͨ������
 @param	  IN	                                nStatus				״̬�����ڷ���״̬1����2������������·״̬1��·2ȡ����·
 @param	  IN	                                pUserParam			�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
 ���籨������״̬Ҫ�Լ���ѯ���ͻ��˲�����֪ͨ�����ͻ��ˡ�
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKNetAlarmHostStatusCallback)(  IN int32_t nPDLLHandle,
														 	IN char*   szDeviceId,
															IN int32_t nRType, 
															IN int32_t nOperType,
															IN int32_t nStatus,
															IN void* pUserParam );
/** ͼƬ���ݻص���������
    @param int session												��Ӧ����ʱ���ص�session
    @param const char* nodeId										���ݶ�Ӧ��ͨ��/�豸ID
    @param char* pData												ͼƬ������
    @param int dataLen												���ݳ��� 
	@param void* pUserParam											�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
	@param dpsdk_picdata_notify_e notify_e							ͼƬ��������
*/
typedef int (DPSDK_CALLTYPE *fPicDataCallback)(int session, const char* nodeId, char* pData, int dataLen, void* pUserParam, dpsdk_picdata_notify_e notify_e);

/** Json����Э��ص�
	@param szJson	Json�ַ���
*/
typedef int (DPSDK_CALLTYPE* fDPSDKGeneralJsonTransportCallback)(IN int32_t nPDLLHandle, IN const char* szJson, void* pUserParam);

/** Json����Э��ص�
	@param szJson	Json�ַ���
*/
typedef int (DPSDK_CALLTYPE* fDPSDKGeneralJsonTransportCallbackEx)(int32_t nPDLLHandle, const char* szJson, int nJsonLen, void* pUserParam);


/** ����Χ���ı�ص���������
	@param void* pUserParam											
*/
typedef int (DPSDK_CALLTYPE *fDPSDKAreaChangeCallback)(int32_t nPDLLHandle, void* pUserParam);

/** ������ϵ�ı�ص���������
	@param void* pUserParam											
*/
typedef int (DPSDK_CALLTYPE *fDPSDKRelationChangeCallback)(int32_t nPDLLHandle, void* pUserParam);

/** �Ű���Ϣ�ı�ص���������
	@param	<IN>	                                nPDLLHandle		    SDK���
	@param	<IN>	                                LineID				��·id
	@param	<IN>									pUserParam			�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int (DPSDK_CALLTYPE *fDPSDKBusScheduleChangeCallback)(int32_t nPDLLHandle, int LineID, void* pUserParam);

/** �Ű���Ϣ�ı�ص���������
	@param	<IN>	                                nPDLLHandle		    SDK���
	@param	<IN>	                                LineID				��·id
	@param	<IN>	                                LineType			��·����
	@param	<IN>	                                PlanId				�ƻ�id
	@param	<IN>	                                State				״̬
	@param	<IN>	                                DevId				�豸id
	@param	<IN>	                                Time				ʱ��
	@param	<IN>									pUserParam			�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int (DPSDK_CALLTYPE *fDPSDKBusScheduleStateChangeCallback)(int32_t nPDLLHandle,
																   int LineID,
																   int LineType,
																   int PlanId,
																   int State,
																   char* DevId,
																   char* Time,
																   void* pUserParam);
/** ������Ϣ�ص���������
	@param	<IN>	                                nPDLLHandle		    SDK���
	@param	<IN>	                                PlanID				�ƻ�id
	@param	<IN>	                                LineName			��·����
	@param	<IN>	                                DisPatchTime		����ʱ��
	@param	<IN>	                                State				״̬
	@param	<IN>	                                DevName				�豸����
	@param	<IN>	                                DepartTime			ʱ��
	@param	<IN>									pUserParam			�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int (DPSDK_CALLTYPE *fDPSDKDispitchInfoCallback)(int32_t nPDLLHandle,
														   int PlanID,
														   char* LineName,
														   int DisPatchTime,
														   int State,
														   char* DevName,
														   int DepartTime,
														   void* pUserParam);


/** Υ�±����ص���������
	@param void* pUserParam											
*/
typedef int (DPSDK_CALLTYPE *fDPSDKPeccancyAlarmCallback)(int32_t nPDLLHandle, Peccancy_Alarm_t* pAlarmInfo, void* pUserParam);

/** ����Ԥ������ص���������
	@param void* pUserParam											
*/
typedef int (DPSDK_CALLTYPE *fDPSDKAlarmSchemeCallback)(int32_t nPDLLHandle, AlarmSchemeChg_t* pAlarmInfo, void* pUserParam);

/** �û���Ϣ����ص���������
	@param void* pUserParam											
*/
typedef int (DPSDK_CALLTYPE *fDPSDKDataChangeCallback)(int32_t nPDLLHandle, DataChange_t* pDataChangeInfo, void* pUserParam);

/** ��Ⱥ�Խ�������в����ص�
	@param	<IN>	                                nPDLLHandle		    SDK���
	@param	<IN>	                                param				����������еĶԽ����������ڱ�����Ƶ�ɼ�
	@param	<IN>									pUserParam			�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int (DPSDK_CALLTYPE *fStartCallParamCallBack)(int32_t nPDLLHandle, StartCallParam_t* param, void* pUserParam);


/** ��Ⱥ�Խ�������������ص�
	@param	<IN>	                                nPDLLHandle		    SDK���
	@param	<IN>	                                param				������Խ��ĶԽ����������ڱ�����Ƶ�ɼ�
	@param	<IN>									pUserParam			�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int (DPSDK_CALLTYPE *fInviteCallParamCallBack)(int32_t nPDLLHandle, InviteCallParam_t* param, void* pUserParam);


/** ���ӶԽ�������������ص�
	@param	<IN>	                                nPDLLHandle		    SDK���
	@param	<IN>	                                param				������Խ��ĶԽ����������ڱ�����Ƶ�ɼ�
	@param	<IN>									pUserParam			�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int (DPSDK_CALLTYPE *fDPSDKInviteVtCallParamCallBack)(int32_t nPDLLHandle, InviteVtCallParam_t* param, void* pUserParam);

/** ����֪ͨ�ص�
	@param	<IN>	                                nPDLLHandle		    SDK���
	@param	<IN>	                                param				�������
	@param	<IN>									pUserParam			�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int (DPSDK_CALLTYPE * fDPSDKRingInfoCallBack)(int32_t nPDLLHandle, RingInfo_t* param, void* pUserParam);

/** ���ӶԽ�����״̬��æ֪ͨ�ص�
	@param	<IN>	                                nPDLLHandle		    SDK���
	@param	<IN>	                                param				״̬��æ��Ϣ����
	@param	<IN>									pUserParam			�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int (DPSDK_CALLTYPE * fDPSDKBusyVtCallCallBack)(int32_t nPDLLHandle, BusyVtCallInfo_t* param, void* pUserParam);

/** �����Խ���Ƶ���ͺ�������. 
    @param char * pData						ý��������
    @param int dataLen						���ݳ��� 
    @param void * pUserParam				�û�����,��AudioUserParam
*/
typedef void (DPSDK_CALLTYPE  *fAudioDataCallback)( char* pData, int dataLen, void* pUserParam );

/** �Ž�״̬�ϱ����պ�������. 
    @param char * szCamearId				�Ž�ͨ��ID
    @param int nStatus						���ݳ��� 
    @param int nTime						�ϱ�ʱ��
    @param void * pUserParam				�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef void (DPSDK_CALLTYPE  *fDPSDKPecDoorStarusCallBack)(int32_t nPDLLHandle, const char* szCamearId, dpsdk_door_status_e nStatus, int64_t nTime, void* pUserParam);


/** �豸���ͨ���Ŀ�������Ϣ�ص�. 
	@param	<IN>	                                nPDLLHandle		    SDK���
	@param	<IN>	                                szCamearId			ͨ��ID
	@param	<IN>	                                nDistance			���Ӿ���, ��λ:�� 
	@param	<IN>	                                nAngelH				ˮƽ���ӽǶ�, 0~1800, ��λ:ʮ��֮һ��
	@param	<IN>	                                nAzimuthH			ˮƽ��λ�Ƕ�, 0~3600, ��λ:ʮ��֮һ��
	@param	<IN>	                                nInclinationH		ˮƽ��б�Ƕ�, -900~900, ��λ:ʮ��֮һ��
	@param	<IN>									pUserParam			�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int32_t (DPSDK_CALLTYPE  *fDPSDKChannelViewInfoCallback)(int32_t nPDLLHandle, const char* szCamearId, int nDistance, int nAngelH, int nAzimuthH, int nInclinationH, void* pUserParam);


/** ��һ֡������Ϣ�ص�. 
	@param	<IN>	                                nPDLLHandle		    SDK���
	@param	<IN>	                                nSequence			�������кţ������ڹر��������� 
	@param	<IN>	                                szCamearId			ͨ��ID
	@param	<IN>	                                nCameraIDLen		ͨ��ID����
	@param	<IN>	                                nPlayMode			�������ͣ�1ʵʱ��2�طţ���ϸ�ο�dpsdk_media_func_e
	@param	<IN>	                                nFactoryType		���̱�ʾ	*- 0��ʾ������ͷ�ĳ�����������Ҫ�ڲ��������ĸ����̣�Ŀǰֻ֧�ִ󻪡�����������
																					*- 1��ʾ�󻪳���
																					*- 2��ʾ��������
																					*- 4��ʾ�����
																					*- 5��ʾ���ΰҵ
																					*- 6��ʾ����
																					*- 7��ʾ�ƺ�
																					*- 8��ʾ�ʳ�
																					*- 9��ʾ����
																					*- 10��ʾ���� 
																					*- 11��ʾ����
																					*- 12��ʾ��ά���ͣ���׺��ͨ��Ϊ801
																					*- 13��ʾ��ά���Ͱ忨,��׺��ͨ��Ϊsv4(��ͨ�ð汾��2��SDK��
																					*- 14��ʾ��������
																					*- 15��ʾ��ͨ
																					*- 16��ʾ��Ԫ��DB33
																					*- 17��ʾ����
																					*- 18��ʾ����
	@param	<IN>									pUserParam			�û�ָ�����,�ɶ�Ӧ��DPSDK_SetxxxxCallBack����
*/
typedef int32_t (DPSDK_CALLTYPE  *fMediaDataFirstFrameCallback)(int32_t nPDLLHandle, int nSequence, const char* szCamearId, int nCameraIDLen, int nPlayMode, int nFactoryType, void* pUserParam);

/***************************************************************************************
 @ �ص������������
***************************************************************************************/
#endif
