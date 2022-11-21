// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#define N 3 // the tictactoe grid size(squared);
#define X 'X'
#define O 'O'
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int tictactoe();
void printGrid(char grid[N][N]);
void initializeGrid(char grid[N][N]);
void placingChoice(char grid[N][N], char playerName[]);
void startGame(char grid[N][N]);
int checkifwin(char grid[N][N]);

int main()
{
	srand(time(NULL));
	tictactoe();
	return 0;
}
/* tic tac toe project against the computer*/
int tictactoe() 
{
	char grid[N][N];
	initializeGrid(grid); // initizlizing the grid wih '*' x 9(3,3)
	printGrid(grid);
	
	startGame(grid);
	
	return 0;

}


void printGrid(char grid[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%c\t", grid[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

void initializeGrid(char grid[N][N])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			grid[i][j] = '*';
}

void startGame(char grid[N][N])
{
	int winner = 0;
	int turn = 0; // if even, player turn, if odd, computer's turn;
	printf("You are player1, you are X.\n");
	while (1)
	{
		if (turn%2 == 0)
		{
			placingChoice(grid, "player1");
		}
		else if (turn % 2 == 1)
		{
			placingChoice(grid, "player2");
		}

		winner = checkifwin(grid);
		if (winner == 3)
		{
			printf("Game ended with no winners");
			break;
		}
		if (winner)
		{
			printf("Winner is player%d", winner);
			break;
		}
		turn++;
	}

}
void placingChoice(char grid[N][N], char playerName[])
{
	int rowChoice, columnChoice;
	while (1) {
		if (playerName == "player1")
		{
			printf("Where would you like to place the X\n");
			printf("ROW(1-3):");
			scanf(" %d", &rowChoice);
			printf("\nColumn(1-3):");
			scanf(" %d", &columnChoice);
			if (grid[rowChoice-1][columnChoice-1] != '*')
			{
				printf("The current cell was already placed with a choice, please choose again");
			}
			else 
			{
				grid[rowChoice-1][columnChoice-1] = 'X';
				printGrid(grid);
				break;
			}

		}
		else
		{
				rowChoice = rand() % 3 + 1;
				columnChoice = rand() % 3 + 1;
				if (grid[rowChoice - 1][columnChoice - 1] != '*')
					continue;
				else
				{
					grid[rowChoice - 1][columnChoice - 1] = 'O';
					printGrid(grid);
					break;
				}

		}
	}
}

int checkifwin(char grid[N][N]) // return 1 for player1, 2 for player 2;
{
	for (int i = 0; i < N; i++)
	{
		if (grid[i][0] == X && grid[i][1] == X && grid[i][2] == X)
			return 1;
		else if (grid[i][0] == O && grid[i][1] == O && grid[i][2] == O)
			return 2;

	}
	for (int i = 0; i < N; i++)
	{
		if (grid[0][i] == X && grid[1][i] == X && grid[2][i] == X)
			return 1;
		else if (grid[0][i] == O && grid[1][i] == O && grid[2][i] == O)
			return 2;
	}
	if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2])
	{
		if (grid[0][0] == X)
		{
			return 1;
		}
		else if(grid[0][0] == O)
		{
			return 2;
		}
	}
	if (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0])
	{
		if (grid[0][2] == X)
		{
			return 1;
		}
		else if (grid[0][2] == O)
		{
			return 2;
		}
	}
	int found = 0;
	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j] == '*')
				found++;
		}
	}
	if (found == 0)
		return 3;
	
	return 0;
}