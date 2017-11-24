#ifndef INCLUDED_DPSDK_CORE_CALL_H
#define INCLUDED_DPSDK_CORE_CALL_H

//////////////////////////////////////////////////////////////////////////
// ��Ⱥ�Խ�ҵ��ӿ� ��ʼ

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetStartCallParamCallback(int32_t nPDLLHandle,  
																		fStartCallParamCallBack pFun, 
																		void* pUser);

/** �򿪺���
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nCallSeq		�����������,����Ϊ����������ʶ
 @param   IN	nCallType		�������� 0������1�鲥��2���ӶԽ�
 @param   IN	szGroupId		������ID
 @param   IN    pFun			�����ص�����				
 @param   IN    pUser			�����ص��û�����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartCall(int32_t nPDLLHandle, 
														int32_t& nCallSeq, 
														dpsdk_call_type_e nCallType,
														const char* szGroupId,
														fMediaDataCallback pFun, 
														void* pUser, 
														int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** �رպ���
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nCallSeq		�����������,����Ϊ����������ʶ
 @param   IN	szGroupId		��ID
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopCall(int32_t nPDLLHandle, 
													   int32_t nCallSeq, 
													   const char* szGroupId,
													   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** ���ú�����������ص�
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
	1����Ҫ��DPSDK_Create�ɶ�ʹ��
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetInviteCallParamCallBack(int32_t nPDLLHandle,  
																		 fInviteCallParamCallBack pFun, 
																		 void* pUser);

/** ��������
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nCallSeq		�����������,����Ϊ����������ʶ
 @param   IN	pGetInfo		����������Ϣ 
 @param   IN    pFun			�����ص�����				
 @param   IN    pUser			�����ص��û�����
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_InviteCall(int32_t nPDLLHandle, 
														 int32_t& nCallSeq, 
														 Get_InviteCall_Info_t* pGetInfo, 
														 fMediaDataCallback pFun, 
														 void* pUser, 
														 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** ���б��Ҷϣ��ͷ�����
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nCallSeq		�����������,����Ϊ����������ʶ 
 @param   IN	szGroupId		������ID
 @param   IN	nTid			T ID
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ByeCall(int32_t nPDLLHandle, 
													  int32_t nCallSeq, 
													  const char* szGroupId,
													  int32_t nTid,
													  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** �������״̬
 @param   IN	nPDLLHandle		SDK���
 @param   IN	nCallSeq		�����������,����Ϊ����������ʶ 
 @param   IN	szGroupId		������ID
 @param   IN	nCallStatus		����״̬
 @param   IN	nTimeout		��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ModifyCallStatus(	int32_t nPDLLHandle, 
																int32_t nCallSeq, 
																const char* szGroupId,
																dpsdk_call_status_e nCallStatus,
																int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** ��ȡ�������ͺ���ָ��
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	pCallBackFun	�ص�����
 @param   OUT	pUserParam   	�ص������û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetAudioSendFunCallBack(	int32_t nPDLLHandle,
																		void** pCallBackFun,
																		AudioUserParam_t** pUserParam);

/** ������Ϣ��scs����
 @param		IN		nPDLLHandle			SDK���
 @param		IN		szGroupId			������ID
 @param		IN		szStrText			���͵��ı�����
 @param		IN		nTimeout			��ʱʱ��
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @sample
	DPSDK_SendScsMsg(m_nPDLLHandle, "test", "test", DPSDK_CORE_DEFAULT_TIMEOUT);
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendScsMsg(IN int32_t nPDLLHandle,
														 IN const char* szGroupId, 
														 IN const char* szStrText,
														 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** ��ȡ����IP
 @param   IN	nPDLLHandle		SDK���
 @param   OUT	nLocalIP		����IP
 @param   IN	nLen   			IP�ĳ��ȣ�IP����󳤶�46
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetLocalIp(int32_t nPDLLHandle,
														 char* nLocalIP,
														 int32_t nLen);

//��Ⱥ�Խ�ҵ��ӿ� ����


//���ӶԽ�ҵ��ӿ� ��ʼ

/** ���ÿ��ӶԽ�������������ص�
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetVtCallInviteCallback(int32_t nPDLLHandle,
																	  fDPSDKInviteVtCallParamCallBack pFun,
																	  void* pUser);

/** �����������֪ͨ�ص�
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetRingCallback(int32_t nPDLLHandle,
															  fDPSDKRingInfoCallBack pFun,
															  void* pUser);

/** ���ÿ��ӶԽ���æ״̬֪ͨ�ص�
 @param   IN	nPDLLHandle		SDK���
 @param   IN	fun				�ص�����
 @param   IN	pUser			�û�����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetBusyVtCallCallback(int32_t nPDLLHandle,
																	fDPSDKBusyVtCallCallBack pFun,
																	void* pUser);


/** ������ӶԽ�
 @param   IN	nPDLLHandle			SDK���
 @param   OUT	audioSessionId		��Ƶ�������,���ڹرնԽ�
 @param   OUT	videoSessionId		��Ƶ�������,���ڹرնԽ�
 @param   OUT	nStartVtCallParm	Ӧ����������ڱ���ƵƵ�ɼ��͹رնԽ�
 @param   IN	nCallType			�������� 0������1�鲥��2���ӶԽ�
 @param   IN	szUserId			������ID
 @param   IN    pFun				�����ص�����				
 @param   IN    pCBParam			�����ص��û�����
 @param   IN	nTimeout			��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartVtCall(int32_t nPDLLHandle, 
														  uint32_t &audioSessionId, 
														  uint32_t &videoSessionId, 
														  StartVtCallParam_t * nStartVtCallParm, 
														  dpsdk_call_type_e nCallType, 
														  const char* szUserId, 
														  fMediaDataCallback funCB, 
														  void* pCBParam, 
														  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** ����ȡ�����ӶԽ�
 @param   IN	nPDLLHandle			SDK���
 @param   IN	szUserId			������ID
 @param   IN	audioSessionId		�����������к�
 @param   IN	videoSessionId		��Ƶ�������к�
 @param   IN    nCallId				����ID			
 @param   IN    m_dlgId				�ػ�ID
 @param   IN	nTimeout			��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendCancelVtCall(int32_t nPDLLHandle,
															   const char* szUserId,
															   uint32_t audioSessionId,
															   uint32_t videoSessionId,
															   int callId,
															   int dlgId,
															   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ������ӶԽ��ɹ���ֹͣ���ӶԽ�
 @param   IN	nPDLLHandle			SDK���
 @param   IN	szUserId			������ID
 @param   IN	audioSessionId		�����������к�
 @param   IN	videoSessionId		��Ƶ�������к�
 @param   IN    nCallId				����ID			
 @param   IN    m_dlgId				�ػ�ID
 @param   IN	nTimeout			��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopVtCall(int32_t nPDLLHandle,
														 const char* szUserId,
														 uint32_t audioSessionId,
														 uint32_t videoSessionId,
														 int m_callId = 0,
														 int m_dlgId = 0,
														 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ���ܿ��ӶԽ�����
 @param   IN	nPDLLHandle			SDK���
 @param   OUT	audioSessionId		��Ƶ�������,���ڹرնԽ�
 @param   OUT	videoSessionId		��Ƶ�������,���ڹرնԽ�
 @param   IN	nInviteVtCallParam	�Խ���������DPSDK_SetVtCallInviteCallback��ȡ
 @param   IN	nCallType			�������� 0������1�鲥��2���ӶԽ�
 @param   IN    pFun				�����ص�����				
 @param   IN    pCBParam			�����ص��û�����
 @param   IN	nTimeout			��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_InviteVtCall(int32_t nPDLLHandle,
														   uint32_t &audioSessionId,
														   uint32_t &videoSessionId,
														   InviteVtCallParam_t* nInviteVtCallParam,
														   dpsdk_call_type_e nCallType,
														   fMediaDataCallback funCB,
														   void* pCBParam,
														   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ��������󣬹ҶϿ��ӶԽ�
 @param   IN	nPDLLHandle			SDK���
 @param   IN	szUserId			������ID
 @param   IN	audioSessionId		�����������к�
 @param   IN	videoSessionId		��Ƶ�������к�
 @param   IN    nTid				
 @param   IN	nTimeout			��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ByeVtCall(int32_t nPDLLHandle,
														const char* szUserId,
														uint32_t audioSessionId,
														uint32_t videoSessionId,
														int nTid,
														int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** �ܾ����ӶԽ�����
 @param   IN	nPDLLHandle			SDK���
 @param   IN	szUserId			������ID
 @param   IN    nCallId				����ID				
 @param   IN    nTid				
 @param   IN	nTimeout			��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendRejectVtCall(int32_t nPDLLHandle,
															   const char* szUserId,
															   int nCallId,
															   int dlgId,
															   int nTid,
															   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** ����ӶԽ�����json����
 @param   IN	nPDLLHandle			SDK���
 @param   IN	nSendjson			����json
 @param   OUT   nRecivejson			Ӧ��json								
 @param   IN	nTimeout			��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_sendVtCallInfo(int32_t nPDLLHandle,
															 const char* nSendjson,
															 char* nRecivejson,
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** �޸Ŀ��ӶԽ�״̬
 @param   IN	nPDLLHandle			SDK���
 @param   IN	szUserId			������ID
 @param   IN	nCallStatus			����״̬
 @param   IN	audioSessionId		�����������к�
 @param   IN	videoSessionId		��Ƶ�������к�		
 @param   IN	nTimeout			��ʱʱ������λ����
 @return  �������ش������ͣ��ο�dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ModifyVtCallStatus(int32_t nPDLLHandle,
																 const char* szUserId,
																 dpsdk_call_status_e nCallStatus,
																 uint32_t audioSessionId,
																 uint32_t videoSessionId,
																 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

///** ��ȡ�������ͺ���ָ��
// @param   IN	nPDLLHandle		SDK���
// @param   OUT	AudioSendFun	�������ͺ���ָ�룬�μ�fAudioDataCallback
// @param   OUT	pUserParam   	�ص������û�����
// @return  �������ش������ͣ��ο�dpsdk_retval_e
// @remark		
//*/
//DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetVtCallAudioSendFunCallBack(int32_t nPDLLHandle,
//																			void* &AudioSendFun,
//																			AudioUserParam_t* &pUserParam);

//���ӶԽ�ҵ��ӿ� ��ʼ

#endif