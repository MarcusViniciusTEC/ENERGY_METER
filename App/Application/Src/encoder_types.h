#ifndef __ENCODER_TYPES_H__
#define __ENCODER_TYPES_H__


#include "encoder_cfg.h"

typedef enum
{
    ENCODER_TUNR_LEFT = 0U,
    ENCODER_TURN_RIGHT,
    ENCODER_STOPED
}encoder_state_t;

typedef enum
{
    BUTTON_SHORT_PRESS = 1,
    BUTTON_LONG_PRESS,
    BUTTON_STOPED
}button_press_type_t;

typedef struct 
{
    encoder_state_t encoder;
    button_press_type_t button;
    uint16_t value;
}encoder_event_t;


typedef struct
{
    uint16_t add;
    uint16_t state;
    uint16_t last_state;
}rotary_encoder_update_t;

typedef struct 
{
    FlagStatus  state;
    FlagStatus  state_long_press;
    FlagStatus  state_previous;
    uint32_t    current_tick;
    uint32_t    previous_tick;
    uint32_t    long_press_tick;
    uint32_t    press_duration;
}button_encoder_update_t;




#endif