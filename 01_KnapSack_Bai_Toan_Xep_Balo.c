//w[i]: the weight of the ith things(trong luong cua do vat thu i)
//v[i]: the value of the ith things(gia tri cua do vat thu i)
//S: trong luong toi da cua cai tui
//dp[i][j]: gia tri lon nhat cua tui khi lua chon do vat 1,2,3,...,i va co trong luong toi da la j
//Cong thuc quy hoach dong: 
//dp[i][j]=dp[i-1][j]: Neu khong lua chon do vat i vao tui
//dp[i][j]=max(dp[i][j],dp[i-1][j-w[j]]+v[i]): Neu lua chon do vat thu i vao tui
//Ket qua la dp[n][S]
#include<stdio.h>
#include<string.h>
#include<math.h>
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int n,S;
    scanf("%d %d",&n,&S);
    int w[n+1],v[n+1];
    for(int i=1; i<=n; i++){
        scanf("%d",&w[i]);
    }
    for(int i=1; i<=n; i++){
        scanf("%d",&v[i]);
    }
    int dp[n+1][S+1];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=S; j++){
            //Coi nhu khong de do vat thu i vao tui
            dp[i][j]=dp[i-1][j];
            if(j>=w[i]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
                //j-w[i]: tong can nang cua tui con co the chiu dung duoc neu cho do vat i vao
            }
        }
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<= S; j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",dp[n][S]);


    return 0;
}
