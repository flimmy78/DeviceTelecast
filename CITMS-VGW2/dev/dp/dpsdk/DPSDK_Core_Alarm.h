#ifndef INCLUDED_DPSDK_CORE_ALARM_H
#define INCLUDED_DPSDK_CORE_ALARM_H


/** ���ñ���״̬�ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
	1����Ҫ��DPSDK_Create�ɶ�ʹ��
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDKAlarmCallback( IN int32_t nPDLLHandle, 
																	 IN fDPSDKAlarmCallback fun, 
																	 IN void* pUser );

/** �����±���״̬�ص�
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
	1����Ҫ��DPSDK_Create�ɶ�ʹ��
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDKNewAlarmCallback( IN int32_t nPDLLHandle, 
																	 IN fDPSDKNewAlarmCallback fun, 
																	 IN void* pUser );

/** ��������.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pSourceInfo		�������� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
 1������ʱ��Ҫ���ײ�ͬ�ı������Ͷ�Ӧ��ͬ�Ĳ���
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_EnableAlarm( IN int32_t nPDLLHandle, 
														   IN Alarm_Enable_Info_t* pSourceInfo, 
														   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��������(���ĳ�������µ������豸)
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pSourceInfo		�������� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
 1������ʱ��Ҫ���ײ�ͬ�ı������Ͷ�Ӧ��ͬ�Ĳ���
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_EnableAlarmByDepartment( IN int32_t nPDLLHandle, 
														               IN Alarm_Enable_By_Dep_Info_t* pSourceInfo, 
														               IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��������.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DisableAlarm( IN int32_t nPDLLHandle, 
															IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ��ѯ��������.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN    pQuery          ��ѯ��Ϣ
 @param	  OUT	nCount			������������ 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryAlarmCount( IN int32_t nPDLLHandle, 
															   IN Alarm_Query_Info_t* pQuery, 
															   OUT int32_t& nCount, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ѯ������Ϣ.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN    pQuery          ��ѯ��Ϣ
 @param	  		pInfo			������Ϣ 
 @param	  IN	nFirstNum		�ӵڼ�����ʼ��ȡ 
 @param	  IN	nQueryCount		��ȡ���ٸ� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
 1��֧�ַ�����ȡ
 2���˽ӿ��Ƽ���DPSDK_QueryAlarmCountһ��ʹ��
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryAlarmInfo( IN int32_t nPDLLHandle, 
															  IN Alarm_Query_Info_t* pQuery, 
															  INOUT Alarm_Info_t* pInfo, 
															  IN int32_t nFirstNum, 
															  IN int32_t nQueryCount, 
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ��ѯ����ͼƬ��Ϣ.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN    optype          ��������
 @param	  IN	szCameraId		ͨ��ID 
 @param	  IN	szIvsURL		ͼƬURL 
 @param	  IN	szSavePath		����·�� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
 1��֧�ַ�����ȡ
 2���˽ӿ��Ƽ���DPSDK_QueryAlarmCountһ��ʹ��
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryIvsbAlarmPicture( int32_t nPDLLHandle,
																   dpsdk_operator_ftp_type_e optype, 
																   const char* szCameraId,
																   const char* szIvsURL, 
																   const char* szSavePath,
																   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );



/** ���ͱ���������.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN    Client_Alarm_Info_t		������Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendAlarmToServer( IN int32_t nPDLLHandle, 
																 IN Client_Alarm_Info_t* pAlarmInfo,
															     IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ��ȡ����ģ������
 @param   IN    nPDLLHandle		SDK���
 @param   OUT   pCount			����ģ������
 @param   IN	nTimeout		��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetCustomTimeTemplateCount(IN int32_t nPDLLHandle,
																		 IN uint32_t* pCount,
																		 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/**	��ȡ�Զ�������ģ��.
@param		IN		nPDLLHandle			SDK���
@param		IN		id					ʱ��ģ��id(�������0�����ȡ����ʱ��ģ��)
@param		OUT		pTimeTemplate		����ģ����Ϣ
@param		IN		nTimeout			��ʱʱ��
@param		IN		nTimeout			��ʱʱ��
@return									�������ش������ͣ��ο�dpsdk_retval_e
@remark  
1�������Ҫ��ȡ����ģ�壬�����Ȳ�ѯ���ȡ
2��DPSDK_GetCustomTimeTemplateCount�᷵�ؼ�¼����,pTimeTemplate���ݼ�¼����������������Ӧ�ڴ�
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetCustomTimeTemplate(IN int32_t nPDLLHandle,
																	IN int32_t id,
																	OUT TimeTemplateInfo_t* pTimeTemplate,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/**	��ȡ��������Ԥ���ļ�����.
@param		IN		nPDLLHandle			SDK���
@param		IN		id					Ԥ�����ݿ�id
@param		OUT		pLen				Ԥ���ļ����ݳ���
@param		IN		nTimeout			��ʱʱ��
@return									�������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetSchemeFileDataLen(IN int32_t nPDLLHandle,
																   IN int32_t id,
																   OUT int32_t* pLen,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/**	��ȡ��������Ԥ��.
@param		IN		nPDLLHandle			SDK���
@param		IN		id					Ԥ�����ݿ�id
@param		OUT		pTimeTemplate		Ԥ����Ϣ
@param		IN		nTimeout			��ʱʱ��
@return									�������ش������ͣ��ο�dpsdk_retval_e
@remark  
1. pTimeTemplate�ڴ���Ҫ���������;
2. ���ô˺���ǰ�����ȵ���DPSDK_GetSchemeFileDataLen��ȡԤ���ļ����ȣ����ݴ˳��ȷ���data�ڴ�,data�ڴ�Ҳ��Ҫ���������.
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetSchemeFile(IN int32_t nPDLLHandle,
															IN int32_t id,
															OUT AlarmSchemeFileInfo_t* pTimeTemplate,
															IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ɾ������Ԥ��.
@param		IN		nPDLLHandle			SDK���
@param		IN		id					Ԥ�����ݿ�id
@param		IN		nTimeout			��ʱʱ��
@return									�������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DelSchemeFile(IN int32_t nPDLLHandle,
															IN uint32_t id, 
															IN bool bNotifyAll=false,
															IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ֪ͨԤ��ʧЧ.
@param		IN		nPDLLHandle			SDK���
@param		IN		schemeID			Ԥ��ID
@param		IN		notifyType			������ͣ� (7)������Ϣ��ʱ�������������Դ��������,(1)ʱ�������,(2)����Դ,(4)�������������.
@param		IN		nTimeout			��ʱʱ��
@return									�������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_NotifySchemeInvalidate(IN int32_t nPDLLHandle,
																	 IN int64_t schemeID, 
																	 IN uint32_t notifyType,
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ���ñ���Ԥ������ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetAlarmSchemeCallback(IN int32_t nPDLLHandle,
																			  IN fDPSDKAlarmSchemeCallback fun,
																			  IN void * pUser);
/** ��ȡ����Ԥ������
 @param   IN    nPDLLHandle		SDK���
 @param   OUT   pCount			����Ԥ������
 @param   IN	nTimeout		��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetAlarmSchemeCount(IN int32_t nPDLLHandle,
																  OUT uint32_t* pCount,
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** ��ȡ����Ԥ���б�
 @param		IN		nPDLLHandle			SDK���
 @param		OUT		pAlarmSchemeList	����Ԥ��
 @param		IN		nCount				����Ԥ������
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetAlarmSchemeList(IN int32_t nPDLLHandle,
																 OUT AlarmSchemeInfo_t* pAlarmSchemeList,
																 IN uint32_t nCount,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ���汨��Ԥ��
 @param		IN		nPDLLHandle			SDK���
 @param		IN		pAlarmScheme		����Ԥ��
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SaveAlarmScheme(IN int32_t nPDLLHandle,
															  IN const AlarmSchemeInfo_t* pAlarmScheme,
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ���汨��Ԥ���ļ�
 @param		IN		nPDLLHandle			SDK���
 @param		IN		id					Ԥ�����ݿ�id
 @param		IN		schemeName			Ԥ������
 @param		IN		status				Ԥ������
 @param		IN		templateId			ʱ��ģ��id
 @param		IN		desc				Ԥ������
 @param		IN		data				Ԥ������
 @param		IN		len					Ԥ�����ݳ���
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SaveSchemeFile(IN int32_t nPDLLHandle,
															 IN uint32_t id,
															 IN const char* schemeName,
															 IN dpsdk_alarmScheme_status_e status, 
															 IN uint32_t templateId, 
															 IN const char* desc, 
															 IN const char* data, 
															 IN uint32_t len,
															 IN bool bNotifyAll = false,
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ͼ��ȡ����ͼƬ
 @param		IN		nPDLLHandle			SDK���
 @param		IN      szCameraId						����ʶ���豸��ָ��ͨ��ID
 @param		IN      requestFlag						�û��Զ���������ǣ�����������
 @param		IN		picData							ͼƬ����
 @param		IN		nFileLength						ͼƬ�ļ���С
 @param		IN		nPicWidth						ͼƬ���
 @param		IN		nPicHeight						ͼƬ�߶�
 @param		OUT		faceDataLength					���ص��������ݳ���
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ExtractFacePicDataLength(int32_t nPDLLHandle,
															 const char* szCameraId, 
															 long requestFlag, 
															 char* picData, 
															 uint32_t nFileLength, 
															 uint32_t nPicWidth, 
															 uint32_t nPicHeight,
															 long* faceDataLength,
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ͼ��ȡ����ͼƬ
 @param		IN		nPDLLHandle			SDK���
 @param		IN      szCameraId						����ʶ���豸��ָ��ͨ��ID
 @param		IN      requestFlag						�û��Զ���������ǣ�����������
 @param		IN		picData							ͼƬ����
 @param		IN		nFileLength						ͼƬ�ļ���С
 @param		IN		nPicWidth						ͼƬ���
 @param		IN		nPicHeight						ͼƬ�߶�
 @param		OUT		faceData						���ص���������
 @param		IN		faceDataLength					���ص��������ݳ���
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ExtractFacePicData(int32_t nPDLLHandle,
															 const char* szCameraId, 
															 long requestFlag, 
															 char* picData, 
															 uint32_t nFileLength, 
															 uint32_t nPicWidth, 
															 uint32_t nPicHeight,
															 char*	faceData,
															 long faceDataLength,
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ���ݲ�ѯ��������ȡ��������ƥ�������
 @param		IN		nPDLLHandle			SDK���
 @param		IN		const char* szCameraId						    ����ʶ���豸��ָ��ͨ��ID
 @param		IN		long requestFlag								�û��Զ���������ǣ�����������
 @param		IN		const char* data								��ѯ����
 @param		IN		uint32_t len									��ѯ���������ݳ���
 @param		OUT		int32_t count									ƥ������
 @param		OUT		uint32_t querySession							��ѯ�Ự
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryFaceCount(int32_t nPDLLHandle,
															 const char* szCameraId, 
															 long requestFlag, 
															 const char* data, 
															 uint32_t len,
															 int32_t* count,
															 uint32_t* querySession,
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ���ݲ�ѯ��������ȡ����Session����ȡָ�������ƥ������
 @param		IN		nPDLLHandle			SDK���
 @param		IN		szCameraId						    ����ʶ���豸��ָ��ͨ��ID
 @param		IN		nQuerySession						��ѯƥ����Ŀʱ��ȡ����Session
 @param		IN		nStartIndex							��ʼ��������
 @param		IN		nQueryNum							��������
 @param		OUT		dataLength							���ص����ݳ���
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryFaceDataLength(int32_t nPDLLHandle,
															const char* szCameraId, 
															uint32_t nQuerySession, 
															uint32_t nStartIndex, 
															uint32_t nQueryNum,	
															uint32_t* dataLength,
															int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ���ݲ�ѯ��������ȡ����Session����ȡָ�������ƥ������
 @param		IN		nPDLLHandle			SDK���
 @param		IN		szCameraId						    ����ʶ���豸��ָ��ͨ��ID
 @param		IN		nQuerySession						��ѯƥ����Ŀʱ��ȡ����Session
 @param		IN		nStartIndex							��ʼ��������
 @param		IN		nQueryNum							��������
 @param		OUT		personData							���صľ�������
 @param		IN		dataLength							���ص����ݳ���
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryFaceData(int32_t nPDLLHandle,
															 const char* szCameraId, 
															 uint32_t nQuerySession, 
															 uint32_t nStartIndex, 
															 uint32_t nQueryNum,
															 char*	personData,		
															 uint32_t dataLength,
															 char* szPicServerIp,
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ����ע�����ݲ���
 @param		IN		nPDLLHandle			SDK���
 @param		IN		szCameraId							����ʶ���豸��ָ��ͨ��ID
 @param		IN		requestFlag							�û��Զ���������ǣ�����������
 @param		IN		operateType,						�������ͣ����/�޸ļ�ɾ����
 @param		IN		data								����������
 @param		IN		len									���ݳ���
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OperateFaceLib(int32_t nPDLLHandle,
															const char* szCameraId, 
															long requestFlag, 
															uint32_t operateType, 
															const char* data, 
															uint32_t len,
															int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** �Ͽ�ָ�����������ѯSession
 @param		IN		nPDLLHandle			SDK���
 @param		IN		szCameraId							����ʶ���豸��ָ��ͨ��ID
 @param		IN		nQuerySession						��ѯƥ����Ŀʱ��ȡ����Session
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopFaceQuery(int32_t nPDLLHandle,
															 const char* szCameraId, 
															 uint32_t nQuerySession,
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ���ݲ�ѯ��������ȡ����ʶ�𱨾���ƥ������
 @param		IN		nPDLLHandle			SDK���
 @param		IN		szCameraId						����ʶ���豸��ָ��ͨ��ID
 @param		IN		requestFlag						�û��Զ���������ǣ�����������
 @param		IN		nStartTime						����ʱ��Ŀ�ʼ����
 @param		IN		nEndTime						����ʱ��Ľ�������
 @param		IN		szAddress						�����ص�
 @param		IN		nAlarmType						�������ͣ��ڰ�����������
 @param		OUT		count							ƥ������
 @param		OUT		querySession					��ѯ�Ự
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryIvsfAlarmCount(int32_t nPDLLHandle,
															const char* szCameraId, 
															long requestFlag, 
															int64_t nStartTime, 
															int64_t nEndTime, 
															const char* szAddress, 
															uint32_t nAlarmType,
															int* count,
															uint32_t* querySession,
															int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ���ݲ�ѯ����ʶ�𱨾���ȡ����Session����ȡָ�������ƥ������
 @param		IN		nPDLLHandle			SDK���
 @param		IN		szCameraId						    ����ʶ���豸��ָ��ͨ��ID
 @param		IN		nQuerySession						��ѯƥ����Ŀʱ��ȡ����Session
 @param		IN		nStartIndex							��ʼ��������
 @param		IN		nQueryNum							��������
 @param		OUT		dataLength							���ص����ݳ���
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryIvsfAlarmDataLength(int32_t nPDLLHandle,
																 const char* szCameraId, 
																 uint32_t nQuerySession, 
																 uint32_t nStartIndex, 
																 uint32_t nQueryNum,
																 uint32_t* dataLength,
																 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ���ݲ�ѯ����ʶ�𱨾���ȡ����Session����ȡָ�������ƥ������
 @param		IN		nPDLLHandle			SDK���
 @param		IN		szCameraId						    ����ʶ���豸��ָ��ͨ��ID
 @param		IN		nQuerySession						��ѯƥ����Ŀʱ��ȡ����Session
 @param		IN		nStartIndex							��ʼ��������
 @param		IN		nQueryNum							��������
 @param		OUT		personData							���صľ�������
 @param		IN		dataLength							���ص����ݳ���
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryIvsfAlarmData(int32_t nPDLLHandle,
																  const char* szCameraId, 
																  uint32_t nQuerySession, 
																  uint32_t nStartIndex, 
																  uint32_t nQueryNum,
																  char*	personData,
																  uint32_t dataLength,
																  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** �Ͽ�ָ��������ʶ�𱨾���ѯSession
 @param		IN		nPDLLHandle			SDK���
 @param		IN		szCameraId							����ʶ���豸��ָ��ͨ��ID
 @param		IN		nQuerySession						��ѯƥ����Ŀʱ��ȡ����Session
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopIvsfAlarmQuery(int32_t nPDLLHandle,
															const char* szCameraId, 
															uint32_t nQuerySession,
															int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ȡ��������ʶ�𱨾�������ͼƬ����
 @param		IN		nPDLLHandle			SDK���
 @param		IN		szCameraId						����ʶ���豸��ָ��ͨ��ID
 @param		IN		requestFlag						�û��Զ���������ǣ�����������
 @param		IN		data							��������ʶ�𱨾�������ͼƬ��Ϣ
 @param		IN		len								ͼƬ��Ϣ����
 @param		OUT		picFullDataLength				���ݳ���
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetIvsfAlarmPicLength(int32_t nPDLLHandle,
															  const char* szCameraId, 
															  long requestFlag, 
															  const char* data, 
															  uint32_t len,
															  long* picFullDataLength,
															  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ȡ��������ʶ�𱨾�������ͼƬ����
 @param		IN		nPDLLHandle			SDK���
 @param		IN		szCameraId						����ʶ���豸��ָ��ͨ��ID
 @param		IN		requestFlag						�û��Զ���������ǣ�����������
 @param		IN		data							��������ʶ�𱨾�������ͼƬ��Ϣ
 @param		IN		len								ͼƬ��Ϣ����
 @param		OUT		picFullData						���ص�����ͼƬ����(���ͼƬ��������)
 @param		IN		picFullDataLength				���ݳ���
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetIvsfAlarmPic(int32_t nPDLLHandle,
																 const char* szCameraId, 
																 long requestFlag, 
																 const char* data, 
																 uint32_t len,
																 char* picFullData,
																 long picFullDataLength,
																 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ѯRFID������Ϣ.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN    pQuery          ��ѯ��Ϣ
 @param	  		pInfo			RFID������Ϣ 
 @param	  IN	nFirstNum		�ӵڼ�����ʼ��ȡ 
 @param	  IN	nQueryCount		��ȡ���ٸ� 
 @param   IN    pSwLabel		������̽���ǩ
 @param   IN    pElecLabel		���õ��ӱ�ǩ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
 1��֧�ַ�����ȡ
 2���˽ӿ��Ƽ���DPSDK_QueryAlarmCountһ��ʹ��
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryRFIDAlarmInfo( IN int32_t nPDLLHandle, 
																	IN Alarm_Query_Info_t* pQuery, 
																	INOUT Alarm_Info_t* pInfo, 
																	IN int32_t nFirstNum, 
																	IN int32_t nQueryCount,
																	IN const char* pSwLabel = NULL,
																	IN const char* pElecLabel = NULL,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

#endif