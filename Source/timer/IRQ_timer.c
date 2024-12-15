/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include <string.h>
#include "LPC17xx.h"
#include "timer.h"
#include "../GLCD/GLCD.h" 
#include "../TouchPanel/TouchPanel.h"
#include <stdio.h> /*for sprintf*/
#include "GameControl//PacmanMovements.h"

/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

extern Direction newDirection;

void TIMER0_IRQHandler (void)
{
	if (newDirection != NONE){
		if (!PacmanCheckWallCollision(&pacmanPos, newDirection, 1)){
			if (newDirection != pacmanDir){
				PacmanRotate(&pacmanPos, newDirection);
				pacmanDir = newDirection;
			}
			PacmanMove(&pacmanPos, pacmanDir);
		} else if (!PacmanCheckWallCollision(&pacmanPos, pacmanDir, 0)){
			PacmanMove(&pacmanPos, pacmanDir);
		}
	}
	
  LPC_TIM0->IR = 1;			/* clear interrupt flag */
  return;
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER1_IRQHandler (void)
{
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
