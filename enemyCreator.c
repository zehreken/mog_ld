//
//  enemyCreator.c
//  mog
//
//  Created by Guchan Alkan on 24/03/14.
//  Copyright (c) 2014 Guchan Alkan. All rights reserved.
//

#include <stdio.h>
#include "math.h"
#include "mog.h"

Enemy enemies[7];
float enemyHPs[7] = { 5, 10, 10, 10, 15, 5, 50 };
float enemyWeapons[7] = { 0, 1, 1, 1, 1, 1, 1 };
int enemyCubeCounts[7] = { 1, 2, 3, 4, 5, 6, 8 };
float enemyDifficultyRatings[7] = { 1 };

Enemy createEnemy(float HP, float damage, float speed, int cubeCount)
{
	Enemy temp;
	
	temp.HP = HP;
	temp.damage = damage;
	temp.speed = speed;
	temp.cubeCount = cubeCount;
	
	return temp;
}

Enemy (*getEnemies())[7]
{
	int i;
	printf("====CREATING ENEMIES===\n");
	for (i = 0; i < 7; ++i)
	{
		enemies[i] = createEnemy(enemyHPs[i], enemyWeapons[i], 5 + sqrt(i), enemyCubeCounts[i]);
		printf("type: %d\thp: %.1f\tdamage: %.1f\tspeed: %.1f\tcubeCount: %d\n", i, enemies[i].HP, enemies[i].damage, enemies[i].speed, enemies[i].cubeCount);
	}
	printf("=======================\n");
	
	return &enemies;
}