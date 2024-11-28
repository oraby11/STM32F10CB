/**********************************************/
/*********************************************/
/**************** Author: Shaaban Oraby  ******/
/*************** Layer: MCAL             ********/
/**************  SWC: RCC            **********/
/**************  Version : 1.00         **********/

#ifndef  RCC_CONFIG_H_
#define  RCC_CONFIG_H_

/*
your options:
RCC_HSI 
RCC_HSE
RCC_PLL
*/
#define RCC_CLOCK_SYSTEM      RCC_HSI

/*
your options:
         RCC_RC_CLK_
         RCC_CRYSTAL_CLK_
*/
#define RCC_HSE         RCC_RC_CLK_

/*
your options:
         RCC_PLL_IN_HSI_DIV_2
         RCC_PLL_IN_HSE_DIV_2
         RCC_PLL_IN_HSE
*/
#define RCC_PLL_INPUT    RCC_PLL_IN_HSI_DIV_2


#endif
