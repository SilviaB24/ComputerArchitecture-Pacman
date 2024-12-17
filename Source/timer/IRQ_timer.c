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
		} else {
			
			//reset_RIT();
			//LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
		}
	}
	
	PacmanCheckPillCollision(pacmanPos);
	
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
	CountdownTime--;
	LCD_UpdateCountDown(CountdownTime);
	
	if(CountdownTime == 0){
		endGame();
		
	}
	
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

extern int zeros[LABYRINTH_HEIGHT * LABYRINTH_WIDTH];  // Array to store the indices of cells with 0

void TIMER2_IRQHandler (void)
{
		static int k = 0; // Tracks the current iteration index
    int index, row, col;

		if (k < NUM_POWER_PILLS) {
					//rand time between 1 and 5
					uint32_t next_interval = rand() % 0x2FAF080; // 0s to 2s in timer ticks
					init_timer(2, next_interval); // Reinitialize Timer 2 with new interval
					int index = zeros[k];
					int row = index / LABYRINTH_WIDTH;
					int col = index % LABYRINTH_WIDTH;
					labyrinthMatrix[row][col] = 3;
					LCD_DrawPowerPill(col*PACMAN_SIZE + 5, row*PACMAN_SIZE + 25, White, pillMatrix);
					k++;
			} else {
					disable_timer(2);
			}

	LPC_TIM2->IR = 1;			/* clear interrupt flag */
  return;
}