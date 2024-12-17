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
extern Position pacmanPos;
extern Direction pacmanDir;
Direction newDirection = NONE;
int pause = 0;
int down=0;
void RIT_IRQHandler (void)
{			
	static int up=0, lx=0, dw=0, rx=0;
	static int position=0;	
	
	//pause button

	
	
	if(down != 0){
		if((LPC_GPIO2->FIOPIN & (1<<10)) == 0){
			static uint8_t position=0;
			reset_RIT();
			switch(down){
				case 1:
					if(pause == 0){
						
						LCD_DrawLabyrinth(5, 25, Blue, 10, 11, 15);
						LCD_DrawPacman(pacmanPos, Yellow, *pacmanMatrix);
						
						enable_timer(0);
						enable_timer(1);
						enable_timer(2);
					
						pause = 1;
					} else{
						LCD_SetFilledRect(5, 135, White, 230, 50);
						LCD_SetFilledRect(10, 140, Black, 220, 40);
						GUI_Text(100, 155, (uint8_t *) "PAUSE", Yellow, Black);
					
						disable_timer(0);
						disable_timer(1);
						disable_timer(2);
						
						pause = 0;
						
					}
				
					break;
				default:
					break;
			}
			down++;
		}
		else {	/* button released */
			down=0;
			NVIC_EnableIRQ(EINT0_IRQn);							 /* disable Button interrupts			*/
			LPC_PINCON->PINSEL4    |= (1 << 20);     /* External interrupt 0 pin selection */
		}
	}
	if((LPC_GPIO1->FIOPIN & (1<<26)) == 0){	
		/* Joytick DOWN pressed */
		dw++;
		switch(dw){
			case 1:
				newDirection = DOWN;
			default:
				break;
		}
	}
	else{
			dw=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){	
		/* Joytick LEFT pressed */
		lx++;
		switch(lx){
			case 1:
				newDirection = LEFT;
			default:
				break;
		}
	}
	else{
			lx=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){	
		/* Joytick RIGHT pressed */
		rx++;
		switch(rx){
			case 1:
				newDirection = RIGHT;
			default:
				break;
		}
	}
	else{
			rx=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<29)) == 0){	
		/* Joytick UP pressed */
		up++;
		switch(up){
			case 1:
				newDirection = UP;
			default:
				break;
		}
	}
	else{
			up=0;
	}
	
	reset_RIT();
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
