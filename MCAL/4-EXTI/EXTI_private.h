/**********************************************/
/*********************************************/
/**************** Author: Shaaban Oraby  ******/
/*************** Layer: MCAL             ********/
/**************  SWC: NVIC            **********/
/**************  Version : 1.00         **********/

#ifndef   EXTI_PRIVATE_H_
#define   EXTI_PRIVATE_H_


#define EXTI_BASE_ADDRESS    0x40010400U

/**< EXTI register structure */
typedef struct 
{
    volatile u32 IMR;   /**< Interrupt Mask Register */
    volatile u32 EMR;   /**< Event Mask Register */
    volatile u32 RTSR;  /**< Rising Trigger Selection Register */
    volatile u32 FTSR;  /**< Falling Trigger Selection Register */
    volatile u32 SWIER; /**< Software Interrupt Event Register */
    volatile u32 PR;    /**< Pending Register */
} EXTI_RegDef_t;

/**< Pointer to EXTI register structure */
#define EXTI   ((EXTI_RegDef_t *)EXTI_BASE_ADDRESS)

/**< Total number of EXTI lines available */
#define EXTI_LINES_COUNT        16

/**< EXTI line enabled */
#define EXTI_LINE_ENABLED       1

/**< EXTI line disabled */
#define EXTI_LINE_DISABLED      0






#endif
