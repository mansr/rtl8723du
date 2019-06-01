/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright(c) 2016 - 2017 Realtek Corporation */

#ifndef __HALBTC_WIFIONLY_H__
#define __HALBTC_WIFIONLY_H__

#include <drv_types.h>
#include <hal_data.h>

/* Define the ICs that support wifi only cfg in coex. codes */
#define CONFIG_BTCOEX_SUPPORT_WIFI_ONLY_CFG 0

#if (CONFIG_BTCOEX_SUPPORT_WIFI_ONLY_CFG == 1)

typedef enum _WIFIONLY_CHIP_INTERFACE {
	WIFIONLY_INTF_UNKNOWN	= 0,
	WIFIONLY_INTF_PCI		= 1,
	WIFIONLY_INTF_USB		= 2,
	WIFIONLY_INTF_SDIO		= 3,
	WIFIONLY_INTF_MAX
} WIFIONLY_CHIP_INTERFACE, *PWIFIONLY_CHIP_INTERFACE;

typedef enum _WIFIONLY_CUSTOMER_ID {
	CUSTOMER_NORMAL			= 0,
	CUSTOMER_HP_1			= 1
} WIFIONLY_CUSTOMER_ID, *PWIFIONLY_CUSTOMER_ID;

struct wifi_only_haldata {
	u16		customer_id;
	u8		efuse_pg_antnum;
	u8		efuse_pg_antpath;
	u8		rfe_type;
	u8		ant_div_cfg;
};

struct wifi_only_cfg {
	void *						Adapter;
	struct	wifi_only_haldata		haldata_info;
	WIFIONLY_CHIP_INTERFACE	chip_interface;
};

void halwifionly_write1byte(void * pwifionlyContext, u32 RegAddr, u8 Data);
void halwifionly_write2byte(void * pwifionlyContext, u32 RegAddr, u16 Data);
void halwifionly_write4byte(void * pwifionlyContext, u32 RegAddr, u32 Data);
u8 halwifionly_read1byte(void * pwifionlyContext, u32 RegAddr);
u16 halwifionly_read2byte(void * pwifionlyContext, u32 RegAddr);
u32 halwifionly_read4byte(void * pwifionlyContext, u32 RegAddr);
void halwifionly_bitmaskwrite1byte(void * pwifionlyContext, u32 regAddr, u8 bitMask, u8 data);
void halwifionly_phy_set_rf_reg(void * pwifionlyContext, enum rf_path eRFPath, u32 RegAddr, u32 BitMask, u32 Data);
void halwifionly_phy_set_bb_reg(void * pwifionlyContext, u32 RegAddr, u32 BitMask, u32 Data);
void hal_btcoex_wifionly_switchband_notify(PADAPTER padapter);
void hal_btcoex_wifionly_scan_notify(PADAPTER padapter);
void hal_btcoex_wifionly_hw_config(PADAPTER padapter);
void hal_btcoex_wifionly_initlizevariables(PADAPTER padapter);
void hal_btcoex_wifionly_AntInfoSetting(PADAPTER padapter);
#else
#define hal_btcoex_wifionly_switchband_notify(padapter)
#define hal_btcoex_wifionly_scan_notify(padapter)
#define hal_btcoex_wifionly_hw_config(padapter)
#define hal_btcoex_wifionly_initlizevariables(padapter)
#define hal_btcoex_wifionly_AntInfoSetting(padapter)
#endif

#endif
