//
//  main.c
//  mog
//
//  Created by Guchan Alkan on 23/03/14.
//  Copyright (c) 2014 Guchan Alkan. All rights reserved.
//
//	MOG Level Creator
//
//	This program generates level data for the game MOG
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mog.h"

#define WAVECOUNT 5
#define WAVEPARAM 3

void createLevel();
void calculateDifficulty();
void printLevel();
void printLevelForServer();

int availableMonsters[] = { 0, 1, 2, 3, 4, 5, 6 };

int main()
{
	float playerHp, playerBulletDamage, playerFireRate, playerFirePower, playerSpeed;
    
	playerHp = 100;
	playerBulletDamage = 1;
	playerFireRate = 0.2;
	playerFirePower = 1 / playerFireRate * playerBulletDamage;
	playerSpeed = 1;
	
	int level[WAVECOUNT][WAVEPARAM];
	
	const int monsterTypeCount = 1;
	int monsters[] = { 0 };
	
	getEnemies();
	
	createLevel(&level[0][0], monsters, monsterTypeCount, WAVECOUNT, WAVEPARAM);
//	printLevel(level, WAVECOUNT, WAVEPARAM);
	printLevelForServer(level, WAVECOUNT, WAVEPARAM);
	calculateDifficulty(level, WAVECOUNT, WAVEPARAM);
	
	return 0;
}

void createLevel(int *pArr, int monsters[], int monsterTypeCount, int count, int param)
{
	srand(0);
	
	int i;
	for (i = 0; i < count; ++i)
	{
		*pArr++ = 1 + i * 3 + rand() % 5; // seconds
		*pArr++ = monsters[rand() % monsterTypeCount]; // monster type
		*pArr++ = 10 + rand() % 10; // monster count
	}
}

void calculateDifficulty(int arr[WAVECOUNT][WAVEPARAM], int count, int param)
{
	int i;
	float totalEnemyHP = 0;
	float totalDamage = 0;
	int totalCubes = 0;
	
	Enemy *pe = getEnemies()[0];
	printf("%f\n", (++pe)->HP);
	
	for (i = 0; i < count; ++i)
	{
		totalEnemyHP += (pe + arr[i][1])->HP * arr[i][2]; // enemy HP times enemy count
		totalDamage += (pe + arr[i][1])->damage * arr[i][2]; // enemy damage times enemy count
		totalCubes += (pe + arr[i][1])->cubeCount * arr[i][2]; // enemy cube times enemy count
		pe++;
	}
//	printf("total hp: %f\n", totalEnemyHP);
//	printf("total bullet damage/second: %f\n", totalDamage);
//	printf("total cubes: %d\n", totalCubes);
}

void printLevelForServer(int arr[WAVECOUNT][WAVEPARAM], int count, int param)
{
	int i, j;
	for (i = 0; i < count; ++i)
	{
		for (j = 0; j < param; ++j)
		{
			if (j == param - 1) printf("%d\n", arr[i][j]);
			else printf("%d\t", arr[i][j]);
		}
	}
}

void printLevel(int arr[WAVECOUNT][WAVEPARAM], int count, int param)
{
	int i, j;
	printf("level wave data\nseconds\ttype\tcount\n");
	for (i = 0; i < count; ++i)
	{
		printf("new int[] { ");
		for (j = 0; j < param; ++j)
		{
			if (j == param - 1) printf("%d ", arr[i][j]);
			else printf("%d, ", arr[i][j]);
		}
		printf("},");
		printf("\n");
	}
}
