#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
//1 2 7 8 5 3 4
void swap(int* a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int partition(int a[],int l,int r){
    int pivot=a[r];
    int i=l-1;
    for(int j=l; j<r; j++){
        if(a[j]<= pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    //dua chot ve giua
    i++;
    swap(&a[i],&a[r]);
    return i;//vi tri chia mang
}
void quickSort(int a[],int l,int r){
    if(l>=r) return;
    int p=partition(a,l,r);
    quickSort(a,l,p-1);
    quickSort(a,p+1,r);
}
int main(){
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",a+i);
    }
    quickSort(a,0,n-1);
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    free(a);
    return 0;
}