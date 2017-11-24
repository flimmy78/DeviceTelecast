#ifndef INCLUDED_DPSDK_CORE_ALARMBUSINESS_H
#define INCLUDED_DPSDK_CORE_ALARMBUSINESS_H

/** �����豸ID��ȡ��������ͨ����Ϣ
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	pstruUserInfo	�û���Ϣ�ṹ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
 1��pAlarmInChannelnfo��Ҫ�����洴����
 2��pAlarmInChannelnfo�ĸ�����DPSDK_GetDGroupInfo����ʱ�б��������豸id�ͱ�������ͨ������
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetAlarmInChannelInfo( IN int32_t nPDLLHandle, 
																	INOUT Get_AlarmInChannel_Info_t* pstruUserInfo);

/** ��ѯ���籨������״̬
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szDeviceId		�豸id
 @param   IN	nChannelcount	ͨ������
 @param   OUT	pDefence		ͨ����Ϣ�ṹ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 1��pDefence��Ҫ�����洴���ã�����ͨ������new
 2��û�е����豸�Ĳ�����״̬����Ҫ����ͨ����״̬�ж�
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryNetAlarmHostStatus( IN int32_t nPDLLHandle, 
																	   IN const char* szDeviceId,
																	   IN int32_t nChannelcount,
																	   OUT dpsdk_AHostDefenceStatus_t* pDefence,
																	   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ѯ���籨������״̬������ͨ������
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szDeviceId		�豸id
 @param   OUT	pChannelcount	ͨ������
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 1��pDefence��Ҫ�����洴���ã�����ͨ������new
 2��û�е����豸�Ĳ�����״̬����Ҫ����ͨ����״̬�ж�
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryNetAlarmHostChannelCount(int32_t nPDLLHandle, 
																			const char* szDeviceId,
																			int32_t* pChannelcount,
																			int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** ��ȡ���籨����������״̬
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nChannelcount	ͨ������
 @param   OUT	pDefence		ͨ����Ϣ�ṹ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 1���ȵ���DPSDK_QueryNetAlarmHostChannelCount��ȡͨ������nChannelcount
 2��Ȼ��newһ��nChannelcount��С�Ľṹ������dpsdk_AHostDefenceStatus_tָ��pDefence
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetNetAlarmHostStatus(int32_t nPDLLHandle,
																	int32_t nChannelcount,
																	dpsdk_AHostDefenceStatus_t* pDefence);

/** ������Ƶ��������������/��·״̬�ص�.
 @param   IN    nPDLLHandle     SDK���
 @param   IN    fun             �ص�����
 @param   IN    pUser           �û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
 1����½ƽ̨��ʱ��ƽ̨�Ȼص��豸������״̬�����Żص�ͨ����·״̬
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetVideoAlarmHostStatusCallback(IN int32_t nPDLLHandle,
																			  IN fDPSDKVideoAlarmHostStatusCallback fun, 
																			  IN void* pUser);

/** �������籨������������/��·״̬�ص�.
 @param   IN    nPDLLHandle     SDK���
 @param   IN    fun             �ص�����
 @param   IN    pUser           �û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
 1���������ͻ����޸������籨������״̬�Ժ󣬻ص�֪ͨ
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetNetAlarmHostStatusCallback(IN int32_t nPDLLHandle,
																			  IN fDPSDKNetAlarmHostStatusCallback fun, 
																			  IN void* pUser);

/** ������������-������Ӫƽ̨.
 @param   IN    nPDLLHandle     SDK���
 @param   IN    userParam       �û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PhoneSubscribeAlarm(IN int32_t nPDLLHandle,
																  INOUT dpsdk_phone_subscribe_alarm_t& userParam, 
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��Ƶ�����������豸������/ͨ����·/����ͨ������.
 @param   IN    nPDLLHandle     SDK���
 @param   IN    szDeviceId      �豸id
 @param   IN    channelId       ͨ���ţ�-1��ʾ���豸����
 @param   IN    controlType     ��������, �ο�dpsdk_AlarmhostOperator_e
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
 1����Ƶ������������Ϊ:1101
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ControlVideoAlarmHost(IN int32_t nPDLLHandle,
																	IN const char *szDeviceId, 
																	IN int32_t channelId, 
																	IN int32_t controlType,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ���籨���������豸������/ͨ����·/����ͨ������.
 @param   IN    nPDLLHandle     SDK���
 @param   IN    szId			�豸id/ͨ��id
 @param   IN    opttype			�豸/ͨ������,�ο�dpsdk_netalarmhost_operator_e
 @param   IN    controlType     ��������, �ο�dpsdk_netalarmhost_cmd_e
 @param   IN    iStart			��ʼʱ��,Ĭ��Ϊ0
 @param   IN    iEnd			����ʱ��,Ĭ��Ϊ0
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
 1�����籨����������Ϊ:601
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ControlNetAlarmHostCmd(IN int32_t nPDLLHandle,
																	 IN const char* szId, 
																	 IN int32_t opttype, 
																	 IN int32_t controlType, 
																	 IN int64_t iStart, 
																	 IN int64_t iEnd, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


#endif