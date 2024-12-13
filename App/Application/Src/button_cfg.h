#ifndef __BUTTON_CFG_H__
#define __BUTTON_CFG_H__

#include "main.h"


#define ENCODER_DEFAULT_VALUE   0

#define TIME_LONG_PRESS         800      


#define button_vector_default       \
{                                   \
    {                               \
        .GPIO = BT_UP_GPIO_Port,    \
        .pin  = BT_UP_Pin           \
    }                               \
    ,                               \
    {                               \
        .GPIO = BT_DOWN_GPIO_Port,  \
        .pin  = BT_DOWN_Pin         \
    }                               \
    ,                               \
    {                               \
        .GPIO = BT_LEFT_GPIO_Port,  \
        .pin  = BT_LEFT_Pin         \
    }                               \
    ,                               \
    {                               \
        .GPIO = BT_RIGHT_GPIO_Port, \
        .pin  = BT_RIGHT_Pin        \
    }                               \
}                                       
                          

#endif