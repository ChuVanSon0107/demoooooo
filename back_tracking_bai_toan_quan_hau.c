#include<stdio.h>
#include<string.h>
// de gan x[i]=j -> cot[j]=1 -> con trong
//                  d1[i-j+n]=1 -> con trong
//                  d2[i+j-1]=1 -> con trong
int n, d1[500], d2[500], cot[500], x[100];
int a[500][500];
void printres(){
    memset(a,0,sizeof(a));
    for(int i=1; i<=n; i++){
        a[i][x[i]]=1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    printf("----------\n");
}
void backtracking(int i){
    for(int j=1; j<=n; j++){
        if(cot[j]==1 && d1[i-j+n]==1 && d2[i+j-1]==1){
            cot[j]=0;
            d1[i-j+n]=0;
            d2[i+j-1]=0;
            x[i]=j;
            if(i==n){
                printres();
            }
            else{
                backtracking(i+1);
            }
            //back track
            cot[j]=1;
            d1[i-j+n]=1;
            d2[i+j-1]=1;
        }
    }
}
int main(){
    for(int i=0; i<500; i++){
        d1[i]=1;
        d2[i]=1;
        cot[i]=1;
    }
    scanf("%d",&n);
    backtracking(1);
    return 0;
}