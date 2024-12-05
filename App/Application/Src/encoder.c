#include "sl.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "encoder.h"
#include "encoder_cfg.h"
#include "stdio.h"

/******************************************************************************/

volatile uint32_t encoder_execution_rate_1ms_timer;

/******************************************************************************/

static encoder_event_t *encoder_event;
static rotary_encoder_update_t rotary_encoder_update;
static button_encoder_update_t button_encoder_update;

/******************************************************************************/



void encoder_update_1ms_clock(void)
{
  // rotary_encoder_update.state = ((TIM2 -> CNT) >> 2);
   //button_encoder_update.state = HAL_GPIO_ReadPin(ENC_BT_GPIO_Port, ENC_BT_Pin);
   button_encoder_update.current_tick = HAL_GetTick();
}

/******************************************************************************/

void rotary_encoder(uint16_t *value)
{
    rotary_encoder_update.add = *value;
    if(rotary_encoder_update.state > rotary_encoder_update.last_state)
    {
        rotary_encoder_update.add +=1;
        rotary_encoder_update.last_state = rotary_encoder_update.state;
    }
    else if(rotary_encoder_update.state < rotary_encoder_update.last_state)
    {
        rotary_encoder_update.add -=1;
        rotary_encoder_update.last_state = rotary_encoder_update.state;
    }
    *value = rotary_encoder_update.add;
}

/******************************************************************************/

void button_encoder(uint8_t *state)
{
    uint8_t update_state = *state;
    if(button_encoder_update.state == RESET && button_encoder_update.state_previous == SET && button_encoder_update.state_long_press == RESET)
    {
        button_encoder_update.long_press_tick = button_encoder_update.current_tick;
        button_encoder_update.state_previous = RESET;
        //*state = BUTTON_STOPED;
    }
    button_encoder_update.press_duration = button_encoder_update.current_tick - button_encoder_update.long_press_tick;
    if(button_encoder_update.state == RESET && button_encoder_update.state_long_press == RESET && button_encoder_update.press_duration >= TIME_LONG_PRESS)
    {
        update_state = BUTTON_LONG_PRESS;
    }
    if(button_encoder_update.state == RESET && button_encoder_update.state_previous == RESET)
    {
        button_encoder_update.state_previous    = SET;
        button_encoder_update.state_long_press  = RESET;;
        if(button_encoder_update.press_duration < TIME_LONG_PRESS)
        {
            update_state = BUTTON_SHORT_PRESS;
        }
        button_encoder_update.previous_tick = button_encoder_update.current_tick;  
    }
    *state = update_state;
}

/******************************************************************************/

void encoder_1ms_clock(void)
{
    encoder_update_1ms_clock();
}

/******************************************************************************/

void encoder_init(void)
{
    rotary_encoder_update.state             = ENCODER_DEFAULT_VALUE;
    rotary_encoder_update.last_state        = ENCODER_DEFAULT_VALUE;
    rotary_encoder_update.add               = ENCODER_DEFAULT_VALUE;
    encoder_event->value                    = ENCODER_DEFAULT_VALUE;
    TIM2 -> CNT                             = ENCODER_DEFAULT_VALUE;

    //button_encoder_update.state             = SET;
    button_encoder_update.state_previous    = SET;
    button_encoder_update.state_long_press  = RESET;
    button_encoder_update.previous_tick     = ENCODER_DEFAULT_VALUE;
    button_encoder_update.long_press_tick   = ENCODER_DEFAULT_VALUE;
    button_encoder_update.press_duration    = ENCODER_DEFAULT_VALUE;
    button_encoder_update.current_tick      = ENCODER_DEFAULT_VALUE;

}   

/******************************************************************************/

void encoder_update(void)
{
    
}

/******************************************************************************/

void encoder_deinit(void)
{

}