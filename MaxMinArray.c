#include<stdio.h>
#include<limits.h>
void maxmin(int arr[], int lo, int hi, int ans[]){  // ans array se ptr ka jhanjhat nh rhega 
    if(lo == hi) {
    ans[0] = ans[1] = arr[lo]; 
}
else if(lo == hi-1){
    if(arr[lo]>arr[hi]) {
        ans[0]=arr[hi];
        ans[1]=arr[lo];
    }else{
        ans[0] = arr[lo];
        ans[1]  = arr[hi];
    }
}
else{
        int mid = (lo+hi)/2;
        int left[2] = {INT_MAX, INT_MIN};
        int right[2] = {INT_MAX, INT_MIN};
        maxmin(arr,lo,mid,left);
        maxmin(arr,mid+1,hi,right);
        if(left[0]>right[0]) ans[0] = right[0];
        else ans[0] = left[0];

        if(left[1]>right[1]) ans[1] = left[1];
        else ans[1] = right[1];
    }

}
int main(int argc, char const *argv[])
{
    int arr[]={23,111,30,5,7,33333,87777777,4,99,6};
    
    // int n  = sizeof(arr)/sizeof(arr[0]);
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The Array Elements Are : \n[\t");
    for(int i = 0 ; i< n;i++){
        printf("%d\t", arr[i]);
    }
    int ans [] = {INT_MAX,INT_MIN};
    maxmin(arr,0,n-1,ans);
    printf("]\nFrom the above array : \n");
    printf("\nThe min is %d", ans[0]);
    printf("\n&\nThe max is %d", ans[1]);

    return 0;
}
