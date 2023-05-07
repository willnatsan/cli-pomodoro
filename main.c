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

    int modeMain = 0;
    int modeTimer;

    int rawTime;

    // typedef struct time
    // {
    //     int hoursWork;
    //     int minutesWork;
    //     int secondsWork;

    //     int hoursBreak;
    //     int minutesBreak;
    //     int secondsBreak;
    // }time;

    while (flag)
    {
        if (modeMain == 0)
        {
            printf("\t\t       __      __       .__                               \n");
            printf("\t\t      /  \\    /  \\ ____ |  |   ____  ____   _____   ____  \n");
            printf("\t\t      \\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\ \n");
            printf("\t\t       \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/ \n");
            printf("\t\t        \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >\n");
            printf("\t\t             \\/       \\/          \\/            \\/     \\/\n\n");

            printf("\t\t\t\t           __          \n");
            printf("\t\t\t\t         _/  |_  ____  \n");
            printf("\t\t\t\t         \\   __\\/  _ \\ \n");
            printf("\t\t\t\t          |  | (  <_> )\n");
            printf("\t\t\t\t          |__|  \\____/ \n\n");

            printf("\t_________ .____    .___  __________                         .___                   \n");
            printf("\t\\_   ___ \\|    |   |   | \\______   \\____   _____   ____   __| _/___________  ____  \n");
            printf("\t/    \\  \\/|    |   |   |  |     ___/  _ \\ /     \\ /  _ \\ / __ |/  _ \\_  __ \\/  _ \\ \n");
            printf("\t\\     \\___|    |___|   |  |    |  (  <_> )  Y Y  (  <_> ) /_/ (  <_> )  | \\(  <_> )\n");
            printf("\t \\______  /_______ \\___|  |____|   \\____/|__|_|  /\\____/\\____ |\\____/|__|   \\____/ \n");
            printf("\t        \\/        \\/                           \\/            \\/                    \n");

            do
            { 
                printf("\n  Press:\n\t[1] to view the instructions\n\t[2] to go to the timer\n\t[3] to exit the program\n  Enter your choice here: ");
                scanf("%d", &modeMain);
            }while(modeMain != 1 && modeMain != 2 && modeMain != 3);
        } 
        

        else if (modeMain == 1)
        {
            printf("\nThe Pomodoro Technique is a time management method developed by Francesco Cirillo in the late 1980s.\n");
            printf("The technique uses a timer to break down work into intervals, separated by short breaks.\n");
            printf("Traditionally, work sessions are broken up into 25 minute interval with a 5 minute break in between each interval.\n\n");

            printf("You will be able to choose the number of intervals you want to work for and how long you want each of those intervals.\n");
            printf("The breaks will be automatically calculated to be roughly a fourth of the work time (This has been shown to be the ideal)\n");
            printf("The timer will then count down the time for each interval and break.\n");
            printf("When the timer is done, you will be able to choose whether you want to continue working or stop.\n\n");
            printf("If you want to stop the timer before it is done, you will be able to do so.\n\n");

            printf("Note: The maximum number of hours you can work for is 24 hours because... well frankly doing more than that is concerning.\n\n");

            do
            {
                printf("\n  Press:\n\t[0] to go back to the main menu\n\t[3] to exit the program\n  Enter your choice here:");
                scanf("%d", &modeMain);
            } while (modeMain != 0 && modeMain != 3);
            
            
        }
        else if (modeMain == 2)
        {
            printf("You have chosen to go to the timer.\n");

            if (timerActive == 0)
            {
                do
                {
                    printf("\n  Press:\n\t[0] to go back to the main menu\n\t[1] to edit the session\n\t[2] to start the session\n  Enter your choice here: ");
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
        
        if (modeMain == 3)
        {
            printf("You have chosen to exit the program.\n");
            flag = 0;
        }
    }
}