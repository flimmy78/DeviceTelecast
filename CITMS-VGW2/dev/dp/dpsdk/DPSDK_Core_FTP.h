#ifndef INCLUDED_DPSDK_CORE_FTP_H
#define INCLUDED_DPSDK_CORE_FTP_H

/** ����ʱ��β�ѯFTPͼƬ��Ϣ
 @param   IN    nPDLLHandle     SDK���
 @param   IN    szCameraId      ͨ�����
 @param   IN    nBeginTime      ��ʼʱ��
 @param   IN    nEndTime		����ʱ��
 @param   IN    nTimeout        ��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryFtpPic(IN int32_t nPDLLHandle,
															IN const char *szCameraId, 
															IN uint64_t nBeginTime,
															IN uint64_t nEndTime,
															IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** ��ȡFtpͼƬ��Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	ftpPicInfo		FtpͼƬ��Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
   1�������Ȳ�ѯ���ȡ
   2��DPSDK_QueryFtpPic�᷵�ؼ�¼����,
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFtpPicInfo( IN int32_t nPDLLHandle, 
															 OUT Ftp_Pic_Info_t &ftpPicInfo );

/** ɾ��FTPͼƬ��Ϣ
 @param   IN    nPDLLHandle     SDK���
 @param   IN    szFtpPicPath	FtpͼƬ·��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DelFtpPic(IN int32_t nPDLLHandle,
														IN const char *szFtpPicPath);

/** ͼƬ�ϴ���Ftp
@param    IN    nPDLLHandle    SDK���
@param    IN    szCameraId     ��ͼ��Դ���Ǹ�CameraId
@param    IN    nCaptureTime   ��ͼ��ʱ��
@param    IN    szLocalFile    ����ͼƬ��ȫ·��
@param    IN    szFtpAddr      ftp�ĵ�ַ����ʽ��"ftp://172.7.2.249"
@param    IN    szName         ftp�ĵ�½��
@param    IN    szPwd          ftp�ĵ�½����
@return   �������ش������ͣ��ο�dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_UploadFtpPic(IN int32_t nPDLLHandle, 
														   IN const char* szCameraId, 
														   IN uint64_t nCaptureTime, 
														   IN const char* szLocalFile, 
														   IN const char* szFtpAddr, 
														   IN const char* szName, 
														   IN const char* szPwd,  
														   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ����Ftp�ļ�
@param   IN    nPDLLHandle     SDK���
@param   IN    szLocalFile	   Ҫ�ϴ������غ�ı����ļ�����
@param   IN    szFtpFile	   Ҫ������FtpĿ¼�ϵ��ļ�����·������ftp:��ͷ��
@param   IN    szName	       ��½Ftp���û���
@param   IN    szPwd	       ��½Ftp������
@param   IN    opType	       �������ͣ������ϴ������أ�ɾ����
@return  �������ش������ͣ��ο�dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OperatorFtpFile(IN int32_t nPDLLHandle,
															  IN const char* szLocalFile,
															  IN const char* szFtpFile,
															  IN const char* szName,
															  IN const char* szPwd,
															  IN dpsdk_operator_ftp_type_e opType,
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


#endif