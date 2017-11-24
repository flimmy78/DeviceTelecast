#ifndef INCLUDED_DPSDK_CORE_TVWALL_H
#define INCLUDED_DPSDK_CORE_TVWALL_H



//////////////////////////////////////////////////////////////////////////
// ����ǽҵ��ӿ� ��ʼ

/** ��ѯ����ǽ�б����.
 @param	  IN	nPDLLHandle		SDK���
 @param	  OUT	nCount			���ظ���
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTvWallListCount(int32_t nPDLLHandle, 
															   uint32_t* nCount, 
															   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ����ǽ�б���Ϣ.
 @param	  IN	nPDLLHandle		SDK���
 @param	  INOUT	pInfo			����ǽ�б���Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTvWallList( IN int32_t nPDLLHandle, 
															 INOUT TvWall_List_Info_t* pTvWallListInfo );

/** ��ѯ����ǽ������Ϣ
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	nTvWallId		����ǽID
 @param	  OUT	nCount			���ظ���
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTvWallLayoutCount(int32_t nPDLLHandle, 
																 int32_t nTvWallId, 
																 uint32_t* nCount, 
																 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ����ǽ������Ϣ.
 @param	  IN	nPDLLHandle		SDK���
 @param	  INOUT	pInfo			����ǽ������Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTvWallLayout( IN int32_t nPDLLHandle, 
															   INOUT TvWall_Layout_Info_t* pTvWallLayoutInfo );


/** ��ȡOSD��Ϣģ����Ϣ.
 @param	  IN	nPDLLHandle		SDK���
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @param   IN	nTimeout		��ʱʱ������λ����
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetOSDTemplatInfo( IN int32_t nPDLLHandle, 
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �޸�OSD��Ϣģ����Ϣ.
 @param	  IN	nPDLLHandle		SDK���
 @param    IN Ope_OSD_Templat_Info_t     ������Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @param   IN	nTimeout		��ʱʱ������λ����
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OperateOSDTemplatInfo(IN int32_t nPDLLHandle,
																	IN Ope_OSD_Templat_Info_t* pOpeInfo,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ��ѯOSD��ʷ��Ϣ.
 @param	  IN	nPDLLHandle		SDK���
 @param    IN Search_History_OSDInfo_t     ��ѯ��Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @param   IN	nTimeout		��ʱʱ������λ����
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SearchHistoryOSDInfo(IN int32_t nPDLLHandle,
																   IN Search_History_OSDInfo_t* pOpeInfo,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ����OSD��Ϣ.
 @param	  IN	nPDLLHandle		SDK���
 @param    IN Send_OSDInfo_t     osd��Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @param   IN	nTimeout		��ʱʱ������λ����
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendOSDInfo(IN int32_t nPDLLHandle,
																   IN Send_OSDInfo_t* pOpeInfo,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ����SMS��Ϣ.
 @param	  IN	nPDLLHandle		SDK���
 @param    IN Send_SMS_Info_t     sms��Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @param   IN	nTimeout		��ʱʱ������λ����
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendSMSInfo(IN int32_t nPDLLHandle,
																   IN Send_SMS_Info_t* pOpeInfo,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ���л���������
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pPipTvWallInfo		���л�����
 @param   IN	nScreenId		��ID
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPipTvWallScreen( IN int32_t nPDLLHandle, 
																   IN Pip_TvWall_Screen_Info_t* pPipTvWallInfo,
																   IN int32_t nScreenId,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ���ָ�.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pSplitInfo		����ǽ���ָ���Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetTvWallScreenSplit( IN int32_t nPDLLHandle, 
																	IN TvWall_Screen_Split_t* pSplitInfo,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ������.
 @param	  IN	nPDLLHandle		SDK���
 @param	  INOUT	pOpenWindowInfo		����ǽ��������Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_TvWallScreenOpenWindow( IN int32_t nPDLLHandle, 
																	  INOUT TvWall_Screen_Open_Window_t* pOpenWindowInfo,
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �����ƶ�.
 @param	  IN	nPDLLHandle		SDK���
 @param	  INOUT	pMoveWindowInfo		����ǽ�������ƶ���Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_TvWallScreenMoveWindow( IN int32_t nPDLLHandle, 
																	  INOUT TvWall_Screen_Move_Window_t* pMoveWindowInfo,
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ���ش�.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pCloseWindowInfo		����ǽ���ش���Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_TvWallScreenColseWindow( IN int32_t nPDLLHandle, 
																	   IN TvWall_Screen_Close_Window_t* pCloseWindowInfo,
																	   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �������ö������ڿ�����Ч��.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pTopWindowInfo		����ǽ�������ö���Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_TvWallScreenSetTopWindow( IN int32_t nPDLLHandle, 
																     	IN TvWall_Screen_Set_Top_Window_t* pTopWindowInfo,
																     	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ������������ƵԴ.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pWindowSourceInfo		����ǽ��������ƵԴ��Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetTvWallScreenWindowSource( IN int32_t nPDLLHandle, 
															        	   IN Set_TvWall_Screen_Window_Source_t* pWindowSourceInfo,
																           IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �ر���������ƵԴ.
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	pCloseSourceInfo		����ǽ�����ڹر���ƵԴ��Ϣ
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseTvWallScreenWindowSource( IN int32_t nPDLLHandle, 
																	         IN TvWall_Screen_Close_Source_t* pCloseSourceInfo,
																	         IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��յ���ǽ��  
 @param   �˽ӿڴ������⣬������ǽ�󶨶��������idʱ��ֻ�����һ��������id��������ʹ�ýӿ�DPSDK_ClearTvWallScreenByDecodeId
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	nTvWallId		����ǽID
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ClearTvWallScreen( IN int32_t nPDLLHandle, 
																 IN int32_t nTvWallId,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ���ݽ�����ID��յ���ǽ��
 @param	  IN	nPDLLHandle		SDK���
 @param	  IN	nTvWallId		����ǽID
 @param	  IN	szDecodeId		������ID
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ClearTvWallScreenByDecodeId(int32_t nPDLLHandle, 
																int32_t nTvWallId,
																const char* szDecodeId,
																int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

// ����ǽҵ��ӿ� ����
//////////////////////////////////////////////////////////////////////////


#endif