
#ifndef __PIEZO_H
#define __PIEZO_H

#include "hmi_wifi_types.h"
#include "button_types.h"

void hmi_wifi_init();                          
void hmi_wifi_deinit();                          
void hmi_wifi_show_screen();                    
void hmi_wifi_show_data();                     
void hmi_wifi_update_data(button_id_t button_id, button_press_type_t button_press_type);
#define hmi_wifi_on_exit      NULL


#endif