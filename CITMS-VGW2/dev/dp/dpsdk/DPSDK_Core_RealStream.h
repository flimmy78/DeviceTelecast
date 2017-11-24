#ifndef INCLUDED_DPSDK_CORE_REALSTREM_H
#define INCLUDED_DPSDK_CORE_REALSTREM_H

//#include "DPSDK_Core_Define.h"

/** ��ȡʵ������.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nRealSeq		�����������,����Ϊ����������ʶ 
 @param   IN	pGetInfo		����������Ϣ 
 @param   IN    pFun			�����ص�����				
 @param   IN    pUser			�����ص��û�����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRealStream( IN int32_t nPDLLHandle, 
															 OUT int32_t& nRealSeq, 
															 IN Get_RealStream_Info_t* pGetInfo, 
															 IN fMediaDataCallback pFun, 
															 IN void* pUser, 
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

#ifndef LINUX
/** ��ȡʵ��������ת��Ϊָ�������ٻص�
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nRealSeq		�����������,����Ϊ����������ʶ 
 @param   IN	pGetInfo		����������Ϣ
 @param   IN    scType          ����ת����Ŀ������
 @param   IN    pFun			�����ص�����				
 @param   IN    pUser			�����ص��û�����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRealStreamEx( IN int32_t nPDLLHandle, 
															   OUT int32_t& nRealSeq, 
															   IN Get_RealStream_Info_t* pGetInfo,
															   IN dpsdk_stream_convertor_type_e scType,
															   IN fMediaDataCallback pFun, 
															   IN void* pUser, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
#endif


/** ��������Źر�����.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nRealSeq		�����������
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseRealStreamBySeq( IN int32_t nPDLLHandle, 
																	IN int32_t nRealSeq, 
																    IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ��ͨ���໭��ƴ��ʵʱ����.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nRealSeq		�����������,����Ϊ����������ʶ 
 @param   IN	pGetInfo		����������Ϣ 
 @param   IN    pFun			�����ص�����				
 @param   IN    pUser			�����ص��û�����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRealStreamPreview( int32_t nPDLLHandle,
																   int& nRealSeq, 
																   Get_RealStream_Info_t* pGetInfo,
																   int32_t nStartChannelIndex, 
																   fMediaDataCallback pFun, 
																   void* pUser, 
																   int nTimeout );

 /** ��ȡʵʱ����URL
 @param   IN	nPDLLHandle				SDK���
 @param   INOUT	pRealStreamUrlInfo		��ѯʵʱ��Url��Ϣ
 @param   IN	nTimeout				��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRealStreamUrl( IN int32_t nPDLLHandle, 
																INOUT Get_RealStreamUrl_Info_t* pRealStreamUrlInfo, 
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡDSSƽ̨�����ý����URL
 @param   IN	nPDLLHandle						SDK���
 @param   INOUT	pExternalRealStreamUrlInfo		��ѯʵʱ��Url��Ϣ
 @param   IN	nTimeout						��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetExternalRealStreamUrl( IN int32_t nPDLLHandle, 
 																		 INOUT Get_ExternalRealStreamUrl_Info_t* pExternalRealStreamUrlInfo, 
 																		 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetIvsRuleSzLen(int32_t nPDLLHandle,
														 const char* szCameraId, 
														 int32_t nRealSeq,
														 int32_t* pSzLen,
														 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetIvsRule(int32_t nPDLLHandle,
														 const char* szCameraId, 
														 int32_t nRealSeq,
														 char*   szIvsRule,
														 int32_t iSzLen,
														 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);



#endif