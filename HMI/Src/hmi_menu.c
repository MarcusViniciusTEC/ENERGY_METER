
#include "hmi.h"
#include "hmi_types.h"
#include "hmi_menu.h"
#include "hmi_menu_cfg.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "encoder.h"


/******************************************************************************/

static const hmi_menu_data_t hmi_menu_item_vector_value_default[HMI_MENU_OF_ITENS] = hmi_menu_item_vector_value;
static hmi_menu_control_t hmi_menu_control = {0};

/******************************************************************************/

static void menu_show_visible_itens(void)
{

    for (uint8_t index = 2; index < HMI_MENU_NUMBER_OF_ITENS_VISIBLE; index++)
    {
        //uint8_t index = 0;
        ssd1306_SetCursor(20, index*10);
        ssd1306_WriteString(hmi_menu_item_vector_value_default[(index-2) + hmi_menu_control.firt_visible_item_index].sz_description, Font_7x10, White);
    }
}

/******************************************************************************/


     
#define vector     {{0,29,127,38}, {0,19,127,28}} 


typedef struct 
{
    uint8_t cursor1;
    uint8_t cursor2;
    uint8_t cursor3;
    uint8_t cursor4;
}vector_retangle_t;


vector_retangle_t vector_retangle[2] = vector;
                                          

static void hmi_menu_show_cursor(void)
{
    //ssd1306_SetCursor(0, (hmi_menu_control.selected_item_index - hmi_menu_control.firt_visible_item_index)*10);
    //ssd1306_WriteString(CURSOR_ITEM_MENU, Font_7x10, White);

    uint8_t index = 0;

   // ssd1306_InvertRectangle(0,index*19,127,index*28);
    ssd1306_InvertRectangle(vector_retangle[0].cursor1,vector_retangle[0].cursor2, vector_retangle[0].cursor3,vector_retangle[0].cursor4);


}

/******************************************************************************/

static void hmi_menu_needs_atualize(void)
{
    static uint8_t last_index = 1; 
    if(hmi_menu_control.selected_item_index != last_index)
    {
        ssd1306_Fill(Black);
        menu_show_visible_itens();
        hmi_menu_show_cursor();
        ssd1306_UpdateScreen();
        last_index = hmi_menu_control.selected_item_index;
    }
}

/******************************************************************************/

void hmi_menu_init()
{
    hmi_menu_control.button_menu_press_type  =  0;
    hmi_menu_control.selected_item_index     =  0;
}  


/******************************************************************************/

void hmi_menu_deinit()
{

}                   

/******************************************************************************/

void hmi_menu_show_screen()
{
    hmi_menu_needs_atualize();  
}
    

/******************************************************************************/

void hmi_menu_show_data()
{

} 

/******************************************************************************/

void hmi_menu_update_data()
{
    // rotary_encoder(&hmi_menu_control.selected_item_index);
    // button_encoder(&hmi_menu_control.button_menu_press_type);

    // if(hmi_menu_control.selected_item_index >= eHMI_NUMBER_OF_SCREENS_IDS)
    // {
    //    hmi_menu_control.selected_item_index = eHMI_NUMBER_OF_SCREENS_IDS-2;
    // }
    // switch (hmi_menu_control.button_menu_press_type)
    // {
    // case BUTTON_SHORT_PRESS:
    //     switch (hmi_menu_item_vector_value_default[hmi_menu_control.selected_item_index].id)
    //     {
    //     case HMI_MenuItem_ID_Voltage:
    //         //hmi_set_screen(eHMI_ITEM_ID_VOLTAGE);
    //         break;
    //     case HMI_MenuItem_ID_Current:
    //         hmi_set_screen(eHMI_ITEM_ID_CURRENT);
    //         break;
    //     case HMI_MenuItem_ID_Piezo_1:
    //         hmi_set_screen(eHMI_ITEM_ID_PIEZO_1);
    //         break;
    //     case HMI_MenuItem_ID_Piezo_2:
    //         hmi_set_screen(eHMI_ITEM_ID_PIEZO_2);
    //         break;
    //     case HMI_MenuItem_ID_Piezo_3:
    //         hmi_set_screen(eHMI_ITEM_ID_PIEZO_3);
    //         break;
    //     case HMI_MenuItem_ID_Piezo_4:
    //         hmi_set_screen(eHMI_ITEM_ID_PIEZO_4);
    //         break;
    //     case HMI_MenuItem_ID_Piezo_5:
    //         hmi_set_screen(eHMI_ITEM_ID_PIEZO_5);
    //         break;
    //     case HMI_MenuItem_ID_Piezo_6:
    //         hmi_set_screen(eHMI_ITEM_ID_PIEZO_6);
    //         break;
    //     case HMI_MenuItem_ID_Piezo_7:
    //         hmi_set_screen(eHMI_ITEM_ID_PIEZO_7);
    //         break;
    //     case HMI_MenuItem_ID_Piezo_8:
    //         hmi_set_screen(eHMI_ITEM_ID_PIEZO_8);
    //         break;
    //     case HMI_MenuItem_ID_Piezo_9:
    //         hmi_set_screen(eHMI_ITEM_ID_PIEZO_9);
    //         break;
    //     case HMI_MenuItem_ID_Settings:
    //         hmi_set_screen(eHMI_ITEM_ID_SETTINGS);
    //         break;
    //     default:
    //         break;
    //     }
    //     break;
    // case BUTTON_LONG_PRESS:

    //     break;
    // default:
    //     break;
    // }

    // if(hmi_menu_control.selected_item_index > HMI_MENU_NUMBER_OF_ITENS_VISIBLE - 1)
    // {
    //     hmi_menu_control.firt_visible_item_index  = HMI_MENU_NUMBER_OF_ITENS_VISIBLE;
    // }
    // else if(hmi_menu_control.selected_item_index < HMI_MENU_NUMBER_OF_ITENS_VISIBLE)
    // {
    //     hmi_menu_control.firt_visible_item_index  = 0;
    // }
}



