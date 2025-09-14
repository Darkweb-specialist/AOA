#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit;
}

void jobSequencing(Job jobs[], int n) {
     qsort(jobs, n, sizeof(Job), compare);

    int result[n];  
    int slot[n];    

    
    for (int i = 0; i < n; i++)
        slot[i] = 0;

    for (int i = 0; i < n; i++) {
   
        for (int j = (jobs[i].deadline < n ? jobs[i].deadline : n) - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                result[j] = i; 
                break;
            }
        }
    }

    printf("Scheduled jobs to maximize profit:\n");
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("Job %d (Profit: %d, Deadline: %d)\n", jobs[result[i]].id, jobs[result[i]].profit, jobs[result[i]].deadline);
            totalProfit += jobs[result[i]].profit;
        }
    }
    printf("Total Profit = %d\n", totalProfit);
}

int main() {
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
Job jobs[n];
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        printf("Enter deadline and profit for job %d: ", jobs[i].id);
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    return 0;
}
