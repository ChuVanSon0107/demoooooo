#include<stdio.h>
int n, x[1000], k;
void printres(){
    for(int i=1; i<=k; i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}
void backtracking(int i){
    //x[i]: chay tu x[i-1]+1 den x-k+i
    for(int j=x[i-1]+1; j<= n-k+i; j++){
        x[i]=j;
        if(i==k){
            printres();
        }
        else{
            backtracking(i+1);
        }
    }
}
int main(){
    scanf("%d %d",&n,&k);
    backtracking(1);
    return 0;
}