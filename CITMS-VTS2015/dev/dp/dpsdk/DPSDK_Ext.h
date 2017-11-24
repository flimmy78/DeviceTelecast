#ifndef INCLUDED_DPSDK_EXT_H
#define INCLUDED_DPSDK_EXT_H

#include "DPSDK_Core_Define.h"

typedef enum
{
	IVS_RULE_VISIBLE	= 1,			// ����
	IVS_OBJ_VISIBLE		= 2,			// Ŀ���
	IVS_LOCUS_VISIBLE	= 3,			// �켣
}IvsInfoVisible;

/***************************************************************************************
 @ �ص���������
***************************************************************************************/

/** ý�����ݻص�.
 @param nPDLLHandle				SDK���
 @param nSeq					��Ӧ����ʱ���ص�Seq
 @param nMediaType				ý�����ͣ��ο�dpsdk_media_type_e
 @param	szNodeId				���ݶ�Ӧ��ͨ��/�豸ID
 @param	nParamVal				��չֵ;mediaTypeΪrealʱ��ΪstreamType;
 @param szUserParams			�û�����
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fMediaDataComplete)( IN int32_t nPDLLHandle, 
													  IN int32_t nSeq, 
													  IN int32_t nMediaType, 
													  IN const char* szNodeId, 
													  IN int32_t nParamVal, 
													  IN void* pUserParam );

/**
  @brief ����ص�
  @param nPDLLHanlde	SDK���
  @param nSeq			�����������
  @param pBuf			����������Ƶ����
  @param nLen			���ݳ���
  @param pFrameInfo		pFrameInfo ֡��Ϣ,���FRAME_INFO�ṹ��
  @param pUserParam		�û�����
  @remark
 */
typedef int32_t (DPSDK_CALLTYPE *fMediaDataYUV)( IN int32_t nPDLLHandle,
												IN int32_t nSeq, 
												IN const char* pBuf, 
												IN int32_t nLen,
												IN Frame_Info* pFrameInfo,
												IN void* pUserParam);

/**
  @brief �����Խ�����Ƶ���ݻص�
  @param nPDLLHanlde	SDK���
  @param nSession		�Խ��ỰID
  @param nMediaType		ý�����ͣ��ο�dpsdk_media_type_e
  @param szNodeId		���ݶ�Ӧ��ͨ��/�豸ID
  @param nParamVal		��չֵ;mediaTypeΪrealʱ��ΪstreamType;
  @param szData			����������Ƶ����
  @param nDataLen		���ݳ���
  @param pUserParam		�û�����
  @remark
 */
typedef int ( DPSDK_CALLTYPE *fTalkDataCallback )( IN int32_t nPDLLHandle,
												  IN int32_t nSession, 
												  IN int32_t nMediaType, 
												  IN const char* szNodeId,
												  IN int32_t nParamVal, 
												  IN char*	szData, 
												  IN int32_t nDataLen, 
												  IN void* szUserParam);

/**
  @brief ����¼���ļ���ɻص���������
  @param nPDLLHanlde	SDK���
  @param nDownloadSeq	����¼������к�
  @param pUserParam		�û�����
  @remark
 */
typedef int32_t (DPSDK_CALLTYPE *fDownloadFinishedCallback)( IN int32_t nPDLLHandle,
															 IN int32_t nDownloadSeq,
															 IN void *pUserParam);

/**
  @brief ����¼���ļ����Ȼص���������
  @param nPDLLHanlde	SDK���
  @param nDownloadSeq	����¼������к�
  @param nPos           ���ȶȣ���Χ0--100
  @param pUserParam		�û�����
  @remark
 */
typedef int32_t (DPSDK_CALLTYPE *fDownloadProgressCallback)( IN int32_t nPDLLHandle,
															 IN int32_t nDownloadSeq,
                                                             IN int32_t nPos,
															 IN void *pUserParam);

/**
  @brief ����¼���ļ������쳣�ص���������
  @param nPDLLHanlde	SDK���
  @param nDownloadSeq	����¼������к�
  @param pUserParam		�û�����
  @remark
 */
typedef int32_t (DPSDK_CALLTYPE *fDownloadNetErrorCallback)( IN int32_t nPDLLHandle,
															 IN int32_t nDownloadSeq,
															 IN void *pUserParam);

/**
  @brief �ⲿʹ�õ������ص���������
  @param nPDLLHanlde	SDK���
  @param nSeq       	�������к�
  @param StreamType     ��������,0ϵͳͷ��1������
  @param Data           ��������
  @param DataLen        �������ݳ���
  @param DecoderTag     �����ǩ����hik������dahua����
  @param UserData		�û�����
  @remark
 */
typedef void (DPSDK_CALLTYPE *fStreamCallback)(IN int32_t nPDLLHanlde,
											   IN int32_t nSeq, 
											   IN int StreamType, 
											   IN const char *Data, 
											   IN int DataLen, 
											   IN const char *DecoderTag, 
											   IN void *UserData);

/**
  @brief ��Ⱦ�ص�����,��õ�ǰ�����device context,����������DC�ϻ�ͼ(������),�ͺ����ڴ��ڵĿͻ���DC�ϻ�ͼ
  @param nPDLLHanlde	SDK���
  @param nSeq			�����������
  @param hDc			��ǰ�����device context
  @param pUser			�û�����
  @remark
 */
typedef void (DPSDK_CALLTYPE* fDrawFunCallback)(IN int32_t nPDLLHanlde, 
												IN int32_t nSeq, 
												IN void *hDc,
												IN void *pUser);

/**
  @brief �طŽ��Ȼص�����
  @param nPDLLHanlde	SDK���
  @param nSeq			�����������
  @param nPlayedTime	�Ѳ��ŵ�ʱ�䣬��λs
  @parm  nStatus        ״ֵ̬��0�����У�1����������2�쳣����
  @param pUser			�û�����
  @remark
 */
typedef void (DPSDK_CALLTYPE* fPlaybackPosTimerCallback)(IN int32_t nPDLLHanlde, 
														 IN int32_t nSeq, 
														 IN long nPlayedTime, 
														 IN long nStatus, 
														 IN void* pUser);

/***************************************************************************************
 @ �ص������������
***************************************************************************************/


/***************************************************************************************
 @ �ӿڶ���
***************************************************************************************/

/** ��ʼ����չ��.
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark									
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_InitExt( void );

/** ����ʼ����չ��.
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
	1����Ҫ��DPSDK_InitExt�ɶ�ʹ��
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_UnitExt( void );


/** ����ʵ������.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nRealSeq		�����������,����Ϊ����������ʶ 
 @param   IN	pGetInfo		����������Ϣ 
 @param	  IN	hDestWnd		��ʾ���ھ��
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRealplay( IN int32_t nPDLLHandle, 
															 OUT int32_t& nRealSeq, 
															 IN Get_RealStream_Info_t* pGetInfo, 
															 IN void* hDestWnd, 
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetIVSAlarmInfo(IN int32_t nPDLLHandle, 
															  IN int32_t nRealSeq,
															  IN int32_t nAlarmType,
															  IN const char* szAlarmInfo, 
															  IN int32_t nDataLen);

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetIvsShowFlag(IN int32_t nPDLLHandle, 
															  IN int32_t nRealSeq,
															  IN IvsInfoVisible nType,
															  IN int32_t nFlag);
//����ͨ���໭��ƴ��ʵʱ��Ƶ
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRealplayPreview( IN int32_t nPDLLHandle, 
																   OUT int32_t& nRealSeq, 
																   IN Get_RealStream_Info_t* pGetInfo, 
																   IN int nStartChIndex,
																   IN void* hDestWnd, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRealplayAsync(IN int32_t nPDLLHandle, 
																 IN int32_t& nRealFlag,
																 IN Get_RealStream_Info_t* pGetInfo, 
																 IN void* hDestWnd);

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetRealPlayResultCallback(fDPSDKStartRealplayCallback fun, void *pUser);



/** �л����ŵĴ���.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nRealSeq		�����������,����Ϊ����������ʶ 
 @param	  IN	hDstWnd		    Ŀ�Ĵ��ھ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ChangePlayWndBySeq( IN int32_t nPDLLHandle, 
																 IN int32_t nRealSeq, 
																 IN void* hDstWnd );

/**���ý����YUV�ص�
@param   IN	nPDLLHandle		SDK���
@param   IN	nRealSeq		�����������
@param   IN pFun            YUV�ص�
@param   IN pUser           �û�����
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDecCallback( IN int32_t nPDLLHandle, 
															  IN int32_t nRealSeq, 
															  IN fMediaDataYUV pFun,
															  IN void* pUser);

/** ����ʵ���������������ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nRealSeq		�����������,����Ϊ����������ʶ 
 @param   IN	pGetInfo		����������Ϣ 
 @param	  IN	hDestWnd		��ʾ���ھ��
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRealplayWithCallback( IN int32_t nPDLLHandle, 
															 OUT int32_t& nRealSeq, 
															 IN Get_RealStream_Info_t* pGetInfo, 
															 IN void* hDestWnd,
															 IN fStreamCallback fun,
															 IN void* pUser,
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ����ʵ�����������Ƿ��YUV�ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nRealSeq		�����������,����Ϊ����������ʶ 
 @param   IN	pGetInfo		����������Ϣ 
 @param	  IN	hDestWnd		��ʾ���ھ��
 @param   IN	nTimeout		��ʱʱ������λ����
 @param   IN    bDecCallback    �Ƿ��YUV�ص�
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRealplayEx( IN int32_t nPDLLHandle, 
															OUT int32_t& nRealSeq, 
															IN Get_RealStream_Info_t* pGetInfo, 
															IN void* hDestWnd, 
															IN bool  bDecCallback,
															IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��������Źر�����.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nRealSeq		�����������,��Ϊ����������ʶ 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopRealplayBySeq( IN int32_t nPDLLHandle, 
																 IN int32_t nRealSeq, 
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopRealplayBySeqAsync( IN int32_t nPDLLHandle, 
																IN int32_t nRealSeq);

/** ��ʼ�㲥
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nTalkSeq		�����������,����Ϊ����������ʶ 
 @param   IN	pGetInfo		����������Ϣ 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartBroadcastExt( int32_t nPDLLHandle, 
															  int32_t* nTalkSeq, 
															  const char* szJson, 
															  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ʼ�㲥
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nTalkSeq		�����������,����Ϊ����������ʶ 
 @param   IN	pGetInfo		����������Ϣ 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopBroadcast( int32_t nPDLLHandle, 
															  int32_t nTalkSeq, 
															  const char* szJson, 
															  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ʼ�����Խ�
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nTalkSeq		�����������,����Ϊ����������ʶ 
 @param   IN	pGetInfo		����������Ϣ 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartTalk( IN int32_t nPDLLHandle, 
														 OUT int32_t& nTalkSeq, 
														 IN Get_TalkStream_Info_t* pGetInfo, 
														 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ���������ֹͣ�����Խ�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nTalkSeq		�����������,��Ϊ����������ʶ 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopTalkBySeq( IN int32_t nPDLLHandle, 
															 IN int32_t nTalkSeq, 
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��CameraIdֹͣ�����Խ�
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szCameraId		�豸��ͨ�����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  �ر����е��Ѿ��򿪵�CameraId	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopTalkByCameraId( IN int32_t nPDLLHandle, 
																  IN const char* szCameraId, 
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


//��Ⱥ�Խ�

/** ��ʼ����
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nCallSeq		�����������,��Ϊ����������ʶ 
 @param   IN	nCallType		�������� 0������1�鲥��2���ӶԽ�
 @param   IN	szGroupId		������ID
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartCallExt( int32_t nPDLLHandle, 
														    int32_t& nCallSeq, 
															dpsdk_call_type_e nCallType,
															const char* szGroupId, 
															int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** �رպ���
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nCallSeq		�����������,����Ϊ����������ʶ
 @param   IN	szGroupId		��ID
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopCallExt(int32_t nPDLLHandle, 
														  int32_t nCallSeq, 
														  const char* szGroupId,
														  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��������
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nCallSeq		�����������,����Ϊ����������ʶ
 @param   IN	pGetInfo		����������Ϣ 
 @param   IN    RecordParam		������Ƶ�ɼ�����				
 @param   IN    pUser			�����ص��û�����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_InviteCallExt(int32_t nPDLLHandle, 
															int32_t& nCallSeq, 
															Get_InviteCall_Info_t* pGetInfo,
															AudioRecrodParam_t* RecordParam,
															void* pUser,
															int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ���б��Ҷϣ��ͷ�����
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nCallSeq		�����������,����Ϊ����������ʶ 
 @param   IN	szGroupId		������ID
 @param   IN	nTid			T ID
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ByeCallExt(int32_t nPDLLHandle, 
														 int32_t nCallSeq, 
														 const char* szGroupId,
														 int32_t nTid,
														 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** ��/�رձ�����˷�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nRealSeq		�����������,����Ϊ����������ʶ
 @param   IN	bOpen		    true��������false�ر�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OpenAudioRecord(int32_t nPDLLHandle, 
															  int32_t nSeq,
															  bool bOpen);

/** ��/�رձ�����˷�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nRealSeq		�����������,����Ϊ����������ʶ
 @param   IN	bOpen		    true��������false�ر�����
 @param   IN	nAudioType		    true��������false�ر�����
 @param   IN	nBitsPerSample		    true��������false�ر�����
 @param   IN	nSamplesPerSec		    true��������false�ر�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OpenAudioRecordExt(int32_t nPDLLHandle, 
															  int32_t nSeq,
															  bool bOpen,long nAudioType, long nBitsPerSample, long nSamplesPerSec);



/** ���ûطţ�����¼��طš�ƽ̨/�豸¼��طţ����������ص�.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pFun			�ص�����
 @param	  IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetMediaDataCompleteCallback( IN int32_t nPDLLHandle, 
																			IN fMediaDataComplete pFun, 
																			IN void* pUser );

/** ��/�ر���Ƶ����.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nRealSeq		�����������,����Ϊ����������ʶ 
 @param   IN	bOpen		    true��������false�ر�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OpenAudio( IN int32_t nPDLLHandle, 
														 IN int32_t nSeq,
														 IN bool bOpen);

/** �Թ���ʽ��/�ر�������ֻ�ܲ��ű�·��������ȥ�ر�����·������.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nRealSeq		�����������,����Ϊ����������ʶ 
 @param   IN	bOpen		    true��������false�ر�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OpenAudioShare(int32_t nPDLLHandle, 
															 int32_t nSeq,
															 bool bOpen);

/** ��ȡ����
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nRealSeq		�����������,����Ϊ����������ʶ 
 @param   OUT	nVol		    ������С,��Χ[0,0xFFFF]
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetVolume( IN int32_t nPDLLHandle, 
														 IN int32_t nSeq,
														 OUT int32_t &nVol);

/** ��������
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nRealSeq		�����������,����Ϊ����������ʶ 
 @param   IN	nVol		    ������С,��Χ[0,0xFFFF]
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetVolume( IN int32_t nPDLLHandle, 
														 IN int32_t nSeq,
														 IN int32_t nVol);

/** ���ļ�����¼����.
 @param	  IN	nPDLLHandle		SDK���
 @param   OUT	nPlaybackSeq	�ط��������,��Ϊ����������ʶ  
 @param	  IN	pRecordInfo		¼����Ϣ 
 @param	  IN	hDestWnd		��ʾ���ھ��
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByFile( IN int32_t nPDLLHandle, 
																   OUT int32_t& nPlaybackSeq, 
																   IN Get_RecordStream_File_Info_t* pRecordInfo, 
																   IN void* hDestWnd, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ���ļ��ط�¼��ͬʱ���������ص�.
 @param	  IN	nPDLLHandle		SDK���
 @param   OUT	nPlaybackSeq	�ط��������,��Ϊ����������ʶ  
 @param	  IN	pRecordInfo		¼����Ϣ 
 @param	  IN	hDestWnd		��ʾ���ھ��
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByFileWithCallback( IN int32_t nPDLLHandle, 
																   OUT int32_t& nPlaybackSeq, 
																   IN Get_RecordStream_File_Info_t* pRecordInfo, 
																   IN void* hDestWnd,
																   IN fStreamCallback fun,
																   IN void* pUser,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** ��ʱ������¼����.
 @param	  IN	nPDLLHandle		SDK���
 @param   OUT	nPlaybackSeq	�ط��������,��Ϊ����������ʶ  
 @param	  IN	pRecordInfo		¼����Ϣ
 @param	  IN	hDestWnd		��ʾ���ھ��
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByTime( IN int32_t nPDLLHandle, 
																   OUT int32_t& nPlaybackSeq, 
																   IN Get_RecordStream_Time_Info_t* pRecordInfo, 
																   IN void* hDestWnd, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �����������Ͱ�ʱ������¼����.
 @param	  IN	nPDLLHandle		SDK���
 @param   OUT	nPlaybackSeq	�ط��������,��Ϊ����������ʶ  
 @param	  IN	pRecordInfo		¼����Ϣ
 @param   IN	nStreamType		��������
 @param	  IN	hDestWnd		��ʾ���ھ��
 @param   IN	nTimeout		��ʱʱ������λ����
 @param	  IN	nTranMode		����ģʽ��1:TCP 0:UDP
 @param   IN	bBack			�Ƿ񵹷�
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByStreamType( IN int32_t nPDLLHandle, 
																		OUT int32_t& nPlaybackSeq, 
																		IN Get_RecordStream_Time_Info_t* pRecordInfo,
																		IN dpsdk_stream_type_e nStreamType,
																		IN void* hDestWnd, 
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT,
																		IN int32_t nTranMode = 1,
																		IN bool bBack = false);

/** ��ʱ������¼�����Ҵ������ص�.
 @param	  IN	nPDLLHandle		SDK���
 @param   OUT	nPlaybackSeq	�ط��������,��Ϊ����������ʶ  
 @param	  IN	pRecordInfo		¼����Ϣ
 @param	  IN	hDestWnd		��ʾ���ھ��
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByTimeWithCallback( IN int32_t nPDLLHandle, 
																   OUT int32_t& nPlaybackSeq, 
																   IN Get_RecordStream_Time_Info_t* pRecordInfo, 
																   IN void* hDestWnd,
																   IN fStreamCallback fun,
																   IN void* pUser,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �������ļ�����¼��.
 @param	  IN	nPDLLHandle		SDK���
 @param   OUT	nPlaybackSeq	�ط��������,��Ϊ����������ʶ  
 @param	  IN	pRecordInfo		¼����Ϣ
 @param	  IN	hDestWnd		��ʾ���ھ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByLocal( IN int32_t nPDLLHandle, 
																    OUT int32_t& nPlaybackSeq, 
																	IN Get_Record_Local_Info_t* pRecordInfo, 
																	IN void* hDestWnd );

/** �������ļ�����¼��.
 @param	  IN	nPDLLHandle		SDK���
 @param   OUT	nPlaybackSeq	�ط��������,��Ϊ����������ʶ  
 @param	  IN	pRecordInfo		¼����Ϣ
 @param	  IN	hDestWnd		��ʾ���ھ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
          ֻ֧�ִ��豸
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByLocalWithCallback( IN int32_t nPDLLHandle, 
																    OUT int32_t& nPlaybackSeq, 
																	IN Get_Record_Local_Info_t* pRecordInfo, 
																	IN void* hDestWnd,
																	IN fStreamCallback fun,
																	IN void* pUser);


/** ��ͣ¼��.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PausePlaybackBySeq( IN int32_t nPDLLHandle, 
																  IN int32_t nPlaybackSeq, 
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��λ¼��.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN    seekBegin       ��λ��ʼֵ.�ļ�ģʽʱ,�Ƕ�λ�����ļ���Сֵ;ʱ��ģʽʱ,�Ƕ�λ����ʱ��ֵ;
 @param   In    seekEnd         ��λ����ֵ.�ļ�ģʽʱ,������;ʱ��ģʽʱ,���ڴ��Ľ���ʱ��.
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
          seekBegin���ļ�ģʽ�µļ��㷽ʽ������:(�ļ���Сֵ)/100*(��λ������ļ��İٷֱ�)
		  ������Զ��¼��طţ���ֻ֧�ִ��豸
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SeekPlaybackBySeq( IN int32_t nPDLLHandle, 
																 IN int32_t nPlaybackSeq, 
																 IN uint64_t seekBegin,
																 IN uint64_t seekEnd, 
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** ��λ����¼��.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN	nPos        	λ�ðٷֱȣ�0-100 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SeekLocalPlaybackBySeq( IN int32_t nPDLLHandle, 
																	  IN int32_t nPlaybackSeq, 
																	  IN int32_t nPos,
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �ָ�¼��.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ResumePlaybackBySeq( IN int32_t nPDLLHandle, 
																   IN int32_t nPlaybackSeq, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ����¼������.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN    nSpeed,         ¼�����ط��ٶ�
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPlaybackSpeed( IN int32_t nPDLLHandle, 
																IN int32_t nPlaybackSeq, 
																IN dpsdk_playback_speed_e nSpeed, 
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ���õ���¼������.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN    nSpeed,         ¼�����ط��ٶ�
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetBackwardPlaybackSpeed( IN int32_t nPDLLHandle, 
																		IN int32_t nPlaybackSeq, 
																		IN dpsdk_playback_speed_e nSpeed, 
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �ر�¼��.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopPlaybackBySeq( IN int32_t nPDLLHandle, 
																 IN int32_t nPlaybackSeq, 
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ͨ���ر�¼��.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	szCameraId   	ͨ����� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopPlaybackByCameraId( IN int32_t nPDLLHandle, 
																	  IN const char* szCameraId, 
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );



/** �ر�¼��.ͬ���ȴ�����Ӧ����ҪDSSƽ̨֧�֣�����ӿڻᳬʱ��
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SynchroStopPlaybackBySeq( IN int32_t nPDLLHandle, 
																		IN int32_t nPlaybackSeq, 
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ͨ���ر�¼��.ͬ���ȴ�����Ӧ����ҪDSSƽ̨֧�֣�����ӿڻᳬʱ��
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	szCameraId   	ͨ����� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SynchroStopPlaybackByCameraId( IN int32_t nPDLLHandle, 
																			IN const char* szCameraId, 
																			IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ��ǰ�ط���������ʱ��.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN	nFramTime	    ���ص�ʱ��ֵ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFrameTime( IN int32_t nPDLLHandle,
															IN int32_t nPlaybackSeq,
															OUT uint64_t& nFramTime );
/** ��ȡ����¼��ǰ���Ž���.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN	nPos	        ���Ž���
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetPlayPos( IN int32_t nPDLLHandle,
														  IN int32_t nPlaybackSeq,
														  OUT int32_t& nPos );
/** ץͼ.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @param   IN	nPicType		ͼƬ����
 @param   IN	szFilename		�ļ���
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PicCapture( IN int32_t nPDLLHandle, 
														  IN int32_t nSeq, 
														  IN dpsdk_pic_type_e nPicType, 
														  IN const char* szFilename );

/** ʵʱ¼����Ƶ
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @param   IN	nDataType		*- 0 ��ʾԭʼ��Ƶ��;  *- 1 ��ʾת����AVI��ʽ, ֻ�Դ�������Ч  *- 2 ��ʾת����ASF��ʽ, ֻ�Դ�������Ч
 @param   IN	szFilename		�ļ���
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRecord( IN int32_t nPDLLHandle, 
														   IN int32_t nSeq,  
														   IN char* szFilename,
														   IN int32_t nDataType = 0 );

/** ʵʱ¼����Ƶ¼��ΪFLV��ʽ
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @param   IN	szFilename		�ļ���
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRecordToFLV( IN int32_t nPDLLHandle, 
														        IN int32_t nSeq,  
														        IN char* szFilename );

/** ʵʱ¼����Ƶ�ɶ���¼���ļ���ʽ
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @param   IN	nFileType		¼���ļ���ʽ
 @param   IN	szFilename		�ļ���

 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRecordEx( IN int32_t nPDLLHandle, 
														     IN int32_t nSeq,  
														     IN char* szFilename,
														     IN int32_t nFileType);

/** ֹͣʵʱ¼����Ƶ
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopRecord( IN int32_t nPDLLHandle, 
														  IN int32_t nSeq);

/** ֹͣʵʱ¼����Ƶ
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopRecordToFLV( IN int32_t nPDLLHandle, 
														       IN int32_t nSeq);

/** ֹͣʵʱ¼����Ƶ
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopRecordEx( IN int32_t nPDLLHandle, 
														    IN int32_t nSeq);


/** ����OSd�ı���Ϣ
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @param   IN	szOsdInfo		Osd��Ϣ�����ó���15���ֽ�,һ������ռ�������ֽ�
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetOsdTxt( IN int32_t nPDLLHandle, 
														 IN int32_t nSeq,
														 IN char* szOsdInfo);

/** ����OSd�ı���Ϣ,ͬʱ�����������壬��ɫ����С�����ڴ��ڵ�λ��
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @param   IN	szOsdInfo		Osd��Ϣ�����ó���15���ֽ�,һ������ռ�������ֽ�
 @param   IN	nWindowHeight;	���ڸ߶ȣ���λ����
 @param   IN	nWindowWeight;	���ڿ�ȣ���λ����
 @param   IN	fFaceName;		������ʽ�����塱�����塱��΢���źڡ���
 @param   IN	fHeight;		����߶� 1~100��ռ�ô��ڸ߶ȵİٷֱ�
 @param   IN	fWeight;		������ 1~100��ռ�ô��ڿ�ȵİٷֱ�
 @param   IN	left;			���������λ�� 1~100��ռ�ô��ڿ�ȵİٷֱ�
 @param   IN	top;			�������Ϸ�λ�� 1~100��ռ�ô��ڸ߶ȵİٷֱ�
 @param   IN	fColor;			������ɫ0��ɫ��255(0x0000FF)��ɫ��16777215(0xFFFFFF)��ɫ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetOsdTxtEx(int32_t nPDLLHandle, 
														  int32_t nSeq,
														  const char* szOsdInfo,
														  int nWindowHeight,
														  int nWindowWeight,
														  const char* fFaceName,
														  int fHeight,
														  int fWeight,
														  int left,
														  int top,
														  unsigned long fColor);

/**���osd��Ϣ
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CleanUpOsdInfo( IN int32_t nPDLLHandle, 
														      IN int32_t nSeq);

/** ��ȡ��Ƶ����
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @param   OUT	videoColorInfo	��Ƶ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetColor( IN int32_t nPDLLHandle, 
														IN int32_t nSeq,
														OUT Video_Color_Info_t &videoColorInfo);

/** ������Ƶ����
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @param   IN	videoColorInfo	��Ƶ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AdjustColor( IN int32_t nPDLLHandle, 
														   IN int32_t nSeq,
														   IN Video_Color_Info_t videoColorInfo);

/**��֡�ط�
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PlayOneByOne( IN int32_t nPDLLHandle, 
															IN int32_t nSeq);

/**��֡����
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PlayOneByOneBack( IN int32_t nPDLLHandle, 
																IN int32_t nSeq);

/**�ָ���������
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			������� 
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_Play( IN int32_t nPDLLHandle, 
													IN int32_t nSeq);

/** ֹͣ�Խ�
 @param   IN	nPDLLHandle		SDK���
 @param   IN    nTalkSeq	    �Խ��������
 @param   IN    szCameraId      �豸ID
 @param   IN    nTalkType       �Խ�����
 @param   IN    nTimeout        ��ʱʱ������λ���� 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopTalk( IN int32_t  nPDLLHandle, 
													    IN int32_t  nTalkSeq,
													    IN const    char * szDeviceId,
													    IN int32_t  nTalkType,
													    IN int32_t  nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ����ͨ��ID¼��
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	szCameraId   	ͨ��ID 
 @param   IN	szFileName      �ļ���
 @param   OUT   nSeq            ¼���������к�	
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRecordByCameraId(IN int32_t nPDLLHandle, 
																	IN const char* szCameraId, 
																	IN const char* szFileName, 
																	OUT int32_t &nSeq,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ֹͣ����ͨ��ID¼��
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nSeq		¼���������,
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopRecordCameraIdBySeq(IN int32_t nPDLLHandle, 
																	  IN int32_t nSeq, 
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**��ͼ�ص�
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nSeq   			�������
 @param   IN    DrawFun         �ص���������
 @param   IN    pUser           �ص���������
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_RegisterDrawFun(IN int32_t nPDLLHandle, 
															  IN int32_t nSeq,
															  IN fDrawFunCallback fDrawFun,
															  void *pUser);

/**����¼���ļ���ɻص���ע�����������ûص�
@param   IN	nPDLLHandle		SDK���
@param   IN	fDownloadFinishedCallback	�ص�����
@param   IN	pUser		                �û�����
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDownloadFinishedCallback(IN int32_t nPDLLHandle, 
																		  IN fDownloadFinishedCallback cb, 
																		  IN void *pUser);

/**����¼���ļ����Ȼص���ע�����������ûص�
@param   IN	nPDLLHandle		SDK���
@param   IN	fDownloadProgressCallback	�ص�����
@param   IN	pUser		                �û�����
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDownloadProgressCallback(IN int32_t nPDLLHandle, 
																		  IN fDownloadProgressCallback cb, 
																		  IN void *pUser);

/**����¼���ļ������������ص���ע�����������ûص�
@param   IN	nPDLLHandle		SDK���
@param   IN	fDownloadNetErrorCallback	�ص�����
@param   IN	pUser		                �û�����
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDownloadNetErrorCallback(IN int32_t nPDLLHandle, 
																		  IN fDownloadNetErrorCallback cb, 
																		  IN void *pUser);

/**���ļ�����������¼���ļ�
@param   IN	  nPDLLHandle		SDK���
@param   OUT  nDownloadSeq	���ر�־���к�
@param   IN	  szCameraId	ͨ��ID
@param   IN	  pSingleRecord	¼���ļ���Ϣ��GetRecordInfo �����ֵ
@param   IN	  szFileName	¼�񱣴��ļ���
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DownloadRecordByFile( IN int32_t nPDLLHandle, 
																   OUT int32_t& nDownloadSeq, 
																   IN const char *szCameraId,
																   IN Single_Record_Info_t* pSingleRecord,
																   IN const char *szFileName,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**���ļ�����������¼���ļ�
@param   IN	  nPDLLHandle		SDK���
@param   OUT  nDownloadSeq	���ر�־���к�
@param   IN	  szCameraId	ͨ��ID
@param   IN	  pSingleRecord	¼���ļ���Ϣ��GetRecordInfo �����ֵ
@param   IN	  szFileName	¼�񱣴��ļ���
@param   IN   nFileType     ¼�񱣴��ļ����ͣ�֧��FLV��MP4
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DownloadRecordByFileEx( IN int32_t nPDLLHandle, 
																   OUT int32_t& nDownloadSeq, 
																   IN const char *szCameraId,
																   IN Single_Record_Info_t* pSingleRecord,
																   IN const char *szFileName,
																   IN int32_t nFileType,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**ֹͣ¼������
@param   IN	nPDLLHandle		SDK���
@param   IN	nDownloadSeq	������
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopDownloadRecord( IN int32_t nPDLLHandle, 
																 IN int32_t nDownloadSeq );

/**ֹͣ¼������,ͬ���ȴ�����Ӧ����ҪDSSƽ̨֧�֣�����ӿڻᳬʱ��
@param   IN	nPDLLHandle		SDK���
@param   IN	nDownloadSeq	������
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SynchroStopDownloadRecord( IN int32_t nPDLLHandle, 
																		IN int32_t nDownloadSeq,
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT  );

/**ֹͣ¼������
@param   IN	nPDLLHandle		SDK���
@param   IN	szFileName	������
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopDownloadRecordByFileName( IN int32_t nPDLLHandle, 
																 IN const char* szFileName );

/**ֹͣ¼�����أ�ͬ���ȴ�����Ӧ����ҪDSSƽ̨֧�֣�����ӿڻᳬʱ��
@param   IN	nPDLLHandle		SDK���
@param   IN	szFileName	������
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SynchroStopDownloadRecordByFileName( IN int32_t nPDLLHandle, 
																					IN const char* szFileName,
																					IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**ֹͣ¼������,����¼������
@param   IN	nPDLLHandle		SDK���
@param   IN	nDownloadSeq	������
@param   OUT nPartitionNum  ���ɵ�¼�������
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopDownloadRecordAndGetFileNum( IN int32_t nPDLLHandle, 
																 IN int32_t nDownloadSeq,
																 OUT int32_t& nPartitionNum);

/**ֹͣ¼������,����¼��������ͬ���ȴ�����Ӧ����ҪDSSƽ̨֧�֣�����ӿڻᳬʱ��
@param   IN	nPDLLHandle		SDK���
@param   IN	nDownloadSeq	������
@param   OUT nPartitionNum  ���ɵ�¼�������
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SynchroStopDownloadRecordAndGetFileNum( IN int32_t nPDLLHandle, 
																					  IN int32_t nDownloadSeq,
																					  OUT int32_t& nPartitionNum,
																					  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**��ȡ¼������λ��
@param   IN	nPDLLHandle		SDK���
@param   IN	nDownloadSeq	������
@param   OUT	nPos	    λ�õ� 0--100
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDownloadPos(IN int32_t nPDLLHandle, 
															 IN int32_t nDownloadSeq, 
															 OUT int32_t &nPos);

/**��ʱ������¼��
@param   IN	nPDLLHandle		SDK���
@param   IN	nDownloadSeq	������
@param   IN	  szCameraId	ͨ��ID
@param   IN	  nSourceType	¼��Դ����
@param   IN	  uBeginTime	��ʼʱ��
@param   IN	  uEndTime	    ����ʱ��
@param   IN	  szFileName	¼�񱣴��ļ���
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DownloadRecordByTime( IN int32_t nPDLLHandle, 
																   OUT int32_t& nDownloadSeq, 
																   IN const char *szCameraId,
																   IN dpsdk_recsource_type_e nSourceType,
																   IN uint64_t uBeginTime,
																   IN uint64_t uEndTime,
																   IN const char *szFileName,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**��ʱ������¼��
@param   IN	nPDLLHandle		SDK���
@param   IN	nDownloadSeq	������
@param   IN	  szCameraId	ͨ��ID
@param   IN	  nSourceType	¼��Դ����
@param   IN	  uBeginTime	��ʼʱ��
@param   IN	  uEndTime	    ����ʱ��
@param   IN	  szFileName	¼�񱣴��ļ���
@param   IN   nFileType     ¼�񱣴��ļ����ͣ�֧��FLV��MP4
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DownloadRecordByTimeEx( IN int32_t nPDLLHandle, 
																   OUT int32_t& nDownloadSeq, 
																   IN const char *szCameraId,
																   IN dpsdk_recsource_type_e nSourceType,
																   IN uint64_t uBeginTime,
																   IN uint64_t uEndTime,
																   IN const char *szFileName,
																   IN int32_t nFileType,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**��ͣ����¼��
@param   IN	nPDLLHandle		SDK���
@param   IN	nDownloadSeq	������
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PauseDownloadRecord( IN int32_t nPDLLHandle, 
																	 IN int32_t nDownloadSeq, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**��ͣ����¼��
@param   IN	nPDLLHandle		SDK���
@param   IN	szFileName	    �ļ���
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PauseDownloadRecordByFileName( IN int32_t nPDLLHandle, 
																  IN const char* szFileName, 
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**��������¼��
@param   IN	nPDLLHandle		SDK���
@param   IN	nDownloadSeq	������
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ResumeDownloadRecord( IN int32_t nPDLLHandle, 
																	 IN int32_t nDownloadSeq, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**��������¼��
@param   IN	nPDLLHandle		SDK���
@param   IN	szFileName  	�ļ���
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ResumeDownloadRecordByFileName( IN int32_t nPDLLHandle, 
																   IN const char* szFileName, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**
��ȡ�ļ�����ʱ������λ������
@param   IN	  nPDLLHandle	SDK���
@param   IN	  nSeq        	�������к�
@param   IN	  nTotalTime	ͨ��ID
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFileTotalTime(IN int32_t nPDLLHandle, 
															   IN int32_t nSeq, 
															   OUT int32_t &nTotalTime);

/**
��ȡ�ļ��ĵ�ǰ���ŵ㣬��λ������
@param   IN	  nPDLLHandle	SDK���
@param   IN	  nSeq        	�������к�
@param   IN	  nPlayedTime	�Ѳ���ʱ��
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFilePlayedTime(IN int32_t nPDLLHandle, 
																IN int32_t nSeq, 
																OUT int32_t &nPlayedTime);

/**
��ȡԶ��¼��ĵ�ǰ���ŵ㣬��λ������
@param   IN	  nPDLLHandle	SDK���
@param   IN	  nSeq        	�������к�
@param   IN	  nPlayedTime	�Ѳ���ʱ��
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRemotePlayedTime(IN int32_t nPDLLHandle, 
																IN int32_t nSeq, 
																OUT int32_t &nPlayedTime);

/**
�����ļ��ĵ�ǰ���ŵ㣬 ��λ������
@param   IN	  nPDLLHandle	SDK���
@param   IN	  nSeq        	�������к�
@param   IN	  nPlayedTime	���õĲ���ʱ��
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetFilePlayedTime(IN int32_t nPDLLHandle, 
																IN int32_t nSeq, 
																IN int32_t nPlayedTime);

/**
����Զ�̵ĵ�ǰ���ŵ㣬 ��λ������
@param   IN	  nPDLLHandle	SDK���
@param   IN	  nSeq        	�������к�
@param   IN	  nPlayedTime	���õĲ���ʱ��
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetRemotePlayedTime(IN int32_t nPDLLHandle, 
																IN int32_t nSeq, 
																IN int32_t nPlayedTime);

/**
���������ݲ�ͬ���̣�д���Ӧ���̿ɲ��ŵ�ԭʼ����
@param   INOUT  hHandle   	������ָ�룬��һ����ΪNULL���룬֮����д����ʱ����
@param   INOUT  nProviderType	�������кţ���һ����Ϊ0���룬֮����д����ʱ����
@param   IN   fp            �ļ�ָ��
@param   IN   szData        Ҫд�������
@param   IN   nDataLen      ���ݳ���
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_WriteDataByAnalysis(INOUT void*& hHandle,
																  INOUT int32_t& nProviderType,
																  IN void* fp,
																  IN char* szData,
																  IN int32_t nDataLen);

/**
���ö�Ӧĳ��nSeq�Ĳ��ŵ�ͬʱ���������Ļص�����
@param   IN	  nPDLLHandle	SDK���
@param   IN	  nSeq        	�������к�
@param   IN	  fun       	�ص�����
@parm    IN   pUser         �û�����
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKStreamCBPFBySeq(IN int32_t nPDLLHandle,
																	  IN int32_t nSeq,
																	  IN fStreamCallback fun,
																	  IN void* pUser);

/**
���ö�Ӧĳ��nSeq�ķ����������ݻص�
@param   IN	  nPDLLHandle	SDK���
@param   IN	  nSeq        	�������к�
@param   IN	  fun       	�ص�����
@param   IN   pUser         �û�����
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKDownloadDataCallbackBySeq(IN int32_t nPDLLHandle,
																			    IN int32_t nSeq,
																			    IN fStreamCallback fun,
																			    IN void* pUser);

/**
���ö�ʱ�����лطŽ��Ƚ��лص�
@param   IN	  nPDLLHandle	SDK���
@param   IN	  fun        	�ص�����
@param   IN	  pUser     	�û�����
@param   IN   nInterval     ʱ����
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPlaybackPosCallback(IN int32_t nPDLLHandle,
																	 IN fPlaybackPosTimerCallback fun,
																	 IN void* pUser,
																	 IN int32_t nInterval = 3000);

/**
����ĳ����Ƶ�����򿪻�ر�
@param   IN	  nPDLLHandle	SDK���
@param   IN	  nSeq        	�������к�
@param   IN	  nChannel  	�������
@param   IN   bOpen         �Ƿ��
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetAudioChannel(IN int32_t nPDLLHanle,
															  IN int32_t nSeq,
															  IN int32_t nChannel,
															  IN bool bOpen);

/**
��ȡ����״̬
@param   IN	  nPDLLHandle	SDK���
@param   IN	  nSeq        	�������к�
@param   IN	  nChannel   	�������
@param   IN   bOpen         �Ƿ��
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetAudioChannelState(IN int32_t nPDLLHanle,
															       IN int32_t nSeq,
															       IN int32_t nChannel,
															       OUT bool& bOpen);

/**
��ȡ��������
@param   IN	  nPDLLHandle	SDK���
@param   IN	  nSeq        	�������к�
@param   IN	  nChannelNum	������
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetAudioChannels(IN int32_t nPDLLHanle,
															   IN int32_t nSeq,
															   OUT int32_t& nChannelNum);

/**
�ļ�����
ֻ�Դ��ļ���Ч
@param   IN	  sSrcFile	    Դ�ļ�
@param   IN	  sDestFile     Ŀ���ļ�
@param   IN	  nBeginTime	��ʼʱ��
@param   IN   nEndTime      ����ʱ��
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_FileCut( IN const char *sSrcFile,
													   IN const char *sDestFile,
													   IN long nBeginTime,
													   IN long nEndTime );

/**
���������ļ��ֶ��ļ����棬��ʽΪ �ļ���_(i).��׺(i=1,2,3,...)
@param   IN	  nPDLLHandle	SDK���
@param   IN	  nSeq        	�������к�
@param   IN	  szFileNameWithOutExt	�ļ�·��������������׺
@param   IN   szExt         ��׺��,�ԡ�.����ͷ���硰.dav��
@param   IN   nFileLimit    ÿ���ļ��Ĵ�С����λB
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDownloadPartition( IN int32_t nPDLLHandle, 
																    IN int32_t nSeq, 
																	IN const char *szFileNameWithOutExt, 
																	IN const char *szExt, 
																	IN int32_t nFileLimit );

/**
��ȡ�Ƿ�Ϊ���ز���
@param   IN	  nPDLLHandle	SDK���
@param   IN	  nSeq        	�������к�
@param   IN	  bLocalPlay	�Ƿ�Ϊ���ز���
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_IsLocalPlay( IN int32_t nPDLLHandle, IN int32_t nSeq, OUT bool& bLocalPlay );


/**
����ĳ��ʵ����������ʹ�õ���Դ�������򿪵���Ƶ���������ص�¼�񡢴򿪵�������
@param   IN	  nPDLLHandle	SDK���
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseTasksByDLLHandle( IN int32_t nPDLLHandle);

/** ��ȡʵ��YUV����.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nRealSeq		�����������,����Ϊ����������ʶ 
 @param   IN	pGetInfo		����������Ϣ 
 @param   IN    pFun			�����ص�����				
 @param   IN    pUser			�����ص��û�����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRealYUVStream( IN int32_t nPDLLHandle, 
																OUT int32_t& nRealSeq, 
																IN Get_RealStream_Info_t* pGetInfo, 
																IN fMediaDataYUV pFun, 
																IN void* pUser, 
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �ر�ʵ��YUV����.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nRealSeq		�����������,����Ϊ����������ʶ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseRealYUVStreamBySeq( IN int32_t nPDLLHandle,
																		IN int32_t nRealSeq,
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ʼƽ̨¼�񣬳���һ��ʱ����Զ�ֹͣ
@param   IN    nPDLLHandle     SDK���
@param   IN    szCameraId      ͨ��ID
@param   IN    nDuration       ����ʱ�䣬��λ����
@param   IN    streamType      ʵʱ��������
@param   IN    nTimeout        ��ʱʱ������λ����
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark  
         �������ʱ���ڣ��ֵ��ñ��ӿڣ���nPDLLHandleֵһ�£���ô����ʱ���ӳ���(���һ�ε��õ�ʱ��� + ���һ�ε��õ�nDuration)��
*/
/*DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlatformReocrdForAPeriod(IN int32_t nPDLLHandle,
																			IN const char *szCameraId,
																			IN int32_t nDuration,
																			IN dpsdk_encdev_stream_e streamType = DPSDK_CORE_STREAM_MAIN,
																			IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );*/

/** ����Seq��������Ϣ�л�ȡ�����ļ���
@param   IN    nPDLLHandle     SDK���
@param   IN    nSeq            �������
@param   OUT   szFileName      �ļ���
@param   IN    nBufSize        szFileName�Ļ�������С
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFileNameFormDownloadInfoBySeq(IN int32_t nPDLLHandle,
																			   IN int32_t nSeq,
																			   OUT char* szFileName,
																			   IN int32_t nBufSize);

/** ��ȡ�ֱ���
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nRealSeq		�����������,����Ϊ����������ʶ 
 @param   OUT	nW				ͼƬ���
 @param   OUT	nH				ͼƬ�߶�
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetPictureSize( IN int32_t nPDLLHandle, 
														 IN int32_t nSeq,
														 OUT long* pnW,
														 OUT long* pnH);

/** ��ȡʵʱ����
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nRealSeq		�����������,����Ϊ����������ʶ 
 @param   OUT	pBitRate		ʵʱ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  ֻ�Դ�������Ч
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRealFrameBitRate( IN int32_t nPDLLHandle, 
																  IN int32_t nSeq,
																  OUT double *pBitRate);

/** �ֲ��Ŵ���ʾ
 @param		IN	nPDLLHandle		SDK���
 @param		IN	nRealSeq		�����������,����Ϊ����������ʶ 
 @param		IN	nRegionNum		��ʾ�������,0~(MAX_DISPLAY_WND-1),���Ϊ0,�����õ�������ʾ����������.
 @param		IN	pSrcRect		�ֲ���ʾ����
 @param		IN	hDestWnd		��ʾ���ھ��
 @param		IN	bEnable			��(����)��ر���ʾ����
 @return	�������ش������ͣ��ο�dpsdk_retval_e
 @remark	ֻ�Դ�������Ч
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDisplayRegion(	int32_t nPDLLHandle, 
																int32_t nSeq,
																int32_t nRegionNum, 
																int32_t nX,
																int32_t nY,
																int32_t nWidth,
																int32_t nHeight,
																void* hDestWnd, 
																bool bEnable);
/** ����������һ֡���ݻص�
 @param		IN	nPDLLHandle		SDK���
 @param		IN	pFun			��һ֡���ݻص�����ָ��
 @param		IN	UserParam		�û�����.
 @return	�������ش������ͣ��ο�dpsdk_retval_e
 @remark	ʵʱ���طŶ���ص�֪ͨ���յ�֪ͨ����ʾvaxplayer���ſ��ʼ���ɹ�
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetMediaDataFirstFrameCallback(fMediaDataFirstFrameCallback pFun, void* UserParam);

//////////////////////////////////////////////////////////////////////////
// ���½ӿڷ���
DPSDK_DLL_DEPRECATED int32_t DPSDK_CALL_METHOD DPSDK_SnapPictureByCameraId(IN int32_t nPDLLHandle, 
																		   IN const char* szCameraId, 
																		   IN dpsdk_pic_type_e nPicType, 
																		   IN const char* szFileName, 
																		   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
#endif
