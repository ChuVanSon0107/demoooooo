#include<stdio.h>
int n, k, ok, a[1000];
void khoitao(){
    for(int i=1; i<= k; i++){
        a[i]=i;
    }
}
void Sinh(){
    int i=k;
    //n-k+i => gia tri lon nhat tai vi tri i co the dat duoc
    while(i>=1 && a[i]==n-k+i){
        i--;
    }
    if(i==0){
        //da den cau hinh cuoi cung
        ok=0;
    }
    else{
        a[i]++;
        for(int j=i+1; j<=n; j++){
            a[j]=a[j-1]+1;
        }
    }
}
int main(){
    FILE* out=fopen("aa.txt","w");
    scanf("%d %d",&n,&k);
    ok=1;
    khoitao();
    while(ok){
        for(int i=1; i<=k; i++){
            fprintf(out,"%d ",a[i]);
        }
        fprintf(out,"\n");
        Sinh();
    }
    return 0;
}