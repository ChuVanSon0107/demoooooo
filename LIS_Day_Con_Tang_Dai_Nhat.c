#include<stdio.h>
#include<math.h>
//Cong thuc Quy Hoach Dong: if(a[i]>a[j]) L[i]=max(L[i],L[j]+1)
int max(int a,int b){
    return a>b? a:b;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int L[n];
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        //Khoi tao do dai day con lon nhat cua tat ca la 1
        L[i]=1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[i]>a[j]){
                //Neu a[i]>a[j] thi cho a[i] vao day con cua a[j]
                L[i]=max(L[i],L[j]+1);
            }
        }
    }
    int res=0;
    for(int i=0; i<n; i++){
        if(L[i]>res) res=L[i];
    }
    printf("%d\n",res);
    return 0;
}