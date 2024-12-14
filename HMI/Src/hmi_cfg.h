
#ifndef _HMI_CFG_H_
#define _HMI_CFG_H_

#include "hmi.h"
#include "hmi_menu.h"
#include "hmi_voltage.h"
#include "hmi_current.h"
#include "hmi_dashboard.h"
#include "hmi_wifi.h"
#include "hmi_watts.h"
#include "hmi_cost.h"
#include "hmi_settings.h"
#include "hmi_about.h"
#include "button_types.h"



#define DELAY_UPDATE_SCREENS           1
#define HMI_NUMBER_OF_SCREENS_VECTOR    7

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
    ,                               \
    {                               \
        eHMI_ITEM_ID_WATTS,         \
        hmi_watts_init,             \
        hmi_watts_deinit,           \
        hmi_watts_show_screen,      \
        hmi_watts_show_data,        \
        hmi_watts_update_data,      \
        hmi_watts_on_exit           \
    }                               \
    ,                               \
    {                               \
        eHMI_ITEM_ID_COAST,         \
        hmi_cost_init,              \
        hmi_cost_deinit,            \
        hmi_cost_show_screen,       \
        hmi_cost_show_data,         \
        hmi_cost_update_data,       \
        hmi_cost_on_exit            \
    }                               \
    ,                               \
    {                               \
        eHMI_ITEM_ID_SETTINGS,      \
        hmi_settings_init,          \
        hmi_settings_deinit,        \
        hmi_settings_show_screen,   \
        hmi_settings_show_data,     \
        hmi_settings_update_data,   \
        hmi_settings_on_exit        \
    }                               \
    ,                               \
    {                               \
        eHMI_ITEM_ID_ABOUT,        \
        hmi_about_init,             \
        hmi_about_deinit,           \
        hmi_about_show_screen,      \
        hmi_about_show_data,        \
        hmi_about_update_data,      \
        hmi_about_on_exit           \
    }                               \
}

#endif
