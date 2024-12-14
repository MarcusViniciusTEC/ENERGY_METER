

#ifndef HMI_MENU_CFG_H_
#define HMI_MENU_CFG_H_


#include "hmi_menu.h"
#include "stdint.h"

#define CURSOR_ITEM_MENU ">"
#define HMI_MENU_NUMBER_OF_ITENS_VISIBLE    4
#define HMI_MENU_OF_ITENS                   8




typedef struct 
{
    uint8_t point_x1;
    uint8_t point_y1;
    uint8_t point_x2;
    uint8_t point_y2;
}vector_retangle_sel_t;
                                          
#define vector_retangle_selection_default     { {0,19,127,28}, {0,29,127,38}, {0,39,127,48}, {0,49,127,58}} 


#define hmi_menu_item_vector_value      \
{                                       \
    {                                   \
        .id = HMI_MenuItem_ID_Dashboard,\
        .sz_description = "1.DASHBOARD" \
    }                                   \
    ,                                   \
    {                                   \
        .id = HMI_MenuItem_ID_WIFI,     \
        .sz_description = "2.WIFI"      \
    }                                   \
    ,                                   \
    {                                   \
        .id = HMI_MenuItem_ID_Voltage,  \
        .sz_description = "3.VOLTAGE"   \
    }                                   \
    ,                                   \
    {                                   \
        .id = HMI_MenuItem_ID_Current,  \
        .sz_description = "4.CURRENT"   \
    }                                   \
    ,                                   \
    {                                   \
        .id = HMI_MenuItem_ID_WATTS,    \
        .sz_description = "5.WATTS"     \
    }                                   \
    ,                                   \
    {                                   \
        .id = HMI_MenuItem_ID_Cost,     \
        .sz_description = "6.COST "     \
    }                                   \
    ,                                   \
    {                                   \
        .id = HMI_MenuItem_ID_Settings, \
        .sz_description = "7.SETTINGS " \
    }                                   \
    ,                                   \
    {                                   \
        .id = HMI_MenuItem_ID_Settings, \
        .sz_description = "8.ABOUT "    \
    }                                   \
    ,                                   \
    {                                   \
        .id = HMI_MenuItem_ID_Default,  \
        .sz_description = "9.ABOUT "    \
    }                                   \
}                               


#endif