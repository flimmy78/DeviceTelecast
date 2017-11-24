#ifndef INCLUDED_DPSDK_CORE_VEHICLE_H
#define INCLUDED_DPSDK_CORE_VEHICLE_H

/** ����DPSDKΧ�������ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKPeccancyAlarmCallback( IN int32_t nPDLLHandle,
																			 IN fDPSDKPeccancyAlarmCallback fun,
																			 IN void* pUser);

/** ����DPSDK����Χ������ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKAreaChangeCallback( IN int32_t nPDLLHandle,
																		  IN fDPSDKAreaChangeCallback fun,
																		  IN void* pUser);


/** Զ���豸ץͼ �����ڳ���ƽ̨
 @param   IN    nPDLLHandle		    SDK���
 @param   IN	szCameraId			ͨ��ID
 @param   IN	szLocalPath			ץͼ·��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_RemoteDeviceSnap(int32_t nPDLLHandle,
															   const char *szCameraId,
															   const char *szLocalPath);


/** ����Զ���豸ץͼ�ص�
 @param   IN    nPDLLHandle		SDK���
 @param   IN    fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKRemoteDeviceSnapCallback(int32_t nPDLLHandle,
																			   fDPSDKRemoteDeviceSnapCallback fun,
																			   void *pUser);

/** ����3G��Ϣ�ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDK3GFlowInfoCallback( IN int32_t nPDLLHandle, 
																			IN fDPSDK3GFlowInfoCallback fun, 
																			IN void* pUser );
/**��ȡ����GPS��ϢXML������.
 @param		IN		nPDLLHandle				SDK���
 @param		OUT		nGpsXMLLen				GPS XML�ĳ���
 @param		IN		nTimeout				��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AskForLastGpsStatusXMLStrCount(int32_t nPDLLHandle, 
																  int* nCount,
																  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/**��ȡ����GPS��Ϣ.
 @param		IN		nPDLLHandle				SDK���
 @param		OUT		LastGpsIStatus			GPS XML����
 @param		IN		nCount					GPS XML�ĳ���,DPSDK_AskForLastGpsStatusXMLStrCount���������ֵ
 @param		IN		nTimeout				��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AskForLastGpsStatusXMLStr(int32_t nPDLLHandle, 
																		char* LastGpsIStatus,
																		int nCount);

/**��ȡ����GPS��Ϣ.
 @param		<IN>		nPDLLHandle				SDK���
 @param		<OUT>		LastGpsIStatus			����GPS��Ϣ
 @param		<IN>		nTimeout				��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AskForLastGpsStatus(int32_t nPDLLHandle, 
																  char* LastGpsIStatus,
																  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);
/**��ȡ�û�Ȩ���µ���·��Ϣ.
 @param		<IN>		nPDLLHandle			SDK���
 @param		<OUT>		szJsonLineInfo		ƽ̨���ص���·��Ϣ(Json�ַ���)
 @param		<IN>		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetOwnLineInfo(int32_t nPDLLHandle, 
															 char* szJsonLineInfo,
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);



/**��ȡ�Ű���Ϣ.
 @param		<IN>		nPDLLHandle			SDK���
 @param		<IN>		BeginTime			��ʼʱ��
 @param		<IN>		EndTime				����ʱ��
 @param		<IN>		InListLineId[]		��·id
 @param		<IN>		LineNum				��·����
 @param		<OUT>		szJsonBusSchedule	ƽ̨���ص��Ű���Ϣ(Json�ַ���)
 @param		<IN>		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetBusScheduleInfo(int32_t nPDLLHandle,
																 const char* BeginTime,
																 const char* EndTime, 
																 const int InListLineId[], 
																 const int LineNum,
																 char* szJsonBusSchedule,
																 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/**�����Ű���Ϣ�޸Ļص�.
 @param		<IN>		nPDLLHandle			SDK���
 @param		<IN>		fun					�ص�����
  @param	<IN>		pUser				�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetBusScheduleChangeCallback(int32_t nPDLLHandle,
																			fDPSDKBusScheduleChangeCallback fun,
																			void* pUser);

/**�����Ű�״̬�޸Ļص�.
 @param		<IN>		nPDLLHandle			SDK���
 @param		<IN>		fun					�ص�����
 @param		<IN>		pUser				�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetBusScheduleStateChangeCallback(int32_t nPDLLHandle,
																				fDPSDKBusScheduleStateChangeCallback fun,
																				void* pUser);
/**���õ�����Ϣ֪ͨ�ص�.
 @param		<IN>		nPDLLHandle			SDK���
 @param		<IN>		fun					�ص�����
 @param		<IN>		pUser				�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDispitchInfoCallback(int32_t nPDLLHandle,
																	  fDPSDKDispitchInfoCallback fun,
																	  void* pUser);

/**��ȡ����վ����Ϣ.
 @param		<IN>		nPDLLHandle				SDK���
 @param		<IN>		LineId					��·id
 @param		<OUT>		szJsonLastStationInfo	ƽ̨���ص�����վ����Ϣ(Json�ַ���)
 @param		<IN>		nTimeout				��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetLastStationsInfo(int32_t nPDLLHandle,
																  const int LineId, 
																  char* szJsonLastStationInfo,
																  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ���ӵ���Χ��
@param  IN		nPDLLHandle     SDK���
@param	IN		pAreaInfo		����Χ����Ϣ
@param	IN		arryDevId		�豸ID������
@param	IN		nDevIdCount		�豸ID������ĳ���
@param	OUT		strAreaId		Χ��ID
@param	IN		nAreaIdLen		Χ��ID���ַ�����С
@return
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AddAreaInfo(IN int32_t nPDLLHandle, 
														  IN Area_Info_t* pAreaInfo,
														  IN char arryDevId[][DPSDK_CORE_DEV_ID_LEN],
														  IN int32_t nDevIdCount,
														  OUT char szAreaId[],
														  IN int32_t nAreaIdLen,
														  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ɾ������Χ��
@param  IN		nPDLLHandle     SDK���
@param	IN		szAreaId		����Χ��Id
@return
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DelAreaInfo(IN int32_t nPDLLHandle, 
														  IN const char* szAreaId,
														  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** �޸ĵ���Χ��
@param  IN		nPDLLHandle     SDK���
@param	IN		szAreaId		����Χ��Id
@param	IN		pAreaInfo		����Χ����Ϣ
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ModAreaInfo(IN int32_t nPDLLHandle,
														  IN const char* szAreaId,
														  IN Area_Info_t* pAreaInfo,
														  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** �����豸�����Χ���Ĺ�����ֻ�޸��˱����ڴ��еģ���ҪUpload���ϴ�����
@param  IN		nPDLLHandle     SDK���
@param	IN		szDevId			�豸ID
@param	IN		szAreaId		����Χ��ID
@param	IN		nAreaType		����Χ������
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AddAreaInDev(IN int32_t nPDLLHandle, 
														   IN const char* szDevId,
														   IN const char* szAreaId,
														   IN dpsdk_area_type_e nAreaType,
														   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ɾ���豸�����Χ���Ĺ�����ֻ�޸��˱����ڴ��еģ���ҪUpload���ϴ�����
@param  IN		nPDLLHandle     SDK���
@param	IN		szDevId			�豸ID
@param	IN		szAreaId		����Χ��ID
@return							
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DelAreaInDev(IN int32_t nPDLLHandle, 
														   IN const char* szDevId,
														   IN const char* szAreaId,
														   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** �ϴ��豸��Χ����ϵ������
@param  IN		nPDLLHandle     SDK���
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_UploadRelationChange(IN int32_t nPDLLHandle,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** ��ͼƬ���ַ����������ת��
@param  IN		nPDLLHandle     SDK���
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ConvertPicStrToBinary(IN int32_t nPDLLHandle,
																	IN char* pInputPic,
																	OUT char* pOutPic,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ѯ�豸��Χ���Ĺ�ϵ
@param  IN		nPDLLHandle     SDK���
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryDevAreaRelationLen(IN int32_t nPDLLHandle,
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** ��ȡΧ����Ϣ
@param  IN		nPDLLHandle     SDK���
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AskForAreaInfo(IN int32_t nPDLLHandle,
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ����ͣ������ͣ��������ȡ��Ӧͨ��ID
@param  IN		nPDLLHandle     SDK���
@param	IN		StopSection		ͣ����
@param	IN		StopWay			ͣ����
@param	OUT		CameraID		ͨ��ID
@param	IN		nTimeout		������ʱʱ��
@return							�첽˳����,�����¼��ص�ʱ,��Ӧ���¼�ƥ��
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetCameraIDbyStopSectionandWay(int32_t nPDLLHandle,
																			 const char* StopSection,
																			 const char* StopWay,
																			 char* CameraID,
																			 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ����ͨ��ID��������ͷ�������ַ�������
@param  IN		nPDLLHandle     SDK���
@param	IN		DeviceID		����ͷ�豸ID
@param	IN		bFlag			���ر�־ true����  false����
@param	IN		nTimeout		������ʱʱ��
@return							�첽˳����,�����¼��ص�ʱ,��Ӧ���¼�ƥ��
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OpenIntrusionDetection(int32_t nPDLLHandle,
																	 const char* CameraID,
																	 bool bFlag,
																	 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

#endif