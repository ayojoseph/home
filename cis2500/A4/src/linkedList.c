// #include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedList.h"

Food * createRecord(char * name, char * group, double calories, char theType) {

	Food * tempFood;
	tempFood = malloc(sizeof(Food));
    tempFood->name = malloc(sizeof(char*));
	strcpy(tempFood->name,name);
	tempFood->foodGroup = malloc(sizeof(char*));
	strcpy(tempFood->foodGroup,group);
	tempFood->calories = calories;
	tempFood->type = theType;
	return tempFood;
}

char * printRecord(Food * toPrint) {
	char * string;

	string = malloc(sizeof(char*));

	sprintf(string,"%s (%s): %.2lf[%c]",toPrint->name,toPrint->foodGroup,toPrint->calories,toPrint->type);

	// printf("%s\n",string);
	return string;

}

void destroyElement(Food * theElement) {

//	free(theElement);
	 free(theElement->foodGroup);
	 free(theElement->name);
	// theElement->calories = 0;
	 theElement->type = '\0';
	// free(theElement->next);

	// free(theElement->calories);
	// free(theElement->type);
}

Food * addToFront(Food * theList, Food * toBeAdded) {

	 Food * foodSent;
	 foodSent = malloc(sizeof(Food));
	 foodSent = toBeAdded;
	 foodSent->next = theList;
	 theList = foodSent;
	 return theList;
}

Food * addToBack(Food * theList, Food * toBeAdded) {
    Food * foodPos;
    foodPos = theList;
    while (foodPos != NULL) {
        foodPos = foodPos->next;
    }
    foodPos->next = malloc(sizeof(Food));
    foodPos->next = toBeAdded;
    foodPos->next->next  = NULL;
    return foodPos;
}

Food * removeFromFront(Food * theList) {

    Food * sec;
    if (theList != NULL) {
        sec = theList->next;
        theList = NULL;
        return sec;
    } else {
        return NULL;
    }
}

Food * removeFromBack(Food * theList) {
    if (theList != NULL) {
        if (theList->next == NULL) {
            return NULL;
        } else {
            while (theList->next != NULL) {
                theList = theList->next;
            }
        }
        return theList;
    } else {
        return NULL;
    }
}

Food * getLastItem(Food * theList) {
    if (theList == NULL) {
        return NULL;
    } else {
        while (theList->next != NULL) {
            theList = theList->next;
        }
            return theList;
    }
}

bool isEmpty(Food * theList) {
    if (theList == NULL) {
        return true;
    } else {
        return false;
    }
}

void printList(Food * theList) {
    while (theList != NULL) {
        printf("%s (%s): %.2lf[%c]\n",theList->name, theList->foodGroup, theList->calories, theList->type);
        theList = theList->next;
    }

}

void destroyList(Food * theList) {
    Food * temp;

    while (theList != NULL) {
        temp = theList;
        theList = temp->next;
        free(temp->name);
        free(temp->foodGroup);
        free(temp);
        
    }
}