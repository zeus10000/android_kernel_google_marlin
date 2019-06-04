/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2004-2006 Atmel Corporation
 */
#ifndef __MACB_PDATA_H__
#define __MACB_PDATA_H__

/**
 * struct macb_platform_data - platform data for MACB Ethernet
 * @phy_mask:		phy mask passed when register the MDIO bus
 *			within the driver
 * @phy_irq_pin:	PHY IRQ
 * @is_rmii:		using RMII interface?
 * @rev_eth_addr:	reverse Ethernet address byte order
 */
struct macb_platform_data {
	u32		phy_mask;
	int		phy_irq_pin;
	u8		is_rmii;
	u8		rev_eth_addr;
};

#endif /* __MACB_PDATA_H__ */
