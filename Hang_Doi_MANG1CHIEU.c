#include<stdio.h>
int maxN=100000, queue[100000];
int n=0;

void push(int x){
    if(n>=maxN) return;
    else{
        queue[n]=x;
        n++;
    }
}

void pop(){
    for(int i=0; i<n-1; i++){
        queue[i]=queue[i+1];
    }
    n--;
}

int front(){
    return queue[0];
}

int size(){
    return n;
}

void duyet(){
    for(int i=0; i<n; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    while(1){
        printf("----------\n");
        printf("0. Thoat\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. front\n");
        printf("4. size\n");
        printf("5. duyet\n");
        printf("----------\n");
        int c;
        printf("Nhap lua chon: ");
        scanf("%d",&c);
        if(c==1){
            int x;
            printf("Nhap x: ");
            scanf("%d",&x);
            push(x);
        }
        else if(c==2){
            pop();
        }
        else if(c==3){
            printf("%d\n",front());
        }
        else if(c==4){
            printf("%d\n",size());
        }
        else if(c==5){
            duyet();
        }
        else break;
    }
    return 0;
}