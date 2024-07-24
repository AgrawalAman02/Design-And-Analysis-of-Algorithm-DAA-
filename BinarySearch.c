#include<stdio.h>
// lo ji binary search
int bs(int arr[], int item,int lo , int hi){
    if(lo==hi){    
        if(arr[lo] == item) return lo;    // check krlo wo barabar h ki nh tb hi return krenge n 
        else return -1;
    }
    else{
        int mid = lo +(hi-lo)/2;
        if(arr[mid] == item) return mid;
        else if(arr[mid]>item) return bs(arr,item,lo,mid-1);
        else return bs(arr,item,mid+1, hi);
    }
}
int main(){
    int arr[] = {1,2,34,76,90,123,456};
    printf("ye rha array hmara : \n");
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0 ; i< n;i++){
        printf("%d\t", arr[i]);
    }
    int item;
    printf("\nKya search krna h re : ");
    scanf("%d",&item);
    int pos = bs(arr,item,0,n-1);
    printf("\nToh item %d is at position %d", item, pos+1);
}