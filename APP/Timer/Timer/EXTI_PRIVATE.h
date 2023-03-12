/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    25 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   EXTI Private contain the memory 
                            mapping of [MCUCR,MCUCSR,GICR,GIFR] 
							  [ EXTI ] -> External Interrupts   */
/****************************************************************/


/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef  _EXTI_PRIVATE_H
#define  _EXTI_PRIVATE_H

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of MCUCR    	*/
/**			   Register	is  0X55						    	*/
/****************************************************************/
/**			   MCUCR : MCU Control Register contains control	*/
/** 		   bits for interrupt sense control and general 	*/
/**            MCU functions.							    	*/
/****************************************************************/

#define MCUCR		*((volatile u8 * ) (0X55))

/* MACROS for the bits of MCUCR to indentify the bits 
                 & avoid MAGIC NUMBERS                     */

#define SE         7
#define SM2        6 
#define SM1        5
#define SM0        4 
#define ISC11      3
#define ISC10      2
#define ISC01      1
#define ISC00      0 

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of MCUCSR   	*/
/**			   Register	is  0X54.								*/
/****************************************************************/
/**			   MCUCSR : MCU Control and Status Register			*/
/****************************************************************/

#define MCUCSR      *((volatile u8 * ) (0X54))

/* MACROS for the bits of MCUCSR to indentify the bits 
                 & avoid MAGIC NUMBERS                     */
				 
#define JTD    7
#define ISC2   6
#define JTRF   4
#define WDRF   3
#define BORF   2
#define EXTRF  1
#define PORF   0

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of GICR     	*/
/**			   Register	is  0X5B.								*/
/****************************************************************/
/**			   GICR : General Interrupt Control Register		*/
/****************************************************************/

#define GICR        *((volatile u8 * ) (0X5B))

/* MACROS for the bits of GICR to indentify the bits 
                 & avoid MAGIC NUMBERS                     */

#define INT1     7
#define INT0     6
#define INT2     5
#define IVSEL    1
#define IVCE     0

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of GIFR     	*/
/**			   Register	is  0X5A.						    	*/
/****************************************************************/
/**			   GIFR : General Interrupt Flag Register			*/
/****************************************************************/

#define GIFR        *((volatile u8 * ) (0X5A))

/* MACROS for the bits of GIFR to indentify the bits 
                 & avoid MAGIC NUMBERS                     */
				 
#define INTF1    7
#define INTF0    6
#define INTF2    5


#endif /* End of the file guard*/
