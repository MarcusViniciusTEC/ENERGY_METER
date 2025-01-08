
#ifndef _HMI_CURRENT_H
#define _HMI_CURRENT_H

/********************************************************************************/

#include "hmi_current_types.h"
#include "hmi_types.h"
#include "button_types.h"

/********************************************************************************/



/********************************************************************************/

void hmi_current_init();                          
void hmi_current_deinit();                          
void hmi_current_show_screen();
void hmi_current_update_1ms();                    
void hmi_current_show_data();                     
void hmi_current_update_data(button_id_t button_id, button_press_type_t button_press_type);
#define hmi_current_on_exit NULL

/********************************************************************************/

#endif