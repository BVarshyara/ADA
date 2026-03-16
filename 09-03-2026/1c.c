#include <stdio.h>

int main()
{
    int at[10], bt[10], rt[10];
    int wt[10], tat[10];
    int n, i, time = 0, remain, smallest;
    int finish_time;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    for(i = 0; i < n; i++)
    {
        printf("Enter arrival time for P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    while(remain != 0)
    {
        smallest = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(smallest == -1 || rt[i] < rt[smallest])
                {
                    smallest = i;
                }
            }
        }

        if(smallest == -1)
        {
            time++;
            continue;
        }

        rt[smallest]--;
        time++;

        if(rt[smallest] == 0)
        {
            remain--;
            finish_time = time;

            wt[smallest] = finish_time - bt[smallest] - at[smallest];
            tat[smallest] = finish_time - at[smallest];

            avg_wt += wt[smallest];
            avg_tat += tat[smallest];
        }
    }

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f", avg_tat);

    return 0;
}
