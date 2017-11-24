#include "DHStreamAccessPlugin.h"
#include "ConfigBox.h"

using namespace ScheduleServer;

// ----------------------------------------------------------------------
// ������: CDHStreamAccessPlugin::CDHStreamAccessPlugin
// ����: fuym
// ����: ���캯��
// ����: 
//   [void] 
// ----------------------------------------------------------------------
CDHStreamAccessPlugin::CDHStreamAccessPlugin(void) :
    _dhconnect_ptr(NULL)
{
}

// ----------------------------------------------------------------------
// ������: CDHStreamAccessPlugin::~CDHStreamAccessPlugin
// ����: fuym
// ����: ��������
// ����: 
//   [void] 
// ----------------------------------------------------------------------
CDHStreamAccessPlugin::~CDHStreamAccessPlugin(void)
{
    if (_dhconnect_ptr)
    {
        delete _dhconnect_ptr;
        _dhconnect_ptr = NULL;
    }
}

// ----------------------------------------------------------------------
// ������: CDHStreamAccessPlugin::config
// ����: fuym
// ����: �������
// ����ֵ: 
//   [void] 
// ����: 
//   [void] 
// ----------------------------------------------------------------------
void CDHStreamAccessPlugin::config(void)
{
	// ���ز�������ļ�
    //CConfigBox config_box;
    //config_box.load(cfg_file);

    // ��ȡ���������Ϣ
    _dhplugin_config.real_type = Plugin::DHDVR::default_real_type;//config_box.get_property_as_int("real.type", Plugin::DHDVR::default_real_type);
    _dhplugin_config.wait_time = Plugin::DHDVR::default_wait_time;//config_box.get_property_as_int("wait.time", Plugin::DHDVR::default_wait_time);
    if (_dhconnect_ptr)
    {
        _dhconnect_ptr->config(_dhplugin_config);
    }
}

// ----------------------------------------------------------------------
// ������: CDHStreamAccessPlugin::init
// ����: fuym
// ����: ���ģ���ʼ��
// ����ֵ: 
//   [void] 
// ����: 
//   [void] 
// ----------------------------------------------------------------------
void CDHStreamAccessPlugin::init(void)
{
	// �����Ϣ����
	//get_module_info().name = Plugin::DHDVR::module_name;
	//get_module_info().version = Plugin::DHDVR::module_version;

    config();
}

// ----------------------------------------------------------------------
// ������: CDHStreamAccessPlugin::uninit
// ����: fuym
// ����: ���ģ��ж��
// ����ֵ: 
//   [void] 
// ����: 
//   [void] 
// ----------------------------------------------------------------------
void CDHStreamAccessPlugin::uninit(void)
{
    //cout << "Enter CDHStreamAccessPlugin::uninit()" << endl;

    // ������ݰ��ص�����ָ��
    //set_packet_callback_ptr(NULL);

    if (_dhconnect_ptr)
    {
        _dhconnect_ptr->uninit();
    }

    //cout << "Leave CDHStreamAccessPlugin::uninit()" << endl;
}

// ----------------------------------------------------------------------
// ������: CDHStreamAccessPlugin::get_device_type
// ����: fuym
// ����: ����豸����
// ����ֵ: 
//   [DEVICE_TYPE] 
// ����: 
//   [void] 
// ----------------------------------------------------------------------
DEVICE_TYPE CDHStreamAccessPlugin::get_device_type(void)
{
    return DHCAMERATYPE;
}

// ----------------------------------------------------------------------
// ������: CDHStreamAccessPlugin::access_stream
// ����: fuym
// ����: ý����봦��
// ����ֵ: 
//   [RETCODE] 
// ����: 
//   [const REQUEST_INFO& request_info] ����ý�����������Ϣ
//   [const CHAR * in_data_ptr] ��������
//   [ULONG in_data_length] �������ݳ���
//   [CHAR * out_data_ptr] �������
//   [ULONG& out_data_length] ������ݳ���
// ----------------------------------------------------------------------
RETCODE CDHStreamAccessPlugin::access_stream(const REQUEST_INFO& request_info, 
                      const CHAR * in_data_ptr,
                      ULONG in_data_length,
                      CHAR * out_data_ptr,
                      ULONG& out_data_length)
{
    //if (!is_active()) return RETCODE_FAIL;

    if (!_dhconnect_ptr)
    {
        _dhconnect_ptr = new CDHVideoServerConnect();//(IPacketCallbackPtr)this);
        _dhconnect_ptr->config(_dhplugin_config);
    }

    if (REAL_START == request_info.operation) // ʵʱ��Ƶ��������
    {
        return _dhconnect_ptr->connect(request_info);
    }
    else if (REAL_STOP == request_info.operation) // �Ͽ�ʵʱ��Ƶ����
    {
        return _dhconnect_ptr->disconnect(request_info);
    }
    else if (REAL_FASTUPDATE == request_info.operation) // ǿ��I֡����
    {
        return _dhconnect_ptr->fast_update(request_info);
    }
    else
    {
        // Do nothing.
    }

    return RETCODE_REQUEST_NOT_IMPLEMENT;
}
