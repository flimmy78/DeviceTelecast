#ifndef INCLUDED_DPSDK_CORE_TALK_H
#define INCLUDED_DPSDK_CORE_TALK_H

/** �����Խ�ʧ�ܺ�����ص�.
 @param   IN    nPDLLHandle     SDK���
 @param   IN    fun             �ص�����
 @param   IN    pUser           �û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKTalkParamCallback(IN int32_t nPDLLHandle,
																		IN fDPSDKTalkParamCallback fun, 
																		IN void* pUser);


/** ��ʼ�㲥���򿪹㲥������
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nBroadcastSeq	�����������,����Ϊ����������ʶ 
 @param   IN	szJson			����������Ϣ 
 @param   IN    pFun			�����ص�����				
 @param   IN    pUser			�����ص��û�����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartBroadcast( int32_t nPDLLHandle, 
																  int32_t* nBroadcastSeq, 
																  const char* szJson,
																  fMediaDataCallback pFun, 
																  void* pUser, 
																  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �رչ㲥
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szJson			������Ϣ 
 @param   IN	nBroadcastSeq	�����������
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseBroadcastStream( int32_t nPDLLHandle, 
															        const char* szJson, 
																	int32_t nBroadcastSeq,
															        int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ��ȡ��������
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nTalkSeq		�����������,����Ϊ����������ʶ 
 @param   IN	pGetInfo		����������Ϣ 
 @param   IN    pFun			�����ص�����				
 @param   IN    pUser			�����ص��û�����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTalkStream( IN int32_t nPDLLHandle, 
														     OUT int32_t& nTalkSeq, 
														     IN Get_TalkStream_Info_t* pGetInfo, 
														     IN fMediaDataCallback pFun, 
														     IN void* pUser, 
														     IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ����������ֹͣ���������Ļ�ȡ
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nRealSeq		�����������,����Ϊ����������ʶ 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseTalkStreamBySeq( IN int32_t nPDLLHandle, 
															        IN int32_t nRealSeq, 
															        IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ��CameralIdֹͣ����������ȡ.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szCameraId		ͨ����� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseTalkStreamByCameralId( IN int32_t nPDLLHandle, 
															              IN const char* szCameraId,
															              IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ�����ɼ��ص���Ϣ
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	pCallBackFun	�ص�����
 @param   OUT	pUserParam   	�ص������û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetSdkAudioCallbackInfo(IN int32_t nPDLLHandle,
															          OUT void* &pCallBackFun,
																      OUT AudioUserParam_t* &pUserParam);



#endif