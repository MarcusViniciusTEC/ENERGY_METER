


#ifndef __HMI_H__
#define __HMI_H__

/******************************************************************************/

#include "hmi_types.h"
#include "stdint.h"

/******************************************************************************/

extern volatile uint32_t hmi_execution_rate_1ms_timer;

#define hmi_pexecution_rate_1ms_timer (&hmi_execution_rate_1ms_timer)

#define HMI_EXECUTION_RATE_1MS_TIME    		100

/******************************************************************************/

hmi_screen_id_t hmi_get_screen(void);
void hmi_set_screen(hmi_screen_id_t hmi_screen_id);

void hmi_1ms_clock(void);
void hmi_init(void);
void hmi_update(void);
void hmi_deinit(void);

/******************************************************************************/

#endif/*__HMI_H__*/
