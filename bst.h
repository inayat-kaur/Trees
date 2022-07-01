# include <stdio.h>
# include <stdlib.h>

struct bstnode{
    int data;
    struct bstnode * left;
    struct bstnode * right;
}typedef bstnode;

bstnode * bst_getbstnode(int x);
void bst_addtree(bstnode* root,int t);
bstnode* bst_delete(bstnode* root,int t);
bstnode * bst_search(bstnode* root, int x);
int bst_minimum(bstnode* root);
int bst_maximum(bstnode* root);
void bst_preorder(bstnode* root);
void bst_inorder(bstnode* root);
void bst_postorder(bstnode* root);