#include<stdio.h>
#include<string.h>
#include<math.h>
//LCS: LONGEST COMMON SUBSEQUENCE
//F[i][j]: luu chieu dai xau con chung dai nhat co duoc bang cach lay ra i ki tu o xau X va j ki tu o xau Y
//Co so quy hoach dong: F[0][i]=0;F[i][0]=0;
//X[i] va Y[j];
//1. Neu X[i]==Y[j] thi F[i][j]=F[i-1][j-1]+1;
//2. Neu X[i] != Y[j] thi F[i][j]=max(F[i-1][j],F[i][j-1]);
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char X[n],Y[m];
    scanf("%s",X);
    scanf("%s",Y);
    int F[n+1][n+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                F[i][j]=0;
            }
            else{
                if(X[i-1]==Y[j-1]){
                    F[i][j]=F[i-1][j-1]+1;
                }
                else{
                    F[i][j]=max(F[i-1][j],F[i][j-1]);
                }
            }
        }
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            printf("%d ",F[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",F[n][m]);
}