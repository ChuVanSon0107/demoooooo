#include<stdio.h>
void swap(int* a,int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int partition(int arr[],int low,int high){
    //choose the pivot
    int pivot=arr[high];
    //Index of smaller element and Indicate
    //the right position of pivot founf so far
    int i=(low-1);
    for(int j=low; j<=high; j++){
        //If current element is smaller than the pivot
        if(arr[j]<pivot){
            //Increment index of smaller element
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quickSort(int arr[],int low,int high){
    //when low if less than high
    if(low<high){
        // pi is the partition return index of pivot
        int pi=partition(arr,low,high);
        //Recursion call
        //smaller element than pivot goes left and higher element goes right
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",arr+i);
    }
    quickSort(arr,0,n-1);
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}