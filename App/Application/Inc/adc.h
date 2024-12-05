#ifndef __ADC_H__
#define __ADC_H__


#include "adc_types.h"

extern volatile uint32_t adc_execution_rate_1ms_timer;

#define adc_pexecution_rate_1ms_timer (&adc_execution_rate_1ms_timer)

#define ADC_EXECUTION_RATE_1MS_TIME    		100

uint16_t adc_get_raw_value_1ms(adc_channels_t channel);
uint16_t adc_get_voltage_value_1ms(adc_channels_t channel);

void adc_1ms_clock(void);
void adc_init(void);
void adc_update(void);
void adc_deinit(void);

#endif
