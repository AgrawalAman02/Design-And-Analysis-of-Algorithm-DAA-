#include<stdio.h>
#include<limits.h>
// bokka abhi  
void mcm(int arr[], int n){
    int dp[n][n];
    int bracket[n][n];
    
    for(int i  = 0 ; i<n; i++){
        for(int j = 0 ; j<n;j++){
            dp[i][j] = -1;
            bracket[i][j] =-1;
        }
    }
    for(int  i = 0 ; i<n;i++){
        dp[i][i] = 0;
    };
    // dp
    for(int  l = 2; l<n;l++){
        for(int i = 1; i<=n-l; i++){
            int j = i+l-1;   // jo toh i se bara hi rhega n re 
            dp[i][j] = INT_MAX;  // bhulna nh re aman ye line
            for(int k = i; k<=j-1; k++){
                int cost = dp[i][k]+dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(cost<dp[i][j]) dp[i][j] = cost;
                bracket[i][j] = k;  

            }
        }
    }

    printf("\n the dp matrix is : \n");
    for(int i  = 0 ; i<n; i++){
        for(int j = 0 ; j<n;j++){
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }

    printf("\n the bracket matrix is :\n");
    for(int i  = 0 ; i<n; i++){
        for(int j = 0 ; j<n;j++){
            printf("%d\t", bracket[i][j]);
        }
        printf("\n");
    }

    printf("\n the minimum no. of operation is : %d", dp[1][n-1]);

}

int main(){
    int n ;
    printf("Enter the no. of matrices : ");
    scanf("%d", &n);
    int arr[n+1];
    printf("\n Enter the dimension of the matrix in chain : ");
    for(int i = 0 ; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    mcm(arr,n+1);
    return 0;

}