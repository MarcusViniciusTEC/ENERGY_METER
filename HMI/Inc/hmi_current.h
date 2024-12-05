
#ifndef _HMI_CURRENT_H
#define _HMI_CURRENT_H

/********************************************************************************/

#include "hmi_current_types.h"
#include "hmi_types.h"

/********************************************************************************/



/********************************************************************************/

void hmi_current_init();                          
void hmi_current_deinit();                          
void hmi_current_show_screen();                    
void hmi_current_show_data();                     
void hmi_current_update_data(h);
#define hmi_current_on_exit NULL

/********************************************************************************/

#endif