/**********************************************/
/*********************************************/
/**************** Author: Shaaban Oraby  ******/
/*************** Layer: MCAL             ********/
/**************  SWC: RCC            **********/
/**************  Version : 1.00         **********/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInit(void )
{
      #if RCC_CLOCK_SYSTEM==HSE
	        /**< Enable the external clock to be the source for the system clock. */
	        #if RCC_CLK_BYPASS == RCC_RC_CLK_
	            SET_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose RC as a SYSCLK */
	        #elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK_
	            CLR_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose CRYSTAL as a SYSCLK */
	        #else
	            #error "Wrong Choice !!"
	        #endif /**< RCC_CLK_BYPASS */

	        /**< Enable the High-Speed External clock. */
	        SET_BIT(RCC_CR, RCC_CR_HSEON);

	        /**< Wait until the High-Speed External clock is stable. */
	        while(!GET_BIT(RCC_CR, RCC_CR_HSERDY));

	        /**< Select High-Speed External clock as the system clock source. */
	        RCC_CFGR = 0x00000001;
     #elif   RCC_CLOCK_SYSTEM==HSI
	        /**< Enable the High-Speed Internal clock. */
	               SET_BIT(RCC_CR, RCC_CR_HSION);

	               /**< Wait until the High-Speed Internal clock is stable. */
	               while(!GET_BIT(RCC_CR, RCC_CR_HSIRDY));

	               /**< Select High-Speed Internal clock as the system clock source. */
	               RCC_CFGR = 0x00000000;
    #elif RCC_CLOCK_SYSTEM==PLL

                 #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2

		         #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2

		         #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE

				 #endif
    #else
               #error "Wrong Choice !!"
    #endif

}

void RCC_voidEnable(u8 Copy_BusId,u8 Copy_PeripheralId)
{
	u8 Local_FunctionStatus=OK;
	 switch(Copy_BusId)
	    {
	        /**< Enable the peripheral on the AHB bus. */
	        case RCC_AHB:
	            SET_BIT(RCC_AHBENR, Copy_PeripheralId);
	            Local_FunctionStatus = OK;
	            break;

	        /**< Enable the peripheral on the APB1 bus. */
	        case RCC_APB1:
	            SET_BIT(RCC_APB1ENR, Copy_PeripheralId);
	            Local_FunctionStatus = OK;
	            break;

	        /**< Enable the peripheral on the APB2 bus. */
	        case RCC_APB2:
	            SET_BIT(RCC_APB2ENR, Copy_PeripheralId);
	            Local_FunctionStatus = OK;
	            break;

	        default:
	            Local_FunctionStatus = NOT_OK;
	            break;
	    }

	 return Local_FunctionStatus;
}

void RCC_voidDisable(u8 Copy_BusId,u8 Copy_PeripheralId)
{

	u8 Local_FunctionStatus=OK;
	 switch(Copy_BusId)
	    {
	        /**< Enable the peripheral on the AHB bus. */
	        case RCC_AHB:
	            CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
	            Local_FunctionStatus = OK;
	            break;

	        /**< Enable the peripheral on the APB1 bus. */
	        case RCC_APB1:
	            CLR_BIT(RCC_APB1ENR, Copy_PeripheralId);
	            Local_FunctionStatus = OK;
	            break;

	        /**< Enable the peripheral on the APB2 bus. */
	        case RCC_APB2:
	            CLR_BIT(RCC_APB2ENR, Copy_PeripheralId);
	            Local_FunctionStatus = OK;
	            break;

	        default:
	            Local_FunctionStatus = NOT_OK;
	            break;
	    }

	 return Local_FunctionStatus;
}




