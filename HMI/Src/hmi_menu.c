
#include "hmi.h"
#include "hmi_types.h"
#include "hmi_menu.h"
#include "hmi_menu_cfg.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "button.h"


/******************************************************************************/

static const hmi_menu_data_t hmi_menu_item_vector_value_default[HMI_MENU_OF_ITENS] = hmi_menu_item_vector_value;
static hmi_menu_control_t hmi_menu_control = {0};


static const vector_retangle_sel_t vector_retangle_default[HMI_MENU_NUMBER_OF_ITENS_VISIBLE ] = vector_retangle_selection_default;

/******************************************************************************/

void hmi_menu_decrement_item_index(void)
{
    hmi_menu_control.selected_item_index--;
    if(hmi_menu_control.selected_item_index > eHMI_NUMBER_OF_SCREENS_IDS-2)
    {
       hmi_menu_control.selected_item_index = eHMI_ITEM_ID_DASHBOARD -1;
    }
}

/******************************************************************************/

void hmi_menu_increment_item_index(void)
{
    hmi_menu_control.selected_item_index++;
    if(hmi_menu_control.selected_item_index > eHMI_NUMBER_OF_SCREENS_IDS-2)
    {
       hmi_menu_control.selected_item_index = eHMI_NUMBER_OF_SCREENS_IDS-2;
    }
}

/******************************************************************************/

static void menu_show_visible_itens(void)
{
    ssd1306_SetCursor(46, 2);
    ssd1306_WriteString("GIOVANNA", Font_7x10, White) ;
    ssd1306_InvertRectangle(0,1,127,10);  
    ssd1306_Line(0,13,128,13,White);

    for (uint8_t index = 2; index < HMI_MENU_OF_ITENS-2; index++)
    {
        ssd1306_SetCursor(1, (index*10));
        ssd1306_WriteString(hmi_menu_item_vector_value_default[(index-2) + hmi_menu_control.firt_visible_item_index].sz_description, Font_7x10, White);
    }
}

/******************************************************************************/

static void hmi_menu_show_cursor(void)
{
    vector_retangle_sel_t vector_retangle_selection;
    uint8_t index = 0;
    index = (hmi_menu_control.selected_item_index - hmi_menu_control.firt_visible_item_index) ;
    if(hmi_menu_control.selected_item_index  < HMI_MENU_NUMBER_OF_ITENS_VISIBLE)
    {
        ssd1306_SetCursor(113,50);
        ssd1306_WriteString(">", Font_7x10, White) ;
    }
    vector_retangle_selection = vector_retangle_default[index];
    ssd1306_InvertRectangle(vector_retangle_selection.point_x1,vector_retangle_selection.point_y1, vector_retangle_selection.point_x2,vector_retangle_selection.point_y2);
}

/******************************************************************************/

void hmi_menu_update_1ms(void)
{

}

/******************************************************************************/

static void hmi_menu_needs_atualize(void)
{
    ssd1306_Fill(Black);
    menu_show_visible_itens();
    hmi_menu_show_cursor();
    ssd1306_UpdateScreen();
}

/******************************************************************************/

void hmi_menu_init()
{
    hmi_menu_control.button_menu_press_type  =  0;
    hmi_menu_control.selected_item_index     =  0;
    hmi_menu_needs_atualize();
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

void hmi_menu_update_data(button_id_t button_id, button_press_type_t button_press_type)
{
    switch (button_id)
    {
        case BUTTON_RIGHT_ID:
            switch (hmi_menu_control.selected_item_index)
            {

            case HMI_MenuItem_ID_Dashboard:
                hmi_set_screen(eHMI_ITEM_ID_DASHBOARD);
                break;
            case HMI_MenuItem_ID_WIFI:
                hmi_set_screen(eHMI_ITEM_ID_WIFI);
                break;                               
            case HMI_MenuItem_ID_Voltage:
                hmi_set_screen(eHMI_ITEM_ID_VOLTAGE);
                break;
            case HMI_MenuItem_ID_Current:
                hmi_set_screen(eHMI_ITEM_ID_CURRENT);
                break;
            case HMI_MenuItem_ID_WATTS:
                hmi_set_screen(eHMI_ITEM_ID_WATTS);
                break;
            case HMI_MenuItem_ID_Cost:
                hmi_set_screen(eHMI_ITEM_ID_COAST);
                break;
            case HMI_MenuItem_ID_Settings:
                 hmi_set_screen(eHMI_ITEM_ID_SETTINGS);
                break;
            case HMI_MenuItem_ID_About:
                hmi_set_screen(eHMI_ITEM_ID_ABOUT);
                break;
            default:
                break;
            }
            break;
        case BUTTON_UP_ID:
            hmi_menu_decrement_item_index();
            
            break;
        case BUTTON_DOWN_ID:
            hmi_menu_increment_item_index();
            
            break;
    default:
        break;
    }

    if(hmi_menu_control.selected_item_index < HMI_MENU_NUMBER_OF_ITENS_VISIBLE)
    {
        hmi_menu_control.firt_visible_item_index  = 0;
        hmi_menu_needs_atualize();
    }
    else if(hmi_menu_control.selected_item_index >= HMI_MENU_NUMBER_OF_ITENS_VISIBLE-1)
    {
        hmi_menu_control.firt_visible_item_index  = HMI_MENU_NUMBER_OF_ITENS_VISIBLE;
        hmi_menu_needs_atualize();
    }

}



