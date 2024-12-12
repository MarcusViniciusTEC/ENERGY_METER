#ifndef __BUTTON_H__
#define __BUTTON_H__

/******************************************************************************/

#include "button_types.h"

/******************************************************************************/

extern volatile uint32_t button_execution_rate_1ms_timer;

#define button_pexecution_rate_1ms_timer (&button_execution_rate_1ms_timer)

/******************************************************************************/

#define BUTTON_EXECUTION_RATE_1MS_TIME    		100

/******************************************************************************/
void button_update_state(button_data_t *button_event);

void button_1ms_clock(void);
void button_init(void);
void button_update(void);
void button_deinit(void);

#endif