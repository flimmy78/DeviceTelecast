#ifndef INCLUDED_DPSDK_ORG_H
#define INCLUDED_DPSDK_ORG_H

/** ������֯�豸��Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nGroupLen       ��֯�ṹ��Ϣ����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_LoadDGroupInfo( IN int32_t nPDLLHandle, 
															  OUT int32_t& nGroupLen, 
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** ��ȡ��֯������֯�����豸�ĸ���.
 @param   IN	nPDLLHandle		SDK���
 @param   INOUT	pGetInfo		��ȡ��֯����������Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDGroupCount( IN int32_t nPDLLHandle, 
															  INOUT Get_Dep_Count_Info_t* pGetInfo );
/** ��ȡ��֯������֯�����豸����Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   INOUT	pGetInfo		����֯���豸��Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 1��pDepInfo��pDeviceInfo��Ҫ�����洴����
 2��pDepInfo��pDeviceInfo�Ĵ�С��DPSDK_GetDGroupCount������Ҫһ��
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDGroupInfo( IN int32_t nPDLLHandle, 
															 INOUT Get_Dep_Info_t* pGetInfo );

/** ��ȡ��֯������֯�����豸����ͨ������Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   INOUT	pGetInfo		����֯���豸ͨ����Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 1��pDepInfo��pDeviceInfo��Ҫ�����洴����
 2��pDepInfo��pDeviceInfo�Ĵ�С��DPSDK_GetDGroupCount������Ҫһ��
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDGroupInfoEx( IN int32_t nPDLLHandle, 
															 INOUT Get_Dep_Info_Ex_t* pGetInfo );

/** ���û�����֯���ļ�·��.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	szFilePath		�ļ�·��,androidĬ��Ϊ"/sdcard"
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 1��szFilePath androidĬ��Ϊ"/sdcard"
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetSaveGroupFilePath( IN int32_t nPDLLHandle, 
																	IN const char* szFilePath );

/** �첽������֯�豸��Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	pFun            ������ɺ���ô˻ص�����
 @param   IN    pUserParam      �ش���pFun�еĲ���
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
          DPSDK_AsyncLoadDGroupInfo�ڼ�����֯�󣬻��������أ����߳��еȴ�������ɣ���ɺ���ûص�pFun.
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AsyncLoadDGroupInfo( IN int32_t nPDLLHandle, 
															  IN fAsyncLoadDGroupInfoCallback pFun,
															  IN void* pUserParam,
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** �첽������֯�豸��Ϣ�������ز������к�
 @param   IN	nPDLLHandle		SDK���
 @param   IN    nGroupSeq       �������к�
 @param   IN	pFun            ������ɺ���ô˻ص�����
 @param   IN    pUserParam      �ش���pFun�еĲ���
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark.
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AsyncLoadDGroupInfoWithSeq( IN int32_t nPDLLHandle,
																  OUT int32_t& nGroupSeq,
																  IN fAsyncLoadDGroupInfoCallback pFun,
																  IN void* pUserParam,
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ��֯�ṹʱ�������Ƿ����ѹ����ʽ��ȡ.
 @param   IN	nPDLLHandle			SDK���
 @param   IN	nCompressType		�Ƿ����ѹ����ʽ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark									
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetCompressType( IN int32_t nPDLLHandle, 
																IN dpsdk_get_devinfo_compress_type_e nCompressType);


/** �ּ�������֯�豸��Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   IN	pGetInfo		�ּ���ȡ�Ľڵ���Ϣ 
 @param   OUT	nGroupLen       ��֯�ṹ��Ϣ����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_LoadDGroupInfoLayered( IN int32_t nPDLLHandle, 
																	 IN Load_Dep_Info_t* pGetInfo, 
																	 OUT int32_t& nGroupLen, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ��֯�豸��Ϣ��.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	szGroupBuf		��֯�ṹ����,��Ҫ�ⲿ�������棬��СΪnGroupLen+1
 @param   IN	nGroupLen       ��֯�ṹ��Ϣ����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 1��szGroupBuf��Ҫ�����洴����
 2��szGroupBuf�Ĵ�С��nGroupLen��Ҫһ�»��ߴ���nGroupLen
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDGroupStr( IN int32_t nPDLLHandle, 
															OUT char* szGroupBuf, 
															IN int32_t nGroupLen, 
															IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ�ּ����ص���֯�豸��Ϣ��.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	szGroupBuf		��֯�ṹ����,��Ҫ�ⲿ�������棬��СΪnGroupLen+1
 @param   IN	nGroupLen       ��֯�ṹ��Ϣ����
 @param   IN	szCoding		�ڵ�code
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
 1��szGroupBuf��Ҫ�����洴����
 2��szGroupBuf�Ĵ�С��nGroupLen��Ҫһ�»��ߴ���nGroupLen
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDGroupLayeredStr( IN int32_t nPDLLHandle, 
																   OUT char* szGroupBuf, 
																   IN int32_t nGroupLen,
																   IN const char* szCoding, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ���ڵ���Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	pGetInfo		���ڵ���Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDGroupRootInfo(IN int32_t nPDLLHandle,
																OUT Dep_Info_t* pGetInfo );
/** �����ض�������֯��Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   IN    type            ͨ�ýڵ�����
 @param   OUT	nOrgCount       ������֯��Ϣ������
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_LoadOrgInfoByType( IN int32_t nPDLLHandle, 
																 IN dpsdk_org_node_e type,
																 OUT int32_t& nOrgCount,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ��֯������֯����.
 @param   IN	nPDLLHandle		SDK���
 @param   IN    type            �ڵ�����
 @param   INOUT	pGetInfo        ��ȡ��֯����������Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetOrgCountByType( IN int32_t nPDLLHandle, 
																 IN dpsdk_org_node_e type,
																 INOUT Get_Org_Count_Info_t* pGetInfo );

/** ��ȡ��֯������֯�����豸����Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   IN    type            ��֯����
 @param   INOUT	pGetInfo       ��ȡ��֯������Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetOrgInfoByType( IN int32_t nPDLLHandle, 
																IN dpsdk_org_node_e type,
																INOUT Get_Org_Info_t* pGetInfo);

//////////////////////////////////////////////////////////////////////////
//�߼���֯��start

/** �Ƿ���ҵ����
 @param   IN	nPDLLHandle		SDK���
 @return  ��������true��ʾ����ҵ�����������ʾû��ҵ����
 @remark
*/
DPSDK_DLL_API bool DPSDK_CALL_METHOD DPSDK_HasLogicOrg(IN int32_t nPDLLHandle);

/** ��ȡҵ�������ڵ���Ϣ.
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	pDepInfoEx		ҵ�������ڵ���Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetLogicRootDepInfo(IN int32_t nPDLLHandle,
																OUT Dep_Info_Ex_t* pDepInfoEx );

/** ��ȡҵ����ָ���ڵ��� �ڵ�/ͨ��/�豸����Ŀ
 @param   IN	nPDLLHandle						SDK���
 @param   IN    szDepCoding						�ڵ�Coding
 @param   IN    nNodeType						��֯/ͨ��/�豸
 @param   OUT   pnDepNodeNum					�ڵ��� �ڵ�/ͨ��/�豸����Ŀ
 @return  �������ش������ͣ��ο�dpsdk_retval_e 
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetLogicDepNodeNum(IN int32_t nPDLLHandle,
																  IN char* szDepCoding, 
																  IN dpsdk_node_type_e nNodeType, 
																  OUT int32_t* pnDepNodeNum);

/** ��ȡҵ����ָ���ڵ��� �ڵ���Ϣ
 @param   IN	nPDLLHandle						SDK���
 @param   IN    szDepCoding						�ڵ�Coding
 @param   IN    nIndex							���
 @param   OUT   pDepInfoEx						��֯�ڵ���Ϣ
 @return  �������ش������ͣ��ο�dpsdk_retval_e 
 @remark    
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetLogicSubDepInfoByIndex(IN int32_t nPDLLHandle, 
																		IN char* szDepCoding, 
																		IN int32_t nIndex, 
																		OUT Dep_Info_Ex_t* pDepInfoEx);

/** ��ȡҵ����ָ���ڵ��� �豸����ͨ��ID
 @param   IN	nPDLLHandle						SDK���
 @param   IN    szDepCoding						�ڵ�Coding
 @param   IN    nIndex							���
 @param   IN	bChnl							=true Ϊͨ�����������豸
 @param   OUT	szCodeID						�ڵ�ID
 @return  �������ش������ͣ��ο�dpsdk_retval_e 
 @remark     
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetLogicID(IN int32_t nPDLLHandle, 
														  IN char* szDepCoding, 
														  IN int nIndex, 
														  IN bool bChnl, 
														  OUT char* szCodeID);


//�߼���֯��end

#endif