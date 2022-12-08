/*
Program to implement priority Scheduling algorithms
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct
{
    int pno;
    int pri;
    int btime;
    int wtime;
} sp;
int main()
{
    int i, j, n;
    int tbm = 0, totttime = 0, totwtime = 0;
    sp *p, t;
    printf("\nPRIORITY SCHEDULING.\n");
    printf("Enter the number of process...\n");
    scanf("%d", &n);
    p = (sp *)malloc(sizeof(sp));
    printf("Enter the burst time and priority : \n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d : ", i + 1);
        scanf("%d %d", &p[i].btime, p[i].pri);
        p[i].pno = i + 1;
        p[i].wtime = 0;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].pri > p[j].pno)
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        totwtime += p[i].wtime = tbm;
        tbm += p[i].btime;
        printf("\n%d\t\t%d", p[i].pno, p[i].btime);
        printf("\t\t%d\t\t%d", p[i].wtime, p[i].wtime + p[i].btime);
    }
    totttime - tbm + totwtime;
    printf("\nTotal waiting time : %d", totwtime);
    printf("\nAverage waiting time : %d", (float)totwtime / n);
    printf("\nTotal Turnaround time : %d", totttime);
    printf("\nAverage Turnaround time : %d", (float)totttime / n);
    getch();
    return 0;
}