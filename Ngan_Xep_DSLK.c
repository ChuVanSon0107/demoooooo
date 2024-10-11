#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node node;

node* newNode(int x){
    node* new=(node*)malloc(sizeof(node));
    new->data= x;
    new->next= NULL;
    return new;
}

void push(node** top,int x){
    node* new=newNode(x);
    new->next=*top;
    *top=new;
}
void pop(node** top){
    if(*top == NULL) return;
    else{
        node* tmp=*top;
        *top=(*top)->next;
        free(tmp);
    }
}

int size(node* top){
    int ans=0;
    while(top != NULL){
        top=top->next;
        ans++;
    }
    return ans;
}

int tOp(node* top){
    if(top != NULL) return top->data;
}

void duyet(node* top){
    while(top != NULL){
        printf("%d ",top->data);
        top=top->next;
    }
    printf("\n");
}

int main(){
    node* top=NULL;
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
            push(&top,x);
        }
        else if(c==2){
            pop(&top);
        }
        else if(c==3){
            printf("%d\n",tOp(top));
        }
        else if(c==4){
            printf("%d\n",size(top));
        }
        else if(c==5){
            duyet(top);//day la duyet tu top xuong day nhe
        }
        else break;
    }
    return 0;
}