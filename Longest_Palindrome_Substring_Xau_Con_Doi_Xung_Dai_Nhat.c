#include<stdio.h>
#include<string.h>
#include<math.h>
//F[i][j]: kiem tra xau con bat dau o chi so i, ket thuc o chi so j
//1. Neu S[i] != S[j] thi F[i][j]=False(0);
//2. Neu S[i]==S[j] && F[i+1][j-1]==True(1) thi F[i][j]=True(1);
//=> F[i][j]=F[i+1][j-1]&&(S[i]==S[j])
//F[i+1][j-1]: Xau con o giua xau F[i][j]
int max(int a,int  b){
    return a>b?a:b;
}
int main(){
    int n;
    scanf("%d",&n);
    char S[n];
    scanf("%s",S);
    int F[n+1][n+1];
    memset(F,0,sizeof(F));
    for(int i=1; i<=n; i++){
        F[i][i]=1;
    }
    int res=1;
    //Xet cac xau con co do dai lan luot tu 2 den n
    for(int length=2; length<=n; length++){
        for(int i=1; i<=n-length+1; i++){
            int  j=i+length-1;
            //F[i][j] co do dai la length
            if(length==2){
                if(S[i]==S[j]){
                    F[i][j]=1;
                }
            }
            else{
                if(F[i+1][j-1]==1 && S[i]==S[j]){
                    F[i][j]=1;
                }
            }
            if(F[i][j]==1){
                res=max(res,length);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ",F[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",res);
    return 0;
}