#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
void swap(int* a,int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void heapify(int a[],int n,int i){
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<n && a[l]>a[largest]){
        largest=l;
    }
    if(r<n && a[r]>a[largest]){
        largest=r;
    }
    if(largest != i){
        swap(&a[largest],&a[i]);
        heapify(a,n,largest);
    }
}
void heapSort(int a[],int n){
    //Xay dung ham max heap
    for(int i=n/2; i>=0; i--){
        heapify(a,n,i);
    }

    for(int i=n-1; i>=0; i--){
        swap(&a[i],&a[0]);
        heapify(a,i,0);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",a+i);
    }
    heapSort(a,n);
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    free(a);
    return 0;
}