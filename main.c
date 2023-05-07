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
    int mode;

    while (flag)
    {
        do
        {
            printf("Press 0 to view the instructions, 1 to go to the timer, and 2 to exit the program.\n");
            scanf("%d", &mode);
        }while(mode != 0 && mode != 1 && mode != 2);

        if (mode == 0)
        {
            printf("\nThe Pomodoro Technique is a time management method developed by Francesco Cirillo in the late 1980s.\n");
            printf("The technique uses a timer to break down work into intervals, separated by short breaks.\n");
            printf("Traditionally, work sessions are broken up into 25 minute interval with a 5 minute break in between each interval.\n\n");

            printf("You will be able to choose the number of intervals you want to work for and how long you want each of those intervals to be.\n");
            printf("You will also be able to choose how long you want your breaks to be.\n");
            printf("The timer will then count down the time for each interval and break.\n");
            printf("When the timer is done, you will be able to choose whether you want to continue working or stop.\n\n");

            printf("Note: If you want to stop the timer before it is done, you will be able to do so.\n\n");

            do
            {
                printf("Press 0 to go back to the main menu or 2 to exit the program.\n");
                scanf("%d", &mode);
            } while (mode != 0 && mode != 2);
            
            
        }
        else if (mode == 1)
        {
            printf("You have chosen to go to the timer.\n");
        }
        
        if (mode == 2)
        {
            printf("You have chosen to exit the program.\n");
            flag = 0;
        }
        
    }
}