
#ifndef _HMI_CFG_H_
#define _HMI_CFG_H_

#include "hmi.h"
#include "hmi_menu.h"
#include "hmi_voltage.h"
#include "hmi_current.h"
#include "hmi_dashboard.h"
#include "hmi_wifi.h"
#include "button_types.h"



#define DELAY_UPDATE_SCREENS           1
#define HMI_NUMBER_OF_SCREENS_VECTOR    4

#define hmi_screens_vector_deafult  \
{                                   \
    {                               \
        eHMI_ITEM_ID_MENU,          \
        hmi_menu_init,              \
        hmi_menu_deinit,            \
        hmi_menu_show_screen,       \
        hmi_menu_show_data,         \
        hmi_menu_update_data,       \
        hmi_menu_on_exit            \
    }                               \
    ,                               \
    {                               \
        eHMI_ITEM_ID_DASHBOARD,     \
        hmi_dashboard_init,         \
        hmi_dashboard_deinit,       \
        hmi_dashboard_show_screen,  \
        hmi_dashboard_show_data,    \
        hmi_dashboard_update_data,  \
        hmi_dashboard_on_exit       \
    }                               \
    ,                               \
    {                               \
        eHMI_ITEM_ID_WIFI,          \
        hmi_wifi_init,              \
        hmi_wifi_deinit,            \
        hmi_wifi_show_screen,       \
        hmi_wifi_show_data,         \
        hmi_wifi_update_data,       \
        hmi_wifi_on_exit            \
    }                               \
    ,                               \
    {                               \
        eHMI_ITEM_ID_VOLTAGE,       \
        hmi_voltage_init,           \
        hmi_voltage_deinit,         \
        hmi_voltage_show_screen,    \
        hmi_voltage_show_data,      \
        hmi_voltage_update_data,    \
        hmi_voltage_on_exit         \
    }                               \
    ,                               \
    {                               \
        eHMI_ITEM_ID_CURRENT,       \
        hmi_current_init,           \
        hmi_current_deinit,         \
        hmi_current_show_screen,    \
        hmi_current_show_data,      \
        hmi_current_update_data,    \
        hmi_current_on_exit         \
    }                               \
}

#endif
