
#ifndef __ADC_TYPES_H__
#define __ADC_TYPES_H__


#include "adc_cfg.h"


#define AVG_FIRST_INDEX             0

typedef enum
{
    eADC_CHANNEL_0 = 0U,
    eADC_CHANNEL_1,
    eADC_CHANNEL_2,
    eADC_CHANNEL_ALL
}adc_channels_t;

typedef enum
{
    ADC_START = 0U,
    ADC_WAITING_TIME,
    ADC_CALC_AVG,
    ADC_SET_VALUE,
    ADC_SUCESS
}adc_data_state_t;

typedef struct 
{
    adc_data_state_t state;
    uint16_t time_acquisition;
    uint16_t vector[AVG_NUMBER_OF_SAMPLES_MAX];
    uint32_t add;
}moving_data_t;

typedef struct 
{
    moving_data_t cacl[AVG_NUMBER_OF_SAMPLES_MAX];
}moving_avg_t;





#endif
