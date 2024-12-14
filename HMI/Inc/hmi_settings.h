
#ifndef _HMI_SETTINGS_H
#define _HMI_SETTINGS_H

/********************************************************************************/

#include "hmi_settings_types.h"
#include "hmi_types.h"
#include "button_types.h"

/********************************************************************************/



/********************************************************************************/

void hmi_settings_init();                          
void hmi_settings_deinit();                          
void hmi_settings_show_screen();                    
void hmi_settings_show_data();                     
void hmi_settings_update_data(button_id_t button_id, button_press_type_t button_press_type);
#define hmi_settings_on_exit NULL

/********************************************************************************/

#endif