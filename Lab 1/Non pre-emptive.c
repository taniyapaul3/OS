#include <stdio.h>

typedef struct {
    int id, AT, BT, CT, TAT, WT, RT;
} Process;

void sorted(Process p[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].AT > p[j + 1].AT) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void sjf_non_preemptive(Process p[], int n) {
    int TotalTAT = 0, TotalWT = 0, time = 0;
    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    int completed = 0;
    int isCompleted[n];
    for (int i = 0; i < n; i++) {
        isCompleted[i] = 0;
    }

    while (completed != n) {
        int idx = -1;
        int minBT = 9999;

        for (int i = 0; i < n; i++) {
            if (!isCompleted[i] && p[i].AT <= time && p[i].BT < minBT) {
                minBT = p[i].BT;
                idx = i;
            }
        }

        if (idx != -1) {
            time += p[idx].BT;
            p[idx].CT = time;
            p[idx].TAT = p[idx].CT - p[idx].AT;
            p[idx].WT = p[idx].TAT - p[idx].BT;
            TotalTAT += p[idx].TAT;
            TotalWT += p[idx].WT;
            p[idx].RT = p[idx].WT;
            isCompleted[idx] = 1;
            completed++;

            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[idx].id, p[idx].AT, p[idx].BT, p[idx].CT, p[idx].TAT, p[idx].WT);
        } else {
            time++;
        }
    }

    float avgTAT = (float)TotalTAT / n;
    float avgWT = (float)TotalWT / n;
    printf("\nAverage Turn Around Time: %.2f\n", avgTAT);
    printf("Average Waiting Time: %.2f\n", avgWT);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time (AT), and Burst Time (BT) for Process %d: ", i + 1);
        scanf("%d %d", &p[i].AT, &p[i].BT);
    }

    sorted(p, n);
    sjf_non_preemptive(p, n);

    return 0;
}
