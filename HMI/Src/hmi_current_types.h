

#ifndef _HMI_CURRENT_TYPES_H
#define _HMI_CURRENT_TYPES_H

#include "hmi_current_cfg.h"

typedef enum
{
    ADC_CONVERT_START = 0U,
    ADC_CONVERT,
    ADC_CONVERT_SUCESS
}adc_convert_state_t;

typedef struct 
{
    adc_convert_state_t convert_state;
    uint16_t voltage;
    uint16_t raw;
}adc_types_t;

typedef struct 
{
    adc_types_t adc[NUMBER_OF_CHANNELS_VOLTAGE];
}adc_values_t;


#endif