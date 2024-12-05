
#include "hmi.h"
#include "hmi_voltage.h"
#include "hmi_voltage_cfg.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "encoder.h"
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
        ssd1306_SetCursor(10,10);
        ssd1306_WriteString("gg:", Font_7x10, White);
        ssd1306_SetCursor(10,20);
        ssd1306_WriteString("gg1", Font_7x10, White);

        ssd1306_UpdateScreen();   
}           

/******************************************************************************/

#define FORMAT_NUMBER_WITH_POINT(buffer, size, num)   snprintf(buffer, size, "%d.%03d", (num) / 1000, (num) % 1000)
                                                                

void hmi_voltage_show_data()
{
        char buff[10];
        FORMAT_NUMBER_WITH_POINT(buff, sizeof(buff), adc_get_voltage_value_1ms());
        ssd1306_SetCursor(60,60);
        ssd1306_WriteString(buff, Font_7x10, White);
} 

/******************************************************************************/

void hmi_voltage_update_data()
{
        
}