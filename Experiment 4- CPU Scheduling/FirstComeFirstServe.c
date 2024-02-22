#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct processList 
{
 int n;
 int AT;
 int BT;
 int WT;
 int CT;
};

int FCFS(int, struct processList *process);
int sort(int, struct processList *process);

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct processList process[n];
    printf("Enter arrival time and burst time of processes:\n");
    for(int i=0; i<n; i++)
    {
        process[i].n = i;
        printf("Process %d: ", i+1);
        scanf("%d %d", &process[i].AT, &process[i].BT);
    }
    sort(n, process);
    printf("\n\nProcesses you have enterred in sorted order based on arrival time: \n"); 
    printf("Processes   Arrival Time   Burst Time\n"); 
    for (int  i=0; i<n; i++) 
    { 
        printf("\n  P%d ",process[i].n);
        printf("            %d  ", process[i].AT );
        printf("            %d ",process[i].BT );
    }
    FCFS(n, process);
}

int FCFS(int n, struct processList *process)
{
    for(int i=0; i<n; i++)
    {
        if (i==0)
        {
            process[0].WT = 0;
        }
        else
        {
            if(process[i].AT>process[i-1].CT)
            {
                process[i].WT = 0;
            }
            else
            {
                process[i].WT = process[i-1].CT-process[i].AT;
            }
        }
        process[i].CT = process[i].AT + process[i].WT + process[i].BT;
        
    }
        printf("\n\n Scheduled Processes: \n"); 
        printf("Processes   Arrival Time   Burst Time   Wait Time   Completion Time\n"); 
        for (int  i=0; i<n; i++) 
        { 
            printf("\n  P%d ",process[i].n);
            printf("            %d  ", process[i].AT);
            printf("            %d  ",process[i].BT );
            printf("            %d  ",process[i].WT );
            printf("            %d  ",process[i].CT );
        }
        
}

int sort(int n, struct processList *process)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (process[j].AT > process[j+1].AT) {
                struct processList temp = process[j];
                process[j] = process[j+1];
                process[j+1] = temp;
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}




