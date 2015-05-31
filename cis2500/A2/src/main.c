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

int main (void) {
//varibles and initializations used
    int com = 0;
    int arraySize = 20;
    int x,y;
    char * * stringsArray;  //array of strings
    Command * * commandArray;
    Cursor draw;
    FILE * feedptr;
    feedptr = fopen("feed.txt","w");
    draw.xpos = 72;
	draw.ypos = 9;
	draw.ori = 'U';
	draw.pen = 1;
	draw.color  = 'B';
	x = 72;
	y = 9;
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	stringsArray = malloc(sizeof(char*)*arraySize);
	commandArray = malloc(sizeof(Command)*20);
    char buffer[50];
    echo();
	drawboard();
	move(21,1);	
	
		
	while (com < 40) {

		move(21,1);
		getstr(buffer);
		move(21,1);
		clrtoeol();

		if (strcmp(buffer, "exit") == 0) {
			break;

		}

		if (buffer != NULL) {
			if (strlen(buffer) < 2) {
				mvprintw(20,0,"Not a valid command. Try again: ");
				move(21,1);
				continue;
			} else {

				if ((strcmp(buffer, "pu") == 0)||(strcmp(buffer, "pd") == 0)) {
					
					draw.pen++;

				}

				else if (buffer == "save") {


				}

				else if (buffer == "new") {


				} 

				else if (strcmp(buffer, "setpencolor") == 0) {
					stringsArray[com] = malloc(sizeof(char)*(strlen(buffer)+1));
					strcpy(stringsArray[com],buffer);
					fprintf(feedptr, "%s,\n",stringsArray[com] );

					changeColor(&draw.color,stringsArray[com]);
					

				} else {

					stringsArray[com] = malloc(sizeof(char)*(strlen(buffer)+1));
					strcpy(stringsArray[com],buffer);
					fprintf(feedptr, "%s,\n",stringsArray[com] );

					x = draw.xpos;
					y = draw.ypos;
					
		
					commandArray[com] = getEditString(stringsArray[com]);
					mvaddch(draw.ypos,draw.xpos,' ');
					setXy(commandArray[com],&draw.xpos,&draw.ypos,&draw.ori);

					//executed only if pen is down
						if (draw.pen % 2 == 0) {
							if ((draw.ori == 'U')||(draw.ori == 'D')) {
								drawVertical(&x,&y,&draw.ypos,&draw.color);
							} else {
								drawHorizontal(&x,&y,&draw.xpos,draw.color);
							}
						}

					printMarker(&draw.xpos,&draw.ypos,&draw.ori);
					
					com++;
				} //code to split correct input
			} 

		} else {
				mvprintw(20,0,"Not a valid command. Try again: ");
				move(21,1);
			  }



	for (int i = 0; i< com ; i++) {

		mvprintw(i+2,1,"%s",stringsArray[i]);
	}
		 

	}//end of while loop

	fclose(feedptr);
	echo();
	endwin();
	return 0;
}
