#include<stdio.h>
#include<string.h>
#include<math.h>
//dp[i]: co the tao duoc tong bang i khong
//dp[j]->dp[j-a[i]]
//dp[j] phu thuoc vao dp[j-a[i]]
int main(){
    int n,S;
    scanf("%d %d",&n,&S);
    int dp[S+1];
    int a[n+1];
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0; i<n; i++){
        //Xet tong lon cho den a[i] chu khong duoc xet tu tong nho cho den tong lon
        for(int j=S; j>=a[i]; j--){
            if(dp[j-a[i]]==1){
                dp[j]=1;
            }
        }
    }
    printf("%d\n",dp[S]);
    return 0;
}