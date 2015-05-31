 /*************************Assignment 3.c*******************************
 Student Name: Love Joseph                                   Student Number: 0890515
 Date: March 13th, 2015                                           Course Name: CIS2500
 I have exclusive control over this submission via my password.
 By including this statment in this header comment, I certify that:
 1) I have read and understood the University polict on academic integrity;
 2) I have completed the Computing with Integrity Self Test
 3)I have achieved at least 80% in the Computing with Integrity Test
 I assert that this work is my own. I have approipratiely acknowledged any and all material
 (data, images, ideas or words) that I have used, whether directly quoted or paraphraased.
 Furthermore, I certify that this assignment was prepared by me specifically for this course.
 *******************************************************************************/

#include "main.h"

char * * breakLongString(char * s, int * ecount) {

	char * tok;


	int i = 1;

	char * * tempStringArray;
	tempStringArray = malloc(sizeof(char*)*10);
	tok = strtok(s," ");
	tempStringArray[0] = malloc(sizeof(char)*(strlen(tok)+1));
	strcpy(tempStringArray[0],tok);
	tok = strtok(NULL, " ");

			 while ( tok != NULL ) {
				tempStringArray[i] = malloc(sizeof(char)*(strlen(tok)+200));

				strcpy(tempStringArray[i],tok);

				tok = strtok(NULL, " ");
				 i++;
			}
			*ecount = i;
	return tempStringArray;

	for (int i = 0; i < 10; i++) {
		free(tempStringArray[i]);
	}
	free(tempStringArray);
}

Room * setRoomCharacteristics (char * * stringArr, int numElements, int * num, int * room) {

	Room * tempRoom;
	char buffer[5];
	int i = 0;
	tempRoom = malloc(sizeof(Room*));
	char * token;
	while (i < numElements) {
		strcpy(buffer,stringArr[i]);

		//room dimesions
		if( i == 0 ) {
			token = strtok(stringArr[i],"X");
			tempRoom->roomY = atoi(token);
			token = strtok(NULL, "\n");
			tempRoom->roomX = atoi(token);
		}
		//door allocation
		if (buffer[0] == 'd') {
			if (buffer[1] == 'e') {
				tempRoom->doorE = buffer[2] - '0';
			}
			if (buffer[1] == 'w') {
				tempRoom->doorW = buffer[2] - '0';
			}
			if (buffer[1] == 'n') {
				tempRoom->doorN = buffer[2] - '0';
			}
			if (buffer[1] == 's') {
				tempRoom->doorS = buffer[2] - '0';
			}
		}
	//other item allocations
		if (buffer[0] == 'h') {
			tempRoom->heroY = buffer[1] - '0';
			tempRoom->heroX = buffer[3] - '0';
			*room = *num;
		}
		if (buffer[0] == 'g') {
			tempRoom->goldY = buffer[1] - '0';
			tempRoom->goldX = buffer[3] - '0';
		}
		if (buffer[0] == 'p') {
			tempRoom->potionY = buffer[1] - '0';
			tempRoom->potionX = buffer[3] - '0';
		}
		if (buffer[0] == 'M') {
			tempRoom->monsterY = buffer[1] - '0';
			tempRoom->monsterX = buffer[3] - '0';
		}
		if (buffer[0] == 'm') {
			tempRoom->magicY = buffer[1] - '0';
			tempRoom->magicX = buffer[3] - '0';
		}
		if (buffer[0] == 'w') {
			tempRoom->weaponY = buffer[1] - '0';
			tempRoom->weaponX = buffer[3] - '0';
		}
		if (buffer[0] == 's') {
			tempRoom->stairY = buffer[1] - '0';
			tempRoom->stairX = buffer[3] - '0';
		}
		i++;
	}
	i = 0;
	return tempRoom;
}

void drawRoom1(Room * specs, int oriX, int oriY) {

	move(oriY,oriX);

	refresh();

	//Northwall
	for (int i = oriX; i != (specs->roomX + oriX) + 2 ; i++) {
		if (i-1 == (specs->doorN + oriX)) {
			mvaddch(oriY,i,'+');
		} else {
			mvaddch(oriY,i,'-');
		}
	}

	//Westwall
	for (int i = oriY + 1; i != specs->roomY + 2 ; i++) {
		if (i-1 == specs->doorW) {
			mvaddch(i,oriX,'+');
		} else {
			mvaddch(i,oriX,'|');
		}
	}

	//Eastwall
	for (int i = oriY +1; i != specs->roomY + 2 ; i++) {
		if (i-1 == specs->doorE) {
			mvaddch(i,(oriX + specs->roomX + 1),'+');
		} else {
			mvaddch(i,(oriX + specs->roomX + 1),'|');
		}
	}

	//Southwall
	for (int i = oriX; i < (specs->roomX + oriX) + 2 ; i++) {
		if (i-1 == (specs->doorS + oriX)) {
			mvaddch(oriY + specs->roomY + 1,i,'+');
		} else {
			mvaddch(oriY + specs->roomY + 1,i,'-');
		}
	}

//draw floor (nested loop)

	for (int i = oriX + 1; i != specs->roomX + oriX + 1 ; i++) {
		for (int j = oriY + 1; j != specs->roomY + 2; j++) {

			if (( i == specs->heroX + oriX )&&( j-1 == specs->heroY )) {
				mvaddch(j,i,'@');
			}
			if ((i == specs->goldX + oriX)&&(j-1 == specs->goldY)) {
				mvaddch(j,i,'*');
			}
			if ((i == specs->weaponX + oriX)&&(j-1 == specs->weaponY)) {
				mvaddch(j,i,')');
			}
			if ((i == specs->monsterX + oriX)&&(j-1 == specs->monsterY)) {
				mvaddch(j,i,'M');
			}
			if ((i == specs->magicX + oriX)&&(j-1 == specs->magicY)) {
				mvaddch(j,i,'?');
			}
			if ((i == specs->potionX +oriX)&&(j-1 == specs->potionY)) {
				mvaddch(j,i,'!');
			}
			if ((i == specs->stairX +oriX)&&(j-1 == specs->stairY)) {
				mvaddch(j,i,'%');
			} else {
				//mvaddch(j,i,'.');
			}
		}
	}
	refresh();
}

void drawRoom2(Room * specs, int oriX, int oriY) {



	move(oriY,oriX);

	refresh();

	//Northwall
	for (int i = oriX; i != (specs->roomX + oriX) + 2 ; i++) {
		if (i-1 == (specs->doorN + oriX)) {
			mvaddch(oriY,i,'+');
		} else {
			mvaddch(oriY,i,'-');
		}
	}

	//Westwall
	for (int i = oriY + 1; i != (specs->roomY + oriY) + 2 ; i++) {
		if (i == specs->doorW + oriY) {
			mvaddch(i,oriX,'+');
		} else {
			mvaddch(i,oriX,'|');
		}
	}

	//Eastwall
	for (int i = oriY +1; i != (specs->roomY + oriY) + 2 ; i++) {
		if (i == specs->doorE + oriY) {
			mvaddch(i,(oriX + specs->roomX + 1),'+');
		} else {
			mvaddch(i,(oriX + specs->roomX + 1),'|');
		}
	}

	//Southwall
	for (int i = oriX; i != (specs->roomX + oriX) + 2 ; i++) {
		if (i-1 == (specs->doorS + oriX)) {
			mvaddch(oriY + specs->roomY + 1,i,'+');
		} else {
			mvaddch(oriY + specs->roomY + 1,i,'-');
		}
	}

	//draw floor (nested loop)

	for (int i = oriX + 1; i != specs->roomX + oriX + 1 ; i++) {
		for (int j = oriY + 1; j != (specs->roomY + oriY) + 1; j++) {

			if (( i == specs->heroX + oriX )&&( j == specs->heroY + oriY )) {
				mvaddch(j,i,'@');
			}
			if ((i == specs->goldX + oriX)&&(j == specs->goldY + oriY )) {
				mvaddch(j,i,'*');
			}
			if ((i == specs->weaponX + oriX)&&(j == specs->weaponY + oriY)) {
				mvaddch(j,i,')');
			}
			if ((i == specs->monsterX + oriX)&&(j == specs->monsterY + oriY)) {
				mvaddch(j,i,'M');
			}
		    if ((i == specs->potionX +oriX)&&(j == specs->potionY + oriY)) {
				mvaddch(j,i,'!');
			}
			if ((i == specs->magicX + oriX)&&(j == specs->magicY + oriY)) {
				mvaddch(j,i,'?');
			}
		    if ((i == specs->stairX +oriX)&&(j-1 == specs->stairY + oriY)) {
				mvaddch(j,i,'%');
			} else {
				mvaddch(j,i,'.');
			}
		}
	}
	refresh();
}

void heromovement(int * x, int * y, int room, Room * * rooms, char move) {

	switch(move) {

		case 'w':
			mvaddch(*y,*x,'.');
			*y = *y - 1;
			mvaddch(*y,*x,'@');
			break;

		case 'a':
			mvaddch(*y,*x,'.');
			*x = *x - 1;
			mvaddch(*y,*x,'@');
			break;

		case 's':
			mvaddch(*y,*x,'.');
			*y = *y + 1;
			mvaddch(*y,*x,'@');
			break;

		case 'd':
			mvaddch(*y,*x,'.');
			*x = *x + 1;
			mvaddch(*y,*x,'@');
			break;
	}
}