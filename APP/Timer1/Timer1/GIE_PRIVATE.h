/****************************************************************/
/*   Author             :    Abdelrahman Magdy				    */
/*	 Date 				:    25 February 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   GIE Private contain the memory 
                            mapping of SREG                   	*/
/****************************************************************/



/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/


#ifndef _GIE_PRIVATE_H
#define _GIE_PRIVATE_H


/****************************************************************/	
/**            From Data Sheet :  Memory mapped of SREG   	    */
/**			   Register	is  0X5F.								*/
/****************************************************************/
/**			   SREG : Status Register               			*/
/****************************************************************/

#define SREG     *((volatile u8 * ) (0X5F))

/* Bit Number Seven in SREG */

#define GIE_BIT   7    



#endif /* End of the file guard*/