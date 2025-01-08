
#include "hmi.h"
#include "hmi_voltage.h"
#include "hmi_voltage_cfg.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "button.h"
#include "stdio.h"

void hmi_voltage_init()
{

}   

/******************************************************************************/

void hmi_voltage_deinit()
{

}                   

/******************************************************************************/

void hmi_voltage_update_1ms()
{



}

/******************************************************************************/

void hmi_voltage_show_screen()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(42, 2);
    ssd1306_WriteString("VOLTAGE", Font_7x10, White) ;
    ssd1306_InvertRectangle(0,1,127,10);  
    ssd1306_Line(0,13,128,13,White);
    ssd1306_UpdateScreen();
}           

/******************************************************************************/                                                             

void hmi_voltage_show_data()
{

} 

/******************************************************************************/

void hmi_voltage_update_data(button_id_t button_id, button_press_type_t button_press_type)
{
    ssd1306_Fill(Black);
    char buff0[50];

    sprintf(buff0,"%d", adc_get_raw_votage(0));
    ssd1306_SetCursor(10, 10);
    ssd1306_WriteString(buff0, Font_7x10, White);

    ssd1306_UpdateScreen();
    switch (button_id)
    {
        case BUTTON_RIGHT_ID:
            hmi_set_screen(eHMI_ITEM_ID_MENU);
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