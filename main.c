#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include<time.h>

void draw(int Apple[],int SnakeX[],int SnakeY[],int length,int Quit);
void fruit(int Apple[]);
void delay(int milli_seconds);
int GetKey(int Mode);
void Change_The_Snake_Location(int Snake_x[], int Snake_y[], int Length_Of_Snake);
void Prepare_Snake_For_Printing(int Snake_x[], int Snake_y[], int Snake_x_print[], int Snake_y_print[], int Length_Of_Snake);
int Did_The_Snake_Eat_Itself(int Snake_x[], int Snake_y[],int Length_of_snake);
int Did_The_Snake_Hit_The_Boarder(int SnakeX[], int SnakeY[]);
int Should_The_Game_Stop(int Snake_x[], int Snake_y[],int Length_of_snake);


/*
Name:
Prupose:
Input Name:
Input type:
Input method:
Input meaning:
Output Name:
Output type:
Output method:
Output meaning:
Source:
*/


int main()
{
    int length=1;
    int SnakeX[10000] = {1};
    int SnakeY[10000] = {0};
    int SnakeX_Print[10000] = {1};
    int SnakeY_Print[10000] = {0};
    int Apple[2] = {10,10};
    int Quit = 3;
    int level_of_diffculity = 1;

    printf("Chose level of difficulity:\n1)super hard\n2)hard\n3)mid\n4)easy\n5)How old are you!! 2 days?!!!\nYour choice: ");
    scanf("%d",&level_of_diffculity);

    fruit(Apple);

    while(Quit)
    {
        system("cls");

        if(SnakeX[0]==Apple[0] && SnakeY[0]==Apple[1])
        {
          fruit(Apple);
          length++;
        }

        Change_The_Snake_Location(SnakeX,SnakeY, length);
        Prepare_Snake_For_Printing(SnakeX, SnakeY, SnakeX_Print, SnakeY_Print, length);
        draw(Apple,SnakeX_Print,SnakeY_Print,length,Quit);

        delay(level_of_diffculity*level_of_diffculity*level_of_diffculity*7+30);
        if(Should_The_Game_Stop(SnakeX,SnakeY, length) == -1)
        {
            Quit--;
            length = 1;
            SnakeX[0] = 1;
            SnakeY[0] = 0;
            GetKey(2);
        }

    }

    system("cls");
    printf("Game Over, Sweete....\n\n\n\n");

    return 0;
}



/*
Name: draw
Prupose: Printing everything on colsole
Input Name: Apple,                    SnakeX                                     SnakeY,                                         length                     Quit
Input type: Array of integers,        Array of integers                          Array of integers,                              int                        int
Input method: By reference,           By reference,                              By reference,                                   By value                   value
Input meaning: Location of the Apple, The x location of every part of the snake, The y location of every part of the snake,      The score of the snake,    Numver of lives left
Output Name: None
Output type: Text on console
Output method: None
Output meaning: the whole snake game
Source: Yousef,Ibrahim
*/
void draw(int Apple[],int SnakeX[],int SnakeY[],int length,int Quit)
{
    int num=15;
    int Snake_Counter = 0;
    for(int i=0; i<num*2; i++)
    {
        printf("#");
    }
    printf("\n");
    for(int i=0; i<=num; i++)
    {
        for(int j=0; j<=num*2; j++)
        {
            if (SnakeX[Snake_Counter]==j && SnakeY[Snake_Counter]==i && Snake_Counter<length)
            {
                printf("*");
                Snake_Counter++;
            }
            else if (Apple[0]==j && Apple[1]==i)
            {
                 printf("O");
            }
            else if(j>0 && j<num*2)
            {
               printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
    for(int i=0; i<num*2; i++)
    {
        printf("#");
    }
    printf("\nYour score is :%d    Number of lives left: %d",length*10,Quit);
    printf("\nSnake head x,y = %d,%d",SnakeX[0],SnakeY[0]);
    printf("\nApple x,y = %d,%d",Apple[0],Apple[1]);
}

/*
Name: fruit
Prupose: Generate the location of the apple randomly
Input Name: Apple
Input type: Array of integers
Input method: By referance
Input meaning: The array stores the x and y coordinates of the apple
Output Name: None
Output type: None
Output method: None
Output meaning: None
Source: Ibrahim
*/
void fruit(int Apple[])
{
    //              Max-min + min
    //              Range   + min
    Apple[0]=rand()%(29-1) + 1;
    Apple[1]=rand()%(15-1) + 1;
}

/*
Name: Delay
Prupose: Delay the system from functioning for some time
Input Name: milli_seconds
Input type: int
Input method: By value
Input meaning: number of miliseconds you want to delay
Output Name: None
Output type: None
Output method: None
Output meaning:None
Source: Copy paste from Google
*/
///walahi ma fahmin haia bata3mil eh f wanabi bara7a 3alina a7ana 8alaba, bas ta2riban howa bai baigib 2l time bata3 2l gahaz w ba3d kada yazawid 3alh 2l time bata3 2l delay, then ya loop la7ad ma 2l time ya match w since 2n 2l pc sari3 awiiii f kada kada hai3adi 3ala 2l time da w m4 haia3malo skip 2w 7aga
void delay(int milli_seconds)
{
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

/*
Name: GetKey
Prupose: Check if there is a pressed key, if yes, get the value as long as it is a w,s,d or a,dssddd if not, ignore that key
Input Name: Mode
Input type: int
Input method: by value
Input meaning: Which operatoin to perform
Output Name: key
Output type: int
Output method: By value
Output meaning: The direction of movement of the snake
Source: Soliman
*/
int GetKey(int Mode)
{
    static int Previous_key = 'd';
    int key;

    if(Mode == 1)
    {
        if(kbhit())
        {
            key = getch();
        }

        if((key == 'w' || key == 's' || key == 'd' || key == 'a') && (Previous_key != 'w' && key == 's') || (Previous_key != 's' && key == 'w') || (Previous_key != 'a' && key == 'd') || (Previous_key != 'd' && key == 'a'))
        {
            Previous_key = key;
        }
        else
        {
            key = Previous_key;
        }
    }
    else if(Mode == 2)
    {
        Previous_key = 'd';
    }

    return key;
}

/*
Name: Change_The_Snake_Location
Prupose: Change the location of the whole snake if according to the input key, or the previous location
Input Name:    Snake_x                                    Snake_y                                       Length_Of_Snake
Input type:    Array of integers                          Array of integers                             int
Input Method: Be reference                                By reference                                  By value
Input meaning: The x location of every part of the snake, The y location of every part of the snake,    Current Length of snake
Output Name: None
Output type: None
Output methode: By reference
Output meaning: The new location of the every part of the snake
Source: Ibrahim,Slem
*/
void Change_The_Snake_Location(int Snake_x[], int Snake_y[], int Length_Of_Snake)
{
    int Counter = 0;
    int Current_Location_Of_Head[] = {Snake_x[0],Snake_y[0]};
    int key = GetKey(1);

    if(key != -1)
    {
        for(int i = Length_Of_Snake-2; i>-1; i--)
        {
            Snake_x[i+1] = Snake_x[i];
            Snake_y[i+1] = Snake_y[i];
        }

        if(key == 'w')
        {
            Snake_y[0] = Snake_y[0]-1;
        }
        else if(key == 's')
        {
            Snake_y[0] = Snake_y[0]+1;
        }
        else if(key == 'd')
        {
            Snake_x[0] = Snake_x[0]+1;
        }
        else if(key == 'a')
        {
            Snake_x[0] = Snake_x[0]-1;
        }
    }
}

/*
Name: Prepare_Snake_For_Printing
Prupose: Change the location of the whole snake if according to the input key, or the previous location
Input Name:    Snake_x                                    Snake_y                                   	Snake_x_print                                  Snake_y_print                                   Length_Of_Snake
Input type:    Array of integers                          Array of integers                             Array of integers                              Array of integers                               int
Input Method:  Be reference                               By reference                                  Be reference                                   By reference                                    By value
Input meaning: The x location of every part of the snake, The y location of every part of the snake,    The array that will be used to print x values, The array that will be used to print x values,  Current Length of snake
Output Name: None
Output type: None
Output methode: By reference
Output meaning: The Snake in the proper of order for printing
Source: Soliman
*/
///wenabi ya Doctor matas2ali4 7ad 8iri fal function di 3al4an 7awalt a4ra7lohom haia bata3mil eh bas ma7adi4 fahim 7aga
void Prepare_Snake_For_Printing(int Snake_x[], int Snake_y[], int Snake_x_print[], int Snake_y_print[], int Length_Of_Snake)
{
    for(int i = 0; i<Length_Of_Snake+1; i++)
    {
        Snake_x_print[i] = Snake_x[i];
        Snake_y_print[i] = Snake_y[i];
    }

    for(int i = 0; i<Length_Of_Snake-1; i++)
    {
        for(int j = 0; j<Length_Of_Snake-1; j++)
        {
            if(Snake_x_print[j] > Snake_x_print[j+1])
            {
                Snake_x_print[j+1] = Snake_x_print[j+1] + Snake_x_print[j];
                Snake_x_print[j] = Snake_x_print[j+1] - Snake_x_print[j];
                Snake_x_print[j+1] = Snake_x_print[j+1] - Snake_x_print[j];

                Snake_y_print[j+1] = Snake_y_print[j+1] + Snake_y_print[j];
                Snake_y_print[j] = Snake_y_print[j+1] - Snake_y_print[j];
                Snake_y_print[j+1] = Snake_y_print[j+1] - Snake_y_print[j];

            }
        }
    }

    for(int i = 0; i<Length_Of_Snake-1; i++)
    {
        for(int j = 0; j<Length_Of_Snake-1; j++)
        {
            if(Snake_y_print[j] > Snake_y_print[j+1])
            {
                Snake_y_print[j+1] = Snake_y_print[j+1] + Snake_y_print[j];
                Snake_y_print[j] = Snake_y_print[j+1] - Snake_y_print[j];
                Snake_y_print[j+1] = Snake_y_print[j+1] - Snake_y_print[j];

                Snake_x_print[j+1] = Snake_x_print[j+1] + Snake_x_print[j];
                Snake_x_print[j] = Snake_x_print[j+1] - Snake_x_print[j];
                Snake_x_print[j+1] = Snake_x_print[j+1] - Snake_x_print[j];
            }
        }
    }
}

/*
Name: Did_The_Snake_Eat_Itself
Prupose: Change the location of the whole snake if according to the input key, or the previous location
Input Name:    Snake_x                                    Snake_y                                       Length_Of_Snake
Input type:    Array of integers                          Array of integers                             int
Input Method: Be reference                                By reference                                  By value
Input meaning: The x location of every part of the snake, The y location of every part of the snake,    Current Length of snake
Output Name: Flag
Output type: int
Output methode: By value
Output meaning: Check the action happened or not
Source: Soliman
*/
int Did_The_Snake_Eat_Itself(int Snake_x[], int Snake_y[],int Length_of_snake)
{
    int Flag = 0;

        for(int j = 1; j<Length_of_snake;j++)
        {
            if(Snake_x[0] == Snake_x[j] && Snake_y[0] == Snake_y[j])
            {
                Flag = 1;
                break;
            }
        }

    return Flag;
}


/*
Name: Change_The_Snake_Location
Prupose: Change the location of the whole snake if according to the input key, or the previous location
Input Name:    Snake_x                                    Snake_y
Input type:    Array of integers                          Array of integers
Input Method: Be reference                                By reference
Input meaning: The x location of every part of the snake, The y location of every part of the snake
Output Name: Flag
Output type: int
Output methode: By value
Output meaning: Check the action happened or not
Source: Soliman,Slem
*/
int Did_The_Snake_Hit_The_Boarder(int SnakeX[], int SnakeY[])
{
    int Flag = 0;
    if(SnakeX[0] == 0 || SnakeY[0] == -1 || SnakeX[0] == 30 || SnakeY[0] == 16)
    {
        Flag = 1;
    }
    return Flag;
}

/*
Name: Change_The_Snake_Location
Prupose: Change the location of the whole snake if according to the input key, or the previous location
Input Name:    Snake_x                                    Snake_y                                       Length_Of_Snake
Input type:    Array of integers                          Array of integers                             int
Input Method: Be reference                                By reference                                  By value
Input meaning: The x location of every part of the snake, The y location of every part of the snake,    Current Length of snake
Output Name: Quit
Output type: int
Output methode: By value
Output meaning: Confirmation to stop or not.
Source: Soliman
*/
int Should_The_Game_Stop(int Snake_x[], int Snake_y[],int Length_of_snake)
{
    int Quit = 0;
    if(Did_The_Snake_Eat_Itself(Snake_x,Snake_y,Length_of_snake) || Did_The_Snake_Hit_The_Boarder(Snake_x,Snake_y))
    {
        Quit = -1;
    }

    return Quit;
}

