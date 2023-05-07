/*

Program: CLI Pomodoro Timer
Author: William Nathanael Santoso
Date Written: 07/05/2023

The following program creates a simple CLI Pomodoro timer. 
The general aesthetic of the program takes heavy inspiration from the wonderful Wisdom Tree program by HACKER097
https://github.com/HACKER097/wisdom-tree

*/

#include <stdio.h>

int main()
{
    int flag = 1;
    int timerActive = 0;
    int modeMain;
    int modeTimer;
    int rawTime;

    while (flag)
    {
        do
        {
            printf("Press 0 to view the instructions, 1 to go to the timer, or 2 to exit the program.\n");
            scanf("%d", &modeMain);
        }while(modeMain != 0 && modeMain != 1 && modeMain != 2);

        if (modeMain == 0)
        {
            printf("\nThe Pomodoro Technique is a time management method developed by Francesco Cirillo in the late 1980s.\n");
            printf("The technique uses a timer to break down work into intervals, separated by short breaks.\n");
            printf("Traditionally, work sessions are broken up into 25 minute interval with a 5 minute break in between each interval.\n\n");

            printf("You will be able to choose the number of intervals you want to work for and how long you want each of those intervals to be.\n");
            printf("You will also be able to choose how long you want your breaks to be.\n");
            printf("The timer will then count down the time for each interval and break.\n");
            printf("When the timer is done, you will be able to choose whether you want to continue working or stop.\n\n");
            printf("If you want to stop the timer before it is done, you will be able to do so.\n");

            printf("Note: The maximum number of hours you can work for is 24 hours because... well frankly doing more than that is deeply concerning.\n\n");

            do
            {
                printf("Press 0 to go back to the main menu\n");
                scanf("%d", &modeMain);
            } while (modeMain != 0);
            
            
        }
        else if (modeMain == 1)
        {
            printf("You have chosen to go to the timer.\n");

            if (timerActive == 0)
            {
                do
                {
                    printf("Press 0 to go back to the main menu, 1 to edit the session, or 2 to start the session\n");
                    scanf("%d", &modeTimer);
                } while (modeTimer != 0 && modeTimer != 1 && modeTimer != 2);

                if (modeTimer == 0)
                {
                    modeMain = 0;
                    continue;
                }
                else if (modeTimer == 1)
                {
                    printf("Please enter the number of intervals you want to work for.\n");
                    scanf("%d", &rawTime);
                    printf("Please enter the length of each interval in minutes.\n");
                    scanf("%d", &rawTime);
                    printf("Please enter the length of each break in minutes.\n");
                    scanf("%d", &rawTime);
                }
            }
            else
            {
                printf("You have already started the timer.\n");
            }
            

        }
        
        if (modeMain == 2)
        {
            printf("You have chosen to exit the program.\n");
            flag = 0;
        }
        
    }
}