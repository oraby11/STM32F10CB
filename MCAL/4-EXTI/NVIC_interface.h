/**********************************************/
/*********************************************/
/**************** Author: Shaaban Oraby  ******/
/*************** Layer: MCAL             ********/
/**************  SWC: NVIC            **********/
/**************  Version : 1.00         **********/

#ifndef   NVIC_INTERFACE_H_
#define   NVIC_INTERFACE_H_



void NVIC_Enable_IRQ(u8 Copy_IRQn);

void NVIC_Disable_IRQ(u8 Copy_IRQn);

void NVIC_SetPending_IRQ(u8 Copy_IRQn);

void NVIC_ClearPending_IRQ(u8 Copy_IRQn);

u32 NVIC_GetPending_IRQ(u8 Copy_IRQn);

void NVIC_SetPriority_IRQ(u8 Copy_IRQn,u32 Copy_Priority);
u32 NVIC_GetPriority_IRQ(u8 Copy_IRQn);
u8 MCAL_NVIC_xGetPriority(u8 Copy_IRQn, u8 *Copy_Priority)

#endif