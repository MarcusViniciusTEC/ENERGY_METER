
/******************************************************************************/

#include "hmi.h"
#include "hmi_dashboard.h"
#include "hmi_dashboard_types.h"
#include "adc.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"



/******************************************************************************/

void hmi_dashboard_init()
{

}   

/******************************************************************************/

void hmi_dashboard_deinit()
{

}                   

/******************************************************************************/

void hmi_dashboard_update_1ms()
{

}

/******************************************************************************/

void hmi_dashboard_show_screen()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(46, 2);
    ssd1306_WriteString("DASHBOARD", Font_7x10, White) ;
    ssd1306_InvertRectangle(0,1,127,10);  
    ssd1306_Line(0,13,128,13,White);
    ssd1306_UpdateScreen();
}           

/******************************************************************************/

void hmi_dashboard_show_data()
{

} 

/******************************************************************************/

void hmi_dashboard_update_data(button_id_t button_id, button_press_type_t button_press_type)
{
    switch (button_id)
    {
        case BUTTON_RIGHT_ID:
        
            break;
        case BUTTON_LEFT_ID:
            hmi_set_screen(eHMI_ITEM_ID_MENU);
            break;
        case BUTTON_UP_ID:
                      
            break;
        case BUTTON_DOWN_ID:
                
            break;
    default:
        break;
    }
        

}