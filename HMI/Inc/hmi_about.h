
#ifndef _HMI_ABOUT_H
#define _HMI_ABOUT_H

/********************************************************************************/
#include "hmi_types.h"
#include "button_types.h"

/********************************************************************************/



/********************************************************************************/

void hmi_about_init();                          
void hmi_about_deinit();                          
void hmi_about_show_screen();
void hmi_about_update_1ms();                    
void hmi_about_show_data();                     
void hmi_about_update_data(button_id_t button_id, button_press_type_t button_press_type);
#define hmi_about_on_exit NULL

/********************************************************************************/

#endif