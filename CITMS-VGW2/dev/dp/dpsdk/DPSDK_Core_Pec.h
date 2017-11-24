/**
 * Copyright (c) 2012, �㽭��
 * All rights reserved.
 *
 * �ļ����ƣ�DPSDK_Core_Pec.h
 * �ļ���ʶ��
 * ժ����Ҫ��PECģ�� �ӿ��ļ� 
 *
 * ��ǰ�汾��1.0
 * ԭ���ߡ���whg
 * ������ڣ�2015��10��13��
 * �޶���¼������
*/

#ifndef INCLUDED_DPSDK_CORE_PEC_H
#define INCLUDED_DPSDK_CORE_PEC_H


/** �����Ž�����״̬�ϱ��ص�
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPecDoorStatusCallback(int32_t nPDLLHandle,
																	   fDPSDKPecDoorStarusCallBack pFun,
																	   void* pUser);


/** �ſ���.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pRequest		������Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDoorCmd(int32_t nPDLLHandle, 
														SetDoorCmd_Request_t* pRequest, 
														int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ����Ƶ��Դ.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	pResponce		����Ƶ��ԴXML
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryLinkResource( int32_t nPDLLHandle,
															     uint32_t* nLen, 
																 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ȡ����Ƶ��Դ.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	pResponce		����Ƶ��ԴXML
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetLinkResource( int32_t nPDLLHandle,
															   GetLinkResource_Responce_t* pResponce );

#endif
