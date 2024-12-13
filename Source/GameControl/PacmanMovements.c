
#include "PacmanMovements.h"



uint16_t labyrinthMatrix[LABYRINTH_HEIGHT][LABYRINTH_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

uint16_t pacmanMatrix_Left[PACMAN_SIZE][PACMAN_SIZE] = {
	{0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
	{0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
	{0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
	{0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 0, 0}
};

uint16_t pacmanMatrix_Right[PACMAN_SIZE][PACMAN_SIZE] = {
    {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 0, 0}
};

uint16_t pacmanMatrix_Down[PACMAN_SIZE][PACMAN_SIZE] = {
    {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0, 1, 1, 1},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}
};
uint16_t pacmanMatrix_Up[PACMAN_SIZE][PACMAN_SIZE] = {
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {1, 1, 1, 0, 0, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 0, 0}
};

uint16_t pacmanMatrixMovements_Left[PACMAN_SIZE][PACMAN_SIZE] = {
	{0, 0, 1, 0, 0, 0, 0, 2, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 2, 0},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 2},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 2},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 2},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 2},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{0, 1, 0, 0, 0, 0, 0, 0, 2, 0},
	{0, 0, 1, 0, 0, 0, 0, 2, 0, 0},
};

uint16_t pacmanMatrixMovements_Right[PACMAN_SIZE][PACMAN_SIZE] = {
	{0, 0, 2, 0, 0, 0, 0, 1, 0, 0},
	{0, 2, 0, 0, 0, 0, 0, 0, 1, 0},
	{2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{2, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{2, 0, 0, 1, 0, 0, 0, 0, 0, 0},
	{2, 0, 0, 1, 0, 0, 0, 0, 0, 0},
	{2, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{0, 2, 0, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 2, 0, 0, 0, 0, 1, 0, 0},
};

uint16_t pacmanMatrixMovements_Down[PACMAN_SIZE][PACMAN_SIZE] = {
	{0, 0, 2, 2, 2, 2, 2, 2, 0, 0},
	{0, 2, 0, 0, 0, 0, 0, 0, 2, 0},
	{2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
};

uint16_t pacmanMatrixMovements_Up[PACMAN_SIZE][PACMAN_SIZE] = {
	{0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
	{2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{0, 2, 0, 0, 0, 0, 0, 0, 2, 0},
	{0, 0, 2, 2, 2, 2, 2, 2, 0, 0},
};


uint16_t pillMatrix[PACMAN_SIZE][PACMAN_SIZE]  = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void PacmanRotate(Position *pos, Direction newDir){
	switch(newDir){
		case UP:
				pacmanMatrix = &pacmanMatrix_Up;
				pacmanMovMatrix = &pacmanMatrixMovements_Up;
				break;
			case DOWN:
				pacmanMatrix = &pacmanMatrix_Down;
				pacmanMovMatrix = &pacmanMatrixMovements_Down;
				break;
			case RIGHT:
				pacmanMatrix = &pacmanMatrix_Right;
				pacmanMovMatrix = &pacmanMatrixMovements_Right;
				break;
			default:
				pacmanMatrix = &pacmanMatrix_Left;
				pacmanMovMatrix = &pacmanMatrixMovements_Left;
				break;
	}
	
  LCD_DrawPacman(pacmanPos, Yellow, *pacmanMatrix);
}

void PacmanMove(Position *pos, Direction dir){
	
	if (dir != NONE){
	
		int x,y;
			
		//Clear
		for(y=0; y<10; y++){
			for(x=0; x<10; x++){
				if ((*pacmanMovMatrix)[y][x] == 2){
					LCD_SetPoint(pos->xPos + x, pos->yPos + y, Black);
				}
			}
		}
		//Check if possible to move (pos % 10 == 0) from labyrinth matrix (yes if 0, no if 1)
		//Move
		switch (dir) {
			case UP:
				pos->yPos--;
				break;
			case DOWN:
				pos->yPos++;
				break;
			case LEFT:
				pos->xPos--;
				break;
			case RIGHT:
				pos->xPos++;
				break;
			case NONE:
				break;
			default:
				break;
		}
		
		//Draw
		for(y=0; y<10; y++){
			for(x=0; x<10; x++){
				if ((*pacmanMovMatrix)[y][x] == 1){
					LCD_SetPoint(pos->xPos + x, pos->yPos + y, Yellow);
				}
			}
		}
	}
}

int16_t coordX, coordY, xx, yy;
int16_t PacmanCheckWallCollision(Position *pos, Direction dir, int16_t changeDir){
	
	//Check position is a finite square position in order to be allowed to change direction, otw always collision
	if (((pos->yPos-25) % 10 != 0 || (pos->xPos-5) % 10 != 0) && changeDir == 1) return 1;
	
	xx = pos->xPos;
	yy = pos->yPos;
	
	
	coordY = (pos->yPos-25 + PACMAN_SIZE - 1)/PACMAN_SIZE;
	coordX = (pos->xPos-5 + PACMAN_SIZE - 1)/PACMAN_SIZE;
	
	switch (dir) {
			  case UP: 
					if ((pos->yPos-25) % 10 == 0) coordY--;
					break;
		  	case LEFT:
					if ((pos->xPos-5) % 10 == 0) coordX--;
					break;
				case DOWN:
					if ((pos->yPos-25) % 10 == 0) coordY++;
					break;
				case RIGHT:
					if ((pos->xPos-5) % 10 == 0) coordX++;
					break;
				default:
					break;
			}
	if (pos->yPos % 5 == 0 || pos->xPos % 5 == 0){
		if (labyrinthMatrix[coordY][coordX] == 1){
			return 1;
		}
	}
	return 0;
}


int zeros[LABYRINTH_HEIGHT * LABYRINTH_WIDTH];  // Array to store the indices of cells with 0
    
void generatePills(){
		int zero_count = 0;
		int i,j,k;
    // Collect indices of all zeros
    for (i = 0; i < LABYRINTH_HEIGHT; i++) {
        for (j = 0; j < LABYRINTH_WIDTH; j++) {
            if (labyrinthMatrix[i][j] == 0) {
                zeros[zero_count++] = i * LABYRINTH_WIDTH + j;  // Store index in 1D form
            }
        }
    }
		
		for (i = zero_count - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = zeros[i];
        zeros[i] = zeros[j];
        zeros[j] = temp;
    }
		
		for (k = 0; k < NUM_POWER_PILLS; k++) {
        int index = zeros[k];
        int row = index / LABYRINTH_WIDTH;
        int col = index % LABYRINTH_WIDTH;
        labyrinthMatrix[row][col] = 3;
    }
		
		for (k = NUM_POWER_PILLS; k < NUM_STANDARD_PILLS + NUM_POWER_PILLS; k++) {
			  int index = zeros[k];
        int row = index / LABYRINTH_WIDTH;
        int col = index % LABYRINTH_WIDTH;
        labyrinthMatrix[row][col] = 2;
    }
}

