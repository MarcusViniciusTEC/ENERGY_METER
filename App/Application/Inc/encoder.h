#ifndef __ENCODER_H__
#define __ENCODER_H__

/******************************************************************************/

#include "encoder_types.h"

/******************************************************************************/

extern volatile uint32_t encoder_execution_rate_1ms_timer;

#define encoder_pexecution_rate_1ms_timer (&encoder_execution_rate_1ms_timer)

/******************************************************************************/

#define ENCODER_EXECUTION_RATE_1MS_TIME    		100

/******************************************************************************/


void rotary_encoder(uint16_t *value);
void button_encoder(uint8_t *state);


void encoder_1ms_clock(void);
void encoder_init(void);
void encoder_update(void);
void encoder_deinit(void);

#endif