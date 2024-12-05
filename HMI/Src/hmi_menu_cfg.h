

#ifndef HMI_MENU_CFG_H_
#define HMI_MENU_CFG_H_


#include "hmi_menu.h"

#define CURSOR_ITEM_MENU ">"
#define HMI_MENU_NUMBER_OF_ITENS_VISIBLE    6
#define HMI_MENU_OF_ITENS                   12

#define hmi_menu_item_vector_value              \
{                                               \
    {                                           \ 
        .id = HMI_MenuItem_ID_Voltage,          \
        .sz_description = "VOLTAGE"             \
    }                                           \
    ,                                           \
    {                                           \ 
        .id = HMI_MenuItem_ID_Current,          \
        .sz_description = "CURRENT"             \
    }                                           \
    ,                                           \
    {                                           \ 
        .id = HMI_MenuItem_ID_Piezo_1,          \
        .sz_description = "PIEZO 1"             \
    }                                           \
    ,                                           \    
    {                                           \ 
        .id = HMI_MenuItem_ID_Piezo_2,          \
        .sz_description = "PIEZO 2"             \
    }                                           \
    ,                                           \    
    {                                           \ 
        .id = HMI_MenuItem_ID_Piezo_3,          \
        .sz_description = "PIEZO 3"             \
    }                                           \
    ,                                           \    
    {                                           \ 
        .id = HMI_MenuItem_ID_Piezo_4,          \
        .sz_description = "PIEZO 4"             \
    }                                           \
    ,                                           \    
    {                                           \ 
        .id = HMI_MenuItem_ID_Piezo_5,          \
        .sz_description = "PIEZO 5"             \
    }                                           \
    ,                                           \    
    {                                           \ 
        .id = HMI_MenuItem_ID_Piezo_6,          \
        .sz_description = "PIEZO 6",            \
    }                                           \
    ,                                           \    
    {                                           \ 
        .id = HMI_MenuItem_ID_Piezo_7 ,         \
        .sz_description = "PIEZO 7"             \
    }                                           \
    ,                                           \    
    {                                           \ 
        .id = HMI_MenuItem_ID_Piezo_8,          \
        .sz_description = "PIEZO 8"             \
    }                                           \
    ,                                           \    
    {                                           \ 
        .id = HMI_MenuItem_ID_Piezo_9,         \
        .sz_description = "PIEZO 9"             \
    }                                           \
    ,                                           \    
    {                                           \ 
        .id = HMI_MenuItem_ID_Settings,         \
        .sz_description = "SETTINGS"            \
    }                                           \
}                               


#endif