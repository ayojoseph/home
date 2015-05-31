 /*************************Assignment 1.c*******************************
 Student Name: Love Joseph                                   Student Number: 0890515
 Date: January 16th, 2015                                           Course Name: CIS2500
 I have exclusive control over this submission via my password.
 By including this statment in this header comment, I certify that:
 1) I have read and understood the University polict on academic integrity;
 2) I have completed the Computing with Integrity Self Test
 3)I have achieved at least 80% in the Computing with Integrity Test
 I assert that this work is my own. I have approipratiely acknowledged any and all material
 (data, images, ideas or words) that I have used, whether directly quoted or paraphraased.
 Furthermore, I certify that this assignment was prepared by me specifically for this course.
 *******************************************************************************/

#include <ncurses.h>
#include <string.h>

#define UP  'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'


//intitalizing ncurses

//fuction protos
void drawboard();
int movement(char val,int *gri);
int playGame(int p, int *gri, int br[][6]);
int shader(int *gri,int br[][6],int w);
int  wincheck(int w, int br[][6]);



int main()
{


//varibles
int player;
char key,exit;
int board [6][6];
int grid[2] = {0,0};


player = 3;
int win = 1;
char hum1 [50];
char hum2 [50];

//board array initialiization

for(int i = 0;i<6; i++)
{
    for(int j = 0; j<6; j++)
    {
        board[i][j] = 0;
    }
}

   // Intro and user name prompts
    printf("Welcome to obstruction!\n");
    printf("Enter name for player 1: ");
    fgets(hum1,50,stdin);
    printf("\n");
    printf("Enter name for player 2: ");
    fgets(hum2,50,stdin);
    
    
    //start of ncurses screen
    initscr();
    cbreak();
    noecho();
  //draws board and instructions 
    drawboard();
    mvprintw(1,30,"Instructions: ");
    mvprintw(2,30,"Use WSAD keys to move around board. ");
    mvprintw(3,30,"use Q to end game or win.");
    refresh();
 //moves cursor to top left
    move(1,1);
    
   //main game loop
   
    do{
            //checks if exit key pressed
             exit = getch();
             if(exit == 'q')
             {
                break;
             }
          //prints out which users turn it is
            if(player % 2 == 0)
            {
                mvprintw(11,1, "%s's turn", hum1);
                move(1,1);
            }
            else
            {
                mvprintw(11,1, "%s's turn", hum2);
                move(1,1);
            
            }
            //movemnt loop that contiually checks keystrokes
        while(key!='\n')
        {
        

            
            key = getch();
           movement(key, grid);

            
        }
        key = 'u';
        player++;
       
        playGame(player,grid,board);
       
       
        shader(grid,board,win);
        move(1,1);
        grid[1] = 0;
        grid[0] = 0;
        
       
    }while(exit != 'q');   
    
    
  endwin();
  printf("game has ended. Thanks for playing.\n");



    return 0;
}


//draws board
void drawboard()
{

    for(int i=0;i<12;i++)
    {
        if(i%2==1){
            printw("_");
        }else{
            printw(" ");
         }
    }
    printw("\n");

    for(int k=0;k<6; k++)
    {
        for(int i=0;i<12;i++)
        {
            if(i%2 == 1){
                printw("_");
                }else{
                    printw("|");
                }

        }

        printw("|");
        printw("\n");
    }  
    refresh();

}



//movement funct that moves cursor on board and keeps it on board
int movement(char val,int *gri)
{


    char key = val;
    int x,y = 0;
    
    getyx(stdscr,y,x);
    
    switch (key)
    {
        case UP:
            if(y <= 1)
            {
                y = 6;
                gri[1] = 5;
                move(y,x);
            }
            else
            {
                y = y - 1;
                gri[1] = gri[1] - 1;
                move(y,x);
            }
        case DOWN:
            if(y >= 6)
            {
                y = 1;
                gri[1] = 0;
                move(y,x);
            }
            else
            {
                y = y + 1;
                gri[1] = gri[1] + 1;
                move(y,x);

            }
//            printw("down\n");
            break;

        case RIGHT:
            if(x >= 11)
            {
                x = 1;
                gri[0] = 0;
                move(y,x);
            }
            else
            {
                x = x + 2;
                gri[0] = gri[0] + 1;
                move(y,x);
            }
//            printw("right\n");
            break;

        case LEFT:
            if(x <= 1)
            {
                x = 11;
                gri[0] = 5;
                move(y,x);

            }
            else
            {
                x = x - 2;
                gri[0] = gri[0] - 1;
                move(y,x);
            }
//            printw("left\n");
            break;
         //default:
            //printw("error");




    }

    //mvprintw(9,9,"%d",gri[0]);
    //mvprintw(10,9,"%d",gri[1]);
    move(y,x);
    refresh();
    return *gri;
}

int playGame(int p,int *gri, int br[][6])
{
    //int player = p;
    //int x,y;

    //getyx(stdscr,y,x);
    //mvprintw(11,11,"%d",br[0][0]);
    if((p % 2== 0)&&(br[gri[1]][gri[0]] == 0))
    {
        printw("O");
//        p = p + 1;
        move(1,1);
        
        
        br[gri[1]][gri[0]] = 7;

    }
    else if ((p % 2 == 1)&&(br[gri[1]][gri[0]] == 0))
    {
        printw("X");
  //      p = p + 1;
        move(1,1);
        br[gri[1]][gri[0]] = 7;
    }
    else
    {
        mvprintw(17,3,"cannot print there");
        move(1,1);
        p = p - 1;
    
    }


    return **br;

//return **br;

}

int shader(int *gri,int br[][6],int w)
{
    int x,y;
    x = gri[0];
    y = gri[1];
    //mvprintw(15,15,"active");
    //mvprintw(25,25,"%d",x);
    //mvprintw(26,25,"%d",y);
    //move(1,1);
    
    //inside boarder algorithm for taking up spaces
    if(((x > 0)&&(x < 5))&&((y < 5)&&(y > 0)))
    {
        br[y-1][x-1] = 5;
        br[y-1][x] = 5;
        br[y-1][x+1] = 5;
        br[y][x-1] = 5;
        br[y][x+1] = 5;
        br[y+1][x-1] = 5;
        br[y+1][x] = 5;
        br[y+1][x+1] = 5;
 //       mvprintw(15,15,"good");
        //move(1,1);
        
        
       
    }
    
    if(x == 0)
    {   //on left boarder but inbetween top and bottom boarders
        if((y > 0)&&(y<5))
        {
            br[y-1][x] = 5;
            br[y+1][x] = 5;
            br[y-1][x+1] = 5;
            br[y][x+1] = 5;
            br[y+1][x+1] = 5;
   //         mvprintw(19,15,"boarder mid good");
            //move(1,1);
        }
        else if(y == 0)
        {
            br[y][x+1] = 5;
            br[y+1][x] = 5;
            br[y+1][x+1] = 5;
            
     //       mvprintw(20,15,"boarder top good");
            //move(1,1);
        }
        else if(y == 5)
        {
            br[y][x+1] = 5;
            br[y-1][x] = 5;
            br[y-1][x+1] = 5;
       //     mvprintw(21,15,"boarder bottom good");
           // move(1,1);
        }
    
    
    }
//move(27,1);
 for(int i = 0; i<6; i++)
        {
            for(int k = 0; k<6; k++)
            {
             mvprintw(27,1,"%d",br[i][k]);
            
         
            }
        
        
        }
         w = wincheck(w, br);
        
    return w;
}

int wincheck(int w, int br[][6])
{

    int check = 0;
    for(int i = 0; i<6; i++)
    {
        for(int k = 0;k<6; k++)
        {
            if(br[i][k] == 0)
            {
                check++;
            }
        }
    }

return check;

}