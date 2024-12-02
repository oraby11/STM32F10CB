/**********************************************/
/*********************************************/
/**************** Author: Shaaban Oraby  ******/
/*************** Layer: MCAL             ********/
/**************  SWC: NVIC            **********/
/**************  Version : 1.00         **********/

#ifndef   NVIC_CONFIG_H_
#define   NVIC_CONFIG_H_

 /* NVIC_16GROUP_0SUB:  16 subgroups with 0 bits for sub-priority.
 *     - Group Priority Range: 0 to 15
 *     - Sub-Priority Range: NVIC_INVALID_PRIORITY
 * - NVIC_8GROUP_2SUB :  8 subgroups with 2 bits for sub-priority.
 *     - Group Priority Range: 0 to 7
 *     - Sub-Priority Range: 0 to 1
 * - NVIC_4GROUP_4SUB :  4 subgroups with 4 bits for sub-priority.
 *     - Group Priority Range: 0 to 3
 *     - Sub-Priority Range: 0 to 3
 * - NVIC_2GROUP_8SUB :  2 subgroups with 8 bits for sub-priority.
 *     - Group Priority Range: 0 to 1
 *     - Sub-Priority Range: 0 to 7
 * - NVIC_0GROUP_16SUB:  No grouping with 16 bits for sub-priority.
 *     - Group Priority Range: NVIC_INVALID_PRIORITY
 *     - Sub-Priority Range: 0 to 15*/
 
#define PRIORITY_GROUPING   NVIC_4GROUP_4SUB

#define NUMBER_INTERRUPT      67

#define NVIC_MAX_PRIORITY     15


#endif
