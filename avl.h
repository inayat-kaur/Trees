# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
    int height;
}typedef Node;

Node * avl_getnode(int x);
int avl_getheight(Node* t);
Node* avl_addtree(Node* root,int t);
Node* avl_delete(Node* root,int t);
int balancefactor(Node * r);
Node* LL(Node* r);
Node* RR(Node* r);
Node* LR(Node* r);
Node* RL(Node* r);
Node * avl_search(Node* root, int x);
int avl_minimum(Node* root);
int avl_maximum(Node* root);
void avl_preorder(Node* root);
void avl_inorder(Node* root);
void avl_postorder(Node* root);
