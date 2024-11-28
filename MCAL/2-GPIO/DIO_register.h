/**********************************************/
/*********************************************/
/**************** Author: Shaaban Oraby  ******/
/*************** Layer: MCAL             ********/
/**************  SWC: GPIO            **********/
/**************  Version : 1.00         **********/

#ifndef   DIO_REGISTER_H_
#define   DIO_REGISTER_H_


#define DIOA_Base_Address      0x40010800      
#define DIOB_Base_Address      0x40010c00
#define DIOC_Base_Address      0x40011000


#define GPIOA_CRL          *((u32*)(DIOA_Base_Address + 0x00))
#define GPIOA_CRH          *((u32*)(DIOA_Base_Address + 0x04))
#define GPIOA_IDR          *((u32*)(DIOA_Base_Address + 0x08))
#define GPIOA_ODR          *((u32*)(DIOA_Base_Address + 0x0c))
#define GPIOA_BSRR         *((u32*)(DIOA_Base_Address + 0x10))
#define GPIOA_BRR          *((u32*)(DIOA_Base_Address + 0x14))
#define GPIOA_LCKR         *((u32*)(DIOA_Base_Address + 0x18))

#define GPIOB_CRL          *((u32*)(DIOB_Base_Address + 0x00))
#define GPIOB_CRH          *((u32*)(DIOB_Base_Address + 0x04))
#define GPIOB_IDR          *((u32*)(DIOB_Base_Address + 0x08))
#define GPIOB_ODR          *((u32*)(DIOB_Base_Address + 0x0c))
#define GPIOB_BSRR         *((u32*)(DIOB_Base_Address + 0x10))
#define GPIOB_BRR          *((u32*)(DIOB_Base_Address + 0x14))
#define GPIOB_LCKR         *((u32*)(DIOB_Base_Address + 0x18))

#define GPIOC_CRL          *((u32*)(DIOC_Base_Address + 0x00))
#define GPIOC_CRH          *((u32*)(DIOC_Base_Address + 0x04))
#define GPIOC_IDR          *((u32*)(DIOC_Base_Address + 0x08))
#define GPIOC_ODR          *((u32*)(DIOC_Base_Address + 0x0c))
#define GPIOC_BSRR         *((u32*)(DIOC_Base_Address + 0x10))
#define GPIOC_BRR          *((u32*)(DIOC_Base_Address + 0x14))
#define GPIOC_LCKR         *((u32*)(DIOC_Base_Address + 0x18))


#endif
