#include<stdio.h>
int n,x[1000];
void printres(){
    for(int i=1; i<=n; i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}
void  backtracking(int i){
    for(int j=0; j<=1; j++){
        x[i]=j;
        if(i==n){
            printres();
        }
        else{
            backtracking(i+1);
        }
    }
}
int main(){
    scanf("%d",&n);
    backtracking(1);
    return 0;
}