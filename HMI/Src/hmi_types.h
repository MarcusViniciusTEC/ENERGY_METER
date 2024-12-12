#ifndef __HMI_TYPES_H__
#define __HMI_TYPES_H__

/******************************************************************************/


#include "hmi_cfg.h"
#include "hmi_menu_types.h"
#include "button.h"

/******************************************************************************/

typedef enum
{   eHMI_ITEM_ID_MENU     = 0U,
    eHMI_ITEM_ID_VOLTAGE, 
    eHMI_ITEM_ID_CURRENT,
    eHMI_NUMBER_OF_SCREENS_IDS
}hmi_screen_id_t;

typedef enum {
    HMI_BUTTON_ID_ENTER = 0U,
    HMI_BUTTON_ID_UP,
    HMI_BUTTON_ID_DOWN,
    HMI_BUTTON_ID_BACK
} hmi_button_id_t;

typedef struct {
    hmi_button_id_t     button_id;
    button_press_type_t button_press_type;
} hmi_button_event_t;

typedef enum
{
    HMI_STATE_SHOWING_SCREEN = 0,
    HMI_STATE_SHOWING_DATA,
    HMI_STATE_UPDATING_DATA
}hmi_state_t;

typedef struct 
{
    hmi_screen_id_t hmi_screen_id;
    hmi_screen_id_t hmi_next_screen_id;
    hmi_screen_id_t hmi_last_screen_id;
    hmi_state_t     hmi_state;
    uint32_t        delay;
}hmi_ctrl_t;

typedef struct {
    hmi_screen_id_t screen_id;
    void (*init)(void);
    void (*deInit)(void);
    void (*show_screen)(void);
    void (*show_data)(void);
    void (*update_data)(button_id_t button_id, button_press_type_t button_press_type);
    void (*on_exit)(void);
} hmi_screen_info_t;


#endif