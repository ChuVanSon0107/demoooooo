#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node node;

//Function to create a new node
node* newNode(int x){
    node* new=(node*)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    return new;
}

//Function to push a new node to the front
void pushFront(node** head,int x){
    node* new=newNode(x);
    new->next=*head;
    *head=new;
}

//Function to push a new node to the back
void pushBack(node** head,int x){
    node* new=newNode(x);
    if(*head == NULL){
        *head=new;
        return;
    }
    node* temp=*head;//thao tac tren temp de khong lam thay doi head
    while(temp->next != NULL){
        temp=temp->next;//de tro den node cuoi cung
    }
    temp->next=new;
}

// Function to printf nodes in the Linked List
void duyet(node* head){
    while(head != NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

//Function to calculate the size of a Linked List
int size(node* head){
    int cnt=0;
    while(head != NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}

// Function to insert a new node to the middle of the Linked List
void insert(node** head,int k,int x){
    //K: the position to insert
    int n=size(*head);
    if(k<1 || k>n+1) return;
    if(k==1) pushFront(head,x);
    node* temp=*head;
    for(int i=1; i<=k-2; i++){
        temp=temp->next;
    }
    //temp: k-1;
    node* new=newNode(x);
    new->next=temp->next;
    temp->next=new;
}

//Function to pop the node at the front
void popFront(node** head){
    if(*head == NULL) return;
    node* temp=*head;
    *head=(*head)->next;
    free(temp);
}

//Function to pop the node at the push
void popBack(node** head){
    if(*head == NULL) return;//no node in Linked List0
    node* temp=*head;
    if(temp->next==NULL){
        // only one node in Linked List
        *head= NULL;
        free(temp);
        return;
    }
    //Otherwwise
    while(temp->next->next != NULL){
        temp=temp->next;// node gan cuoi
    }
    node* last=temp->next;
    temp->next=NULL;
    free(last);
}

//Function to pop a node in the middle of Linked List
void popMiddle(node** head,int k){
    int n=size(*head);
    if(k<1 || k>n) return;
    if(k==1) popFront(head);
    else{
        node* temp=*head;
        for(int i=1; i<=k-2; i++){
            temp=temp->next;
        }
        //temp: k-1
        node* kth=temp->next;//the kth node
        temp->next=kth->next;
        free(kth);
    }
}

int main(){
    node* head= NULL;
    while(1){
        printf("--------------------\n");
        printf("0. Thoat\n");
        printf("1. Them vao dau DSLK\n");
        printf("2. Them vao cuoi DSLK\n");
        printf("3. Them vao  giua DSLK\n");
        printf("4. Xoa node khoi dau DSLK\n");
        printf("5. Xoa Node khoi cuoi DSLK\n");
        printf("6. Xoa node o giua DSLK\n");
        printf("7. Duyet\n");
        printf("--------------------\n");
        printf("Nhap lua chon: ");
        int c;
        scanf("%d",&c);
        if(c==1){
            int x;
            printf("Nhap x: ");
            scanf("%d",&x);
            pushFront(&head,x);
        }
        else if(c==2){
            int x;
            printf("Nhap x: ");
            scanf("%d",&x);
            pushBack(&head,x);            
        }
        else if(c==3){
            int x;
            printf("Nhap x: ");
            scanf("%d",&x);
            int k;
            printf("Nhap k: ");
            scanf("%d",&k);
            insert(&head,k,x);
        }
        else if(c==4){
            popFront(&head);
        }
        else if(c==5){
            popBack(&head);
        }
        else if(c==6){
            int k;
            printf("Nhap k: ");
            scanf("%d",&k);
            popMiddle(&head,k);
        }
        else if(c==7){
            duyet(head);
            printf("\n");
        }
        else{
            break;
        }
    }
    return 0;
}