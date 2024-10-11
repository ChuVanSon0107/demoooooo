#include<stdio.h>
#include<string.h>
int n, x[1000],used[1000];
void printres(){
    for(int i=1; i<=n; i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}
void backtracking(int i){
    for(int j=1; j<=n; j++){
        if(used[j]==0){
            used[j]=1;
            x[i]=j;
            if(i==n){
                printres();
            }
            else{
                backtracking(i+1);
            }
            //back track
            used[j]=0;
        }
    }
}
int main(){
    memset(used,0,1000);
    scanf("%d",&n);
    backtracking(1);
    return 0;
}