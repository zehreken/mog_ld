//
//  mog.h
//  mog
//
//  Created by Guchan Alkan on 24/03/14.
//  Copyright (c) 2014 Guchan Alkan. All rights reserved.
//

#ifndef mog_mog_h
#define mog_mog_h

typedef struct
{
	float HP;
	float damage;
	float speed;
	int cubeCount;
} Enemy;

Enemy (*getEnemies())[7];

#endif
