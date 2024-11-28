/**********************************************/
/*********************************************/
/**************** Author: Shaaban Oraby  ******/
/*************** Layer: MCAL             ********/
/**************  SWC: RCC            **********/
/**************  Version : 1.00         **********/

#ifndef   RCC_PRIVTE_H_
#define   RCC_PRIVTE_H_

#define RCC_HSI    0
#define RCC_HSE    1
#define RCC_PLL    2



#define RCC_BASE_ADDRESS   (*(volatile u32 *)0x40021000)

#define RCC_CR            (*(volatile u32 *)(0x40021000+0x00))
#define RCC_CFGR          (*(volatile u32 *)0x40021000+0x04)
#define RCC_CIR           (*(volatile u32 *)0x40021000+0x08)
#define RCC_APB2RSTR      (*(volatile u32 *)0x40021000+0x0c)
#define RCC_APB1RSTR      (*(volatile u32 *)0x40021000+0x10)
#define RCC_AHBENR        (*(volatile u32 *)0x40021000+0x14)
#define RCC_APB2ENR       (*(volatile u32 *)0x40021000+0x18)
#define RCC_APB1ENR       (*(volatile u32 *)0x40021000+0x1c)
#define RCC_BDCR          (*(volatile u32 *)0x40021000+0x20)
#define RCC_CSR           (*(volatile u32 *)0x40021000+0x24)
 
#define RCC_CR_HSION       0            //type of RCC HSI
#define RCC_CR_HSIRD       1            //falg  of RCC HSI
#define RCC_CR_HSEON      16            //type of RCC HSE
#define RCC_CR_HSERDY      17            //check if stable 
#define RCC_CR_CSSON       19           //clock security enable
#define RCC_CR_HSEBYP      18          //in HSE if choose 0: RC  or  1:Crystal  
#define RCC_CR_PLLON       24            // PLL enable
#define RCC_CR_PLLRDY      25           //falg  of  PLL 

#define RCC_CFGR_MCO1      26           //clock output {HSI - HSE - PLL - SYSCLK - NO CLOCK}
#define RCC_CFGR_MCO1      25
#define RCC_CFGR_MCO1      24

#define RCC_CFGR_PLLMUL    21         //multiplication factor 
#define RCC_CFGR_PLLMUL    20
#define RCC_CFGR_PLLMUL    19
#define RCC_CFGR_PLLMUL    18      


#define RCC_CFGR_ADCPRE   15    //ADC prascalar 
#define RCC_CFGR_ADCPRE   14

#define RCC_CFGR_PPRE2_1    11     //APB presaclar  APB2
#define RCC_CFGR_PPRE2_2    12
#define RCC_CFGR_PPRE2_3    13


#define RCC_CFGR_PPRE1_1    10     //APB presaclar  APB1
#define RCC_CFGR_PPRE1_2    9
#define RCC_CFGR_PPRE1_3    8

#define RCC_CFGR_HPRE_1     7    //AHB prescaler
#define RCC_CFGR_HPRE_2    6
#define RCC_CFGR_HPRE_3    5
#define RCC_CFGR_HPRE_4     4


#define RCC_CFGR_SWS_1      4       //system clock switch  staus
#define RCC_CFGR_SWS_2     3 
#define RCC_CFGR_SW_1    1        //system clock switch 
#define RCC_CFGR_SW_2    0




      
#endif
