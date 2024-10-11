#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node* left;
    struct node* right;
};
typedef struct node node;

node* newNode(int x){
    node* new=(node*)malloc(sizeof(node));
    new->key=x;
    new->left=NULL;
    new->right=NULL;
    return new;
}

//Function to insert a new node with a key given in BST
node* insert(node* root,int key){
    //If the root is empty, return the new node
    if(root == NULL) return newNode(key);
    //If the key is greater than the root->key
    if(key > root->key){
        root->right=insert(root->right, key);
    }
    //If the key is smaller than the root->key
    else if(key < root->key){
        root->left=insert(root->left, key);
    }
    //return the (unchanged) node
    return root;
}

//Function to Search a node with the key given in BST
node* search(node* root, int key){
    if(root == NULL || root->key == key) return root;
    //Otherwise
    if(key > root->key){
        return search(root->right,key);
    }
    else if(key < root->key){
        return search(root->left,key);
    }
}

void inOrder(node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->key);
        inOrder(root->right);
    }
}

void preOrder(node* root){
    if(root != NULL){
       printf("%d ",root->key);
       preOrder(root->left);
       preOrder(root->right); 
    }
}

void postOrder(node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->key);
    }
}

int height(node* root){
    if(root == NULL) return 0;
    else{
        //Compute the depth of each subtree
        int lDepth=height(root->left);
        int rDepth=height(root->right);
        // Use the larger one
        if(lDepth > rDepth) return (lDepth+1);
        else return (rDepth+1);
    }
}

void printGivenLevel(node* root,int level){
    if(root == NULL) return;
    if(level==1) printf("%d ",root->key);
    else if (level > 1){
        //Recursive Call
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

//Function to line by line print
//level order traversal a tree
void levelOrder(node* root){
    int h=height(root);
    for(int  i=1; i<=h; i++){
        printGivenLevel(root, i);
        printf("\n");
    }
}

//Function to delete a node
node* deleteNode(node* root, int key){
    //Base Case
    if(root == NULL) return root;
    //Recursive calls for ancestors of node to be deleted
    if(root->key > key){
        root->left=deleteNode(root->left, key);
        return root;
    }
    else if(root->key < key){
        root->right=deleteNode(root->right, key);
        return root;
    }
    //We reach here when root is the node to be deleted
    //If one of the children is empty
    if(root->left== NULL){
        node* temp=root->right;
        free(root);
        return temp;
    }
    else if(root->right==NULL){
        node* temp=root->left;
        free(root);
        return temp;
    }

    //If both children exist
    else{
        //succParent để lưu cái node trc cái node "thế mạng"
        node* succParent= root;
        //Find successor(successor: thay thế, tiếp nối)
        // succ: la node sẽ "thế mạng" cho node cần xóa
        node* succ=root->right;
        while(succ->left != NULL){
            succParent=succ;
            succ=succ->left;
        }
        //Delete successor. Since successor is always left child of its parent
        // we can safely make successor's right
        //right child as left of its parent.
        //if there is no succ, then assighn
        //succ->right to succParent->right
        if(succParent != root) succParent->left=NULL;//succParent->left=succ->right;
        else succParent->right=NULL;//succParent->right=succ->right;
        //Copy successor data to root
        root->key=succ->key;
        //Delete Successor and return root
        free(succ);
        return root;
    }
}

int main(){
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 
   */
    node* root= NULL;
    while(1){
        printf("-------------------\n");
        printf("0. Thoat\n");
        printf("1. Insert\n");
        printf("2. inOrder\n");
        printf("3. preOrder\n");
        printf("4. postOrder\n");
        printf("5. levelOrder\n");
        printf("6. search\n");
        printf("7. height\n");
        printf("8. Delete node\n");
        printf("-------------------\n");
        printf("Nhap lua chon: ");
        int c;
        scanf("%d",&c);
        if(c==1){
            int  key;
            printf("Nhap key: ");
            scanf("%d",&key);
            root=insert(root, key);
        }
        else if(c==2){
            inOrder(root);
            printf("\n");
        }
        else if(c==3){
            preOrder(root);
            printf("\n");
        }
        else if(c==4){
            postOrder(root);
            printf("\n");
        }
        else if(c==5){
            levelOrder(root);
        }
        else if(c==6){
            int key;
            printf("Nhap key: ");
            scanf("%d",&key);
            node* temp=search(root,key);
            if(temp==NULL) printf("Not Found\n");
            else printf("Found\n");
        }
        else if(c==7){
            printf("%d\n",height(root));
        }
        else if(c==8){
            int x;
            printf("Nhap x: ");
            scanf("%d",&x);
            root=deleteNode(root,x);
        }
        else break;
    }
    return 0;
}