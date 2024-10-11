#include<stdio.h>
#include<math.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for( int i=0; i<n; i++){
        scanf("%d",a+i);
    }
    long long sum1=0, sum2=0;// sum1 là lưu kỉ lục tạm thời-sum2 là lưu kỉ lục thật
    for( int i=0; i<n; i++){
        sum1+=a[i];
        if(sum1>sum2) sum2=sum1;//cập nhật kỉ lục
        if(sum1<0) sum1=0;//nếu mà sum1<0 thì ta không lấy cái giá trị a[i] đó nên là ta sẽ khởi tạo lại cho sum1=0
    }
    printf("%lld",sum2);
    return 0;
}