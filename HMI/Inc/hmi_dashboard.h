
#ifndef _HMI_DASHBOARD_H
#define _HMI_DASHBOARD_H

/********************************************************************************/

#include "hmi_dashboard_types.h"
#include "hmi_types.h"
#include "button_types.h"

/********************************************************************************/



/********************************************************************************/

void hmi_dashboard_init();                          
void hmi_dashboard_deinit();                          
void hmi_dashboard_show_screen();   
void hmi_dashboard_update_1ms();                 
void hmi_dashboard_show_data();                     
void hmi_dashboard_update_data(button_id_t button_id, button_press_type_t button_press_type);
#define hmi_dashboard_on_exit NULL

/********************************************************************************/

#endif