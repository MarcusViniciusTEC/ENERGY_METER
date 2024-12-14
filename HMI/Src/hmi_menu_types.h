
#ifndef __HMI_MENU_TYPES_H__
#define __HMI_MENU_TYPES_H__

/******************************************************************************/


#include "hmi_menu_cfg.h"
#include "button.h"
#include "stdint.h"

/******************************************************************************/

typedef enum
{
    HMI_MenuItem_ID_Dashboard = 0U,
    HMI_MenuItem_ID_WIFI,
    HMI_MenuItem_ID_Voltage,
    HMI_MenuItem_ID_Current,
    HMI_MenuItem_ID_WATTS,
    HMI_MenuItem_ID_Cost,
    HMI_MenuItem_ID_Settings,
    HMI_MenuItem_ID_Default,
    HMI_Numbers_MenuItem

}hmi_menu_item_id_t;

typedef struct 
{
    hmi_menu_item_id_t id;
    char *sz_description;
}hmi_menu_data_t;


typedef struct 
{
    uint8_t firt_visible_item_index;
    uint8_t selected_item_index;
    button_press_type_t button_menu_press_type;
}hmi_menu_control_t;



#endif