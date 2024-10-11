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
    new->next=NULL;
    return new;
}

void push(node** head,int  x){
    node* new=newNode(x);
    if(*head == NULL){
        *head=new;
        return;
    }
    node* temp=*head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=new;
}

void pop(node** head){
    if(*head == NULL) return;
    node* temp=*head;
    *head=(*head)->next;
    free(temp);
}

int size(node* head){
    int ans=0;
    while(head != NULL){
        head=head->next;
        ans++;
    }
    return ans;
}

int front(node* head){
    if(head != NULL){
        return head->data;
    }
}

void duyet(node* head){
    while(head != NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
    node* head=NULL;
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
            push(&head,x);
        }
        else if(c==2){
            pop(&head);
        }
        else if(c==3){
            printf("%d\n",front(head));
        }
        else if(c==4){
            printf("%d\n",size(head));
        }
        else if(c==5){
            duyet(head);
        }
        else break;
    }
    return 0;   
}