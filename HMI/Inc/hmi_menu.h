
#ifndef     _HMI_MENU_H
#define     _HMI_MENU_H

/********************************************************************************/


#include "hmi_menu_types.h"
#include "hmi_types.h"
#include "button_types.h"

/********************************************************************************/


/********************************************************************************/

void hmi_menu_init();                          
void hmi_menu_deinit();                          
void hmi_menu_show_screen();                    
void hmi_menu_show_data();                     
void hmi_menu_update_data(button_id_t button_id, button_press_type_t button_press_type);
#define hmi_menu_on_exit      NULL


/********************************************************************************/

#endif