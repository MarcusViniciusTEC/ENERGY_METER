#include "sl.h"
#include "adc_cfg.h"
#include "adc.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "main.h"
#include "sl_lib.h"
/******************************************************************************/

volatile uint32_t adc_execution_rate_1ms_timer;

/******************************************************************************/

static moving_avg_t moving_avg;
static uint16_t  adc[3];

/******************************************************************************/


/******************************************************************************/


/******************************************************************************/

void adc_delay_1ms(void)
{
    for (uint8_t index = 0; index < ADC_NUMBER_OF_CHANNELS; index++)
    {
        if(moving_avg.cacl[index].time_acquisition > 0 && moving_avg.cacl[index].state == ADC_WAITING_TIME)
        {
            moving_avg.cacl[index].time_acquisition--;
        }
    }
}

/******************************************************************************/

uint16_t index_sum = 0;

uint16_t adc_moving_average(uint8_t adc_index)
{
    uint8_t index = 0;
    index = adc_index;
    moving_avg.cacl[index].vector[AVG_NUMBER_OF_SAMPLES_MAX];

    for(uint8_t i = AVG_NUMBER_OF_SAMPLES_MAX-1; i > 0; i--)
    {
        moving_avg.cacl[index].vector[i] = moving_avg.cacl[index].vector[i - 1]; 
    }
    moving_avg.cacl[index].vector[AVG_FIRST_INDEX] = adc[adc_index];
    moving_avg.cacl[index].add = 0;
    for (int index_add = 0; index_add < AVG_NUMBER_OF_SAMPLES_MAX ; index_add++)
    {
        moving_avg.cacl[index].add += moving_avg.cacl[index].vector[index_add];
    }
    
    if(index_sum <= AVG_NUMBER_OF_SAMPLES_MAX)
    {
        index_sum++;
        return adc[adc_index];     
    }
    else 
    {
        return ((uint16_t)moving_avg.cacl[index].add/AVG_NUMBER_OF_SAMPLES_MAX);
    }
}

/******************************************************************************/

uint16_t adc_update_1ms(uint8_t index)
{
    static uint16_t avg_adc_value[1];
    switch (moving_avg.cacl[index].state)
    {
    case ADC_START:
        moving_avg.cacl[index].state = ADC_WAITING_TIME;
        break;
    case ADC_WAITING_TIME:
        if(moving_avg.cacl[index].time_acquisition == 0)
        {
            moving_avg.cacl[index].state = ADC_CALC_AVG;
        }
        break;
    case ADC_CALC_AVG:
        avg_adc_value[index] = adc_moving_average(index);
        moving_avg.cacl[index].state = ADC_SET_VALUE;
        break;
    case ADC_SET_VALUE:
        adc_set_value(avg_adc_value[index]);
        moving_avg.cacl[index].state = ADC_SUCESS;
        break;
    case ADC_SUCESS:
        moving_avg.cacl[index].time_acquisition = ADC_TIME_DELAY_1MS;
        moving_avg.cacl[index].state = ADC_START;
        break;
    default:
        break;
    }
    return avg_adc_value[index];
}

/******************************************************************************/

uint16_t adc_get_raw_value_1ms(adc_channels_t channel)
{
    return adc_update_1ms(channel);
}

/******************************************************************************/

uint16_t adc_get_voltage_value_1ms(adc_channels_t channel)
{
    return adc_update_1ms(channel)/* (*VALOR DE CONVERSÃO) */;
}

/******************************************************************************/

void adc_1ms_clock(void)
{
    adc_delay_1ms();
}

/******************************************************************************/

void adc_init(void)
{
    for (uint8_t index = 0; index < ADC_NUMBER_OF_CHANNELS ; index++)
    {
        moving_avg.cacl[index].time_acquisition = ADC_TIME_DELAY_1MS;
    }
}

/******************************************************************************/

void adc_update(void)
{

    // char buff1[50];
    //  char buff0[50];

    // sprintf(buff1,"%d", adc_update_1ms(0));
    // ssd1306_SetCursor(30, 30);
    // ssd1306_WriteString(buff1, Font_7x10, White);

    // sprintf(buff0,"%d", adc_update_1ms(1));
    // ssd1306_SetCursor(10, 10);
    // ssd1306_WriteString(buff0, Font_7x10, White);

    // ssd1306_UpdateScreen();

}

/******************************************************************************/

void adc_deinit(void)
{

}