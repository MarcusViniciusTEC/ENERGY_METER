
#ifndef __PIEZO_H
#define __PIEZO_H

#include "hmi_piezo_types.h"
#include "button_types.h"

void hmi_piezo_init();                          
void hmi_piezo_deinit();                          
void hmi_piezo_show_screen();                    
void hmi_piezo_show_data();                     
void hmi_piezo_update_data(button_id_t button_id, button_press_type_t button_press_type);
#define hmi_piezo_on_exit      NULL


#endif