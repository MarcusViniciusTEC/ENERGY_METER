
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

void hmi_voltage_show_screen()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(46, 2);
    ssd1306_WriteString("CURRENT", Font_7x10, White) ;
    ssd1306_InvertRectangle(0,1,127,10);  
    ssd1306_Line(0,13,128,13,White);
    ssd1306_UpdateScreen();
}           

/******************************************************************************/

#define FORMAT_NUMBER_WITH_POINT(buffer, size, num)   snprintf(buffer, size, "%d.%03d", (num) / 1000, (num) % 1000)
                                                                

void hmi_voltage_show_data()
{

} 

/******************************************************************************/

void hmi_voltage_update_data(button_id_t button_id, button_press_type_t button_press_type)
{
    switch (button_id)
    {
        case BUTTON_RIGHT_ID:

            break;
        case BUTTON_LEFT_ID:

            break;
        case BUTTON_UP_ID:
                      
            break;
        case BUTTON_DOWN_ID:
                
            break;
    default:
        break;
    }
        
}