#include<stdio.h>
// structure se hi acha rhega , km se km id to peserved rhega n!
struct knapsack{
    int id;
    int profit;
    int weight;
    float ratio;

};
int main(int argc, char const *argv[])
{
    printf("\nEnter the capacity of the knapsack : ");
    int cap;  // weight of the knapsack
    scanf("%d",&cap);
    printf("\nEnter the no. of the objects to be put in the knapsack : ");
    int n ;
    scanf("%d", &n);
    struct knapsack object[n]; 
    float vis[n];

    printf("\nEnter the profit and weight of each object: \n");
    for(int i = 0 ; i<n; i++){
        printf("Enter the profit of %d object : ", i+1);
        scanf("%d", &object[i].profit);
        printf("Enter the weight of %d object : ", i+1);
        scanf("%d", &object[i].weight);
        object[i].ratio= (float)object[i].profit/ (float)object[i].weight;

        object[i].id = i;    // (optional for tracking).
        
        vis[i] =0;
    }
    // sorting on the basis of ratio
    for(int i = 0 ; i<n-1; i++){
        for(int j = 0  ; j<n-i-1; j++){
            if(object[j].ratio<object[j+1].ratio){
                struct knapsack temp = object[j];
                object[j] = object[j+1];
                object[j+1] = temp;

            }
        }
    }

    // greedy Algo
    float prof = 0;
    int rcap = cap;
    int i = 0;
    for(i = 0 ; i<n ;i++){
        if(object[i].weight>rcap) break;

        
            prof+= object[i].profit;
            rcap-= object[i].weight;
            vis[object[i].id] =1;
        

    }
    float rprof= 0.0;
    if(i<n){
        rprof= (float)rcap/object[i].weight;
        prof= prof + rprof*object[i].profit;
        vis[object[i].id] = rprof;
    }

    printf("%.2f\n", prof);
    for(int i = 0 ; i<n; i++){
        printf("%.2f\t", vis[i]);
    }
    return 0;

}
