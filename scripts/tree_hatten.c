#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *root = NULL;

struct Node *newNode( int data ) {

	struct Node *nNode;

	nNode = (struct Node *)malloc(sizeof(struct Node));
	nNode->data = data;
	nNode->left = NULL;
	nNode->right = NULL;

	return nNode;

}

/*
 *  ツリーをもとに昇順で表示する関数
 *  再帰以外では実装が難しい
 */
void view( struct Node *itr ) {

	if ( itr->left != NULL ) {
		view(itr->left);
	}
	printf("%d\n", itr->data);
	if ( itr->right != NULL ) {
		view(itr->right);
	}

}


/**
 *   insert関数の再帰部分
 */
void insertProc( struct Node *node, struct Node *nNode ) {
	if ( nNode->data < node->data ) {
		if ( node->left == NULL ) {
			node->left = nNode;
		} else {
			insertProc(node->left, nNode);
		}
	} else {
		if ( node->right == NULL ) {
			node->right = nNode;
		} else {
			insertProc(node->right, nNode);
		}
	}
}

/**
 *   二分木にデータを挿入する関数
 */
void insert( int data ) {

	struct Node *nNode;

	nNode = newNode(data);

	if ( root == NULL ) {
		root = nNode;
		return;
	}

	insertProc(root, nNode);
}

/**
 * 発展課題
 * 二分木にdataの値がある場合は1, 無い場合は0を返す
 */
int agent( struct Node *node, int data ) {
    
    if ( data == node->data ) {
        return 1;
    } else if ( data < node->data ) {
		if ( node->left == NULL ) {
			return 0;
		} else {
			return agent(node->left, data);
		}
	} else {
		if ( node->right == NULL ) {
			return 0;
		} else {
			return agent(node->right, data);
		}
	}
}

/*
 *    4
 *  2   6
 * 1 3 5 7
 */
int main() {
    
    srand((unsigned int)time(NULL));
    
    int i = 0;
    int n;
    
    for(i = 0; i < 7; i++){
        n = rand() % 21;
        if(root == NULL || agent(root, n) == 0){
            insert(n);
        }
        
    }

	view(root);
    
    printf("Do you know ? >");
    scanf("%d", &n);
    
    if(agent(root, n) == 1){
        printf("I know.\n");
    } else {
        printf("I don't know.\n");
    }

	return 0;
}


