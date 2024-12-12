
#include "hmi.h"
#include "hmi_piezo.h"
#include "hmi_piezo_types.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "encoder.h"
#include "stdio.h"

/******************************************************************************/

void hmi_piezo_init()
{
    
}

/******************************************************************************/

void hmi_piezo_deinit()
{
    
}

/******************************************************************************/

static uint8_t button = 0;

void hmi_piezo_show_screen()
{
        char string[10];
        ssd1306_Fill(Black);
        sniprintf(string, sizeof(string), "Piezo%2u:", button);
        ssd1306_SetCursor(10,10);
        ssd1306_WriteString(string, Font_7x10, White);
        ssd1306_UpdateScreen();
}

/******************************************************************************/

void hmi_piezo_show_data()
{
    
}

/******************************************************************************/


void hmi_piezo_update_data(button_id_t button_id, button_press_type_t button_press_type)
{
            
        // switch (button)
        // {
        // case BUTTON_SHORT_PRESS:
               
        //         break;
        // case BUTTON_LONG_PRESS:
                
        //         break;
        // default:
        //         break;
        // }   

}