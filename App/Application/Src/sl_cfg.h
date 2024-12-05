#ifndef __SL_CFG_H__
#define __SL_CFG_H__

/******************************************************************************/

#define SL_NUMBER_OF_TASKS                          3

/******************************************************************************/

#define sl_tasks_data_vector_default_value                \
{                                                         \
  {/*00-hmi */                                            \
    hmi_1ms_clock,                   SL_STATUS_ENABLED,   \
    hmi_init,                        SL_STATUS_ENABLED,   \
    hmi_update,                      SL_STATUS_ENABLED,   \
    hmi_deinit,                      SL_STATUS_ENABLED,   \
    hmi_pexecution_rate_1ms_timer,                        \
    HMI_EXECUTION_RATE_1MS_TIME,                          \
    SL_STATUS_ENABLED                                     \
  }                                                       \
  ,                                                       \
  {/*01-enc */                                            \
    encoder_1ms_clock,               SL_STATUS_ENABLED,   \
    encoder_init,                    SL_STATUS_ENABLED,   \
    encoder_update,                  SL_STATUS_ENABLED,   \
    encoder_deinit,                  SL_STATUS_ENABLED,   \
    encoder_pexecution_rate_1ms_timer,                    \
    ENCODER_EXECUTION_RATE_1MS_TIME,                      \
    SL_STATUS_ENABLED                                     \
  }                                                       \
  ,                                                       \
  {/*02-adc */                                            \
    adc_1ms_clock,               SL_STATUS_ENABLED,       \
    adc_init,                    SL_STATUS_ENABLED,       \
    adc_update,                  SL_STATUS_ENABLED,       \
    adc_deinit,                  SL_STATUS_ENABLED,       \
    adc_pexecution_rate_1ms_timer,                        \
    ADC_EXECUTION_RATE_1MS_TIME,                          \
    SL_STATUS_ENABLED                                     \
  }                                                       \
}

/******************************************************************************/

#include "stdlib.h"
// #include "adc1.h"
// #include "wdt.h"
// #include "mb.h"
// #include "tmp.h"
// #include "din.h"
#include "adc.h"
#include "encoder.h"
#include "hmi.h"
//#include "wlog.h"

/******************************************************************************/

#endif/*__SL_CFG_H__*/
