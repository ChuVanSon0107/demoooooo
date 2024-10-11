#include<stdio.h>
void merge(int a[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;//do lon 2 mang
    int L[n1],R[n2];
    //sao luu ra 2 mang con
    for(int i=0; i<n1; i++){
        L[i]=a[l+i];
    }
    for(int i=0; i<n2; i++){
        R[i]=a[i+m+1];
    }
    //tron 2 mang da sap xep
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k++]=L[i++];
        }
        else{
            a[k++]=R[j++];
        }
    }
    while(i<n1){
        a[k++]=L[i++];
    }
    while(j<n2){
        a[k++]=R[j++];
    }
}

void mergeSort(int a[],int l,int r){
    if(l<r){
        int m=(r+l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",arr+i);
    }
    mergeSort(arr,0,n-1);
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}