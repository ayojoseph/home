#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedList.h"

int main(int argc, char * argv[]) {

	//char * input;
	FILE * infile;
	Food * Head; //array of food
	// Food * Last;
	char * * stringArray;
	double cal = 0;
	char  type;
	char * foodGroup;
	char * foodName;
	int foodNum = 0;
	char buffer[150];
	char * token;
	char ** convertend;
	int sum = 0;
	double Vsum = 0;
	double Msum = 0;
	double Gsum = 0;
	double Dsum = 0;
	double Fsum = 0;

	double Vavg = 0;
	double Mavg = 0;
	double Davg = 0;
	double Gavg = 0;
	double Favg = 0;

	double Vnum = 0;
	double Mnum = 0;
	double Gnum = 0;
	double Fnum = 0;
	double Dnum = 0;
	// char * teststr;

	// teststr = malloc(sizeof(char*));
//	Head = malloc(sizeof(Food));
	stringArray = malloc(sizeof(char*)*20);
	// foodArray = malloc(sizeof(Food*)*20);
	foodName = malloc(sizeof(char*));
	foodGroup = malloc(sizeof(char*));
	convertend = malloc(sizeof(char*));
	// type = malloc(sizeof(char*));

	// Head = malloc(sizeof(Food));
	// Head = createRecord(foodName, foodGroup, cal, type);
	// Head = Head->next;
if ( argc < 2 ) {
	printf("Not enough arguements.\n");
	exit(0);
}

if (argc > 1) {

	infile = fopen(argv[1],"r");

}
if (infile == NULL) {
	printf("File could not be opened\n");
	exit(0);
}

Food * nextLink;


 while (fgets(buffer,250,infile) != NULL) {

// fgets(buffer,250,infile) != NULL
 	   // fgets(buffer,250,infile);
 	 	buffer[strlen(buffer)-1] = '\0'; //removes null terminator
 		stringArray[foodNum] = malloc(sizeof(char)*(strlen(buffer)+1));
 		strcpy(stringArray[foodNum],buffer);

 		// //spliting strings into elements
 		token = strtok(stringArray[foodNum],",");
 		strcpy(foodName,token);
 		token = strtok(NULL,",");
 		strcpy(foodGroup,token);
 		token = strtok(NULL,",");
 		cal = strtod(token,convertend);
 		sum = sum + cal;
 		// printf("%.1lf\n",cal );
 		token = strtok(NULL,",");
 		// strcpy(type,*token);
 		type = token[0];

 		switch(tolower(foodGroup[0]))  {

 			case 'f':
 				Fnum++;
 				Fsum = Fsum + cal;
 				break;

 			case 'v':
 				Vnum++;
 				Vsum = Vsum + cal;
 				break;

 			case 'm':
 				Mnum++;
 				Msum = Msum + cal;
 				break;

 			case 'g':
 				Gnum++;
 				Gsum = Gsum + cal;
 				break;

 			case 'd':
 				Dnum++;
 				Dsum = Dsum + cal;
 				break;
 		}

 		if (foodNum == 0) {
 			Head = createRecord(foodName, foodGroup, cal, type);

 		}

        if (foodNum == 1) {
        	if (type == 'h') {
        		Food * temp;
        		temp = Head;
            	nextLink = createRecord(foodName, foodGroup, cal, type);
            	Head = nextLink;
            	Head->next = temp;
       		} else {
       			nextLink = createRecord(foodName, foodGroup, cal, type);
            	Head->next = nextLink;
       		}
           
        }
 		if (foodNum > 1) {
 			Food * tempPtr;
 		    tempPtr = createRecord(foodName, foodGroup, cal, type);
 			if (type == 'h') {
 				Head = addToFront(Head,tempPtr);
 			} else {
 		    	nextLink->next = tempPtr;
 		    	nextLink = nextLink->next;
 			}
 		}
 		if (foodNum == 4) {
// 		    Head = removeFromFront(Head);
 		}

 	 foodNum++;
 }
 //Calculating averages....
 	Vavg = Vsum/Vnum;
 	Mavg = Msum/Mnum;
 	Davg = Dsum/Dnum;
 	Favg = Fsum/Fnum;
 	Gavg = Gsum/Gnum;
   // teststr = printRecord(Last);
//    destroyElement(Head->next->next);
    printf("%d\n",sum);
    printf("%.2lf\n",Vavg);
    printf("%.2lf\n",Mavg);
    printf("%.2lf\n",Davg);
    printf("%.2lf\n",Gavg);
    printf("%.2lf\n",Favg);
    // printf("%c\n",foodGroup[1] );
    printList(Head);
    
//	printf("%s\n",Head->next->next->next->foodGroup);
    destroyList(Head);
	return 0;
}