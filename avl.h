# include <stdio.h>
# include <stdlib.h>

struct avlnode{
    int data;
    struct avlnode * left;
    struct avlnode * right;
    int height;
}typedef avlnode;

avlnode * avl_getavlnode(int x);
int avl_getheight(avlnode* t);
avlnode* avl_addtree(avlnode* root,int t);
avlnode* avl_delete(avlnode* root,int t);
int balancefactor(avlnode * r);
avlnode* LL(avlnode* r);
avlnode* RR(avlnode* r);
avlnode* LR(avlnode* r);
avlnode* RL(avlnode* r);
avlnode * avl_search(avlnode* root, int x);
int avl_minimum(avlnode* root);
int avl_maximum(avlnode* root);
void avl_preorder(avlnode* root);
void avl_inorder(avlnode* root);
void avl_postorder(avlnode* root);
