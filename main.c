//
//  main.c
//  mog
//
//  Created by Guchan Alkan on 23/03/14.
//  Copyright (c) 2014 Guchan Alkan. All rights reserved.
//
//	MOG Level Creator
//
//	This program generates level data for MOG
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mog.h"

#define WAVECOUNT 6
#define WAVEPARAM 3
#define DIFFFACTOR 2

void createLevel();
void calculateDifficulty();
void printLevel();
void printLevelForServer();
void printLevelForUnity();

int monstersLevel00[] = { 0 }; // seed = 
int monstersLevel01[] = { 0, 5 }; // seed =
int monstersLevel02[] = { 0, 5, 3 }; // seed =
int monstersLevel03[] = { 0, 5, 3 }; // seed = 1
int monstersLevel04[] = { 0, 1 }; // seed = 
int monstersLevel05[] = { 0, 1 }; // seed = 
int monstersLevel06[] = { 0, 1 }; // seed = 
int monstersLevel07[] = { 0, 1 }; // seed = 
int monstersLevel08[] = { 0, 1 }; // seed = 
int monstersLevel09[] = { 0, 1 }; // seed = 
int monstersLevel10[] = { 0, 1 }; // seed = 
int monstersLevel11[] = { 0, 1 }; // seed = 
int monstersLevel12[] = { 0, 1 }; // seed = 
int monstersLevel13[] = { 0, 1 }; // seed = 

Enemy enemies[7];

int main()
{
	Player player = getPlayer();
	
	int level[WAVECOUNT][WAVEPARAM];
	
	const int monsterTypeCount = 3;
	
	enemies[0] = *getEnemies();
	printf("Wavecount: %d\n", WAVECOUNT);
	
	createLevel(level, monstersLevel03, monsterTypeCount, WAVECOUNT, WAVEPARAM, DIFFFACTOR);
	// printLevel(level, WAVECOUNT, WAVEPARAM);
	// printLevelForServer(level, WAVECOUNT, WAVEPARAM);
	printLevelForUnity(level, WAVECOUNT, WAVEPARAM);
	calculateDifficulty(level, WAVECOUNT, WAVEPARAM);
	
	return 0;
}

void createLevel(int *pArr, int monsters[], int monsterTypeCount, int count, int param, int diffFactor)
{
	int seed = 0;
	printf("enter seed: ");
	scanf("%d", &seed);
	srand(seed);
	
	for (int i = 0; i < count; ++i)
	{
		int seconds = 1 + i * (10 / diffFactor + rand() % 5);
		*pArr++ = seconds; // seconds
		int type = monsters[rand() % monsterTypeCount];
		*pArr++ = type; // monster type
		int count = (8 * diffFactor) + rand() % 10;
		*pArr++ = count; // monster count
	}
}

void calculateDifficulty(int arr[WAVECOUNT][WAVEPARAM], int count, int param)
{
	int i;
	float totalEnemyHP = 0;
	float totalDamage = 0;
	int totalCubes = 0;
	
	for (i = 0; i < count; ++i)
	{
		totalEnemyHP += enemies[arr[i][1]].HP * arr[i][2]; // enemy HP times enemy count
		totalDamage += enemies[arr[i][1]].damage * arr[i][2]; // enemy damage times enemy count
		totalCubes += enemies[arr[i][1]].cubeCount * arr[i][2]; // enemy cube times enemy count
	}
	printf("total hp: %f\n", totalEnemyHP);
	printf("total bullet damage/second: %f\n", totalDamage);
	printf("total cubes: %d\n", totalCubes);
}

void printLevelForServer(int *pArr, int count, int param)
{
	for (int i = 0; i < count; ++i)
	{
		printf("time:\t%d", *pArr++);
		printf("\ttype:\t%d", *pArr++);
		printf("\tcount:\t%d", *pArr++);
		printf("\n");
	}
}

void printLevelForUnity(int *pArr, int count, int param)
{
	for (int i = 0; i < count; ++i)
	{
		printf("%d", *pArr++);
		printf("\t%d", *pArr++);
		printf("\t%d", *pArr++);
		printf("\n");
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
