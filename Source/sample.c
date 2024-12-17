/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               main.c
** Descriptions:            The GLCD application function
**
**--------------------------------------------------------------------------------------------------------
** Created by:              AVRman
** Created date:            2010-11-7
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             Paolo Bernardi
** Modified date:           03/01/2020
** Version:                 v2.0
** Descriptions:            basic program for LCD and Touch Panel teaching
**
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "LPC17xx.h"
#include "GLCD/GLCD.h" 
#include "TouchPanel/TouchPanel.h"
#include "timer/timer.h"
#include "RIT/RIT.h"
#include "joystick/joystick.h"
#include "button_EXINT/button.h"


#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif

Position pacmanPos, livesPos;
Direction pacmanDir;
uint16_t (*pacmanMatrix)[PACMAN_SIZE][PACMAN_SIZE];
uint16_t (*pacmanMovMatrix)[PACMAN_SIZE][PACMAN_SIZE];
uint16_t PacmanScore;
uint16_t PacmanLives;
uint16_t RemainingPills;
uint16_t CountdownTime;

int main(void)
{
  SystemInit();  												/* System Initialization (i.e., PLL)  */
	BUTTON_init();
  LCD_Initialization();
	//srand(time(NULL));  // Seed the random number generator
  TP_Init();
	//TouchPanel_Calibrate();
	
	//240*320 screen
	LCD_Clear(Black);
	PacmanScore = 0;
	CountdownTime = 180;
	PacmanLives = 0;
	
	LCD_UpdateCountDown(CountdownTime);
	LCD_UpdateScore(PacmanScore);
	RemainingPills = NUM_STANDARD_PILLS;
	generatePills();
	
	
	pacmanPos.xPos = 15;
	pacmanPos.yPos = 35;
  LCD_DrawLabyrinth(5, 25, Blue, 10, 0, LABYRINTH_HEIGHT-1);
	pacmanDir = NONE;
	pacmanMatrix = &pacmanMatrix_Left;
	pacmanMovMatrix = &pacmanMatrixMovements_Left;
  LCD_DrawPacman(pacmanPos, Yellow, *pacmanMatrix);
	
	livesPos.xPos = 5;
	livesPos.yPos = 300;
	
  PacmanAddLive();
	
	joystick_init();											/* Joystick Initialization       */
	
	
	init_RIT(0x004C4B40);									/* RIT Initialization 50 msec = 50ms * 100MHz    */
	enable_RIT();	
	
	//TIMER 0: PACMAN SPEED
	init_timer(0, 0x98968 ); 						/* 25ms * 25MHz = 0.625*10^6 = 98968 */
	
	init_timer(1, 0x17D7840 ); 						/* 1s * 25MHz = 25*10^9 = 17D7840 */
	
	uint32_t next_interval = rand() % 0x2FAF080; // 0s to 2s in timer ticks
	init_timer(2, next_interval); // Reinitialize Timer 2 with new interval
	
	
	LCD_SetFilledRect(5, 135, White, 230, 50);
	LCD_SetFilledRect(10, 140, Black, 220, 40);
	GUI_Text(100, 155, (uint8_t *) "PAUSE", Yellow, Black);
				
	
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);						
	
  while (1)	
  {
		__ASM("wfi");
  }
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
