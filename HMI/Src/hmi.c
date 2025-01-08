#include "sl.h"
#include "hmi.h"
#include "hmi_types.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "hmi_menu.h"
#include "hmi_menu_cfg.h"
#include "button.h"
#include "stdio.h"


/******************************************************************************/

volatile uint32_t hmi_execution_rate_1ms_timer;

/******************************************************************************/

//hmi_menu_data_t hmi_menu_item_vector_value_default[HMI_NUMBER_OF_ITENS] = hmi_menu_item_vector_value;

static const hmi_screen_info_t hmi_screen_vector[HMI_NUMBER_OF_SCREENS_VECTOR] = hmi_screens_vector_deafult;
static hmi_ctrl_t hmi_ctrl = {0};

void hmi_showing_screen(void);
void hmi_showing_data(void);
void hmi_updating_data(button_id_t button_id, button_press_type_t button_press_type);
void hmi_set_screen(hmi_screen_id_t hmi_screen_id);
hmi_screen_id_t hmi_get_screen(void);

static button_data_t buttons_data[] = 
{
    { {BT_UP_GPIO_Port, BT_UP_Pin     },  hmi_updating_data, 0, BUTTON_UP_ID,0,0 },
    { {BT_DOWN_GPIO_Port, BT_DOWN_Pin },  hmi_updating_data, 0, BUTTON_DOWN_ID,0,0 },
    { {BT_LEFT_GPIO_Port, BT_LEFT_Pin },  hmi_updating_data, 0, BUTTON_LEFT_ID,0,0 },
    { {BT_RIGHT_GPIO_Port, BT_RIGHT_Pin}, hmi_updating_data, 0, BUTTON_RIGHT_ID,0,0 }
};

/******************************************************************************/



void hmi_showing_screen(void)
{
    if(hmi_ctrl.hmi_screen_id < eHMI_NUMBER_OF_SCREENS_IDS)
    {
        if(hmi_screen_vector[hmi_ctrl.hmi_screen_id].show_screen != NULL)
        {
            hmi_screen_vector[hmi_ctrl.hmi_screen_id].show_screen();
        }
    }
}

/******************************************************************************/

void hmi_showing_data(void)
{
    if(hmi_ctrl.hmi_screen_id < eHMI_NUMBER_OF_SCREENS_IDS)
    {
        if(hmi_screen_vector[hmi_ctrl.hmi_screen_id].show_data != NULL)
        {
            hmi_screen_vector[hmi_ctrl.hmi_screen_id].show_data();
        }
    }
}

/******************************************************************************/

void hmi_updating_data(button_id_t button_id, button_press_type_t button_press_type)
{
    if(hmi_ctrl.hmi_screen_id < eHMI_NUMBER_OF_SCREENS_IDS)
    {
        if(hmi_screen_vector[hmi_ctrl.hmi_screen_id].update_data != NULL)
        {
            hmi_screen_vector[hmi_ctrl.hmi_screen_id].update_data(button_id, button_press_type);
        }
    }
}


/******************************************************************************/

void hmi_set_screen(hmi_screen_id_t hmi_screen_id)
{
    if(hmi_screen_id < eHMI_NUMBER_OF_SCREENS_IDS)
    {
        if(hmi_screen_vector[hmi_screen_id].screen_id == hmi_screen_id)
        {
            hmi_ctrl.hmi_next_screen_id = hmi_screen_id;
        }
    }
}

/******************************************************************************/

void hmi_1ms_clock(void)
{
    if(hmi_ctrl.delay > 0)
    {
        if(hmi_ctrl.hmi_state ==  HMI_STATE_UPDATING_DATA)
        {
            hmi_ctrl.delay--;
        }
    }


    hmi_screen_vector[hmi_ctrl.hmi_next_screen_id].eupdate_1ms();

}

/******************************************************************************/

hmi_screen_id_t hmi_get_screen(void)
{
    return hmi_ctrl.hmi_screen_id;
}

/******************************************************************************/

void hmi_init(void)
{
    for(uint8_t index = 0; index < HMI_NUMBER_OF_SCREENS_VECTOR; index ++)
    {
        hmi_screen_vector[index].init();
    }

    hmi_ctrl.hmi_state = HMI_STATE_SHOWING_SCREEN;
    hmi_ctrl.delay     = DELAY_UPDATE_SCREENS;
}   

/******************************************************************************/

void hmi_update(void)
{
    if(hmi_ctrl.hmi_screen_id != hmi_ctrl.hmi_next_screen_id)
    {
        hmi_ctrl.hmi_last_screen_id = hmi_ctrl.hmi_screen_id;
        hmi_ctrl.hmi_screen_id      = hmi_ctrl.hmi_next_screen_id;
        hmi_ctrl.hmi_state = HMI_STATE_SHOWING_SCREEN;
    }

    switch (hmi_ctrl.hmi_state)
    {
    case HMI_STATE_SHOWING_SCREEN:
        hmi_showing_screen();
        hmi_ctrl.hmi_state = HMI_STATE_SHOWING_DATA;    
        break;
    case HMI_STATE_SHOWING_DATA:
        hmi_showing_data();
        hmi_ctrl.hmi_state = HMI_STATE_UPDATING_DATA;
        break;
    case HMI_STATE_UPDATING_DATA:
        for (uint8_t index_buttons = 0; index_buttons < NUMBER_OF_BUTTONS; index_buttons++)
        {
            button_update_state(&buttons_data[index_buttons]);
        }
        break;
    default:
        break;
    }
}

void hmi_deinit(void)
{

}

