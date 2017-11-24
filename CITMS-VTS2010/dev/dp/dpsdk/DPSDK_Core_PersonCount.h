#ifndef INCLUDED_DPSDK_CORE_PERSONCOUNT_H
#define INCLUDED_DPSDK_CORE_PERSONCOUNT_H


/** ��ѯͳ������.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szCameraId		ͨ��ID
 @param   OUT	nQuerySeq		�����������,����Ϊ����������ʶ 
 @param   OUT	totalCount		ͳ������
 @param   IN	nStartTime		��ʼʱ�� 
 @param   IN    nEndTime		����ʱ��				
 @param   IN    nGranularity	��ѯ���ȣ�0:����,1:Сʱ,2:��,3:��,4:��,5:��,6:��;
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryPersonCount(int32_t nPDLLHandle, 
															   const char* szCameraId, 
															   uint32_t& nQuerySeq, 
															   uint32_t& totalCount,
															   uint32_t nStartTime, 
															   uint32_t nEndTime, 
															   int nGranularity,
															   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ҳ��ѯͳ�ƽ��.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szCameraId		ͨ��ID
 @param   IN	nQuerySeq		�����������,����Ϊ����������ʶ 
 @param   IN	nIndex			�˴β�ѯ�Ŀ�ʼֵ
 @param   IN    nCount			�˴β�ѯ������		
 @param   OUT	nPersonInfo		��ϸ������ͳ����Ϣ��newһ��nCount��С������
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryPersonCountBypage(int32_t nPDLLHandle, 
																	 const char* szCameraId, 
																	 uint32_t nQuerySeq, 
																	 uint32_t nIndex, 
																	 uint32_t nCount, 
																	 Person_Count_Info_t* nPersonInfo,
																	 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ������ѯ.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szCameraId		ͨ��ID
 @param   IN	nQuerySeq		�����������,����Ϊ����������ʶ 			
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopQueryPersonCount(int32_t nPDLLHandle, 
																   const char* szCameraId, 
																   uint32_t nQuerySeq,
																   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

#endif