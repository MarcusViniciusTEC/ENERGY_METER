
#ifndef _HMI_VOLTAGE_H
#define _HMI_VOLTAGE_H

/********************************************************************************/

#include "hmi_voltage_types.h"
#include "hmi_types.h"
#include "button_types.h"

/********************************************************************************/



/********************************************************************************/


void hmi_voltage_init();                          
void hmi_voltage_deinit();                          
void hmi_voltage_show_screen();   
void hmi_voltage_update_1ms();                 
void hmi_voltage_show_data();                     
void hmi_voltage_update_data(button_id_t button_id, button_press_type_t button_press_type);
#define hmi_voltage_on_exit NULL

/********************************************************************************/


#endif