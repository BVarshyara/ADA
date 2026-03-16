#include <stdio.h>

int main()
{
    int n, i, j;
    int at[20], bt[20], pr[20];
    int wt[20], tat[20];
    int temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time, Burst Time and Priority:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d AT BT PR: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    // Sorting by Priority then Arrival Time
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(pr[i] > pr[j] || (pr[i] == pr[j] && at[i] > at[j]))
            {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tAT\tBT\tPR\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], wt[i], tat[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
