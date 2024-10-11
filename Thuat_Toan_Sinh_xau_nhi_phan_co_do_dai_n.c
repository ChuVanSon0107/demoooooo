#include<stdio.h>
int n,a[1000],ok;
void khoitao(){
    for(int i=1; i<=n; i++){
        a[i]=0;
    }
}
void sinh(){
    //bat dau t bit cuoi cung va di tu bit 0 dau tien
    int i=n;
    while(i>=1 && a[i]==1){
        a[i]=0;
        i--;
    }
    if(i==0){
        ok=0;//da den cau hinh cuoi cung
    }
    else{
        a[i]=1;
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
        sinh();
    }
    return 0;
}