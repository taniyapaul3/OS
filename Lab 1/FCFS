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

void FCFS(Process p[], int n) {
    int TotalTAT = 0, TotalWT = 0, time = 0;
    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        if (time < p[i].AT)
            time = p[i].AT;
        time += p[i].BT;
        p[i].CT = time;
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
        TotalTAT += p[i].TAT;
        TotalWT += p[i].WT;
        p[i].RT = p[i].WT;

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
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
    FCFS(p, n);

    return 0;
}
