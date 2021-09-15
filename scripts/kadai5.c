#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

int main();
void insert(int);
void insertProc(struct Node *,struct Node *);
void view(struct Node *);

int main(){
    insert(4);
    insert(5);
    insert(2);
    insert(1);
    insert(7);
    insert(6);
    insert(3);

    view(root);
}


struct Node *newNode(int data){
                struct Node *nNode;
                nNode=(struct Node *)malloc(sizeof(struct Node));
                nNode->data=data;
                nNode->left=NULL;
                nNode->right=NULL;
                return nNode;
                }


void insert(int data){
    struct Node *nNode;
    nNode = newNode(data);
    /**
     * (1)のチェック
     */
    if(root==NULL){
        root=nNode;
        return;
    }

    insertProc(root,nNode);
}


void insertProc(struct Node *node,struct Node *nNode){
                /**
                 * (2)の処理
                 */
                if(nNode->data <= node->data){
                    if(node->left==NULL){
                        /********************/
                        node->left = nNode;
                    }else{
                        /*******************/
                        insertProc(node->left,nNode);
                    }
                /**
                 * (3)の処理
                 */
                }else{
                    if(node->right==NULL){
                        /*********************/
                        node->right = nNode;
                    }else{
                        /*********************/
                        insertProc(node->right ,nNode);
                    }
                }
}

void view(struct Node *itr){
    if (itr->left != NULL)
    {
        view(itr->left);
    }
    printf("%d\n",itr->data);
    if (itr->right != NULL)
    {
        view(itr->right);
    }
    
}