#include<stdio.h>
void merge(int arr[], int lo, int mid, int hi){
    int n1= mid-lo+1;
    int n2 = hi-mid;
    int left[n1], right[n2];
    for(int  i = 0 ; i<n1; i++){
        left[i] = arr[lo+i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid+i+1];
    }
    int i = 0, j=0, k=lo;
    while (i<n1 && j <n2)
    {
        if(left[i]<=right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;

        }
        k++;
    }
    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
    
    
    
}
void mergesort(int arr[] , int lo, int hi){
    if(lo== hi) return;
    else{
        int mid = lo+(hi-lo)/2;
        mergesort(arr,lo, mid);
        mergesort(arr,mid+1,hi);
        merge(arr,lo,mid,hi);
    }
}
int main(){
    int arr[] = {1,4,30,79,3,2,0,5,67,34,87,10};
    int n = sizeof(arr)/ sizeof(arr[0]);
    printf("The Array Elements Are : \n");
    for(int i = 0 ; i< n;i++){
        printf("%d\t", arr[i]);
    }
    mergesort(arr,0,n-1);
    printf("\nThe Array Elements After Sorting Are : \n");
    for(int i = 0 ; i< n;i++){
        printf("%d\t", arr[i]);
    }
}