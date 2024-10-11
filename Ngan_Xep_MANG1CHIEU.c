#include<stdio.h>
int maxN=100000, stack[100000];
int n=0;

void push(int x){
    if(n==maxN) return;
    else{
        stack[n]=x;
        n++;
    }
}

void pop(){
    if(n>=1) n--;
}

int top(){
    if(n != 0){
        return stack[n-1];
    }
}

int size(){
    return n;
}

void duyet(){
    for(int i=0; i<n; i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(){
    while(1){
        printf("----------\n");
        printf("0. Thoat\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. top\n");
        printf("4. size\n");
        printf("5. duyet\n");
        printf("----------\n");
        int c;
        printf("Vui long nhap lua chon: ");
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
            printf("%d\n",top());
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