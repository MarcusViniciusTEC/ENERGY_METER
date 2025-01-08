
#ifndef _HMI_WATTS_H
#define _HMI_WATTS_H

/********************************************************************************/

#include "hmi_watts_types.h"
#include "hmi_types.h"
#include "button_types.h"

/********************************************************************************/

void hmi_watts_init();                          
void hmi_watts_deinit();                          
void hmi_watts_show_screen();   
void hmi_watts_update_1ms();                 
void hmi_watts_show_data();                     
void hmi_watts_update_data(button_id_t button_id, button_press_type_t button_press_type);
#define hmi_watts_on_exit NULL

/********************************************************************************/

#endif