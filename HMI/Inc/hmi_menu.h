
#ifndef     _HMI_MENU_H
#define     _HMI_MENU_H

/********************************************************************************/


#include "hmi_menu_types.h"
#include "hmi_types.h"

/********************************************************************************/


/********************************************************************************/

void hmi_menu_init();                          
void hmi_menu_deinit();                          
void hmi_menu_show_screen();                    
void hmi_menu_show_data();                     
void hmi_menu_update_data();
#define hmi_menu_on_exit      NULL


/********************************************************************************/

#endif