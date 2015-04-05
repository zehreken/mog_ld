//
//  playerCreator.c
//  mog
//
//  Created by Guchan Alkan on 31/03/15.
//  Copyright (c) 2015 Guchan Alkan. All rights reserved.
//

#include <stdio.h>
#include "mog.h"

Player getPlayer()
{
	Player temp;

	temp.HP = 100;
	temp.speed = 1;
	temp.damage = 1;
	temp.fireRate = 0.2;
	temp.firePower = 1 / temp.fireRate * temp.damage;

	return temp;
}