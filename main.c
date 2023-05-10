/*

Program: CLI Pomodoro Timer
Author: William Nathanael Santoso
Date Written: 07/05/2023

The following program creates a simple CLI Pomodoro timer. 
The general aesthetic of the program takes heavy inspiration from the wonderful Wisdom Tree program by HACKER097
https://github.com/HACKER097/wisdom-tree

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

typedef struct session
{
    int active;

    int numIntervalsTarget;
    int numIntervalsCurr;

    int rawWorkTime;
    int rawBreakTime;

    int hoursWork;
    int minutesWork;
    int secondsWork;

    int hoursBreak;
    int minutesBreak;
    int secondsBreak;
}session;

typedef struct timeArt
{
    char *line0;
    char *line1;
    char *line2;
    char *line3;
    char *line4;
    char *line5;
}timeArt;

struct timeArt createTimeArt(int *time);
void printTimeArt(struct timeArt ta);
void setTimeParts(int *timeParts, int isWorking, struct session sessionCurr);
void resetWorkTime(struct session *sessionCurr);
void resetBreakTime(struct session *sessionCurr);
void endSession(struct session *sessionCurr, struct session *sessionsFinished, int *sessionsCount, int *timerActive);
void printSessionsFinished(struct session *sessionsFinished, int sessionsCount);

int main()
{
    int flag = 1;
    int isWorking = 1;
    int timerActive = 0;
    int timerPaused = 0;

    int modeMain = 0;
    int modeTimer;
    
    int timeParts[6];
    struct session sessionsFinished[100];
    int sessionsCount = 0;

    struct session sessionCurr;
    struct timeArt time;

    while (flag)
    {
        system("cls");

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
                printf("\n  Press:\n\t[1] to view the instructions\n\t[2] to go to the timer\n\t[3] to view your session history\n\t[4] to exit the program\n  Enter your choice here: ");
                scanf("%d", &modeMain);
            }while(modeMain != 1 && modeMain != 2 && modeMain != 3 && modeMain != 4);
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
                printf("\n  Press:\n\t[0] to go back to the main menu\n\t[4] to exit the program\n  Enter your choice here:");
                scanf("%d", &modeMain);
            } while (modeMain != 0 && modeMain != 4);
            
            
        }
        else if (modeMain == 2)
        {
            printf("You have chosen to go to the timer.\n\n");

            if (timerActive == 0)
            {
                if (sessionCurr.active == 1)
                {
                    printf("You already have a session set up! These are the current settings:\n");
                    printf("\nNumber of intervals: %d\n", sessionCurr.numIntervalsTarget);
                    printf("Length of each work interval: %d minutes\n", sessionCurr.rawWorkTime);
                    printf("Length of each break interval: %d minutes\n", sessionCurr.rawBreakTime);
                }
                else
                {
                    printf("You do not have a session set up yet! Please set it up to start the timer.\n");
                }

                do
                {
                    printf("\n  Press:\n\t[0] to go back to the main menu\n\t[1] to edit the session\n\t[2] to start the session\n\t[4] to exit the program\n  Enter your choice here: ");
                    scanf("%d", &modeTimer);
                } while (modeTimer != 0 && modeTimer != 1 && modeTimer != 2 && modeTimer != 4);

                if (modeTimer == 0)
                {
                    modeMain = 0;
                    continue;
                }
                else if (modeTimer == 1)
                {
                    printf("\nPlease enter the number of intervals you want to work for: ");
                    scanf("%d", &sessionCurr.numIntervalsTarget);
                    printf("Please enter the length of each interval in minutes: ");
                    scanf("%d", &sessionCurr.rawWorkTime);
                    printf("Please enter the length of each break in minutes: ");
                    scanf("%d", &sessionCurr.rawBreakTime);

                    resetWorkTime(&sessionCurr);
                    resetBreakTime(&sessionCurr);

                    sessionCurr.active = 1;
                    sessionCurr.numIntervalsCurr = 0;
                }
                else if (modeTimer == 2 && sessionCurr.active == 1)
                {
                    timerActive = 1;
                }
                else if (modeTimer == 4)
                {
                    modeMain = 4;
                    continue;
                }
            }
            else
            {
                setTimeParts(timeParts, isWorking, sessionCurr);

                time = createTimeArt(timeParts);
                printTimeArt(time);

                free(time.line0);
                free(time.line1);
                free(time.line2);
                free(time.line3);
                free(time.line4);
                free(time.line5);

                printf("\nIntervals Completed: %d/%d\n", sessionCurr.numIntervalsCurr, sessionCurr.numIntervalsTarget);

                if (timerPaused)
                {
                    printf("\n  The timer is paused.\n");
                    printf("\n  Press:\n\t'c' to continue the timer\n\t'e' to end the timer\n");
                    if (kbhit())
                    {
                        switch (getch())
                        {
                        case 'c':
                            printf("\nYou have chosen to continue the timer.\n");
                            timerPaused = 0;
                            break;
                        case 'e':
                            printf("\nYou have chosen to end the timer.\n");
                            timerActive = 0;
                            break;
                        }
                    }
                }
                else
                {
                    if (sessionCurr.numIntervalsCurr == sessionCurr.numIntervalsTarget)
                    {
                        printf("\nYou have completed your session!\n");

                        endSession(&sessionCurr, sessionsFinished, &sessionsCount, &timerActive);
                    }
                    else
                    {
                        if (isWorking)
                        {
                            if (sessionCurr.secondsWork == 0)
                            {
                                if (sessionCurr.minutesWork == 0)
                                {
                                    if (sessionCurr.hoursWork == 0)
                                    {
                                        resetWorkTime(&sessionCurr);
                                        sessionCurr.numIntervalsCurr++;
                                        isWorking = 0;
                                    }
                                    else
                                    {
                                        sessionCurr.hoursWork--;
                                        sessionCurr.minutesWork = 59;
                                        sessionCurr.secondsWork = 59;
                                    }
                                }
                                else
                                {
                                    sessionCurr.minutesWork--;
                                    sessionCurr.secondsWork = 59;
                                }
                            }
                            else
                            {
                                sessionCurr.secondsWork--;
                            }
                        }
                        else
                        {
                            if (sessionCurr.secondsBreak == 0)
                            {
                                if (sessionCurr.minutesBreak == 0)
                                {
                                    if (sessionCurr.hoursBreak == 0)
                                    {
                                        resetBreakTime(&sessionCurr);
                                        isWorking = 1;
                                    }
                                    else
                                    {
                                        sessionCurr.hoursBreak--;
                                        sessionCurr.minutesBreak = 59;
                                        sessionCurr.secondsBreak = 59;
                                    }
                                }
                                else
                                {
                                    sessionCurr.minutesBreak--;
                                    sessionCurr.secondsBreak = 59;
                                }
                            }
                            else
                            {
                                sessionCurr.secondsBreak--;
                            }
                        }

                        printf("\n  Press:\n\t'p' to pause the timer\n\t'e' to end the timer\n");
                        if (kbhit())
                        {
                            switch (getch())
                            {
                            case 'p':
                                printf("\nYou have chosen to pause the timer.\n");
                                timerPaused = 1;
                                break;
                            case 'e':       
                                printf("\nYou have chosen to end the timer.\n");
                                endSession(&sessionCurr, sessionsFinished, &sessionsCount, &timerActive);
                                break;
                            }
                        }
                    }
                }
                
            }
            sleep(1);
        }
        else if (modeMain == 3)
        {
            printSessionsFinished(sessionsFinished, sessionsCount);
            do
            {
                printf("\n  Press:\n\t[0] to go back to the main menu\n\t[4] to exit the program\n  Enter your choice here: ");
                scanf("%d", &modeMain);
            } while (modeMain != 0 && modeMain != 4);
        }
        
        if (modeMain == 4)
        {
            flag = 0;
        }
    }
}

struct timeArt createTimeArt(int *time)
{
    struct timeArt ta;

    ta.line0 = (char*)malloc(100 * sizeof(char));
    ta.line1 = (char*)malloc(100 * sizeof(char));
    ta.line2 = (char*)malloc(100 * sizeof(char));
    ta.line3 = (char*)malloc(100 * sizeof(char));
    ta.line4 = (char*)malloc(100 * sizeof(char));
    ta.line5 = (char*)malloc(100 * sizeof(char));

    strcpy(ta.line0, "");
    strcpy(ta.line1, "");
    strcpy(ta.line2, "");
    strcpy(ta.line3, "");
    strcpy(ta.line4, "");
    strcpy(ta.line5, "");

    for (int i = 0; i < 6; i++)
    {
        if (i % 2 == 0 && i !=0)
        {
            strcat(ta.line0, "        ");
            strcat(ta.line1, "   00   ");
            strcat(ta.line2, "        ");
            strcat(ta.line3, "        ");
            strcat(ta.line4, "   00   ");
            strcat(ta.line5, "        ");
        }

        switch (time[i])
        {
        case 0:
            strcat(ta.line0, "  000000  ");
            strcat(ta.line1, " 00    00 ");
            strcat(ta.line2, " 00    00 ");
            strcat(ta.line3, " 00    00 ");
            strcat(ta.line4, " 00    00 ");
            strcat(ta.line5, "  000000  ");
            break;
        case 1: 
            strcat(ta.line0, " 11111    ");
            strcat(ta.line1, "    11    ");
            strcat(ta.line2, "    11    ");
            strcat(ta.line3, "    11    ");
            strcat(ta.line4, "    11    ");
            strcat(ta.line5, " 11111111 ");
            break;
        case 2:
            strcat(ta.line0, "  222222  ");
            strcat(ta.line1, " 22    22 ");
            strcat(ta.line2, "      22  ");
            strcat(ta.line3, "    22    ");
            strcat(ta.line4, "  22      ");
            strcat(ta.line5, " 22222222 ");
            break;
        case 3:
            strcat(ta.line0, "  333333  ");
            strcat(ta.line1, " 33    33 ");
            strcat(ta.line2, "      33  ");
            strcat(ta.line3, "    333   ");
            strcat(ta.line4, " 33    33 ");
            strcat(ta.line5, "  333333  ");
            break;
        case 4:
            strcat(ta.line0, " 44    44 ");
            strcat(ta.line1, " 44    44 ");
            strcat(ta.line2, " 44444444 ");
            strcat(ta.line3, "       44 ");
            strcat(ta.line4, "       44 ");
            strcat(ta.line5, "       44 ");
            break;
        case 5:
            strcat(ta.line0, " 55555555 ");
            strcat(ta.line1, " 55       ");
            strcat(ta.line2, " 5555555  ");
            strcat(ta.line3, "       55 ");
            strcat(ta.line4, "       55 ");
            strcat(ta.line5, " 5555555  ");
            break;
        case 6: 
            strcat(ta.line0, "  666666  ");
            strcat(ta.line1, " 66       ");
            strcat(ta.line2, " 6666666  ");
            strcat(ta.line3, " 66    66 ");
            strcat(ta.line4, " 66    66 ");
            strcat(ta.line5, "  666666  ");
            break;
        case 7:
            strcat(ta.line0, " 77777777 ");
            strcat(ta.line1, "       77 ");
            strcat(ta.line2, "      77  ");
            strcat(ta.line3, "     77   ");
            strcat(ta.line4, "    77    ");
            strcat(ta.line5, "   77     ");
            break;
        case 8:
            strcat(ta.line0, "  888888  ");
            strcat(ta.line1, " 88    88 ");
            strcat(ta.line2, "  888888  ");
            strcat(ta.line3, " 88    88 ");
            strcat(ta.line4, " 88    88 ");
            strcat(ta.line5, "  888888  ");
            break;
        case 9:
            strcat(ta.line0, "  999999  ");
            strcat(ta.line1, " 99    99 ");
            strcat(ta.line2, " 99    99 ");
            strcat(ta.line3, "  9999999 ");
            strcat(ta.line4, "       99 ");
            strcat(ta.line5, "  999999  ");
            break;
        default:
            break;
        }
    }
    return ta;
}

void printTimeArt(struct timeArt ta)
{
    printf("%s\n", ta.line0);
    printf("%s\n", ta.line1);
    printf("%s\n", ta.line2);
    printf("%s\n", ta.line3);
    printf("%s\n", ta.line4);
    printf("%s\n", ta.line5);
}

void setTimeParts(int *timeParts, int isWorking, struct session sessionCurr)
{
    if (isWorking)
    {
        printf("\n  WORKING!\n\n");
        timeParts[0] = sessionCurr.hoursWork / 10;
        timeParts[1] = sessionCurr.hoursWork % 10;
        timeParts[2] = sessionCurr.minutesWork / 10;
        timeParts[3] = sessionCurr.minutesWork % 10;
        timeParts[4] = sessionCurr.secondsWork / 10;
        timeParts[5] = sessionCurr.secondsWork % 10;
    }
    else
    {
        printf("\n  BREAK!\n\n");
        timeParts[0] = sessionCurr.hoursBreak / 10;
        timeParts[1] = sessionCurr.hoursBreak % 10;
        timeParts[2] = sessionCurr.minutesBreak / 10;
        timeParts[3] = sessionCurr.minutesBreak % 10;
        timeParts[4] = sessionCurr.secondsBreak / 10;
        timeParts[5] = sessionCurr.secondsBreak % 10;
    }
}

void resetWorkTime(struct session *sessionCurr)
{
    sessionCurr->hoursWork = sessionCurr->rawWorkTime / 60;
    sessionCurr->minutesWork = sessionCurr->rawWorkTime % 60;
    sessionCurr->secondsWork = sessionCurr->rawWorkTime*60 - (sessionCurr->hoursWork*60*60 + sessionCurr->minutesWork * 60);
}

void resetBreakTime(struct session *sessionCurr)
{
    sessionCurr->hoursBreak = sessionCurr->rawBreakTime / 60;
    sessionCurr->minutesBreak = sessionCurr->rawBreakTime % 60;
    sessionCurr->secondsBreak = sessionCurr->rawBreakTime*60 - (sessionCurr->hoursBreak*60*60 + sessionCurr->minutesBreak * 60);
}

void endSession(struct session *sessionCurr, struct session *sessionsFinished, int *sessionsCount, int *timerActive)
{
    resetWorkTime(sessionCurr);
    resetBreakTime(sessionCurr);

    sessionCurr->numIntervalsCurr = 0;

    sessionsFinished[*sessionsCount] = *sessionCurr;
    (*sessionsCount)++;

    *timerActive = 0;
}

void printSessionsFinished(struct session *sessionsFinished, int sessionsCount)
{
    printf("\nSession History:\n");
    if (sessionsCount == 0)
    {
        printf("\nNo sessions finished yet.\n");
        return;
    }

    for (int i = 0; i < sessionsCount; i++)
    {
        printf("\nSession %d:\n", i + 1);
        printf("Work time - %02d:%02d:%02d\n", sessionsFinished[i].hoursWork, sessionsFinished[i].minutesWork, sessionsFinished[i].secondsWork);
        printf("Break time - %02d:%02d:%02d\n", sessionsFinished[i].hoursBreak, sessionsFinished[i].minutesBreak, sessionsFinished[i].secondsBreak);
        printf("Number of intervals finished - %d / %d\n", sessionsFinished[i].numIntervalsCurr, sessionsFinished[i].numIntervalsTarget);
    }
}
