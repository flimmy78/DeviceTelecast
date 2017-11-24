/**
 * Copyright (c) 2012, �㽭��
 * All rights reserved.
 *
 * �ļ����ƣ�DPSDK_Core_Prison.h
 * �ļ���ʶ��
 * ժ����Ҫ��������ģ�� �ӿ��ļ� 
 *
 * ��ǰ�汾��1.0
 * ԭ���ߡ���whg
 * ������ڣ�2015��9��18��
 * �޶���¼������
*/

#ifndef INCLUDED_DPSDK_CORE_PRISON_H
#define INCLUDED_DPSDK_CORE_PRISON_H


//////////////////////////////////////////////////////////////////////////
// ������ģ��ӿ� ��ʼ


/** ��ȡ��¼ʵʱ״̬��Ϣ.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pDevBurnerCDStateRequest			������Ϣ
 @param	  OUT	pDevBurnerCDStateResponse			�ظ���Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDevBurnerCDState(int32_t nPDLLHandle, 
																Dev_Burner_CDState_Request_t* pDevBurnerCDStateRequest, 
																Dev_Burner_CDState_Reponse_t* pDevBurnerCDStateResponse,
																int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��¼����.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pDevBurnerCDStateRequest			������Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ControlDevBurner(int32_t nPDLLHandle, 
																Control_Dev_Burner_Request_t* pControlDevBurnerRequest, 
																int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��¼Ƭͷ����.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pInfoHeader		Ƭͷ��Ϣ
 @param	  IN	pAttrName		��Ѷ��������
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDevBurnerHeader( int32_t nPDLLHandle,
																  DevBurnerInfoHeader_t* pInfoHeader, 
																  TrialFormAttrName_t* pAttrName,
																  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ȡ�豸������Ϣ����
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szDevId			�豸ID
 @param   INOUT	pInfoCount		������Ϣ����
 @param   INOUT pSequence		�첽˳����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceDiskInfoCount( int32_t nPDLLHandle,
																	  const char* szDevId,
																	  int32_t& nInfoCount,
																	  int32_t& nSequence,
																	  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ȡ�豸������Ϣ
 @param   IN	nPDLLHandle		SDK���
 @param   IN    nSequence		�첽˳����
 @param   INOUT	pDiskInfo		������Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  ��Ҫ�ȵ���DPSDK_GetDeviceDiskInfoCount��ȡ������Ϣ������pDiskInfo��������������Ӧ�ڴ�
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceDiskInfo( int32_t nPDLLHandle,
																 int32_t nSequence,
																 Device_Disk_Info_t* pDiskInfo);
// ������ģ��ӿ� ����
//////////////////////////////////////////////////////////////////////////


#endif
