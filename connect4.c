#include <stdio.h>
#include <string.h>

#define ROWS 6
#define COLLS 7



int checkAll(char grid[ROWS][COLLS]) {
	for (int i = 5; i >= 0; i--) {
		for (int j = 0; j < COLLS; j++){
			if (grid[i][j] == ' ') {
				return 0;
			}
		}
	}
	return -2;
}


int checkDiagonalRL(char grid[ROWS][COLLS], int row, int col, int count, char playerPiece,int numToWin) {
	if (count == numToWin) {
		return 1;
	}

	if ((row < 0 || col < 0) || (row >= 6 || col >= 7)) {
		return 0;
	}
	
	if (grid[row][col] == playerPiece) {
		count++;

		return checkDiagonalRL(grid, row - 1, col - 1, count, playerPiece, numToWin);
	}
	else {
		return -1;
	}

}



int checkDiagonalLR(char grid[ROWS][COLLS], int row, int col, int count, char playerPiece,int numToWin) {
	if (count == numToWin) {
		return 1;
	}
	
	if ((row < 0 || col < 0) || (row >= 6 || col >= 7)) {
		return 0;
	}
	
	if (grid[row][col] == playerPiece) {
		count++;

		return checkDiagonalLR(grid, row - 1, col+1, count, playerPiece, numToWin);
	}
	else {
		return -1;
	}

}

int checkDiagonalLRD(char grid[ROWS][COLLS], int row, int col, int count, char playerPiece, int numToWin) {
	if (count == numToWin) {
		return 1;
	}

	if ((row < 0 || col < 0) || (row >= 6 || col >= 7)) {
		return 0;
	}

	if (grid[row][col] == playerPiece) {
		count++;

		return checkDiagonalLRD(grid, row +1, col - 1, count, playerPiece, numToWin);
	}
	else {
		return -1;
	}

}
int checkDiagonalLRU(char grid[ROWS][COLLS], int row, int col, int count, char playerPiece, int numToWin) {
	if (count == numToWin) {
		return 1;
	}

	if ((row < 0 || col < 0) || (row >= 6 || col >= 7)) {
		return 0;
	}

	if (grid[row][col] == playerPiece) {
		count++;

		return checkDiagonalLRU(grid, row + 1, col + 1, count, playerPiece, numToWin);
	}
	else {
		return -1;
	}

}



int checkVerticalD(char grid[ROWS][COLLS], int row, int col, int count, char playerPiece,int numToWin) {
	if (row < 0) {
		return 0;
	}
	if (count == numToWin) {
		return 1;
	}
	if (grid[row][col] == playerPiece) {
		count++;

		return checkVerticalD(grid, row +1, col, count, playerPiece, numToWin);
	}
	else {
		return -1;
	}

}

int checkVerticalU(char grid[ROWS][COLLS], int row, int col, int count, char playerPiece,int numToWin) {
	if (row >= 6) {
		return 0;
	}
	if (count == numToWin) {
		return 1;
	}
	if (grid[row][col] == playerPiece) {
		count++;
	
		return checkVerticalU(grid, row-1, col, count, playerPiece, numToWin);
	}
	else {
		return -1;
	}

}



int checkWidthL(char grid[ROWS][COLLS], int row, int col, int count, char playerPiece, int numToWin) {
	if (count == numToWin) {
		return 1;
	}


	if (col < 0) {
		return 0;
	}
	
	
	if (grid[row][col] == playerPiece) {
		count++;

		return checkWidthL(grid, row, col - 1, count, playerPiece, numToWin);
	}
	else {
		return -1;
	}

}


int checkWidthR(char grid[ROWS][COLLS], int row, int col, int count, char playerPiece,int numToWin) {
	if (col >= 7) {
		return 0;
	}
	if (count == numToWin) {
		return 1;
	}
	if (grid[row][col] == playerPiece) {
		count++;

		return checkWidthR(grid, row, col + 1, count, playerPiece, numToWin);
	}
	else {
		return -1;
	}

}







int makeGrid(char grid[ROWS][COLLS]) {



	for (int j = 0; j < COLLS; j++) {
		for (int i = 0; i < ROWS; i++) {
			grid[i][j] = ' ';
		}
	}
	return 0;
}
int checkWin(char grid[ROWS][COLLS], int row, int col, char playerPiece,int numToWin) {

	if (checkAll(grid) == -2) {
		return -2;
	}
	if (checkWidthR(grid, row, col, 0, playerPiece,numToWin) == 1) {
		return 1;
	}
	if (checkWidthL(grid, row, col, 0, playerPiece, numToWin) == 1) {
		return 1;
	}
	if (checkVerticalU(grid, row, col, 0, playerPiece, numToWin) == 1) {
		return 1;
	}
	if (checkVerticalD(grid, row, col, 0, playerPiece, numToWin) == 1) {
		return 1;
	}
	if (checkDiagonalLR(grid, row, col, 0, playerPiece,numToWin) == 1) {
		return 1;
	}
	if (checkDiagonalRL(grid, row, col, 0, playerPiece, numToWin) == 1) {
		return 1;
	}
	if (checkDiagonalLRU(grid, row, col, 0, playerPiece, numToWin) == 1) {
		return 1;
	}
	if (checkDiagonalLRD(grid, row, col, 0, playerPiece, numToWin) == 1) {
		return 1;
	}
	
	return 0;
}
int placePiece(int turn, int collum, char grid[ROWS][COLLS], int numToWin) {
	char toPlace;
	if (turn % 2 == 0) {
		toPlace = 'x';
	}
	else {
		toPlace = '0';
	} 
	
	
		for (int j = ROWS - 1; j >= 0; j--) {
			if (grid[j][collum - 1] == ' ') {
				grid[j][collum - 1] = toPlace;
				if (grid[0][collum - 1] != ' ') {
					return -1;
				}
				else {
					int win = checkWin(grid, j, collum - 1, toPlace, numToWin);
					return win;

					break;

				}
				
			}
		}
	
	return 0;
}




void printBoard(char grid[ROWS][COLLS]) {
	for (int i = 0; i < ROWS; i++) {
		printf("|");
		for (int j = 0; j < COLLS; j++) {
			printf("%c", grid[i][j]);
			printf("|");

		}
		printf("\n");
	}
	printf("_______________\n1 2 3 4 5 6 7\n");
}



int checkColl(char grid[ROWS][COLLS]) {
	int num;
	scanf_s("%d", &num);
	while (num < 1 || num >7) {
		printf("PLEASE ENTER A NUMBER BEWTEEN 1-7");
		scanf_s("%d", &num);
	}
	while (grid[0][num-1] != ' ') {
		printf("COLLUM FULL, PICK ANOTHER");
		scanf_s("%d", &num);
	}
	return num;
	}


void startGame() {
	int collum, row;
	int numToWin;
	printf("HOW MANY IN A ROW FOR A WIN?(3-5)");
	scanf_s("%d", &numToWin);
	char grid[ROWS][COLLS] = {};
	makeGrid(grid);
	printBoard(grid);
	int turn = 0;
	int turnResult;
	while(1) {
		printf("SELECT A COLLUM PLAYER %d\n",turn%2+1);
		collum = checkColl(grid);
		int turnResult = placePiece(turn, collum, grid,numToWin);
		
		if ((turnResult) == 1) {
			printBoard(grid);
			printf("you win, congrats\n");
			
			break;
		}
		else if (turnResult == -2) {
			printBoard(grid);
			printf("DRAWWWW\n");
			
			break;
		}
		turn++;
		printBoard(grid);

	}
}

int main() {
	int playAgain = 2;
	while (playAgain != 1) {
		printf("WELCOME TO CONNECT 4, PRESS 2 TO PLAY, ANY 1 TO QUIT\n");
		scanf_s("%d", &playAgain);
		if (playAgain == 2) {
			startGame();
		}
		else {
			printf("BYE BYE");
			break;
		}


	}
}
