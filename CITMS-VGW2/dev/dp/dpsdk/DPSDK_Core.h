#ifndef INCLUDED_DPSDK_CORE_H
#define INCLUDED_DPSDK_CORE_H

#include "DPSDK_Core_Define.h"
#include "DPSDK_Core_Alarm.h"
#include "DPSDK_Core_AlarmBusiness.h"
#include "DPSDK_Core_Bay.h"
#include "DPSDK_Core_FTP.h"
#include "DPSDK_Core_Org.h"
#include "DPSDK_Core_Playback.h"
#include "DPSDK_Core_PTZ.h"
#include "DPSDK_Core_RealStream.h"
#include "DPSDK_Core_Talk.h"
#include "DPSDK_Core_TvWall.h"
#include "DPSDK_Core_Vehicle.h"
#include "DPSDK_Core_PersonCount.h"
#include "DPSDK_Core_Prison.h"
#include "DPSDK_Core_Pec.h"
#include "DPSDK_Core_Call.h"
/***************************************************************************************
 @ �ӿڶ���
***************************************************************************************/

/** ����SDK���.
 @param   IN	nType			SDK����
 @param   OUT	nPDLLHandle		����SDK���������������Ҫ�Դ���Ϊ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark									
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_Create( IN dpsdk_sdk_type_e nType, 
													  OUT int32_t& nPDLLHandle );

/** ɾ��SDK���.
 @param   IN	nPDLLHandle		SDK���
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
	1����Ҫ��DPSDK_Create�ɶ�ʹ��
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_Destroy( IN int32_t nPDLLHandle );

/** ������־.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nLevel			��־�ȼ�
 @param   IN	szFilename		�ļ�����
 @param   IN	bScreen			�Ƿ��������Ļ
 @param   IN	bDebugger		�Ƿ������������
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark									
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetLog( IN int32_t nPDLLHandle, 
													  IN dpsdk_log_level_e nLevel, 
													  IN const char* szFilename, 
													  IN bool bScreen, 
													  IN bool bDebugger );

/** ��ʼ���ӳ�����������������dump�ļ�
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szFilename		�ļ�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark									
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_StartMonitor( IN int32_t nPDLLHandle,  
													        IN const char* szFilename );

/** ����DPSDK����.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	DPSDKParam_t	����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark									
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetParam( int32_t nPDLLHandle, 
													    DPSDKParam_t* pDPSDKParam = NULL );

/** ����ƽ̨��������״̬�ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDKStatusCallback( IN int32_t nPDLLHandle, 
																	  IN fDPSDKStatusCallback fun, 
																	  IN void* pUser );

/** ����DPSDK��֯������Ͻ��������ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKOrgChangeCallback( IN int32_t nPDLLHandle,
																		 IN fDPSDKOrgChangeCallback fun,
																		 IN void* pUser);
/** ��½DSSƽ̨.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	pLoginInfo		�û���¼��Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_Login( IN int32_t nPDLLHandle, 
													 IN Login_Info_t* pLoginInfo, 
													 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �ǳ�DSSƽ̨.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_Logout( IN int32_t nPDLLHandle, 
													  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ����CMS.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ReconnectToCMS( IN int32_t nPDLLHandle, 
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �����û�����.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szOldPsw		ԭ������
 @param   IN	szNewPsw		������
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ChangeUserPassword( IN int32_t nPDLLHandle, 
																 IN const char* szOldPsw,
																 IN const char* szNewPsw, 
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ����JsonЭ��ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetGeneralJsonTransportCallback(IN int32_t nPDLLHandle,
																			  IN fDPSDKGeneralJsonTransportCallback fun,
																			  IN void * pUser);

/** ����JsonЭ��ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetGeneralJsonTransportCallbackEx(IN int32_t nPDLLHandle,
																				IN fDPSDKGeneralJsonTransportCallbackEx fun,
																				IN void * pUser);

/**ͨ��JsonЭ�鷢�������ƽ̨cms/dms��ģ��,���ؽ����json��ͨ��DPSDK_SetGeneralJsonTransportCallback�ص�
@param   IN    nPDLLHandle		SDK���
@param   IN    szJson			Json�ַ���,
@param   IN    mdltype			ģ��,
@param   IN    trantype			JSON ��������,
@param	 IN    nTimeout			��ʱʱ��
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GeneralJsonTransport(IN int32_t nPDLLHandle,
																   IN const char* szJson,
																   IN dpsdk_mdl_type_e mdltype, 
																   IN generaljson_trantype_e trantype,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

//////////////////////////////////////////////////////////////////////////
//�豸��ع���start

/** ����DPSDK�豸����ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDKDeviceChangeCallback( IN int32_t nPDLLHandle, 
																			IN fDPSDKDeviceChangeCallback fun, 
																			IN void* pUser );

/** ����DPSDK����֯�豸����ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKOrgDevChangeNewCallback( IN int32_t nPDLLHandle, 
																			  IN fDPSDKOrgDevChangeNewCallback fun, 
																			  IN void* pUser );

/** ����DPSDK�豸״̬�ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  1)��½ƽ̨��������֯�ṹ�Ժ�ƽ̨�������豸״̬;2)�豸״̬�仯���ٴ�����
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDKDeviceStatusCallback( int32_t nPDLLHandle, 
																			fDPSDKDevStatusCallback fun, 
																			void* pUser );

/** ��ѯNVRͨ��״̬(ֻ�ܲ�ѯ���ߵ�NVR��SMART_NVR��EVS��NVR6000�豸��ͨ��״̬)
@param   IN    nPDLLHandle     SDK���
@param   IN    deviceId	       �豸��ID
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_QueryNVRChnlStatus( IN int32_t nPDLLHandle, 
																 IN const char* deviceId,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ����NVRͨ��״̬�ص�
@param   IN	nPDLLHandle		SDK���
@param   IN	fun				�ص�����
@param   IN	pUser			�û�����
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark ͨ��״̬�仯��ʱ�������
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDKNVRChnlStatusCallback( IN int32_t nPDLLHandle, 
																			 IN fDPSDKNVRChnlStatusCallback fun, 
																			 IN void* pUser );
/** ͨ���豸IP�Ͷ˿��Լ�ͨ���Ż�ȡͨ��ID.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szDevIp			�豸IP
 @param   IN	nPort			�豸port
 @param   IN	nChnlNum		ͨ���ţ���0��ʼ��
 @param   OUT	szCameraId		ͨ������
 @param	  IN	nUnitType		��Ԫ���ͣ�1-���뵥Ԫ��2-��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetCameraIdbyDevInfo( IN int32_t nPDLLHandle,
																	IN const char* szDevIp,
																	IN const int nPort,
																	IN const int nChnlNum,
																	OUT char* szCameraId,
																	IN dpsdk_dev_unit_type_e nUnitType = DPSDK_DEV_UNIT_ENC);
/** ��ȡͨ������
 @param   IN	nPDLLHandle			SDK���
 @param   IN	szCameraId			ͨ��ID
 @param   OUT	pUnitType			ͨ������
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChnlType( IN int32_t nPDLLHandle, 
															IN char *szCameraId,
															OUT dpsdk_dev_unit_type_e* pUnitType);


/** ���ݱ�����ͨ��Id��ȡ������ͨ����Ϣ
@param   IN    nPDLLHandle     SDK���
@param   IN    szCameraId      ͨ��ID
@param   OUT   pChannelInfo    ͨ����Ϣ���μ�Enc_Channel_Info_Ex_t
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChannelInfoById(IN int32_t nPDLLHanle, 
																 IN const char *szCameraId, 
																 OUT Enc_Channel_Info_Ex_t *pChannelInfo);

/** ����ͨ��ID��ȡͨ��״̬����֧��NVRͨ��״̬��ȡ
@param   IN    nPDLLHandle     SDK���
@param   IN    szCameraId      ͨ��ID
@param   OUT   nStatus         ״ֵ̬���μ�dpsdk_dev_status_e
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChannelStatus(IN  int32_t nPDLLHanle, 
															   IN  const char *szCameraId, 
															   OUT dpsdk_dev_status_e &nStatus);

/** ����ͨ��ID��ȡ�豸��������
@param   IN    nPDLLHandle     SDK���
@param   IN    szCameraId      ͨ��ID
@param   OUT    nDeviceFactoryType     �豸����ֵ
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceInfoById(IN  int32_t nPDLLHanle, 
																IN  const char *szCameraId, 
																OUT int32_t& nDeviceFactoryType);

/** �����豸ID��ȡ�豸��Ϣ
@param   IN    nPDLLHandle     SDK���
@param   IN    szDevId		   �豸ID
@param   OUT   pDeviceInfoEx   �豸��Ϣ
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceInfoExById(IN  int32_t nPDLLHanle, 
																  IN  const char *szDevId, 
																  OUT Device_Info_Ex_t* pDeviceInfoEx);

/** �����豸ID��ȡ�豸����
@param   IN    nPDLLHandle     SDK���
@param   IN    szDevId		   �豸ID
@param   OUT   nDeviceType     �豸����
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceTypeByDevId(	IN  int32_t nPDLLHandle, 
																   IN  const char *szDevId, 
																   OUT dpsdk_dev_type_e& nDeviceType);

/** ����ͨ��ID��ȡ�豸ID.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szChanId		ͨ�����
 @param   OUT	szDevId			�豸���
 @return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDevIdByChnId( IN int32_t nPDLLHandle, 
															   IN char* szChanId,
															   OUT char* szDevId);

/** ��ȡ�豸�±���ͨ���ĸ���
 @param   IN	nPDLLHandle			SDK���
 @param   IN	szDeviceId			�豸ID
 @param   OUT	nEncChannelCount	����ͨ������
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetEncChannelCount( IN int32_t nPDLLHandle, 
																	IN const char *szDeviceId,
																	OUT int32_t& nEncChannelCount);
/** ��ȡ�豸�±�����ͨ������Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   INOUT	pGetInfo		��ͨ����Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 1��pEncChannelnfo��Ҫ�����洴����
 2��pEncChannelnfo�Ĵ�С��DPSDK_GetDGroupInfo��ͨ������������Ҫһ��
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChannelInfo( IN int32_t nPDLLHandle, 
															  INOUT Get_Channel_Info_t* pGetInfo );

/** ��ȡ��֯�±�����ͨ������Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   INOUT	pGetInfo		��ͨ����Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 1��pEncChannelnfo��Ҫ�����洴����
 2��pEncChannelnfo�Ĵ�С��DPSDK_GetDGroupInfo��ͨ������������Ҫһ��
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDepChannelInfo( IN int32_t nPDLLHandle, 
															  INOUT Get_Dep_Channel_Info_t* pGetInfo );

/** ��ȡ�豸�±�����ͨ������Ϣ(��չ).
 @param   IN	nPDLLHandle		SDK���
 @param   INOUT	pGetInfo		��ͨ����Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 1��pEncChannelnfo��Ҫ�����洴����
 2��pEncChannelnfo�Ĵ�С��DPSDK_GetDGroupInfo��ͨ������������Ҫһ��
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChannelInfoEx( IN int32_t nPDLLHandle, 
																INOUT Get_Channel_Info_Ex_t* pGetInfo );


/** ��ȡ�豸֧�ֵ���������.
 @param   IN	nPDLLHandle		SDK���
 @param   INOUT	pGetInfo		��ȡ��Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDevStreamType( IN int32_t nPDLLHandle, 
																INOUT Get_Dev_StreamType_Info_t* pGetInfo );

/** ��ȡ�豸�б���Ϣ����.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nGroupLen       �豸�б���Ϣ����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceListLen( IN int32_t nPDLLHandle,
															    OUT int32_t& nDevListLen, 
															    IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ�豸�б���Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	szDevList       �豸�б�xml�ַ���
 @param   IN	nGroupLen       �豸�б���Ϣ����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
     1����Ҫ2�κ������ò������ջ�ȡ�豸�б���Ϣ��
     2����ʹ��DPSDK_GetDeviceListLen����ȡnDevListLen��ֵ��
	 3����ȡ��nDevListLen��ֵ֮�󣬴���һ������Ϊ��nDevListLen+1����char���飬����Ϊ����szDevList���롣
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceListStr( IN int32_t nPDLLHandle,
															    OUT char *szDevList,
															    IN int32_t nDevListLen, 
															    IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ����豸��ϸ��Ϣ����.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szDevicesId     ��Ҫ��ѯ�Ķ���豸ID�ַ�������
 @param   IN	nDevicesCount   �豸ID�ַ�������ĳ���
 @param   OUT   nDevInfoLen     ��Ҫ��ѯ�Ķ���豸��ϸ��Ϣ��ɵ�xml�ַ����ĳ���
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDevicesInfoLen( IN int32_t nPDLLHandle,
															     OUT int32_t& nDevInfoLen );

/** ��ȡ����豸��ϸ��Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	szDevicesInfo   ��Ҫ��ѯ�Ķ���豸��ϸ��Ϣ��ɵ�xml�ַ���
 @param   IN	nDevInfoLen     �豸��ϸ��Ϣ��ɵ�xml�ַ����ĳ���
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
     1����Ҫ2�κ������ò������ջ�ȡ�豸�б���Ϣ��
     2����ʹ��DPSDK_GetDevicesInfoLen��ȡnDevicesCount��ֵ��
	 3����ȡ��nDevicesCount��ֵ֮�󣬴���һ������Ϊ��nDevicesCount+1����char���飬����Ϊ����szDevicesInfo���롣
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDevicesInfoStr( IN int32_t nPDLLHandle,
																 OUT char* szDevicesInfo, 
															     IN int32_t nDevInfoLen );

/** �ӷ�������ȡ�豸��Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szDeviceId		�豸ID
 @param   OUT   pDeviceInfoEx   �豸��Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceInfoFromService( IN int32_t nPDLLHandle, 
																		IN const char* szDeviceId,
																		OUT Device_Info_Ex_t* pDeviceInfoEx, 
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

//�豸��ع���end
//////////////////////////////////////////////////////////////////////////

/** ��ȡ���ӵ�ͼ����������Ϣ
 @param   IN	nPDLLHandle		SDK���
 @param   IN	mapAddrInfo		���ӵ�ͼ����������Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetMapAddrInfo( IN int32_t nPDLLHandle, 
																OUT Config_Emap_Addr_Info_t& mapAddrInfo,
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �������Ա��־
 @param   IN	nPDLLHandle		 SDK���
 @param   IN	szCameraId		 ͨ�����
 @param   IN    optTime			 ����ʱ��
 @param   IN    optType	         ��������
 @param   IN    optDesc		     ��������
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SaveOptLog(  IN int32_t nPDLLHandle,
														   IN const char* szCameraId,
														   IN uint64_t optTime,
														   IN dpsdk_log_optType_e optType,
														   IN const char* optDesc);
/** �ϴ��ļ�
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	stuFileInfo		�ļ���Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SaveRemoteFile( IN int32_t nPDLLHandle, 
															  IN Save_File_Info stuFileInfo,
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �ļ���������ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
	1����Ҫ��DPSDK_Create�ɶ�ʹ��
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetOperatorRemoteFileCallback( IN int32_t nPDLLHandle, 
																			 IN fDPSDKOperatorRemoteFileCallback fun, 
																			 IN void* pUser );

/** �����յ����˷�����Ƶ��Ϣ��Ļص�����
@param   IN    nPDLLHandle     SDK���
@param   IN    fun             �ص�����
@param   IN    pUser           �û�����
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetShareVideoCallback(IN int32_t nPDLLHandle,
																	IN fDPSDKShareVideoCallback fun, 
																	IN void* pUser);

/** ������Ƶ
@param   IN    nPDLLHandle     SDK���
@param   IN    pVideoInfo	   �������Ƶ��Ϣ�ṹ����
@param   IN    nVideoCount	   ��Ƶ��Ϣ����ĳ���
@param   IN    pUserId	       ��������û�ID����
@param   IN    nUserCount	   ������������
@param   IN    szMsg	       ���ӵ���Ϣ
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ShareVideo(IN int32_t nPDLLHanle,
														 IN ShareVideoInfo* pVideoInfo,
														 IN int32_t nVideoCount,
														 IN int32_t* pUserId,
														 IN int32_t nUserCount,
														 IN const char* szMsg,
														 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** ȡ���첽����
@param   IN    nPDLLHandle     SDK���
@param   IN    nSeq     	   Ҫȡ���Ĳ��������ֵ
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CancelOperationBySeq(IN int32_t nPDLLHandle,
																  IN int32_t nSeq);

/** ��ȡ�û�����.�Ժ��й��û�����Ϣ����DPSDK_UserInfo_t��������
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	pstruUserInfo	�û���Ϣ�ṹ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark	
 1����½ƽ̨�Ժ��û���Ϣ�Ѿ���ȡ��
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetUserInfo( IN int32_t nPDLLHandle, 
															OUT DPSDK_UserInfo_t& pstruUserInfo, 
															IN int32_t nTimeout= DPSDK_CORE_DEFAULT_TIMEOUT );


/** ��ȡ�û���֯��Ϣ����
@param  IN		nPDLLHandle     SDK���
@param  OUT		nLen			����
@param	IN		nTimeout		��ʱʱ��
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetUserOrgInfoLen(IN int32_t nPDLLHandle, 
																OUT int32_t* pLen,
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ȡ�û���֯��Ϣ�ַ���
@param  IN		nPDLLHandle     SDK���
@param  OUT		szOrgInfo		�û���֯��Ϣ
@param  IN		nLen			����
@param	IN		nTimeout		��ʱʱ��
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetUserOrgInfo(IN int32_t nPDLLHandle, 
															 OUT char* szUserOrgInfo,
															 IN int32_t nLen,
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** ��ȡ�ղؼ�xml����.
 @param   IN	nPDLLHandle		SDK���
  @param   int	nDepInfoAllLen	�ղؼ���Ϣ
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFavoriteLen(int32_t nPDLLHandle, int& nDepInfoAllLen, int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��ȡ�ղؼ�.
 @param   IN	nPDLLHandle		SDK���
  @param   OUT	szDepInfoAll	�ղؼ���Ϣ
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFavorite(int32_t nPDLLHandle, char* szDepInfoAll, int32_t nLen, int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** �����ղؼ�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szDepInfoAll	�ղؼ���Ϣ
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SaveFavorite(int32_t nPDLLHandle, char* szDepInfoAll, int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** �û����ݱ���ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDataChangeCallback(  int32_t nPDLLHandle, 
																	fDPSDKDataChangeCallback fun, 
																	void* pUser );

/** ��ʼ¼�񲢷���ƽ̨��ʼʱ��
@param   IN    nPDLLHandle     SDK���
@param   IN    szCameraId      ͨ��ID
@param   OUT   startTime       ƽ̨��ʼ¼��ʱ��
@param   IN    streamType      ��������
@param   IN    nTimeout        ��ʱʱ��
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRecordWithTimeRet(IN int32_t nPDLLHandle,
																	 IN  const char *szCameraId, 
																	 OUT long& startTime,
																	 IN dpsdk_stream_type_e streamType = DPSDK_CORE_STREAMTYPE_MAIN,
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ����¼�񲢷���ƽ̨����ʱ��
@param   IN    nPDLLHandle     SDK���
@param   IN    szCameraId      ͨ��ID
@param   OUT   startTime       ƽ̨����¼��ʱ��
@param   IN    nTimeout        ��ʱʱ��
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopRecordWithTimeRet(IN int32_t nPDLLHandle,
																	IN  const char *szCameraId, 
																	OUT long& stopTime,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ͨ�����غŲ�ѯͨ��ID�б�
@param   IN    nPDLLHandle     SDK���
@param   IN    nSiteCode       ���غ�
@param   OUT   nChnlIdCount    ͨ��ID����
@param   IN    nTimeout        ��ʱʱ��
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryChnlIdBySiteCode(IN int32_t nPDLLHandle,
																	IN int32_t nSiteCode,
																	OUT int32_t& nChnlIdCount,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ͨ�����غŻ�ȡͨ��ID�б�
@param   IN    nPDLLHandle     SDK���
@param   IN    nSiteCode       ���غ�
@param   OUT   pChnlIdInfo     ͨ����Ϣ
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
  1�������Ȳ�ѯ���ȡ
  2��DPSDK_QueryChnlIdBySiteCode�᷵��ͨ��ID����
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChnlIdBySiteCode(IN int32_t nPDLLHandle,
																  IN int32_t nSiteCode,
																  OUT ChnlIdBySiteCode_Info_t* pChnlIdInfo);


/** ��ѯ�����б������������ӣ����ü�����֯�ṹҲ���Կ�����̨�����ձ����������豸״̬�ϱ���
@param   IN    nPDLLHandle     SDK���
@return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryServerList(int32_t nPDLLHandle);


/** ȫ��Уʱ����
@param   IN    nPDLLHandle     SDK���
@param   IN    bOpen		   ���ر�־��ture����false��
@return  �������ش������ͣ��ο�dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetSyncTimeOpen(int32_t nPDLLHandle, bool bOpen);


/** ��ѯ����ǽ�б����.
 @param	  IN	nPDLLHandle		SDK���
 @param	  OUT	nCount			���ظ���
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryTvWallList( IN int32_t nPDLLHandle, 
															   OUT uint32_t& nCount, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ѯ����ǽ������Ϣ
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	nTvWallId		����ǽID
 @param	  OUT	nCount			���ظ���
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryTvWallLayout( IN int32_t nPDLLHandle, 
																 IN int32_t nTvWallId, 
																 OUT uint32_t& nCount, 
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**ͨ��JsonЭ�鷢�������cms.(ʹ��ͨ��json�ӿںͻص��ӿ�)
@param   IN    nPDLLHandle		SDK���
@param   IN    szJson			Json�ַ���,
����:"{ \"DevID\": \"1000000\",\"CameraId\":\"1000000$1$0$1\", \"DevChannel\": 1,\"PicNum\": 1,\"CourtTime\": \"2014-09-17 16:00:00\"}"
@param   OUT   szJsonResult		ƽ̨���ص�Json�ַ���,
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendCammandToCMSByJson(IN int32_t nPDLLHandle,
																	 IN const char* szJson, 
																	 OUT char* szJsonResult,
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**ͨ��JsonЭ�鷢�������DMS.(ʹ��ͨ��json�ӿںͻص��ӿ�)
@param   IN    nPDLLHandle		SDK���
@param   IN    szJson			Json�ַ���,
����:"{ \"DevID\": \"1000000\",\"CameraId\":\"1000000$1$0$1\", \"DevChannel\": 1,\"PicNum\": 1,\"CourtTime\": \"2014-09-17 16:00:00\"}"
@param   IN    szDeviceId		�豸ID,
@param   OUT   szJsonResult		ƽ̨���ص�Json�ַ���,
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendCammandToDMSByJson(IN int32_t nPDLLHandle,
																	 IN const char* szJson,
																	 IN const char* szDeviceId,
																	 OUT char* szJsonResult,
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �����¼��ϱ��ص������ض������ƣ�.
 @param   IN    nPDLLHandle     SDK���
 @param   IN    fun             �ص�����
 @param   IN    pUser           �û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKIssueCallback(IN int32_t nPDLLHandle,
																	IN fDPSDKIssueCallback fun, 
																	IN void* pUser);
/** ��ȡ�û�Id (��ȡ�û���Ϣ������id).
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nUserId			�û�Id
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetUserID( IN int32_t nPDLLHandle, 
														 OUT uint32_t& nUserId );
/** ��ȡ�û��ȼ�(��ȡ�û���Ϣ�����˵ȼ�).
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nUserLevel		�û��ȼ�
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetUserLevel( IN int32_t nPDLLHandle, 
															OUT uint32_t& nUserLevel );

/** ��ȡ���ź�Ͻ����ϵ��¼��.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT    nCount         ��¼��Ŀ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeptAreaRelationCount( IN int32_t nPDLLHandle, 
																		OUT int32_t& nCount,
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);
/** ��ȡ���ź�Ͻ����ϵ��¼.
 @param   IN	nPDLLHandle		SDK���
 @param   INOUT pGetInfo        ��ȡ����Ͻ����ϵ������Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetAllDeptAreaRelation( IN int32_t nPDLLHandle, 
																	  INOUT Get_DeptArea_Relation_t* pGetInfo);

/** ����������Ա��Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   INOUT	nPersonCount	������Ա��Ŀ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_LoadAllPersonInfo( IN int32_t nPDLLHandle, 
																 OUT int32_t& nPersonCount,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);
/** ��ȡ�ض����ŵ�������Ա��.
 @param   IN	nPDLLHandle	   SDK���
 @param   IN szDeptCode        ���ű��
 @param   IN nPersonCount      ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetPersonCountByDept( IN int32_t nPDLLHandle, 
																	IN char* szDeptCode,
																	OUT int32_t& nPersonCount);
/** ��ȡ���ŵ�������Ա��Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   INOUT pGetInfo        ��Ա��Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetPersonInfoByDept( IN int32_t nPDLLHandle, 
															       INOUT Get_Person_Info_t * pGetInfo);
/** ����DPSDK��Ա����ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKPersonChangeCallback( IN int32_t nPDLLHandle,
																			IN fDPSDKPersonChangeCallback fun,
																			IN void* pUser);
/** ����DPSDK������ϵ����ص�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKRelationChangeCallback( IN int32_t nPDLLHandle,
																			  IN fDPSDKRelationChangeCallback fun,
																			  IN void* pUser);

/** ��ȡƽ̨��ǰʱ��
 @param   IN    nPDLLHandle		SDK���
 @param   OUT	lCurTime		ƽ̨��ǰʱ��
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetCurrentPlatformTime( IN int32_t nPDLLHandle, 
																	 OUT long& lCurTime, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ������Ŀ������Ƶ���ż�Ȩ
 @param   IN    nPDLLHandle		SDK���
 @param   IN	szIP			����ƽ̨IP
 @param	  IN	nPort			����ƽ̨�˿�
 @param   IN	szDvrCode		Ӳ��¼�������
 @param   IN	szToken			��������
 @param   OUT	bSuccess		��Ȩ���
 @param   OUT	szErrMsg		������Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CheckRealPlayAuth( IN int32_t nPDLLHandle,
																 IN const char* szIP,
																 IN int nPort,
																 IN const char* szDvrCode,
																 IN const char* szToken,
																 OUT bool& bSuccess,
																 OUT char* szErrMsg,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ������ĿԤԼ��ʷ��Ƶ���ż�Ȩ
 @param   IN    nPDLLHandle		SDK���
 @param   IN	szIP			����ƽ̨IP
 @param	  IN	nPort			����ƽ̨�˿�
 @param   IN	szFileId		��ʷ��ƵID
 @param   IN	szToken			��������
 @param   OUT	bSuccess		��Ȩ���
 @param   OUT	szErrMsg		������Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CheckPlaybackAuth( IN int32_t nPDLLHandle,
																 IN const char* szIP,
																 IN int nPort,
																 IN const char* szFileId,
																 IN const char* szToken,
																 OUT bool& bSuccess,
																 OUT char* szErrMsg,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ����д��־�ӿ�.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nLog			��־����
 @param   IN	ntype			��־����dpsdk_log_type_e
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_WriteDPSDKLog(int32_t nPDLLHandle,const char* nLog, int32_t ntype = 0);

/**	����ҩ�����Ŀ������ͨ�����ƻ�ȡͨ��ID
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szChnlName		ͨ������
 @param   OUT	szChnlID		ͨ��ID
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  ��Ҫƽ̨��û���ظ���ͨ�����ƣ�������ظ��ĸýӿ�ֻ�᷵�ص�һ��ƥ���ͨ��ID�����ô˽ӿ�ǰ��Ҫ�ȼ�����֯�ṹ
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChnlIDByChnlName( IN int32_t nPDLLHandle,
																   IN const char* szChnlName,
																   OUT char* szChnlID );

//////////////////////////////////////////////////////////////////////////
//���½ӿ�Ϊ�����ӿڣ���Ϊ���ּ����ԣ���Ȼ�����ӿ�
//remove interface begin
//���Ͻӿ�Ϊ�����ӿڣ���Ϊ���ּ����ԣ���Ȼ�����ӿ�
//remove interface end
#endif
