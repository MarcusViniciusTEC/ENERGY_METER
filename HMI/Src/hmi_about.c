
/******************************************************************************/

#include "hmi.h"
#include "hmi_about.h"
#include "adc.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"



/******************************************************************************/

void hmi_about_init()
{

}   

/******************************************************************************/

void hmi_about_deinit()
{

}                   

/******************************************************************************/


void hmi_about_show_screen()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(46, 2);
    ssd1306_WriteString("ABOUT", Font_7x10, White) ;
    ssd1306_InvertRectangle(0,1,127,10);  
    ssd1306_Line(0,13,128,13,White);
    ssd1306_UpdateScreen();
}           

/******************************************************************************/

void hmi_about_show_data()
{

} 

/******************************************************************************/

void hmi_about_update_data(button_id_t button_id, button_press_type_t button_press_type)
{
        

}