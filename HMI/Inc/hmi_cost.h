
#ifndef _HMI_COST_H
#define _HMI_COST_H

/********************************************************************************/

#include "hmi_cost_types.h"
#include "hmi_types.h"
#include "button_types.h"

/********************************************************************************/



/********************************************************************************/

void hmi_cost_init();                          
void hmi_cost_deinit();                          
void hmi_cost_show_screen();                    
void hmi_cost_show_data();                     
void hmi_cost_update_data(button_id_t button_id, button_press_type_t button_press_type);
#define hmi_cost_on_exit NULL

/********************************************************************************/

#endif