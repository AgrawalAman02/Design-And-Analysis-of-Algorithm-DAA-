// in floyd warshall the distance of each vertex from each vertex is found
// djikstra ko hi n times laga denge  re binod, tbbhi ho hi jyga!..
// chhoro
#include<stdio.h>
int cost[][4]={{0,3,99,7},
               {8,0,2,99},
               {5,99,0,1},
               {2,99,99,0}};

int min(int a, int b){
    if(a<b) return a;
    else return b;
}
int main(){

    for(int k=0;k<4;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                cost[i][j]=min(cost[i][j],(cost[i][k]+cost[k][j])); // for each i we check its distance with j via vertex k
            }
        }
    }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",cost[i][j]);
        }
        printf("\n");
    }
}