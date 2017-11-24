#ifndef INCLUDED_DPSDK_CORE_PLAYBACK_H
#define INCLUDED_DPSDK_CORE_PLAYBACK_H

/** ����ƽ̨¼��
@param   IN    nPDLLHandle     SDK���
@param   IN    szCameraId      ͨ��ID
@param   IN    streamType      ʵʱ��������
@param   IN    nTimeout        ��ʱʱ������λ����
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlatformReocrd(IN int32_t nPDLLHandle,
																  IN const char *szCameraId,
																  IN dpsdk_encdev_stream_e streamType = DPSDK_CORE_STREAM_MAIN,
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ֹͣƽ̨¼��
@param   IN    nPDLLHandle     SDK���
@param   IN    szCameraId      ͨ��ID
@param   IN    nTimeout        ��ʱʱ������λ����
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/ 
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopPlatformReocrd(IN int32_t nPDLLHandle,
																 IN const char *szCameraId,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** ��ѯ¼��.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	pQueryInfo		��ѯ��Ϣ
 @param   OUT	nRecordCount	¼���¼����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
   1��nRecordCount���5000����¼
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryRecord( IN int32_t nPDLLHandle, 
														   IN Query_Record_Info_t* pQueryInfo, 
														   OUT int32_t& nRecordCount, 
														   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ͨ���������Ͳ�ѯ¼��.
 @param   IN	nPDLLHandle				SDK���
 @param   IN	pQueryInfo				��ѯ��Ϣ
 @param   IN	nStreamType				��������
 @param   OUT	nRecordCount			¼���¼����
 @param   IN	nTimeout				��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
   1��nRecordCount���5000����¼
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryRecordByStreamType( IN int32_t nPDLLHandle, 
																		IN Query_Record_Info_t* pQueryInfo, 
																		IN dpsdk_stream_type_e nStreamType,
																		OUT int32_t& nRecordCount, 
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ¼����Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	pRecords		¼����Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
   1�������Ȳ�ѯ���ȡ
   2��DPSDK_QueryRecord�᷵�ؼ�¼����,
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRecordInfo( IN int32_t nPDLLHandle, 
															 INOUT Record_Info_t* pRecords );

/** ���ļ�����¼����.
 @param	  IN	nPDLLHandle		SDK���
 @param   OUT	nPlaybackSeq	�ط��������,��Ϊ����������ʶ  
 @param	  IN	pRecordInfo		¼����Ϣ 
 @param   IN    pFun			�����ص�����				
 @param   IN    pUser			�����ص��û�����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRecordStreamByFile( IN int32_t nPDLLHandle, 
																	 OUT int32_t& nPlaybackSeq, 
																	 IN Get_RecordStream_File_Info_t* pRecordInfo, 
																	 IN fMediaDataCallback pFun, 
																	 IN void* pUser, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ʱ������¼����.
 @param	  IN	nPDLLHandle		SDK���
 @param   OUT	nPlaybackSeq	�ط��������,��Ϊ����������ʶ  
 @param	  IN	pRecordInfo		¼����Ϣ 
 @param   IN    pFun			�����ص�����				
 @param   IN    pUser			�����ص��û�����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRecordStreamByTime( IN int32_t nPDLLHandle, 
																	 OUT int32_t& nPlaybackSeq, 
																	 IN Get_RecordStream_Time_Info_t* pRecordInfo, 
																	 IN fMediaDataCallback pFun, 
																	 IN void* pUser, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �����������Ͱ�ʱ������¼����.
 @param	  IN	nPDLLHandle		SDK���
 @param   OUT	nPlaybackSeq	�ط��������,��Ϊ����������ʶ  
 @param	  IN	pRecordInfo		¼����Ϣ
 @param   IN	nStreamType		��������
 @param   IN    pFun			�����ص�����				
 @param   IN    pUser			�����ص��û�����
 @param   IN	nTimeout		��ʱʱ������λ����
 @param   IN	nTransMode		����ģʽ��1:TCP 0:UDP
 @param   IN	bBack			�Ƿ񵹷�
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRecordStreamByStreamType( IN int32_t nPDLLHandle, 
																			OUT int32_t& nPlaybackSeq, 
																			IN Get_RecordStream_Time_Info_t* pRecordInfo,
									 										IN dpsdk_stream_type_e nStreamType,
																			IN fMediaDataCallback pFun, 
																			IN void* pUser, 
																			IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT,
																			IN int32_t nTransMode = 1,
																			IN bool bBack = false);

/** ��ͣ¼����.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PauseRecordStreamBySeq( IN int32_t nPDLLHandle, 
																	  IN int32_t nPlaybackSeq, 
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �ָ�¼����.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ResumeRecordStreamBySeq( IN int32_t nPDLLHandle, 
																	   IN int32_t nPlaybackSeq, 
																	   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ����¼��������.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN    nSpeed,         ¼�����ط��ٶ�
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetRecordStreamSpeed( IN int32_t nPDLLHandle, 
																	IN int32_t nPlaybackSeq, 
																	IN dpsdk_playback_speed_e nSpeed, 
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��λ�ط�.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN    seekBegin,		��λ��ʼֵ.�ļ�ģʽʱ,�Ƕ�λ�����ļ���Сֵ;ʱ��ģʽʱ,�Ƕ�λ����ʱ��ֵ;
 @param   IN    seekEnd,		��λ����ֵ.�ļ�ģʽʱ,������;ʱ��ģʽʱ,���ڴ��Ľ���ʱ��.
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark 
			seekBegin���ļ�ģʽ�µļ��㷽ʽ������:(�ļ���Сֵ)/100*(��λ������ļ��İٷֱ�)  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SeekRecordStreamBySeq(IN int32_t nPDLLHandle, 
																	IN int32_t nPlaybackSeq, 
																	IN uint64_t seekBegin, 
																	IN uint64_t seekEnd, 
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �ر�¼����.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseRecordStreamBySeq( IN int32_t nPDLLHandle, 
																	  IN int32_t nPlaybackSeq, 
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �ر�¼��ͬ���ȴ�����Ӧ��.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	nPlaybackSeq	�ط�������� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SynchroCloseRecordStreamBySeq( IN int32_t nPDLLHandle, 
																			  IN int32_t nPlaybackSeq, 
																			  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ͨ���ر�¼����.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	szCameraId   	ͨ����� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseRecordStreamByCameraId( IN int32_t nPDLLHandle, 
																		   IN const char* szCameraId, 
																		   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ͨ���ر�¼������ͬ���ȴ�����Ӧ��.
 @param	  IN	nPDLLHandle		SDK���
 @param   IN	szCameraId   	ͨ����� 
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SynchroCloseRecordStreamByCameraId( IN int32_t nPDLLHandle, 
																				IN const char* szCameraId, 
																				IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );



/** �ֶ������豸¼��
 @param	  IN	nPDLLHandle		SDK���
 @param const char* szDevId							�豸ID
 @param const char* szSN							    ��������
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartDeviceRecord( IN int32_t nPDLLHandle, 
																		  const char* szDevId, const char* szSN,
																		   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �ֶ�ֹͣ�豸¼��
 @param	  IN	nPDLLHandle		SDK���
 @param const char* szDevId							�豸ID
 @param const char* szSN							    ��������
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopDeviceRecord( IN int32_t nPDLLHandle, 
																		  const char* szDevId, const char* szSN,
																		   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ������Ŀ���ƣ�������ʷ��Ƶ�ļ�ID��ѯ¼����Ϣ
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szFileId		��ʷ��Ƶ�ļ�ID
 @param   OUT	szCameraId		����ͷID
 @param   OUT	begTime			��ʼʱ��
 @param   OUT	endTime			����ʱ��
 @param   OUT	szFilePath		��ʷ��Ƶ�ļ�·��
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryRecordByFileId( IN int32_t nPDLLHandle, 
																   IN const char* szFileId,
																   OUT char* szCameraId,
																   OUT uint64_t& begTime,
																   OUT uint64_t& endTime,
																   OUT char* szFilePath,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);
#endif


