#ifndef _PACKET_H_      
#define _PACKET_H_ 

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "Config.h"

// ���ݰ�ʶ�����ֽ�������
#define INDENTITY_SIZE 4

// ý�����ݰ�����غɴ�С����
#define MAX_PAYLOAD_SIZE 20000                            

namespace ScheduleServer
{
    const CHAR IDENTITY[INDENTITY_SIZE] = {'s', 'Y', 'n', 'C'};     // ���ݰ�ʶ���붨��
    
    // ý�����ݰ�������Ϣ�ṹ����
    typedef struct  
    {
        CHAR identity[INDENTITY_SIZE];                              // ���ݰ�ʶ����(4�ֽ�)
        USHORT payload_block_size;                                  // �������ݰ���С(2�ֽڣ����65535)
        USHORT source_uuid;                                         // ý��Դ��ʶ(2�ֽڣ����65535)
        USHORT payload_origin_size;                                 // �������ݰ�ԭʼ���ݿ��С(2�ֽڣ����65535)
        BYTE payload_block_id: 4;                                   // ������ݰ����(���16)
        BYTE payload_block_count: 4;                                // ������ݰ���Ŀ(���16)   
        BYTE data_type: 6;                                          // ��������(���64) 
        BYTE iframe: 1;                                             // I֡��־(0/1) 
        BYTE mark: 1;                                               // ���ݱ��(0/1, Ԥ��ĳЩ�豸SDKʹ��)
        UINT sequence;                                              // ���ݰ����к�(4�ֽ�)
        UINT64 time_stamp;                                          // ʱ��(���뼶)(8�ֽ�)
    } PACKET_INFO, *PACKET_INFO_PTR;

    // ý�����ݰ��ṹ����
    typedef struct 
    {
        PACKET_INFO info;                                           // ������Ϣ
        CHAR payload[MAX_PAYLOAD_SIZE];                             // ������            
    } PACKET_DATA, *PACKET_DATA_PTR;

    // ���ݰ��������Ͷ���
    typedef std::list<PACKET_DATA> PACKET_DATA_LIST;
    typedef std::deque<PACKET_DATA_PTR> PACKET_DATA_PTR_QUEUE;

    // ��ʼ�����ݰ�������Ϣ
    inline void init_packet_info(PACKET_INFO& packet_info)
    {
        ::memset(&packet_info, 0, sizeof(PACKET_INFO));

        packet_info.identity[0] = IDENTITY[0];
        packet_info.identity[1] = IDENTITY[1];
        packet_info.identity[2] = IDENTITY[2];
        packet_info.identity[3] = IDENTITY[3];

        packet_info.source_uuid = (USHORT)INVALID_SOURCE_UUID;
        packet_info.payload_block_count = 1;
    };

    // �ж����ݰ�������Ϣ��ʽ�Ƿ���ȷ
    inline BOOL is_packet_legal(const PACKET_INFO& packet_info)
    {
        // �Ƚ����ݰ���ʶ
        for (INT i=0; i<INDENTITY_SIZE; i++)
        {
            if (packet_info.identity[i] != IDENTITY[i]) return FALSE;
        }

        // ������ݰ�����ֵ
        if (packet_info.payload_block_size > MAX_PAYLOAD_SIZE) return FALSE;

        return TRUE;
    }
}

#endif  // _PACKET_H_       
