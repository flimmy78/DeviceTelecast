#ifndef INCLUDED_DPSDK_CORE_PTZ_H
#define INCLUDED_DPSDK_CORE_PTZ_H

/** ������̨������Ϣ
 @param	  IN	nPDLLHandle				SDK���
 @param   IN	szCameraId		        ͨ�����
 @param	  IN	nSubscribeFlag			���ı�ǡ�0:ȡ�����ģ�1������
 @param   IN	nTimeout				��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SubscribePtzSitAlarm( IN int32_t nPDLLHandle,
																   	IN char* szCameralID,   
																	IN int32_t nSubscribeFlag,
																	OUT int32_t& nResult,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��̨�������.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	pDirectInfo		��̨���������Ϣ 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzDirection( IN int32_t nPDLLHandle, 
															IN Ptz_Direct_Info_t* pDirectInfo, 
															IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��̨��ͷ����.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	pOperationInfo	��̨��ͷ������Ϣ 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzCameraOperation( IN int32_t nPDLLHandle, 
																  IN Ptz_Operation_Info_t* pOperationInfo, 
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** ��̨��ά��λ.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	pSitInfo		��̨��ά��λ��Ϣ 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzSit( IN int32_t nPDLLHandle, 
													  IN Ptz_Sit_Info_t* pSitInfo, 
													  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ѯ��̨��ά��Ϣ
@param	 IN	   nPDLLHandle	SDK���
@param   INOUT pSitInfo		��̨��ά��λ��Ϣ 
@param   IN	   nTimeout		��ʱʱ������λ����
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryPtzSitInfo( IN int32_t nPDLLHandle, 
															   IN OUT Ptz_Sit_Info_t* pSitInfo, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��̨��������.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	pLockInfo	    ��̨����������Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzLockCamera( IN int32_t nPDLLHandle, 
															 IN Ptz_Lock_Info_t* pLockInfo, 
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��̨�ƹ����.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	szCameraId		ͨ��ID 
 @param   IN	bOpen			������ʶ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzLightControl( IN int32_t nPDLLHandle, 
															   IN Ptz_Open_Command_Info_t* Cmd, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��̨��ˢ����.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	szCameraId		ͨ��ID 
 @param   IN	bOpen			������ʶ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzRainBrushControl( IN int32_t nPDLLHandle, 
																   IN Ptz_Open_Command_Info_t* Cmd, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��̨�������.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	szCameraId		ͨ��ID 
 @param   IN	bOpen			������ʶ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzInfraredControl( IN int32_t nPDLLHandle, 
																  IN Ptz_Open_Command_Info_t* Cmd, 
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��̨��ѯԤ�õ���Ϣ.
 @param	  IN	nPDLLHandle		SDK���
 @param	  INOUT	pPrepoint		Ԥ�õ���Ϣ 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryPrePoint( IN int32_t nPDLLHandle, 
															 INOUT Ptz_Prepoint_Info_t* pPrepoint, 
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ѯ������Чʱ��ε���̨Ԥ�õ���Ϣ.
 @param	  IN	nPDLLHandle		SDK���
 @param	  INOUT	pPrepoint		Ԥ�õ���Ϣ 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryTimePrePoint( IN int32_t nPDLLHandle, 
																 INOUT Ptz_Time_Prepoint_Info_t* pPrepoint, 
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��̨Ԥ�õ����.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	pOperation		Ԥ�õ������Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzPrePointOperation( IN int32_t nPDLLHandle, 
																	IN Ptz_Prepoint_Operation_Info_t* pOperation, 
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ������̨��ʱ��������
 @param   IN	nPDLLHandle		SDK���
 @param   IN	pTask		      ��ʱ��̨������Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPtzTimeTask( IN int32_t nPDLLHandle, 
															  IN Ptz_Time_Task_Info_t* pTask, 
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ��ȡ��̨��ʱ��������.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	pTask		      ��ʱ��̨������Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryPtzTimeTask( IN int32_t nPDLLHandle, 
																INOUT Ptz_Time_Task_Info_t* pTask, 
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ����Ԥ�õ����Чʱ���.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	pOperation		Ԥ�õ������Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPrePointTime( IN int32_t nPDLLHandle, 
															   IN Ptz_Prepoint_Time_t* pOperation, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��̨��չ����.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pExtCmd			��չ������Ϣ 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzExtendCommand( IN int32_t nPDLLHandle, 
																IN Ptz_Extend_Command_Info_t* pExtCmd, 
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ������̨��λ������Ϣ�ص�
@param   IN    nPDLLHandle		SDK���
@param   IN    fun				�ص�����
@return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKPtzSitAlarmInfoCallback(int32_t nPDLLHandle, 
																			  fDPSDKPtzSitAlarmInfoCallback fun,  
																			  void* pUser );
/** ���������̨����
@param   IN    nPDLLHandle		SDK���
@param   IN    szCameraId		ͨ��ID
@param   IN    fun				�ص�����
@return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPtzParam(int32_t nPDLLHandle,
														  const char* szCameraId,
														  Ptz_Param_t* pOperation,
														  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ѯ�����������Ϣ
@param   IN    nPDLLHandle		SDK���
@param   IN    szCameraId		ͨ��ID
@param   OUT   pOperation		��������Ϣ
@return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryChannelViewInfo(int32_t nPDLLHandle,
																	const char* szCameraId,
																	Channel_View_Info_t* nChannelViewInfo,
																	int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** ����Ӳ��¼�������������Ŀ�������Ϣ�ص�����
@param   IN    nPDLLHandle		SDK���
@param   IN    fun				��������Ϣ�ص�����ָ��
@param   OUT   pUser			�û��Զ���ָ��
@return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetChannelViewInfoCallback(int32_t nPDLLHandle,
																		 fDPSDKChannelViewInfoCallback fun,
																		 void* pUser );


/** ��ѯӲ��¼���������ͨ���Ŀ�������Ϣ
@param   IN    nPDLLHandle		SDK���
@param   IN    szDeviceId		�豸ID
@return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryDeviceViewInfo(int32_t nPDLLHandle,
																   const char* szDeviceId,
																   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


#endif