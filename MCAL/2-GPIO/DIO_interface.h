/**********************************************/
/*********************************************/
/**************** Author: Shaaban Oraby  ******/
/*************** Layer: MCAL             ********/
/**************  SWC: GPIO            **********/
/**************  Version : 1.00         **********/

#ifndef   DIO_INTERFACE_H_
#define   DIO_INTERFACE_H_

#define DIO_LOW     0
#define DIO_HIGH    1


#define DIO_PORTA     0
#define DIO_PORTB     1
#define DIO_PORTC     2

#define DIO_PIN0     0
#define DIO_PIN1     1
#define DIO_PIN2     2
#define DIO_PIN3     3
#define DIO_PIN4     4
#define DIO_PIN5     5
#define DIO_PIN6     6
#define DIO_PIN7     7
#define DIO_PIN8     8
#define DIO_PIN9     9
#define DIO_PIN10     10
#define DIO_PIN11    11
#define DIO_PIN12    12
#define DIO_PIN13    13
#define DIO_PIN14    14
#define DIO_PIN15    15


#define DIO_INPUT_ANALOG               0b0000
#define DIO_INPUT_FLOATING             0b0100
#define DIO_INPUT_PULLUP               0b1000         //set value LOW
#define DIO_INPUT_PULLDOWN             0b1000         //set value HIGH

#define DIO_OUTPUT_10MHZ_PUSH_PULL         0b0001
#define DIO_OUTPUT_10MHZ_OPEN_DRAIN        0b0101
#define DIO_OUTPUT_10MHZ_ALT_PUSH_PULL     0b1001
#define DIO_OUTPUT_10MHZ_ALT_OPEN_DRAIN    0b1101


#define DIO_OUTPUT_2MHZ_PUSH_PULL         0b0010
#define DIO_OUTPUT_2MHZ_OPEN_DRAIN        0b0110
#define DIO_OUTPUT_2MHZ_ALT_PUSH_PULL     0b1010
#define DIO_OUTPUT_2MHZ_ALT_OPEN_DRAIN    0b1110

#define DIO_OUTPUT_50MHZ_PUSH_PULL        0b0011
#define DIO_OUTPUT_50MHZ_OPEN_DRAIN       0b0111
#define DIO_OUTPUT_50MHZ_ALT_PUSH_PULL    0b1011
#define DIO_OUTPUT_50MHZ_ALT_OPEN_DRAIN   0b1111
 

u8 DIO_u8SetPinDirection(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8DIR);

u8 DIO_u8SetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8VALUE);

u8 DIO_Set_Port_Dir(u8 Copy_u8PORT,u8 Copy_u8Position,u8 Copy_u8Mode);

u8 DIO_Set_Port_Dir(u8 Copy_u8PORT,u8 Copy_u8Positionu8, u16 Copy_u8VALUE);

u8 DIO_GET_PIN(u8 Copy_u8PORT,u8 Copy_u8PIN,u8* Copy_pu8Value);


#endif

