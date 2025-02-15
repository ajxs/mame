// license:BSD-3-Clause
// copyright-holders:Wilbert Pol
/**********************************************************************

   MSX Digital Joystick emulation

**********************************************************************/

#include "emu.h"
#include "joystick.h"


DEFINE_DEVICE_TYPE(MSX_JOYSTICK, msx_joystick_device, "msx_joystick", "MSX Digital Joystick")


static INPUT_PORTS_START(msx_joystick)
	PORT_START("JOY")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP) PORT_8WAY
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN) PORT_8WAY
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT) PORT_8WAY
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT) PORT_8WAY
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_BUTTON1)
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_BUTTON2)
	PORT_BIT(0xc0, IP_ACTIVE_LOW, IPT_UNUSED)
INPUT_PORTS_END

ioport_constructor msx_joystick_device::device_input_ports() const
{
	return INPUT_PORTS_NAME(msx_joystick);
}

msx_joystick_device::msx_joystick_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock)
	: device_t(mconfig, MSX_JOYSTICK, tag, owner, clock)
	, device_msx_general_purpose_port_interface(mconfig, *this)
	, m_joy(*this, "JOY")
{
}

u8 msx_joystick_device::read()
{
	return m_joy->read();
}
