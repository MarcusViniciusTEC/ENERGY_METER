

#ifndef HMI_MENU_CFG_H_
#define HMI_MENU_CFG_H_


#include "hmi_menu.h"
#include "stdint.h"

#define CURSOR_ITEM_MENU ">"
#define HMI_MENU_NUMBER_OF_ITENS_VISIBLE    6
#define HMI_MENU_OF_ITENS                   12




typedef struct 
{
    uint8_t point_x1;
    uint8_t point_y1;
    uint8_t point_x2;
    uint8_t point_y2;
}vector_retangle_sel_t;
                                          
#define vector_retangle_selection_default     {{0,19,127,28}, {0,29,127,38}, {0,39,127,38}} 


#define hmi_menu_item_vector_value      \
{                                       \
    {                                   \ 
        .id = HMI_MenuItem_ID_Voltage,  \
        .sz_description = "VOLTAGE"     \
    }                                   \
    ,                                   \
    {                                   \ 
        .id = HMI_MenuItem_ID_Current,  \
        .sz_description = "CURRENT"     \
    }                                   \
}                               


#endif