/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "RIT.h"
#include "GameControl//PacmanMovements.h"

/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

extern unsigned char currState;  // Declare variables defined in main.c
extern unsigned char taps;
extern int outputBit;
extern Position PacmanPos;
extern Direction PacmanDir;

void RIT_IRQHandler (void)
{			
	static int up=0, lx=0, dw=0, rx=0;
	static int position=0;	
	static Direction oldDirection = NONE;
	Direction newDirection;
	
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){	
		/* Joytick LEFT pressed */
		lx++;
		switch(lx){
			case 1:
				newDirection = LEFT;
				if (newDirection != PacmanDir){
					// pacman rotation
					PacmanDir = newDirection;
				}
			default:
				break;
		}
	}
	else{
			lx=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<29)) == 0){	
		/* Joytick UP pressed */
		up++;
		switch(up){
			case 1:
				newDirection = UP;
				if (newDirection != PacmanDir){
					PacmanRotate(&PacmanPos, newDirection, PacmanDir);
					PacmanDir = newDirection;
				}
			default:
				break;
		}
	}
	else{
			up=0;
	}
	
	PacmanMove(&PacmanPos, PacmanDir);
	
	reset_RIT();
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
