
#ifndef __PacmanMovements_H 
#define __PacmanMovements_H

/* Includes ------------------------------------------------------------------*/
#include "LPC17xx.h"

typedef enum {
    UP,      
    DOWN,    
    LEFT,    
    RIGHT,   
	  NONE
} Direction;

typedef struct {
		uint16_t xPos;
		uint16_t yPos;
} Position;

#define LABYRINTH_WIDTH 23
#define LABYRINTH_HEIGHT 27
#define PACMAN_SIZE 10

#define Black          0x0000
#define Yellow         0xFFE0

extern uint16_t labyrinthMatrix[LABYRINTH_HEIGHT][LABYRINTH_WIDTH];

extern uint16_t pacmanMatrixMovements_Left[PACMAN_SIZE][PACMAN_SIZE];
extern uint16_t pacmanMatrix_Left[PACMAN_SIZE][PACMAN_SIZE];

extern uint16_t pacmanMatrixMovements_Right[PACMAN_SIZE][PACMAN_SIZE];
extern uint16_t pacmanMatrix_Right[PACMAN_SIZE][PACMAN_SIZE];

extern uint16_t pacmanMatrixMovements_Up[PACMAN_SIZE][PACMAN_SIZE];
extern uint16_t pacmanMatrix_Up[PACMAN_SIZE][PACMAN_SIZE];

extern uint16_t pacmanMatrixMovements_Down[PACMAN_SIZE][PACMAN_SIZE];
extern uint16_t pacmanMatrix_Down[PACMAN_SIZE][PACMAN_SIZE];

extern uint16_t pacmanMatrix[PACMAN_SIZE][PACMAN_SIZE];
extern Position pacmanPos;
extern Direction pacmanDir;
/* Private function prototypes -----------------------------------------------*/
void PacmanMove(Position *pos, Direction dir);
	
void PacmanRotate(Position *pos, Direction newDir, Direction oldDir);
#endif 

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
