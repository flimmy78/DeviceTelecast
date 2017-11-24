/********************************************************************
    created:    2013/03/19
    created:    19:3:2013   11:33
    filename:   tmcp_sdk_defines.h
    author:     xukaijun@hikvision.com.cn at its

    @note HangZhou Hikvision System Technology Co., Ltd. All Right Reserved.
    purpose:
*********************************************************************/
#ifndef _tmcp_sdk_defines_
#define _tmcp_sdk_defines_

#include <stdio.h>
#include <time.h>
#include <string>

//////////////////////////////////////////////////////////////////////////
/*                                  ����5000ƽ̨SDK                       */

typedef void (CALLBACK * StreamCallback)(int handle,const char* data,int size,void *pUser);

typedef struct tagDivAreaInfo
{
    int         nAreaID;                // ���������ˮ��
    char     strAreaName[128];            // �����������
    int       nOutputAreaIndex;        // �����������
    BOOL     bUsedForAlarm;            // �Ƿ����ڱ���
    int         nDecIndex;                // ��������ͨ��

    tagDivAreaInfo* pNext;

    tagDivAreaInfo()
    {
        nAreaID = 0;
        memset(strAreaName ,0,128);
        nOutputAreaIndex = 0;
        bUsedForAlarm = FALSE;
        nDecIndex = 0;
        pNext = NULL;
    }

    tagDivAreaInfo &operator = (const tagDivAreaInfo &other)
    {
        if (this == &other)
        {
            return *this;
        }

        nAreaID = other.nAreaID;
        //_tcscpy_s(strAreaName,127,other.strAreaName);
        strncpy(strAreaName,other.strAreaName,127);
        nOutputAreaIndex = other.nOutputAreaIndex;
        bUsedForAlarm = other.bUsedForAlarm;
        nDecIndex = other.nDecIndex;
        pNext = NULL;

        return *this;
    }
}DIVAREAINFO, *PDIVAREAINFO;

typedef struct tagVideoOut
{
    int      nVideoOutID;        // ��Ƶ���ͨ����ˮ��
    int         nDecodeResID;        // ������Դ��ˮ��
    int       nOutputChanIndex;    // ���ͨ������
    int         nType;                // ���ͨ�����ͣ�0-BNC��1-VGA��
    char     strVideoOutName[128];    // ���ͨ������
    char     strVideoOutPos[128];    // �������λ��
    BOOL     bOutput;            //    �����ǣ�0-�������1-�����
    int         nDivType;            // ����ָ����ͣ�0-1���棻1-4���棻2-9���棻3-16���棩

    PDIVAREAINFO pDivAreaInfo;

    tagVideoOut* pNext;

    tagVideoOut()
    {
        nVideoOutID = -1;
        nDecodeResID = -1;
        nOutputChanIndex = -1;
        nType = -1;
        memset(strVideoOutName ,0,128);
        memset(strVideoOutPos ,0,128) ;
        bOutput = FALSE;
        nDivType = -1;
        pDivAreaInfo = NULL;
        pNext = NULL;
    }

    tagVideoOut &operator = (const tagVideoOut &other)
    {
        if (this == &other)
        {
            return *this;
        }
        nVideoOutID = other.nVideoOutID;
        nDecodeResID = other.nDecodeResID;
        nOutputChanIndex = other.nOutputChanIndex;
        nType = other.nType;
        //_tcscpy_s(strVideoOutName,127,other.strVideoOutName);
        //_tcscpy_s(strVideoOutPos,127,other.strVideoOutPos);
        strncpy(strVideoOutName,other.strVideoOutName,127);
        strncpy(strVideoOutPos,other.strVideoOutPos,127);
        bOutput = other.bOutput;
        nDivType = other.nDivType;

        PDIVAREAINFO pTmp = NULL;
        PDIVAREAINFO pPre = NULL;
        PDIVAREAINFO pHead = NULL;

        PDIVAREAINFO Next = other.pDivAreaInfo;
        while(Next != NULL)
        {
            try
            {
                pTmp = new DIVAREAINFO;
            }
            catch(...)
            {
                pTmp = NULL;
            }

            if (pTmp == NULL)
            {
                continue;
            }

            *pTmp = *Next;
            pTmp->pNext = NULL;

            if (pHead == NULL)
            {
                pHead = pTmp;
            }

            if (pPre != NULL)
            {
                pPre->pNext = pTmp;
            }

            pPre = pTmp;

            Next = Next->pNext;
        }
        pDivAreaInfo = pHead;
        pNext = NULL;

        return *this;
    }

    virtual ~tagVideoOut()
    {
        try
        {
            clearAreaInfo();
        }
        catch(...)
        {
            ;
        }
    }

    void clearAreaInfo()
    {
        PDIVAREAINFO pTmp = pDivAreaInfo;
        PDIVAREAINFO pNext = NULL;
        while(pTmp != NULL)
        {
            pNext = pTmp->pNext;
            delete pTmp;
            pTmp = pNext;
        }

        pDivAreaInfo = NULL;
    }
}VIDEOOUTINFO, *PVIDEOOUTINFO;



#define PLAY_START            10001 //��ʼ���� 
#define PLAY_PAUSE            10002 //��ͣ����
#define PLAY_FAST            10003 //�ӿ첥���ٶ�
#define PLAY_SLOW            10004 //���������ٶ�
#define PLAY_OFFSET_POS        10005 //���Ŷ�λλ��
#define PLAY_OFFSET_TIME    10006 //���Ŷ�λʱ��

#define _CONTROLUNIT       0x00        // �������� 
#define _REGION            0x01        // ����
#define _DEVICE            0x02        // ������
#define _CAMERA            0x03        // ����ͷ
#define _ALARMIN           0x04        // ��������
#define _ALARMOUT          0x05        // �������
#define _RECORDFILE        0x06        // ¼���ļ�
#define _MONITORSCREEN     0x07        // ��������
#define _SERVERLIST        0X08        // ������

// �������ĵ�������
namespace    Cell
{
    const char* const ControlUnitID = "ControlUnitID";            // ��������ID
    const char* const ControlUnitName = "ControlUnitName";        // ������������
    const char* const UpControlUnitID = "UpControlUnitID";        // �ϼ���������ID
}

//�����������
namespace  Region
{
    const char* const region_id = "region_id";                    // ����ID
    const char* const region_name = "region_name";                // ��������
    const char* const region_high = "region_high";                // �ϼ�����ID
    const char* const region_level = "region_level";            // ����ȼ�
    const char* const region_cellLsh = "region_cellLsh";        // ����������������ID
}


// �豸��������
namespace  Device
{
    const char* const device_id = "device_id";                    // �豸ID
    const char* const device_name = "device_name";                // �豸����
    const char* const device_type = "device_type";                // �豸����
    const char* const device_state = "device_state";            // �豸״̬ 0-���� 1-����
    const char* const device_talk = "device_talk";                // �Խ�ͨ����
    const char* const device_chan =  "device_chan";                // ͨ������
    const char* const ip_address = "ip_address";                // �豸IP��ַ
    const char* const device_port = "device_port";                // �豸�˿�
    const char* const cell_id = "cell_id";                        // ��������ID
    const char* const device_alarmin = "device_alarmin";        // �����������
    const char* const device_alarmout = "device_alarmout";        // �����������
}

// ����ͷ�豸��������
namespace  Camera
{
    const char* const category_id = "category_id";            // ���ID��0-ǹ��/1-����/2-����/3-��̨��
    const char* const device_id = "device_id";                // �豸ID
    const char* const device_name = "device_name";            // ����ͷ����
    const char* const device_type = "device_type";            // �豸���ͣ�����ͷ�̶�Ϊ0x3
    const char* const inport = "inport";                    // ͨ����
    const char* const ConnectType = "ConnectType";            // �������ͣ�0-TCP/1-UDP/2-MCAST/3-RTP��
    const char* const controlunit_id = "controlunit_id";    // ������������ID
    const char* const parent_device_id = "parent_device_id";// ���豸ID����������ID
    const char* const region_id = "region_id";                // ��������ID
    
    // IVMS8600 ��չ add by xukaijun
    const char* const camera_id = "camera_id";              // ��ص�ID
    const char* const user_index_code = "user_index_code";   // �û��Զ�����
}

// ���������������
namespace  Alarmin
{
    const char* const IO_id = "IO_id";                                // IO��Ϣ
    const char* const device_id = "device_id";                        // IO ID
    const char* const device_name = "device_name";                    // IO����
    const char* const device_type = "device_type";                    // �豸���ͣ���������̶�Ϊ0x4
    const char* const iochanindex = "iochanindex";                    // ͨ����
    const char* const parent_device_id = "parent_device_id";        // ���豸ID
    const char* const region_id = "region_id";                        // ��������ID
}

// ���������������
namespace  Alarmout
{
    const char* const IO_id = "IO_id";                                // IO��Ϣ
    const char* const device_id = "device_id";                        // IO ID
    const char* const device_name = "device_name";                    // IO����
    const char* const device_type = "device_type";                    // �豸���ͣ���������̶�Ϊ0x5
    const char* const iochanindex = "iochanindex";                    // ͨ����
    const char* const parent_device_id = "parent_device_id";        // ���豸ID
    const char* const region_id = "region_id";                        // ��������ID
}

// ¼���ļ���������
namespace  RecordFile
{
    const char* const starttime = "starttime";                    // ��ʼʱ��
    const char* const endtime = "endtime";                        // ����ʱ��
    const char* const type = "type";                            // �洢����
    const char* const filename = "filename";                    // �ļ���
    const char* const size = "size";                            // �ļ���С���ֽڣ�
}

//����������Ϣ
namespace MonitorScreen
{
    // IVMS5000 �߼� �Ѿ�����
    const char * const screenID = "screenID";                   //������ID
    const char * const MonitorName = "MoniterName";             //����������

    // IVMS8600 �汾
    const char * const TvwallID = "TvwallID";                   // ����ǽID
    const char * const DlpID = "DlpID";                         // ����ID
    const char * const WindowID = "WindowID";                   // ������ID
    const char * const AreaID = "AreaID";                       // ����ID
}

//////////////////////////////////////////////////////////////////////////


#define TMCP_SDK_OK                                             0
#define TMCP_SDK_TIME_OUT                                       3

#define TMCP_DOWNLOAD_SESSION_NULL                              0
// cms error start from 10000 and end with 60000
#define CMS_ERROR_START                                         10000
#define CMS_ERROR_END                                           60000

// for :future code developer
// notify: the error code between -1000 and 9999 are treated as gsoap error

// tmcp sdk start from -10001 and end with -20000
#define ERROR_LOGIN_FAILED_PASSWORD_ERROR_TMCP                  -10001
#define ERROR_LOGIN_FAILED_USERNAME_NOT_EXSITED_TMCP            -10002
#define ERROR_CONNECT_CMS_SERVER_FAILED_TMCP                    -10003
#define ERROR_LOCAL_AUTHORIZATION_FAILED_TMCP                   -10004
#define ERROR_LICENSE_AUTHORIZATION_FAILED_TMCP                 -10005
#define ERROR_END_POINT_URL_NOT_SETUP_TMCP                      -10006
#define ERROR_PARAMETER_INCORRECT_TMCP                          -10007
#define ERROR_NEW_MEMORY_FAILED_TMCP                            -10008
#define ERROR_LOGOUT_FAILED_TMCP                                -10009
#define ERROR_UNSUPPORT_DEVICE_TYPE                             -10010
#define ERROR_INITIAL_USER_RESOURCE_FAILED                      -10011
#define ERROR_LOGIN_FAILED_LICENSE_NOT_GRANTED                  -10012
#define ERROR_INIT_STREAM_CLIENT_FAILED_TMCP                    -10013
#define ERROR_INIT_STREAM_LAYER_FAILED_TMCP                     -10014
#define ERROR_ALREADY_INITIALIZED_TMCP                          -10015
#define ERROR_ALREADY_LOGIN_TMCP                                -10016
#define ERROR_DEVICE_NOT_LINK_PAG_SERVER_TMCP                   -10017
#define ERROR_LINKED_PAG_SERVER_NOT_FIND_TMCP                   -10019
#define ERROR_LINKED_VRM_SERVER_NOT_FIND_TMCP                   -10020
#define ERROR_APPLY_PTZ_CONTROL_FAILED_TMCP                     -10021
#define ERROR_SEND_PTZ_CONTROL_FAILED_TMCP                      -10022
#define ERROR_TVWALL_SEND_COMMAND_MSG_FAILED_TMCP               -10023
#define ERROR_TVWALL_PARSE_DATA_FAILED_TMCP                     -10024
#define ERROR_IP_ADDRESS_FORMAT_NOT_CORRECT                     -10025
#define ERROR_INITIAL_INTERNAL_FACTORY_FAILED                   -10026
#define ERROR_INITIAL_INTERNAL_CLIENT_LIB_FAILED                -10027
#define ERROR_SDK_HAVE_BEEN_OPENED                              -10028
#define ERROR_USER_SESSION_NOT_FIND                             -10029
#define ERROR_INIT_VAG_PLAY_CTRL_FAILED_TMCP                    -10030
#define ERROR_INIT_VAG_CLIENT_FAILED_TMCP                    -10031

#define ERROR_GET_STREAM_FAILED_STREAM_SERVER_TMCP              -10100
#define ERROR_GET_STREAM_FAILED_STREAM_LAYER_TMCP               -10101
#define ERROR_STREAM_SESSION_NOT_EXSITED_TMCP                   -10102
#define ERROR_SNAP_PICTURE_FAILED_TMCP                          -10103
#define ERROR_GET_CAMERA_INFO_FAILED_TMCP                       -10104
#define ERROR_GET_PAG_SERVER_FROM_CMS_FAILED_TMCP               -10105
#define ERROR_GET_DATA_FROM_CMS_CHECKOUT_ERROR_CODE_TMCP        -10106
#define ERROR_GET_STREAM_SERVER_FAILED_TMCP                     -10107
#define ERROR_GET_ALL_RS_FAILED_CONTROL_UNIT                    -10108
#define ERROR_GET_ALL_RS_FAILED_REGION                          -10109
#define ERROR_GET_ALL_RS_FAILED_SERVER                          -10110
#define ERROR_GET_ALL_RS_FAILED_DECODE_RESOURCE                 -10111
#define ERROR_GET_ALL_RS_FAILED_TVWALL                          -10112
#define ERROR_GET_ALL_RS_FAILED_DEVICE                          -10113
#define ERROR_GET_DEVICE_INFO_FAILED_TMCP                       -10114
#define ERROR_GET_DATA_FROM_CMS_EMPTY_TMCP                      -10115
#define ERROR_STOP_GET_STREAM_INTERNAL_ERROR                    -10116

#define ERROR_PLAYBACK_CHANGERATE_SET_PLAYER_FAILED             -10201
#define ERROR_PLAYBACK_ABSTIME_PLAY_FAILED                      -10202
#define ERROR_PLAYBACK_STREAM_NOT_START                         -10203
#define ERROR_PLAYBACK_PAUSE_STREAM_FAILED                      -10204
#define ERROR_PLAYBACK_RESUME_STREAM_FAILED                     -10205
#define ERROR_PLAYBACK_CHANGERATE_STREAM_FAILED                 -10206
#define ERROR_SEARCH_VIDEO_FAILED_TMCP                          -10207
#define ERROR_PLAYBACK_VIDEO_FAILED_TCMP                        -10208
#define ERROR_PLAYBACK_CAMERA_NO_RECORD_PLAN                    -10209
#define ERROR_PLAYBACK_NO_RECORD_VIDEO                          -10210
#define ERROR_PAUSE_DOWNLOAD_FAILED                             -10211
#define ERROR_RESUME_DOWMLOAD_FAILED                            -10212
#define ERROR_ENDTIME_EARLY_STARTTIME                              -10213
#define ERROR_NO_RECODE_VIDEO_IN_THIS_TIME                      -10214


#define ERROR_SUBSCRIBE_ALARM_FAILED                            -10301

#define ERROR_NO_PRIVILEGE										-10302
#define ERROR_DEVTALK_SESSION_NOT_EXISTED_TMCP					-10303

#define ERROR_CASC_START_REAL_STREAM_FAILED                    -10400
#define ERROR_CASC_START_PLAYBACK_FAILES                       -10401
#define ERROR_CASC_START_SNAP_FAILES                       -10402

#define ERROR_DEVICE_NOTSUPPORT                              -10500

// factory type code
#define PREALLOCATE_DEVICE_REGION                               10000
#define HIKVISION_DEVICE_TYPE                                   10000
#define DAHUATECH_DEVICE_TYPE                                   20000
#define VIVOTECH_DEVICE_TYPE                                    30000
#define HUASAN_DEVICE_TYPE                                      80000

#define ISEHOME(type) \
    type == 10030 || type == 10040 || type == 10050

#define ISGB28181(type) type == 98181

// predefine common character array length
#define TMCP_MAX_LEN_ERROR_INFO                                 128
#define TMCP_MAX_LEN_IP                                         32
#define TMCP_MAX_LEN_USERNAME                                   64
#define TMCP_MAX_LEN_PASSWORD									64
#define TMCP_MAX_LEN_DESCRIPTION_32								32
#define TMCP_MAX_LEN_DESCRIPTION_64								64
#define TMCP_MAX_LEN_DESCRIPTION_128                            128
#define TMCP_MAX_LEN_DESCRIPTION_256                            256
#define TMCP_MAX_LEN_DESCRIPTION_512                            512
#define TMCP_MAX_LEN_DESCRIPTION_1024                           1024
#define TMCP_MAX_LEN_DESCRIPTION_4096                           4096
#define TMCP_MAX_LEN_TIME_STRING                                26



typedef enum 
{
    login_type_normal = 0

}tmcp_enum_login_types;

typedef enum 
{
    chinese = 0,
    english
}tmcp_enmu_language;

typedef enum tagtmcp_enum_server_type
{
    stream_server_type = 0,
    vrm_server_type,
    pag_server_type,
    vms_server_type,
    ncg_server_type,
    vag_server_type
}tmcp_enmu_server_type;

typedef struct tagtmcp_login_request
{

}tmcp_login_request, *ptmcp_login_request;

typedef struct tagtmcp_login_info
{
    int ip_type;
    int user_id;
    int error_code;
    int control_uint_id;
    int privilege_code_size;
    int* privilege_code_array;
    char session_id[TMCP_MAX_LEN_DESCRIPTION_128];
    bool login_result;
    int userRightLevel;

    tagtmcp_login_info()
    {
        privilege_code_array = NULL;
        login_result = false;
    }

    ~tagtmcp_login_info()
    {
        if(privilege_code_array)
            delete [] privilege_code_array;
    }

}tmcp_login_info, *ptmcp_login_info;

typedef struct tagtmcp_control_unit_info
{
    int cmsCascadeId;
    int cmsCascadeType;
    int controlUnitId;
    time_t createTime;
    char description[TMCP_MAX_LEN_DESCRIPTION_128];
    char indexCode[TMCP_MAX_LEN_DESCRIPTION_128];
    char name[TMCP_MAX_LEN_DESCRIPTION_128];
    int operatorId;
    int parentId;
    int __sizeprivilegeCode;
    int *privilegeCode;
    int sequenceIdx;
    int streamSvId;
    int unitLevel;
    time_t updateTime;
    bool useStreamSv;

    tagtmcp_control_unit_info()
    {
        privilegeCode = NULL;
    }

    ~tagtmcp_control_unit_info()
    {
        if (privilegeCode)
            delete [] privilegeCode;
    }

}tmcp_control_unit_info, *ptmcp_control_unit_info;

typedef struct tagtmcp_region_info
{
    int controlUnitId;
    time_t createTime;
    char indexCode[TMCP_MAX_LEN_DESCRIPTION_128];
    char name[TMCP_MAX_LEN_DESCRIPTION_128];
    int operatorId;
    int parentId;
    int __sizeprivilegeCode;
    int* privilegeCode;
    int regionId;
    int regionLevel;
    char streamPath[TMCP_MAX_LEN_DESCRIPTION_128];
    int streamSvId;
    time_t updateTime;
    int useStreamSv;

    tagtmcp_region_info()
    {
        privilegeCode = NULL;
    }

    ~tagtmcp_region_info()
    {
        if (privilegeCode)
            delete [] privilegeCode;
    }

}tmcp_region_info, *ptmcp_region_info;

typedef struct tagtmcp_control_unit_list
{
    bool result;
    int size;
    int error_code;
    tmcp_control_unit_info* control_unit_list;

    tagtmcp_control_unit_list()
    {
        result = false;
        size = 0;
        error_code = 0;
        control_unit_list = NULL;
    }

    ~tagtmcp_control_unit_list()
    {
        if (control_unit_list)
            delete [] control_unit_list;
    }

}tmcp_control_unit_list, *ptmcp_control_unit_list;

typedef struct tagtmcp_region_list
{
    bool result;
    int size;
    int error_code;
    tmcp_region_info* region_list;

    tagtmcp_region_list()
    {
        result = false;
        size = 0;
        error_code = 0;
        region_list = NULL;
    }

    ~tagtmcp_region_list()
    {
        if (region_list)
            delete [] region_list;
    }

}tmcp_region_list, *ptmcp_region_list;

typedef struct tagtmcp_device_info
{
    int cmsCascadeId;
    int controlUnitId;
    int curState;
    int deviceId;
    char dnsAddr[TMCP_MAX_LEN_IP];
    short dnsPort;
    char indexCode[TMCP_MAX_LEN_DESCRIPTION_128];
    char name[TMCP_MAX_LEN_DESCRIPTION_128];
    char networkAddr[TMCP_MAX_LEN_IP];
    int networkPort;
    int __sizeprivilegeCode;
    int* privilegeCode;
    int registerType;
    char serialNo[TMCP_MAX_LEN_DESCRIPTION_128];
    int typeCode;
    char userName[TMCP_MAX_LEN_USERNAME];
    char userPwd[TMCP_MAX_LEN_PASSWORD];
    int pagServerId;
    int talkChanCount;
    int alarmInCount;
    int alarmOutCount;
    int cameraChanCount;
	int iVoiceDataType;

    tagtmcp_device_info()
    {
        indexCode[0]    = '\0';
        name[0]         = '\0';
        serialNo[0]     = '\0';
        userName[0]     = '\0';
        userPwd[0]      = '\0';
        privilegeCode = NULL;
    }

    ~tagtmcp_device_info()
    {
        if (privilegeCode)
            delete [] privilegeCode;
    }

}tmcp_device_info, *ptmcp_device_info;


typedef struct tagtmcp_device_list
{
    bool result;
    int size;
    int error_code;
    tmcp_device_info* device_list;

    tagtmcp_device_list()
    {
        result = false;
        size = 0;
        error_code = 0;
        device_list = NULL;
    }

    ~tagtmcp_device_list()
    {
        if (device_list)
            delete [] device_list;
    }
}tmcp_device_list, *ptmcp_device_list;

typedef struct tagtmcp_camera_info
{
    int cameraId;
    int cameraType;
    int chanNum;
    int connectType;
    int deviceId;
    char indexCode[TMCP_MAX_LEN_DESCRIPTION_128];
    char name[TMCP_MAX_LEN_DESCRIPTION_128];
    int __sizeprivilegeCode;
    int *privilegeCode;
    int __sizerecLacation;
    int* recLacation;
    int regionId;
    int controlUnitId;
    int sequenceIdx;
    short shareFlag;
    int streamType;
    int vrmId;
    int netZoneId;

	int iCmsCascadeId;		//����ID
	int iCascPrivilege;		//����Ȩ����	
	int iStatus;			//������ص�����״̬
	char cascadeIndexCode[TMCP_MAX_LEN_DESCRIPTION_128];
	char szDecoderTag[TMCP_MAX_LEN_DESCRIPTION_128];	//���������ʶ

	char latitude[TMCP_MAX_LEN_DESCRIPTION_128];  //ά��
	char longitude[TMCP_MAX_LEN_DESCRIPTION_128]; //����

    tagtmcp_camera_info()
    {
        indexCode[0] = '\0';
        name[0] = '\0';
		szDecoderTag[0] = '\0';
        privilegeCode = NULL;
        recLacation = NULL;

		iCmsCascadeId = -1;
		iCascPrivilege = 0;
		iStatus = -1;
		sprintf_s(szDecoderTag, TMCP_MAX_LEN_DESCRIPTION_128, "hikvision");
		cascadeIndexCode[0] = '\0';
		latitude[0] = '\0';
		longitude[0] = '\0';
    }

    ~tagtmcp_camera_info()
    {
        if (privilegeCode)
            delete [] privilegeCode;

        if (recLacation)
            delete [] recLacation;
    }
}tmcp_camera_info, *ptmcp_camera_info;

typedef struct tagtmcp_camera_list
{
    bool result;
    int size;
    int error_code;
    tmcp_camera_info* camera_list;

    tagtmcp_camera_list()
    {
        result = false;
        size = 0;
        error_code = 0;
        camera_list = NULL;
    }

    ~tagtmcp_camera_list()
    {
        if(camera_list)
            delete [] camera_list;
    }

}tmcp_camera_list, *ptmcp_camera_list;

typedef struct tagtmcp_server_info
{
    tmcp_enmu_server_type server_type;
    int controlUnitId;
    int serverId;
    char name[TMCP_MAX_LEN_DESCRIPTION_128];
    char indexCode[TMCP_MAX_LEN_DESCRIPTION_128];
    char IP[TMCP_MAX_LEN_IP];

    int pagCommandPort;         // for send ptz command to pag server based on hpp
    int rtspPort;               // for stream server to get video stream
    int videoSearchPort;        // for video record manager server search video
    int videoPlayBackPort;      // for video playback 
    int vms_data_port;          // for vms
    int vms_keyboard_port;      // for vms
    int vms_ws_port;            // for vms
	
	int ncg_client_port;		
	int ncg_data_port;
	int ncg_ctrl_port;
	int ncg_net_zone_id;

    tagtmcp_server_info()
    {
        controlUnitId = -1;
        serverId = -1;
        name[0] = '\0';
        indexCode[0] = '\0';
        IP[0] = '\0';
        pagCommandPort = -1;
        rtspPort = -1;
        videoSearchPort = -1;
        videoPlayBackPort = -1;
        vms_data_port = -1;
        vms_keyboard_port = -1;
        vms_ws_port = -1;

		ncg_client_port = 0;
		ncg_data_port = 0;
		ncg_ctrl_port = 0;
		ncg_net_zone_id = 0;
    }

}tmcp_server_info, *ptmcp_server_info;

typedef struct tagtmcp_server_list
{
    bool result;
    int size;
    int error_code;
    tmcp_server_info* server_list;

    tagtmcp_server_list()
    {
        result = false;
        size = 0;
        error_code = 0;
        server_list = NULL;
    }

    ~tagtmcp_server_list()
    {
        if(server_list)
            delete [] server_list;
    }
}tmcp_server_list, *ptmcp_server_list;


typedef struct tagtmcp_decode_device_info
{
    int audioNum;
    int bncNum;
    int controlUnitId;
    int decNum;
    int decodeDeviceId;
    int decodeMod;
    int decoderCode;
    int dviNum;
    int hdmiNum;
    int indexCode;
    int matrixId;
    char name[TMCP_MAX_LEN_DESCRIPTION_128];
    char networkAddr[TMCP_MAX_LEN_IP];
    int networkPort;
    int registerType;
    char serialNo[TMCP_MAX_LEN_DESCRIPTION_128];
    int typeCode;
    char userName[TMCP_MAX_LEN_USERNAME];
    char userPwd[TMCP_MAX_LEN_PASSWORD];
    int vgaNum;
    int vmsId;

    tagtmcp_decode_device_info()
    {
        name[0] = '\0';
        networkAddr[0] = '\0';
        serialNo[0] = '\0';
        userName[0] = '\0';
        userPwd[0] = '\0';
    }
}tmcp_decode_device_info, *ptmcp_decode_device_info;

typedef struct tagtmcp_decode_device_list
{

    bool result;
    int size;
    int error_code;
    tmcp_decode_device_info* decode_device_list;

    tagtmcp_decode_device_list()
    {
        result = false;
        size = 0;
        error_code = 0;
        decode_device_list = NULL;
    }

    ~tagtmcp_decode_device_list()
    {
        if(decode_device_list)
            delete [] decode_device_list;
    }
}tmcp_decode_device_list, *ptmcp_decode_device_list;

typedef int (CALLBACK *tmcp_streaming_data_callback)(int stream_session, void* userdata, int datatype, void* pdata, int datalen);
typedef int (CALLBACK *tmcp_streaming_msg_callback)(int stream_session, void* userdata, int msg_id);
typedef void (CALLBACK *tmcp_alarm_event_callback)(const char* camera_index, int alarm_type, const char* description, int alarm_level, const char* alarm_time, int action, void* user_data);

// msg_id
#define TMCP_STREAM_LAYER_E_CONNECT_FAIL              0
#define TMCP_STREAM_LAYER_E_NETWORK_EXCEPTION         1
#define TMCP_STREAM_LAYER_E_RECONNECT_FAIL            2
#define TMCP_STREAM_LAYER_E_RECONNECT_OK              3
#define TMCP_STREAM_LAYER_E_RECONNECT_OVER            4
#define TMCP_STREAM_LAYER_E_CONNECT_OK                5

typedef struct tagtmcp_start_streaming_info
{
    int camera_id;
    void* user_data;
    HWND display_window;                // Ԥ���ͻطŶ���ѡ
    const char* streaming_path;         // �طſ���Ϊ��
    ptmcp_camera_info camera_info;      // �طſ���Ϊ��
    ptmcp_device_info deviceo_info;     // �طſ���Ϊ��
    tmcp_streaming_msg_callback stream_msg_cb;
    tmcp_streaming_data_callback stream_data_cb;
    StreamCallback stream_data_cb_5000;

    tagtmcp_start_streaming_info()
    {
        camera_id = -1;
        display_window = NULL;
        user_data = NULL;
        streaming_path= NULL;
        camera_info = NULL;
        deviceo_info = NULL;
        stream_data_cb = NULL;
        stream_msg_cb = NULL;
        stream_data_cb_5000 = NULL;
    }

}tmcp_start_streaming_info, *ptmcp_start_streaming_info;



typedef enum tagtmcp_enum_ptz_command
{
    TCMP_PTZ_ZOOM_IN = 11,          // �����Ա��(���ʱ��)
    TCMP_PTZ_ZOOM_OUT = 12,         // �����С(���ʱ�С)
    TCMP_PTZ_FOCUS_IN = 13,         // ����ǰ��
    TCMP_PTZ_FOCUS_OUT = 14,        // ������

    TCMP_PTZ_TILT_UP = 21,         /* ��̨��SS���ٶ����� */
    TCMP_PTZ_TILT_DOWN = 22,       /* ��̨��SS���ٶ��¸� */
    TCMP_PTZ_PAN_LEFT = 23,        /* ��̨��SS���ٶ���ת */
    TCMP_PTZ_PAN_RIGHT = 24,       /* ��̨��SS���ٶ���ת */
    TCMP_PTZ_UP_LEFT = 25,         /* ��̨��SS���ٶ���������ת */
    TCMP_PTZ_UP_RIGHT = 26,        /* ��̨��SS���ٶ���������ת */
    TCMP_PTZ_DOWN_LEFT  = 27,      /* ��̨��SS���ٶ��¸�����ת */
    TCMP_PTZ_DOWN_RIGHT = 28,      /* ��̨��SS���ٶ��¸�����ת */
    TCMP_PTZ_PAN_AUTO = 29,        /* ��̨��SS���ٶ������Զ�ɨ�� */

    TCMP_PTZ_GOTO_PRESET = 39,     /* ����ת��Ԥ�õ� */

    TCMP_PTZ_TILT_UP_STOP = -21,    /* ֹͣ ��̨���� */
    TCMP_PTZ_TILT_DOWN_STOP = -22,  /* ֹͣ ��̨���� */
    TCMP_PTZ_PAN_LEFT_STOP = -23,   /* ֹͣ ��̨��ת */
    TCMP_PTZ_PAN_RIGHT_STOP = -24,  /* ֹͣ ��̨��ת */
    TCMP_PTZ_UP_LEFT_STOP = -25,    /* ֹͣ ��̨��SS���ٶ���������ת */
    TCMP_PTZ_UP_RIGHT_STOP = -26,   /* ֹͣ ��̨��SS���ٶ���������ת */
    TCMP_PTZ_DOWN_LEFT_STOP = -27,  /* ֹͣ ��̨��SS���ٶ��¸�����ת */
    TCMP_PTZ_DOWN_RIGHT_STOP = -28, /* ֹͣ ��̨��SS���ٶ��¸�����ת */
    TCMP_PTZ_PAN_AUTO_STOP =  -29,  /* ֹͣ ��̨��SS���ٶ������Զ�ɨ�� */

}tmcp_enum_ptz_command;

typedef struct tagtmcp_ptz_control_parameter
{
    int ptz_speed;          // ��̨�ٶ�
    int para_res1;          // Ԥ���ֶ�1 Ԥ�õ���
    int para_res2;          // Ԥ���ֶ�2
    int para_res3;          // Ԥ���ֶ�3

}tmcp_ptz_control_parameter, *ptmcp_ptz_control_parameter;


typedef struct tagtmcp_video_search_info
{
    ptmcp_camera_info camera;
    char start_time[TMCP_MAX_LEN_TIME_STRING];
    char stop_time[TMCP_MAX_LEN_TIME_STRING];
    int record_type;
    int record_location;

    tagtmcp_video_search_info()
    {
        camera = NULL;
        start_time[0] = '\0';
        stop_time[0] = '\0';
        record_type = -1;
        record_location = -1;
    }

}tmcp_video_search_info, *ptmcp_video_playback_info;

typedef struct tagtmcp_segment_info
{
	__time64_t				time_start;
	__time64_t				time_stop;
	char					url_for_get_stream[TMCP_MAX_LEN_DESCRIPTION_256];
	unsigned int			mediaDataLen;           //��Ƶ���ݵĳ���
	tagtmcp_segment_info	*pNext;

	tagtmcp_segment_info()
	{
		time_start = 0;
		time_stop = 0;
		memset(url_for_get_stream, 0, TMCP_MAX_LEN_DESCRIPTION_256);
		pNext = NULL;
		mediaDataLen = 0;
	}
}tmcp_segment_info, *ptmcp_segment_info;

typedef struct tagtmcp_video_search_rsp
{
    tm time_start;
    tm time_stop;
    int error_code;
    char url_for_get_stream[TMCP_MAX_LEN_DESCRIPTION_256];
    ULONGLONG ull_total_byte;
	ptmcp_segment_info segmentlist;
	int	iSegmentCount;
	int iRelocation;
	int iCameraId;

    tagtmcp_video_search_rsp()
    {
        error_code = 0;
        url_for_get_stream[0] = '\0';
        ull_total_byte = 0;
		iSegmentCount = 0;
		segmentlist = NULL;
		iRelocation = 0;
		iCameraId = 0;
    }

	~tagtmcp_video_search_rsp()
	{
		while (segmentlist)
		{
			ptmcp_segment_info tmp_info = segmentlist;
			segmentlist =tmp_info->pNext;
			delete tmp_info;
			tmp_info = NULL;
		}
	}

	bool operator == (const char * strUrl)
	{
		return 0 == strcmp(strUrl, url_for_get_stream);
	}
}tmcp_video_search_rsp, *ptmcp_video_search_rsp;

//typedef struct tagtmcp_video_search_list
//{
//	int icount;
//	ptmcp_video_search_rsp video_search_info_list;
//
//	tagtmcp_video_search_list()
//	{
//		video_search_info_list = NULL;
//		icount = 0;
//	}
//
//	~tagtmcp_video_search_list()
//	{
//		while (video_search_info_list)
//		{
//			ptmcp_segment_info tmp_info = video_search_info_list;
//			video_search_info_list =tmp_info->pNext;
//			delete tmp_info;
//			tmp_info = NULL;
//		}
//	}
//}tmcp_video_search_list, *ptmcp_video_search_list;

typedef struct tagtmcp_large_sreen_dlp_info
{
    int column;
    int largerPlatenInfoId;
    char name[TMCP_MAX_LEN_DESCRIPTION_128];
    int row;

    tagtmcp_large_sreen_dlp_info()
    {
        name[0] = '\0';
    }

    ~tagtmcp_large_sreen_dlp_info()
    {
        name[0] = '\0';
    }

}tmcp_large_sreen_dlp_info, *ptmcp_large_sreen_dlp_info;

typedef struct tagtmcp_large_screen_list
{
    bool result;
    int size;
    int error_code;
    tmcp_large_sreen_dlp_info* large_screen_list;

    tagtmcp_large_screen_list()
    {
        result = false;
        size = 0;
        error_code = 0;
        large_screen_list = 0;
    }

    ~tagtmcp_large_screen_list()
    {
        if (large_screen_list)
        {
            delete [] large_screen_list;
            large_screen_list = NULL;
        }
    }

}tmcp_large_screen_list, *ptmcp_large_screen_list;

typedef struct tagtmcp_tvwall_info
{
    int controlUnitId;
    char indexCode[TMCP_MAX_LEN_DESCRIPTION_128];
    char name[TMCP_MAX_LEN_DESCRIPTION_128];
    int __sizeprivilegeCode;
    int *privilegeCode;
    int serverId;
    int tvwallId;
    tmcp_large_screen_list large_screen_list;

    tagtmcp_tvwall_info()
    {
        indexCode[0] = '\0';
        name[0] = '\0';
        privilegeCode = NULL;
    }

    ~tagtmcp_tvwall_info()
    {
        if (privilegeCode)
        {
            delete [] privilegeCode;
            privilegeCode = NULL;
        }
    }

}tmcp_tvwall_info, *ptmcp_tvwall_info;

typedef struct tagtmcp_tvwall_list
{
    bool result;
    int size;
    int error_code;
    tmcp_tvwall_info* tvwall_info_list;

    tagtmcp_tvwall_list()
    {
        result = false;
        size = 0;
        error_code = 0;
        tvwall_info_list = NULL;
    }

    ~tagtmcp_tvwall_list()
    {
        if (tvwall_info_list)
        {
            delete [] tvwall_info_list;
            tvwall_info_list = NULL;
        }
    }

}tmcp_tvwall_list, *ptmcp_tvwall_list;

// tmcp_tvwall_header taskType ȡֵ
#define TMCP_TVWALL_COMMAND_START_REAL              0
#define TMCP_TVWALL_COMMAND_STOP_REAL               1
#define TMCP_TVWALL_COMMAND_GET_CUR_SCENE           2

typedef struct tagtmcp_tvwall_header
{
    int   taskType;            //��������
    int   dlpId;               //����id
    int   tvwallId;            //����ǽid
    int   errCode;
}tmcp_tvwall_header, *ptmcp_tvwall_header;

typedef struct tagtmcp_task_start_real_play
{
    tmcp_tvwall_header taskHdr;
    int   monitorIndex;
    int   areaIndex;
    int   cameraId;
    int   playType;
}tmcp_tvwall_start_real_play, *ptmcp_tvwall_start_real_play;

typedef struct tagtmcp_tvwall_stop_real_play
{
    tmcp_tvwall_header taskHdr;
    int   monitorIndex;
    int   areaIndex;
}tmcp_tvwall_stop_real_play, *ptmcp_tvwall_stop_real_play;

typedef struct tagtmcp_get_current_scene
{
    tmcp_tvwall_header taskHdr;
}tmcp_tvwall_get_current_scene, *ptmcp_get_current_scen;


typedef struct tagtmcp_all_resource
{
    tmcp_control_unit_list control_unit_list;
    tmcp_region_list region_list;
    tmcp_device_list device_list;
    tmcp_camera_list camera_list;
    tmcp_server_list server_list;
    tmcp_tvwall_list tvwall_list;
    tmcp_decode_device_list decode_device_list;
}tmcp_all_resource, *ptmcp_all_resource;



#ifndef _MSC_VER
#error tmcp_interface_sdk product only compable for msvc compiler
#endif

#if (defined(WIN32) || defined(_WIN32_WCE))

#if (!defined(_WIN32_WCE)) && (defined(_MSC_VER) && _MSC_VER >= 1400 )
#define tmcp_sdk_snpritf _snprintf_s
#else
#define tmcp_sdk_snpritf _snprintf
#endif

#else
#define tmcp_sdk_snpritf snprintf
#endif // WIN32 || _WIN32_WCE

#endif

#define CAMERA_RIGHT	0x00		//��ص�Ȩ��
#define DEVICE_RIGHT	0x01		//�豸Ȩ��
#define USER_RIGHT		0x02		//�û�Ȩ��
#define IO_RIGHT		0x03		//IOȨ��


#define	VOICEDATATYPE_XML		0		// 0��ʹ��XML��ʽ���������ݰ���
#define	VOICEDATATYPE_STRUCT	1	// 1��ʹ�ýṹ����ʽ���������ݰ��� 
#define	VOICEDATATYPE_STREAM	2	// 2������������
 
#define  CASCADE_PROTOCOL_T28181	1
#define  CASCADE_PORTOCOL_DB33		2

#define  DEF_PAGEITEM    400

//typedef struct tag_tmcp_alarm_log_item
//{
//	int		iAlarmType;		//��������
//	char	szAlarmCode[TMCP_MAX_LEN_DESCRIPTION_128];		//�������
//	char	szObjName[TMCP_MAX_LEN_DESCRIPTION_128];		//��������
//	char	szAlarmEvent[TMCP_MAX_LEN_DESCRIPTION_128];		//�����¼�
//	char	szStartTime[TMCP_MAX_LEN_DESCRIPTION_128];		//������ʼʱ��
//	char    szEndTime[TMCP_MAX_LEN_DESCRIPTION_128];		//��������ʱ��
//
//}tmcp_alarm_log_item, *ptmcp_alarm_log_item;

