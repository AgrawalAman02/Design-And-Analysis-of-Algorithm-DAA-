#include<stdio.h>
/* aman ye konsa partition h ?
 => Lomuto’s partition scheme
 */
int partition(int arr[], int lo, int hi){
    int pivot = arr[lo];
    int count=0;
    for(int i = lo+1; i<=hi; i++){
        if(arr[i]<pivot) count++;
    }
    int pivotidx = lo+count;
    // swap the pivotidx and arr[lo]
    int temp = arr[lo];
    arr[lo] = arr[pivotidx];
    arr[pivotidx] = temp;
    int i = lo, j = hi;
    while(i<pivotidx && j>pivotidx){
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if(arr[i]> pivot && arr[j]<pivot){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        
    } 
    return pivotidx;
}

void quicksort(int arr[], int lo ,int hi){
    if(lo>= hi) return;
    else{
        int pt = partition(arr,lo,hi);
        quicksort(arr, lo,pt-1);
        quicksort(arr,pt+1, hi);
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {1,4,30,79,3,2,0,5,67,34,87,10};
    int n = sizeof(arr)/ sizeof(arr[0]);
    printf("The Array Elements Are : \n");
    for(int i = 0 ; i< n;i++){
        printf("%d\t", arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("\nThe Array Elements After Sorting Are : \n");
    for(int i = 0 ; i< n;i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}
