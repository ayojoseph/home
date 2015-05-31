 /*************************Assignment 2.c*******************************
 Student Name: Love Joseph                                   Student Number: 0890515
 Date: February 13th, 2015                                           Course Name: CIS2500
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

/**
 drawboard: Draws the interpreter board
 Pre: 
 Post: 
*/
void drawboard() {

	int i,j;
	initscr();
	cbreak();
	move(0,45);
	for (i = 0; i < 20; i++) {
		addch(ACS_VLINE);	
		move(i,45);
	}
	addch(ACS_LLCORNER);
	
	for (j = 46; j < 100; j++) {
		addch(ACS_HLINE);
		move(i-1,j);
	}
	addch(ACS_LRCORNER);
	for (i = 18; i > 0; i--) {
		move(i,j-1);
		addch(ACS_VLINE);
	}
	move(19,45);
	for (j = 45; j >= 0; j--) {
		addch(ACS_HLINE);
		move(19,j);
	}
	addch(ACS_LLCORNER);
	move(18,0);
	for (i = 18; i >= 0; i--) {
		addch(ACS_VLINE);
		move(i,0);
	}
	move(22,0);
	for (i = 0; j < 100; j++) {
		addch(ACS_HLINE);
		move(22,j);
	}
	addch(ACS_LRCORNER);
	for (i = 21; i>18; i--) {
		move(i,99);
		addch(ACS_VLINE);	
	}
	move(20,0);
	printw("Enter Command Here: ");
	mvprintw(1,1,"Command History: ");
	move(9,72);
	addch(ACS_UARROW);	
	refresh();	
	echo();
	

 }

/**
 getEditString: gets the correct command and splits it
 Pre: recieves a string
 Post: returns a struct with the sorted out strings
*/
Command * getEditString(char * s) {

 	Command * tempcom;
 	char * token;
 	tempcom = malloc(sizeof(Command)); //allocate for struct first
 	//copy raw string to struct 
 	tempcom->raw = malloc(sizeof(char)*(strlen(s)+1));
 	strcpy(tempcom->raw,s);
 	//split up string using token and copy to struct
 	token = strtok(s," ");
 	tempcom->dir = malloc(sizeof(char)*(strlen(token)+1));
 	strcpy(tempcom->dir,token);
 	token = strtok(NULL," ");
 	tempcom->value = malloc(sizeof(int)*(strlen(token)+1));
 	tempcom->value = atoi(token);
 	return tempcom; //returns the address of the struct of manipulated string parts
}
/**
 setXy: sets the new coordinates of the marker according to the commands
 Pre: reciveves command struct and previous marker position and orientation
 Post: manipulates postion and orientation of marker with pointers
*/
void setXy(Command * com, int * x, int * y, char * ori) {

	//struct that is being pointed too has direction and value.

	char * tempdir = com->dir;

	int tempval = com->value;

	if ( strcmp(tempdir, "fd") == 0 ) {
		switch(*ori) {

			case 'U' :
				*y = *y - tempval;
				break;

			case 'D' :
				*y = *y + tempval;
				break;

			case 'L' :
				*x = *x - tempval;
				break;

			case 'R' :
				*x = *x + tempval;
				break;

		}
	}

	else if ( strcmp(tempdir, "bk") == 0 ) {
		switch(*ori) {

			case 'D' :
				*y = *y - tempval;
				break;

			case 'U' :
				*y = *y + tempval;
				break;

			case 'R' :
				*x = *x - tempval;
				break;

			case 'L' :
				*x = *x + tempval;
				break;

		}
	}

	else if (strcmp(tempdir, "lt") == 0) {
		if (tempval == 45) {
			switch(*ori) {
				case 'U' :
					*ori ='L';
					break;

				case 'D' :
					*ori ='R';
					break;

				case 'L' :
					*ori ='D';
					break;

				case 'R' :
					*ori ='U';
					break;

			}
		} else if (tempval == 90) {
			switch(*ori) {
				case 'U' :
					*ori ='D';
					break;

				case 'D' :
					*ori ='U';
					break;

				case 'L' :
					*ori ='R';
					break;

				case 'R' :
					*ori ='L';
					break;

		     }
		
	       } else {

			mvprintw(20,0, "Not a Valid command. Please try again : ");
	     }
     }

	else if (strcmp(tempdir, "rt") == 0) {
		if (tempval == 45) {
			switch(*ori) {
				case 'U' :
					*ori ='R';
					break;

				case 'D' :
					*ori ='L';
					break;

				case 'L' :
					*ori ='U';
					break;

				case 'R' :
					*ori ='D';
					break;

			}
		} else if (tempval == 90) {
			switch(*ori) {
				case 'U' :
					*ori ='D';
					break;

				case 'D' :
					*ori ='U';
					break;

				case 'L' :
					*ori ='R';
					break;

				case 'R' :
					*ori ='L';
					break;

		     }
		
	       } else {

			mvprintw(20,0, "Not a Valid command. Please try again : ");
	     }
		
	}
	move(21,1);	
}
/**
 printMarker: prints marker with proper position and symbol
 Pre: current marker postion and orientation
 Post: NULL
*/
void printMarker(int * x, int * y, char * ori) {
	if (*ori == 'U') {
		mvaddch(*y,*x,ACS_UARROW);
	} 
	else if (*ori == 'D') {
		mvaddch(*y,*x,ACS_DARROW);
	}
	else if (*ori == 'L') {
		mvaddch(*y,*x,ACS_LARROW);
	}
	else if (*ori == 'R') {
		mvaddch(*y,*x,ACS_RARROW);
	}
}
/**
 drawHorizontal: Draws the horizontal line according to previous marker postion
 Pre: previous marker position and new marker postion and colour 
 Post: NULL
*/
void drawHorizontal (int * x, int * y, int * xpos, char c) {
	
	//drawing to the right
	if (*x < *xpos) {
		for (int i = *x ; i < *xpos ; i++) {

			if (c = 'B') {
				attron(COLOR_PAIR(1)); 
				mvaddch(*y,i,ACS_HLINE);
				attroff(COLOR_PAIR(1)); 	
			}

			else if (c = 'Y') {
				attron(COLOR_PAIR(2)); 
				mvaddch(*y,i,ACS_HLINE);
				attroff(COLOR_PAIR(2)); 	
			}

			else if (c = 'G') {
				attron(COLOR_PAIR(4)); 
				mvaddch(*y,i,ACS_HLINE);
				attroff(COLOR_PAIR(4)); 	
			}

			else if (c = 'R') {
				attron(COLOR_PAIR(3)); 
				mvaddch(*y,i,ACS_HLINE);
				attroff(COLOR_PAIR(3)); 	
			}

			
		}

	} else { //draw to the left
		for (int i = *x ; i > *xpos ; i--) {

			if (c = 'B') {
				attron(COLOR_PAIR(1)); 
				mvaddch(*y,i,ACS_HLINE);
				attroff(COLOR_PAIR(1)); 	
			}

			else if (c = 'Y') {
				attron(COLOR_PAIR(2)); 
				mvaddch(*y,i,ACS_HLINE);
				attroff(COLOR_PAIR(2)); 	
			}

			else if (c = 'G') {
				attron(COLOR_PAIR(4)); 
				mvaddch(*y,i,ACS_HLINE);
				attroff(COLOR_PAIR(4)); 	
			}

			else if (c = 'R') {
				attron(COLOR_PAIR(3)); 
				mvaddch(*y,i,ACS_HLINE);
				attroff(COLOR_PAIR(3)); 	
			}
		}

	} 
	
}
/**
 drawVertical: Draws the Vertical line according to previous marker postion
 Pre: previous marker position and new marker postion and colour 
 Post: NULL
*/
void drawVertical(int * x, int * y, int * ypos, char * c) {

	//drawing upwards
	if (*y < *ypos) {
		for (int i = *y ; i < *ypos ; i++) {
			if (*c = 'B') {
				attron(COLOR_PAIR(1));
				mvaddch(i,*x,ACS_VLINE);
				
			}

			else if (*c = 'Y') {
				attron(COLOR_PAIR(2));
				mvaddch(i,*x,ACS_VLINE);
				
			}

			else if (*c = 'G') {
				attron(COLOR_PAIR(4));
				mvaddch(i,*x,ACS_VLINE);
				
			}

			else if (*c = 'R') {
				attron(COLOR_PAIR(3));
				mvaddch(i,*x,ACS_VLINE);
				
			}
		}

	} else { //drawing downwards
		for (int i = *y ; i > *ypos ; i--) {

			if (*c = 'B') {
				attron(COLOR_PAIR(1));
				mvaddch(i,*x,ACS_VLINE);
				
			}

			else if (*c = 'Y') {
				attron(COLOR_PAIR(2));
				mvaddch(i,*x,ACS_VLINE);
				
			}

			else if (*c = 'G') {
				attron(COLOR_PAIR(4));
				mvaddch(i,*x,ACS_VLINE);
				
			}

			else if (*c = 'R') {
				attron(COLOR_PAIR(3));
				mvaddch(i,*x,ACS_VLINE);
				
			}
		}

	}

	attroff(COLOR_PAIR(1));
	attroff(COLOR_PAIR(2));
	attroff(COLOR_PAIR(3));
	attroff(COLOR_PAIR(3));
}
/**
 changeColor: changes color of draw according to string passed
 Pre: previous colour and string of new colour 
 Post: NULL
*/
void changeColor(char * c, char * s) {
	char * token;
	//char * color;

	token = strtok(s," ");
	token = strtok(NULL," ");

	if (strcmp(token,"blue") == 0) {
		*c = 'B';
	}

	if (strcmp(token,"red") == 0) {
		*c = 'R';
	}

	if (strcmp(token,"yellow") == 0) {
		*c = 'Y';
	}

	if (strcmp(token,"green") == 0) {
		*c = 'G';
	}
} 