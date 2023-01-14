/*
 * APP.h
 *
 *  Created on: Jan 4, 2023
 *      Author: Dell
 */
#include"../COMMON/Bit_wise.h"
#include"../COMMON/STD_Types.h"
#include"../MCAL/DIO/DIO_Header/DIO_Interface.h"
#include"../HAL/Keypad/Keypad_interface.h"
#include"../HAL/LCD/CLCD_Interface.h"
#include<util/delay.h>

#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

void Calculator_Init(void);

void Calculator_start(void);

void Application_start(void);


u16 Sum_Operation(u8 No_1[],u8 No_2[],u8 Counter_1,u8 Counter_2);
u16 Sub_Operation(u8 No_1[],u8 No_2[],u8 Counter_1,u8 Counter_2);
u16 Multiply_Operation(u8 No_1[],u8 No_2[],u8 Counter_1,u8 Counter_2);
u16 Division_Operation(u8 No_1[],u8 No_2[],u8 Counter_1,u8 Counter_2);

#endif /* APPLICATION_APP_H_ */
