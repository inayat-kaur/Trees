# include "tree.h"

int main(){
    printf("Enter 1 for Binary Search tree\nEnter 2 for AVL tree\nEnter 3 for BTree\n");
    int g;
    scanf("%d",&g);
    if(g==1)bst();
    else if(g==2)avl();
    else if (g==3)b_tree();
    else printf("Invalid Option\n");
    return 0;
}