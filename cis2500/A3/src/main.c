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

int main (int argc, char * argv[]) {

//varibles and initializations used
	Room * * roomArray;
	char * * stringsArray;

	FILE * roomfile;
	char buffer[150];
	int heroX;
	int heroY;
	int roomLoc;
	int originX = 1;
	int originY = 1;
	int roomNum;
	int count = 0;
	int elementcount;
	char mover;

	roomNum = 0; //zero being room number 1
	stringsArray = malloc(sizeof(char*)*6);
	roomArray = malloc(sizeof(Room)*6);

	if (argc >= 2) {

		roomfile = fopen(argv[1],"r");


	} else {

		printf("file could not be opened\n");

	}

	while (roomNum < 7) {
		//move(originY,originX);
		fgets(buffer,150,roomfile);
		/*/array of elements from the long string that will
		be broken up into smaller strings and stored in this temporary
		array so that they can be put into the room struct properly
		afterwards */
		buffer[strlen(buffer)-2] = '\0'; //removes null terminator at end of each line
		char * * elementsArray;
		elementsArray = malloc(sizeof(char*)*9);

		stringsArray[roomNum] = malloc(sizeof(char)*(strlen(buffer)+1));
		strcpy(stringsArray[roomNum],buffer);
		elementsArray = breakLongString(stringsArray[roomNum], &elementcount);

		roomArray[roomNum] = malloc(sizeof(Room)+1);

		roomArray[roomNum] = setRoomCharacteristics(elementsArray,elementcount,&roomNum,&roomLoc);
		roomNum++;
	}

	initscr();
	cbreak();
	echo();

	while (count < 3) {
		drawRoom1(roomArray[count], originX, originY);
		originX = originX + 30;
		count++;
	}

	originY = 25;
	originX = 1;

	while (count < 6) {
		drawRoom2(roomArray[count], originX, originY);
		originX = originX + 30;
		count++;
	}
	
//	drawRoom1(roomArray[5],originX,originY);
	heroY = (roomArray[roomLoc]->heroY) + 1;
	heroX = (roomArray[roomLoc]->heroX) + 1;
	
    move(heroY,heroX);
    
	 while (mover != 'q') {
	 	mover = getch();
	 	heromovement(&heroX,&heroY,roomLoc,roomArray,mover);
	 }
	 	endwin();
	 for (int i = 0; i < 6; i++)
	 {
	 	free(stringsArray[i]);
	 	free(roomArray[i]);
	 }
	 free(stringsArray);
	 free(roomArray);
	 return 0;
}