// license:BSD-3-Clause
// copyright-holders:R. Belmont

#ifndef MAME_BUS_HPDIO_98544_H
#define MAME_BUS_HPDIO_98544_H

#pragma once

#include "hp_dio.h"
#include "video/topcat.h"
//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

// ======================> dio16_98544_device

class dio16_98544_device :
	public device_t,
	public device_dio16_card_interface,
	public device_memory_interface
{
public:
	// construction/destruction
	dio16_98544_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	DECLARE_READ16_MEMBER(rom_r);
	DECLARE_WRITE16_MEMBER(rom_w);

	required_device<topcat_device> m_topcat;
	uint32_t screen_update(screen_device &screen, bitmap_rgb32 &bitmap, const rectangle &cliprect);
 protected:
	dio16_98544_device(const machine_config &mconfig, device_type type, const char *tag, device_t *owner, uint32_t clock);

	// device-level overrides
	virtual void device_start() override;
	virtual void device_reset() override;

	// optional information overrides
	virtual void device_add_mconfig(machine_config &config) override;
	virtual const tiny_rom_entry *device_rom_region() const override;
	virtual space_config_vector memory_space_config() const override;
private:

	static constexpr int m_v_pix = 768;
	static constexpr int m_h_pix = 1024;

	const address_space_config m_space_config;
	void map(address_map &map);

	required_region_ptr<uint8_t> m_rom;
	required_shared_ptr<uint8_t> m_vram;
};

// device type definition
DECLARE_DEVICE_TYPE(HPDIO_98544, dio16_98544_device)

#endif // MAME_BUS_HPDIO_98544_H
