#include "STD_TYPES"
#include "BIT_MATH"

#include "DIO_interface.h"


void NVIC_Enable_IRQ(u8 Copy_IRQn)
{
	  u8 Local_FunctionStatus = NOT_OK;
    
   if(Copy_IRQn < 32)
    {
        NVIC_ISER0 = (1 << Copy_IRQn);
        Local_FunctionStatus = OK;
    }
    else if (Copy_IRQn < 64)
    {
        NVIC_ISER1 = (1 << (Copy_IRQn - 32));
        Local_FunctionStatus = OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ISER2 = (1 << (Copy_IRQn - 64));
        Local_FunctionStatus = OK;
    }
    else
    {
        Local_FunctionStatus = NOT_OK;
    }
    
    return Local_FunctionStatus;
}

void NVIC_Disable_IRQ(u8 Copy_IRQn)
{
	    u8 Local_FunctionStatus = NOT_OK;

   if(Copy_IRQn < 32)
    {
        NVIC_ICER0 = (1 << Copy_IRQn);
        Local_FunctionStatus = OK;
    }
    else if (Copy_IRQn < 64)
    {
        NVIC_ICER1 = (1 << (Copy_IRQn - 32));
        Local_FunctionStatus = OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ICER2 = (1 << (Copy_IRQn - 64));
        Local_FunctionStatus = OK;
    }
    else
    {
        Local_FunctionStatus = NOT_OK;
    }
    
    return Local_FunctionStatus;
	}

void NVIC_SetPending_IRQ(u8 Copy_IRQn)
{
	u8 Local_FunctionStatus = NOT_OK;

   if(Copy_IRQn < 32)
    {
        NVIC_ISPR0 = (1 << Copy_IRQn);
        Local_FunctionStatus = OK;
    }
    else if (Copy_IRQn < 64)
    {
        NVIC_ISPR1 = (1 << (Copy_IRQn - 32));
        Local_FunctionStatus = OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ISPR2 = (1 << (Copy_IRQn - 64));
        Local_FunctionStatus = OK;
    }
    else
    {
        Local_FunctionStatus = NOT_OK;
    }
    
    return Local_FunctionStatus;

	
	
}

void NVIC_ClearPending_IRQ(u8 Copy_IRQn)
{
	  u8 Local_FunctionStatus = NOT_OK;

    if (Copy_IRQn < 32)
    {
        NVIC_ICPR0 = (1U << Copy_IRQn);
        Local_FunctionStatus = OK;
    }
    else if (Copy_IRQn < 64)
    {
        NVIC_ICPR1 = (1U << (Copy_IRQn - 32));
        Local_FunctionStatus = OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ICPR2 = (1U << (Copy_IRQn - 64));
        Local_FunctionStatus = OK;
    }

    return Local_FunctionStatus;
	
}

u32 NVIC_GetPending_IRQ(u8 Copy_IRQn)
{
	u8 Local_u8Result=0;
	
	if ( Copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber < 64)
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}
	else if (  Copy_u8IntNumber <96 )
	{
		Copy_u8IntNumber -= 64;
		Local_u8Result = GET_BIT(NVIC_IABR2,Copy_u8IntNumber);
	}
	
	else
	{
		/* Return Error */
	}
	
	return Local_u8Result ;
	
	
}

void NVIC_SetPriority_IRQ(u8 Copy_IRQn,u32 Copy_Priority)
{
	u8 Local_FunctionStatus=NOK;
	if(Copy_IRQn < NUMBER_INTERRUPT && Copy_Priority< NVIC_MAX_PRIORITY)
	{
	    /**< Calculate the register index (IPRx) and bit position within the register */ 
        u32 RegisterIndex = Copy_IRQn / 4;     /**< Divide by 4 to get the register index */  
        u32 BitPosition = (Copy_IRQn % 4) * 8; /**< Multiply by 8 to get the bit position */

        /**< Clear the bits that control the priority for the given interrupt */ 
        NVIC_IPR_BASE_ADDRESS[RegisterIndex] &= ~(0xFF << BitPosition);

        /**< Set the priority in the appropriate IPRx register */ 
        NVIC_IPR_BASE_ADDRESS[RegisterIndex] = (Copy_Priority << (BitPosition << 4));
		Local_FunctionStatus=OK;
	}
	else 
	{
		Local_FunctionStatus=NOK;
	}
	
	return Local_FunctionStatus
}


u8 MCAL_NVIC_xGetPriority(u8 Copy_IRQn, u8 *Copy_Priority)
{
    u8 Local_FunctionStatus =NOK;

    if (Copy_IRQn > NUMBER_OF_INTERRUPTS) /**< Check if IRQn is within valid range */
    {
        return Local_FunctionStatus;
    }

    /**< Calculate the register index (IPRx) and bit position within the register */
    u8 RegisterIndex = Copy_IRQn / 4;     /**< Divide by 4 to get the register index */
    u8 BitIndex = (Copy_IRQn % 4);        /**< Remainder of 4 to get the bit index */
    u8 BitPosition = (Copy_IRQn % 4) * 8; /**< Multiply by 8 to get the bit position */

    /**< Pointer arithmetic to access the IPRx register */
    u8 *PriorityRegister = (u8 *)&NVIC_IPR_BASE_ADDRESS[RegisterIndex];

    /**< Extract the priority from the IPRx register */
    *Copy_Priority = (PriorityRegister[BitIndex] >> (BitPosition)) & 0xFF;

    Local_FunctionStatus = OK;

    /**< Return the function status here */
    return Local_FunctionStatus;
}