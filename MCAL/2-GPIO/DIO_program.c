
/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: SHAAABN ELSAYED        ******************************/
/***************************     Layer:  MCAL                 ******************************/
/***************************     SWC:    DIO                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"



u8 DIO_u8SetPinDirection(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8DIR)
{
	u8 Local_u8ErrorState=NOT_OK;
	switch(Copy_u8PORT)
	{
		case DIO_PORTA:
		 if (Copy_u8PIN<=7)
		 {
			 // Clear the 4 Bits of the wanted Pin [0:15]
			 GPIOA_CRL &=~((0b1111) << (Copy_u8PIN *4));
			 // Set the Value(mode) on the 4 Bits of the wanted Pin [0:15]
			 GPIOA_CRL |=(Copy_u8DIR << (Copy_u8PIN *4));
			 Local_u8ErrorState=OK;
		 }
		 else if (Copy_u8PIN<=15)
		 {
			 Copy_u8PIN-=8;
			 GPIOA_CRH &=~((0b1111) << (Copy_u8PIN *4));
			 GPIOA_CRH |=(Copy_u8DIR << (Copy_u8PIN *4));
			 Local_u8ErrorState=OK; 
		 }
		 else 
		 {
			 Local_u8ErrorState=NOT_OK;
		 }
		break;
		case DIO_PORTB:
		 if (Copy_u8PIN<=7)
		 {
			 GPIOB_CRL &=~((0b1111) << (Copy_u8PIN *4));
			 GPIOB_CRL |=(Copy_u8DIR << (Copy_u8PIN *4));
			 Local_u8ErrorState=OK;
		 }
		 else if (Copy_u8PIN<=15)
		 {
			 Copy_u8PIN-=8;
			 GPIOB_CRH &=~((0b1111) << (Copy_u8PIN *4));
			 GPIOB_CRH |=(Copy_u8DIR << (Copy_u8PIN *4));
			 Local_u8ErrorState=OK; 
		 }
		 else 
		 {
			 Local_u8ErrorState=NOT_OK;
		 }
		break;
		case DIO_PORTC:
	 if (Copy_u8PIN<=7)
		 {
			 GPIOC_CRL &=~((0b1111) << (Copy_u8PIN *4));
			 GPIOC_CRL |=(Copy_u8DIR << (Copy_u8PIN *4));
			 Local_u8ErrorState=OK;
		 }
		 else if (Copy_u8PIN<=15)
		 {
			 Copy_u8PIN-=8;
			 GPIOC_CRH &=~((0b1111) << (Copy_u8PIN *4));
			 GPIOC_CRH |=(Copy_u8DIR << (Copy_u8PIN *4));
			 Local_u8ErrorState=OK; 
		 }
		 else 
		 {
			 Local_u8ErrorState=NOT_OK;
		 }
		break;
		default:
			 Local_u8ErrorState=NOT_OK;		
		break;
		
	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8VALUE)
{
	u8 Local_u8ErrorState=NOT_OK;
	if(Copy_u8VALUE==DIO_HIGH)
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA: 
			        SET_BIT(GPIOA_ODR, Copy_u8PIN);
                    Local_u8ErrorState= OK;
                    break;
			
			case DIO_PORTB:
			        SET_BIT(GPIOB_ODR, Copy_u8PIN);
                    Local_u8ErrorState= OK;
                    break;
			case DIO_PORTC:
					SET_BIT(GPIOC_ODR, Copy_u8PIN);
                    Local_u8ErrorState= OK;
                    break;
			
			default:
			       Local_u8ErrorState=NOT_OK;
			
			break;
		}	
	}
	else if (Copy_u8VALUE==DIO_LOW)
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA: 
			        CLR_BIT(GPIOA_ODR, Copy_u8PIN);
                    Local_u8ErrorState= OK;
                    break;
			
			case DIO_PORTB:
			        CLR_BIT(GPIOB_ODR, Copy_u8PIN);
                    Local_u8ErrorState= OK;
                    break;
			case DIO_PORTC:
					CLR_BIT(GPIOC_ODR, Copy_u8PIN);
                    Local_u8ErrorState= OK;
                    break;
			
			default:
			       Local_u8ErrorState=NOT_OK;
			
			break;
		}
	}
	return Local_u8ErrorState;
}

u8 DIO_Set_Port_Dir(u8 Copy_u8PORT,u8 Copy_u8Position,u8 Copy_u8Mode)
{
	switch(Copy_u8PORT)
	{
		case DIO_PORTA:
		              if(Copy_u8Position==DIO_LOW)
					  {
						   GPIOA_CRL= ( 0x11111111 * Copy_u8Mode ) ;
					  }
					  else if (Copy_u8Position==DIO_HIGH)
					  {
						  GPIOA_CRH=(0x11111111 * Copy_u8Mode ) ;
					  }
					  break;
		case DIO_PORTB:
		              if(Copy_u8Position==DIO_LOW)
					  {
						   GPIOB_CRL= ( 0x11111111 * Copy_u8Mode ) ;
					  }
					  else if (Copy_u8Position==DIO_HIGH)
					  {
						  GPIOB_CRH=(0x11111111 * Copy_u8Mode ) ;
					  }
					  break;
		case DIO_PORTC:
		              if(Copy_u8Position==DIO_LOW)
					  {
						   GPIOCCRL= ( 0x11111111 * Copy_u8Mode ) ;
					  }
					  else if (Copy_u8Position==DIO_HIGH)
					  {
						  GPIOC_CRH=(0x11111111 * Copy_u8Mode ) ;
					  }
					  break;
	}
}

u8 DIO_Set_Port_Dir(u8 Copy_u8PORT,u8 Copy_u8Positionu8,u16 Copy_u8VALUE)
{
	switch( Copy_u8Port ){

	case DIOA:

		if      ( Copy_u8Position == DIO_LOW  ){ DIOA_ODR = (DIOA_ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == DIO_HIGH ){ DIOA_ODR = (DIOA_ODR & 0x00FF ) | (     Copy_u8Value ) ; }

		break;
	case DIOB:

		if      ( Copy_u8Position == DIO_LOW  ){ DIOB_ODR = (DIOB_ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == DIO_HIGH ){ DIOB_ODR = (DIOB_ODR & 0x00FF ) | (     Copy_u8Value ) ; }

		break;
	case DIOC:

		if      ( Copy_u8Position == DIO_LOW  ){ DIOC_ODR = (DIOC_ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == DIO_HIGH ){ DIOC_ODR = (DIOC_ODR & 0x00FF ) | (     Copy_u8Value ) ; }

		break;
	default :break;

	}
	
	
}

u8 DIO_GET_PIN(u8 Copy_u8PORT,u8 Copy_u8PIN,u8* Copy_pu8Value)
{
	u8 Local_u8ErrorState=NOT_OK;
	if(Copy_pu8Value!=NULL && Copy_u8PIN<=15)
	{
	switch(Copy_u8PORT)
	{
		case DIO_PORTA:
		          *Copy_pu8Value= GET_BIT(GPIOA_IDR,Copy_u8PIN);
				   Local_u8ErrorState=OK;
				   break;
		case DIO_PORTC:
		          *Copy_pu8Value= GET_BIT(GPIOB_IDR,Copy_u8PIN);
				   Local_u8ErrorState=OK;
				   break;
        case DIO_PORTC:
		          *Copy_pu8Value= GET_BIT(GPIOC_IDR,Copy_u8PIN);
				   Local_u8ErrorState=OK;	
				   break;
		default: Local_u8ErrorState=NOT_OK;break;
	}	
	}
	else 
	{
		Local_u8ErrorState=NOT_OK;
	}
	return Local_u8ErrorState;
}