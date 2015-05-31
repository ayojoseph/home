#ifndef _LJOSEPH_MAINH
#define _LJOSEPH_MAINH
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <ctype.h>

typedef struct room
{
	int * originX;
	int * originY;
	int * eastWall;
	int * southWall;
	int roomX;
	int roomY;
	int doorE;
	int doorN;
	int doorS;
	int doorW;
	//char * itemDes;
	int goldX;
	int goldY;
	int magicX;
	int magicY;
	int potionX;
	int potionY;
	int weaponX;
	int weaponY;
	int monsterX;
	int monsterY;
	int stairX;
	int stairY;
	int heroX;
	int heroY;


}Room;


char * * breakLongString(char * s, int * ecount);

Room * setRoomCharacteristics (char * * stringArr, int numElements, int * num, int * room);

void drawRoom1(Room * specs, int oriX, int oriY);
void drawRoom2(Room * specs, int oriX, int oriY);

void heromovement(int * x, int * y, int room, Room * * rooms, char move);











#endif