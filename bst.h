# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
}typedef Node;

void bst(void);
Node * bst_getnode(int x);
void bst_addtree(Node* root,int t);
Node* bst_delete(Node* root,int t);
Node * bst_search(Node* root, int x);
int bst_minimum(Node* root);
int bst_maximum(Node* root);
void bst_preorder(Node* root);
void bst_inorder(Node* root);
void bst_postorder(Node* root);