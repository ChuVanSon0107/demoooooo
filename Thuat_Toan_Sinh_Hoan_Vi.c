#include<stdio.h>
int n, a[1000], ok;
void swap(int* a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void khoitao(){
    for(int i=1; i<=n; i++){
        a[i]=i;
    }
}
void Sinh(){
    int i=n-1;
    while(i>=1 && a[i]>a[i+1]){
        i--;
    }
    if(i==0){
        ok=0;//cau hinh cuoi cung
    }
    else{
        //di tim thang > a[i] trong doan [i+1,n];
        int j=n;
        while(a[i]>a[j]){
            j--;
        }
        swap(&a[i],&a[j]);
        int l=i+1, r=n;
        while(l<r){
            swap(&a[l],&a[r]);
            l++;
            r--;
        }
    }
}
int main(){
    scanf("%d",&n);
    ok=1;
    khoitao();
    while(ok){
        for(int i=1; i<=n; i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        Sinh();
    }
    return 0;
}