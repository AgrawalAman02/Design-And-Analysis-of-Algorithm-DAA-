#include<stdio.h>
#include<limits.h>
typedef struct Job {
    int profit;
    int deadline;
    int index;
} Job;

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the no. of jobs : ");
    scanf("%d", &n);
    Job jobs[n];
    for(int i = 0 ; i<n;i++){
        printf("Enter the profit of the job %d : ", i+1);
        scanf("%d", &jobs[i].profit);
        printf("Enter the deadline of job %d : ", i+1);
        scanf("%d", &jobs[i].deadline);
        jobs[i].index = i+1; // Store the original index
    }

    // sorting decreasing order
    for(int i =0 ; i<n-1; i++){
        for(int j = 0 ; j < n-i-1;j++){
            if(jobs[j].profit<jobs[j+1].profit){
                Job temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }

    int maxdl = INT_MIN;
    for(int i = 0 ;i<n; i++){
        if(jobs[i].deadline>maxdl) maxdl = jobs[i].deadline;
    }

    int jobseq[maxdl];
    for(int i = 0 ;i<maxdl; i++){
        jobseq[i] = -1;
    }

    int prof = 0;
    for(int i = 0 ; i<n; i++){
        for(int j = jobs[i].deadline-1;j>=0;j--){
            if(jobseq[j]==-1){
                prof+= jobs[i].profit;
                jobseq[j] = jobs[i].index;
                break;
            }
        }
        
    }

    printf("The max profit is : %d\n", prof);
    // printing the sequence
    for(int i = 0 ; i<maxdl; i++){
        printf("Job%d \t", jobseq[i]);
    }
    
    return 0;
}
