#include "DPStreamAccessPlugin.h"
#include "ConfigBox.h"

using namespace ScheduleServer;

// ----------------------------------------------------------------------
// ������: CDPStreamAccessPlugin::CDPStreamAccessPlugin
// ����: fuym
// ����: ���캯��
// ����: 
//   [void] 
// ----------------------------------------------------------------------
CDPStreamAccessPlugin::CDPStreamAccessPlugin(void) :
    _dpconnect_ptr(NULL)
{
}

// ----------------------------------------------------------------------
// ������: CDPStreamAccessPlugin::~CDPStreamAccessPlugin
// ����: fuym
// ����: ��������
// ����: 
//   [void] 
// ----------------------------------------------------------------------
CDPStreamAccessPlugin::~CDPStreamAccessPlugin(void)
{
    if (_dpconnect_ptr)
    {
        delete _dpconnect_ptr;
        _dpconnect_ptr = NULL;
    }
}

// ----------------------------------------------------------------------
// ������: CDPStreamAccessPlugin::config
// ����: fuym
// ����: �������
// ����ֵ: 
//   [void] 
// ����: 
//   [void] 
// ----------------------------------------------------------------------
void CDPStreamAccessPlugin::config(void)
{
	// ���ز�������ļ�
    //CConfigBox config_box;
    //config_box.load(cfg_file);

    // ��ȡ���������Ϣ
    _dpplugin_config.real_type = Plugin::DPNVR::default_real_type;//config_box.get_property_as_int("real.type", Plugin::DPNVR::default_real_type);
    _dpplugin_config.wait_time = Plugin::DPNVR::default_wait_time;//config_box.get_property_as_int("wait.time", Plugin::DPNVR::default_wait_time);
    if (_dpconnect_ptr)
    {
        _dpconnect_ptr->config(_dpplugin_config);
    }
}

// ----------------------------------------------------------------------
// ������: CDPStreamAccessPlugin::init
// ����: fuym
// ����: ���ģ���ʼ��
// ����ֵ: 
//   [void] 
// ����: 
//   [void] 
// ----------------------------------------------------------------------
void CDPStreamAccessPlugin::init(void)
{
	// �����Ϣ����
	//get_module_info().name = Plugin::DPNVR::module_name;
	//get_module_info().version = Plugin::DPNVR::module_version;

    config();
}

// ----------------------------------------------------------------------
// ������: CDPStreamAccessPlugin::uninit
// ����: fuym
// ����: ���ģ��ж��
// ����ֵ: 
//   [void] 
// ����: 
//   [void] 
// ----------------------------------------------------------------------
void CDPStreamAccessPlugin::uninit(void)
{
    //cout << "Enter CDPStreamAccessPlugin::uninit()" << endl;

    // ������ݰ��ص�����ָ��
    //set_packet_callback_ptr(NULL);

    if (_dpconnect_ptr)
    {
        _dpconnect_ptr->uninit();
    }

    //cout << "Leave CDPStreamAccessPlugin::uninit()" << endl;
}

// ----------------------------------------------------------------------
// ������: CDPStreamAccessPlugin::get_device_type
// ����: fuym
// ����: ����豸����
// ����ֵ: 
//   [DEVICE_TYPE] 
// ����: 
//   [void] 
// ----------------------------------------------------------------------
DEVICE_TYPE CDPStreamAccessPlugin::get_device_type(void)
{
    return DHCAMERATYPE;
}

// ----------------------------------------------------------------------
// ������: CDPStreamAccessPlugin::access_stream
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
RETCODE CDPStreamAccessPlugin::access_stream(const REQUEST_INFO& request_info, 
                      const CHAR * in_data_ptr,
                      ULONG in_data_length,
                      CHAR * out_data_ptr,
                      ULONG& out_data_length)
{
    //if (!is_active()) return RETCODE_FAIL;

    if (!_dpconnect_ptr)
    {
        _dpconnect_ptr = new CDPVideoServerConnect();//(IPacketCallbackPtr)this);
        _dpconnect_ptr->config(_dpplugin_config);
    }

    if (REAL_START == request_info.operation) // ʵʱ��Ƶ��������
    {
        return _dpconnect_ptr->connect(request_info);
    }
    else if (REAL_STOP == request_info.operation) // �Ͽ�ʵʱ��Ƶ����
    {
        return _dpconnect_ptr->disconnect(request_info);
    }
    else if (REAL_FASTUPDATE == request_info.operation) // ǿ��I֡����
    {
        return _dpconnect_ptr->fast_update(request_info);
    }
    else
    {
        // Do nothing.
    }

    return RETCODE_REQUEST_NOT_IMPLEMENT;
}
