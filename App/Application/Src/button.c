#include "sl.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "button.h"
#include "button_cfg.h"
#include "stdio.h"

/******************************************************************************/

volatile uint32_t button_execution_rate_1ms_timer;



/******************************************************************************/

// void button_update_state(button_data_t *button_event)
// {



//     if(button_encoder_update.state == RESET && button_encoder_update.state_previous == SET && button_encoder_update.state_long_press == RESET)
//     {
//         button_encoder_update.long_press_tick = button_encoder_update.current_tick;
//         button_encoder_update.state_previous = RESET;
//         //*state = BUTTON_STOPED;
//     }
//     button_encoder_update.press_duration = button_encoder_update.current_tick - button_encoder_update.long_press_tick;
//     if(button_encoder_update.state == RESET && button_encoder_update.state_long_press == RESET && button_encoder_update.press_duration >= TIME_LONG_PRESS)
//     {
//         // update_state = BUTTON_LONG_PRESS;
//     }
//     if(button_encoder_update.state == RESET && button_encoder_update.state_previous == RESET)
//     {
//         button_encoder_update.state_previous    = SET;
//         button_encoder_update.state_long_press  = RESET;;
//         if(button_encoder_update.press_duration < TIME_LONG_PRESS)
//         {
//             // update_state = BUTTON_SHORT_PRESS;
//         }
//         button_encoder_update.previous_tick = button_encoder_update.current_tick;  
//     }
  
// }









void button_update_state(button_data_t *button_event)
{
    GPIO_PinState pin_state = HAL_GPIO_ReadPin(button_event->cfg.GPIO, button_event->cfg.pin);
    uint32_t current_time = HAL_GetTick();

    if(button_event->state == BUTTON_STATE_START)
    {
        if(pin_state == GPIO_PIN_RESET)
        {
           button_event->state =  BUTTON_STATE_PRESSED;
           button_event->start_time = current_time;

            if(button_event->button_handler)
            {
                button_event->button_handler(button_event->id, BUTTON_SHORT_PRESS);
            }
        }
    }
    if(button_event->state ==  BUTTON_STATE_PRESSED)
    {
        if(pin_state == GPIO_PIN_RESET)
        {
            if(current_time > (button_event->start_time + 800))
            {
            if(button_event->button_handler)
                {
                    button_event->button_handler(button_event->id, BUTTON_LONG_PRESS);
                }
                button_event->state = BUTTON_STATE_WAITRELEASE;
            }
        }
        else
        {
            button_event->state = BUTTON_STATE_START;              
        }
    }
    if(button_event->state == BUTTON_STATE_WAITRELEASE )
    {
        button_event->state = BUTTON_STATE_START;
    }
}

/******************************************************************************/

void button_1ms_clock(void)
{
    
}

/******************************************************************************/

void button_init(void)
{


}   

/******************************************************************************/

void button_update(void)
{
        for (size_t i = 0; i < 4; i++)
        {
           // button_update_state(&buttons[i]);
        }
}

/******************************************************************************/

void button_deinit(void)
{

}