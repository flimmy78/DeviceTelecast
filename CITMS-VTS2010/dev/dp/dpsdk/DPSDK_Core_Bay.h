#ifndef INCLUDED_DPSDK_CORE_BAY_H
#define INCLUDED_DPSDK_CORE_BAY_H

//////////////////////////////////////////////////////////////////////////
// ����ҵ��ӿ� ��ʼ

/** ����Υ�±����ص�
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKTrafficAlarmCallback( IN int32_t nPDLLHandle,
																			IN fDPSDKTrafficAlarmCallback fun,
																			IN void* pUser);

/** ����Υ��ͼƬ��Ϣд��
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pGetInfo		��ϸΥ����Ϣ,�ο�Traffic_Violation_Info_t
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_WriteTrafficViolationInfo(IN int32_t nPDLLHandle,
																		INOUT Traffic_Violation_Info_t* pGetInfo,
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ����Υ��ͼƬ��Ϣ��ѯ
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pGetInfo		��ϸΥ����Ϣ,�ο�Traffic_Violation_Info_t
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTrafficViolationInfo(IN int32_t nPDLLHandle,
																	  INOUT Traffic_Violation_Info_t* pGetInfo,
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ���������ϱ��ص�.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKGetTrafficFlowCallback(IN int32_t nPDLLHandle,
					   													     IN fDPSDKGetTrafficFlowCallback fun,
																			 IN void* pUser);
/** ���ó�������״̬�ϱ��ص�.
 @param   IN    nPDLLHandle     SDK���
 @param   IN    fun             �ص�����
 @param   IN    pUser           �û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKGetDevTrafficFlowCallback(IN int32_t nPDLLHandle,
																				IN fDPSDKGetDevTrafficFlowCallback fun,
																				IN void* pUser);

/** ���������ϱ�.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pGetInfo		�����豸�����ϱ�������Ϣ���ο�Subscribe_Traffic_Flow_Info_t
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SubscribeTrafficFlow( IN int32_t nPDLLHandle,
																	IN Subscribe_Traffic_Flow_Info_t* pGetInfo,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ���ÿ��ڹ�����Ϣ������ͼƬ���ϱ��ص�.
 @param   IN    nPDLLHandle     SDK���
 @param   IN    fun             �ص�����
 @param   IN    pUser           �û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  ���ûص������Ժ��ٶ���DPSDK_SubscribeBayCarInfo
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKGetBayCarInfoCallback(IN int32_t nPDLLHandle,
																			IN fDPSDKGetBayCarInfoCallback fun,
																			IN void* pUser);

/** ���ÿ��ڹ�����Ϣ������ͼƬ���ϱ��ص�.
 @param   IN    nPDLLHandle     SDK���
 @param   IN    fun             �ص�����
 @param   IN    pUser           �û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  ���ûص������Ժ��ٶ���DPSDK_SubscribeBayCarInfo
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKGetBayCarInfoCallbackEx(IN int32_t nPDLLHandle,
																			IN fDPSDKGetBayCarInfoCallbackEx fun,
																			IN void* pUser);


/** ���Ŀ��ڹ�����Ϣ�ϱ�.
 @param   IN    nPDLLHandle   SDK���
 @param   IN    pGetInfo      ���Ŀ��ڹ�����Ϣ�ϱ�������Ϣ���ο�Subscribe_Bay_Car_Info_t
                              ע��: �������ͨ����nChnlCountΪ0(pEncChannelnfoҪ��NULL)��
                              ��ʾ����ͨ���Ĺ������ݶ��ϱ�.
							  ֻ�ж����Ժ�picSDK�Ļص����������á�DPSDK_SetDPSDKGetBayCarInfoCallback���ܻص����ϲ�
 @param   IN    nTimeout        ��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SubscribeBayCarInfo( IN int32_t nPDLLHandle,
																   IN Subscribe_Bay_Car_Info_t* pGetInfo,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);
 
/** ������������ϱ�.
 @param   IN    nPDLLHandle     SDK���
 @param   IN    nSubscribeFlag  ���ı��:1���ģ�0��ȡ������
 @param   IN    nTimeout        ��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SubscribeAreaSpeedDetectInfo( IN int32_t nPDLLHandle,
																		    IN int32_t nSubscribeFlag,
																            IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);
/** ������������ϱ��ص�.
 @param   IN    nPDLLHandle     SDK���
 @param   IN    fun             �ص�����
 @param   IN    pUser           �û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKGetAreaSpeedDetectCallback(IN int32_t nPDLLHandle,
																				 IN fDPSDKGetAreaSpeedDetectCallback fun, 
																				 IN void* pUser);

/** ���ÿ��ڲ��ظ澯�ϱ��ص�.
 @param   IN    nPDLLHandle     SDK���
 @param   IN    fun             �ص�����
 @param   IN    pUser           �û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKBayWantedAlarmCallback(IN int32_t nPDLLHandle,
																			 IN fDPSDKBayWantedAlarmCallback fun, 
																			 IN void* pUser);


/**
	@brief ��ȡָ���������Ƶ���ģ��鲥����ַ�Ͷ˿�
	@param IN	camId				�����id
	@param IN	CamStream_Tnfo_t*	��Ҫ��ѯ����Ϣ
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetCamStreamInfo(IN int32_t nPDLLHandle,INOUT CamStream_Tnfo_t* lpinfo);

/**
	@brief ͨ��������IP��ͨ����,���Ҷ�Ӧ����ǽ��Ϣ�����������ڰ�
	@param IN tagQueryTvWallInfo*	��Ҫ��ѯ����Ϣ
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD BindTvWallInfo(IN int32_t nPDLLHandle,INOUT QueryTvWall_Info_t* lpinfo);

/** ͼƬ���
@param  IN		nPDLLHandle     SDK���
@param	IN		cameraId		ͨ��ID
@param	IN		funCB			ͼƬ���ݻص�����ָ��
@param	IN		pCBParam		�û�����
@param	IN		eBayType		ҵ������
@param	OUT		iSessionId		���صĻỰId DPSDK_StopPicMonitor�ӿ���Ҫ
@return							�첽˳����,�����¼��ص�ʱ,��Ӧ���¼�ƥ��
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPicMonitor(int32_t nPDLLHandle, 
															  const char* cameraId, 
															  fPicDataCallback funCB, 
															  void* pCBParam, 
															  dpsdk_bay_monitor_e eBayType, 
															  int32_t iSessionId);

/** ֹͣͼƬ���
@param  IN		nPDLLHandle     SDK���
@param	IN		sessionId		�ỰId
@return							�첽˳����,�����¼��ص�ʱ,��Ӧ���¼�ƥ��
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopPicMonitor(int32_t nPDLLHandle, 
															 uint32_t sessionId);


// ����ҵ��ӿ� ����


#endif