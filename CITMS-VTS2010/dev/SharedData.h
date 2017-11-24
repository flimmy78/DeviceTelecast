#ifndef _SHARED_DATA_H_
#define _SHARED_DATA_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "Packet.h"

#define SHARE_BUFFER_SIZE 10000

namespace ScheduleServer
{
    // ���ݰ������������ڴ�ṹ����
    typedef struct  
    {
        INT read_item;                                      // ��ȡ���ݰ�λ��
        INT write_item;                                     // д�����ݰ�λ��    
        PACKET_DATA packet_data_list[SHARE_BUFFER_SIZE];    // ���ݰ�������
    } SHARED_DATA;
}

#endif // _SHARED_DATA_H_