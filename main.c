# include <stdio.h>
# include <stdlib.h>
# include "bst.h"
# include "avl.h"
# include "redblack.h"
# include "btree.h"

int main(){
    char c;
    printf("Enter t to create a tree or g to create a graph: ");
    scanf("%c",&c);
    if(c=='t'){
        printf("Options for tree:\n1.Enter s for Binary Search Tree\n2.Enter a for AVL Tree\n3.Enter r for Red Black Tree\n4.Enter b for BTree\n");
        scanf("%c",&c);
        if(c=='s')bst();
        else if(c=='a')avl();
        else if(c=='r')redblack();
        else if(c=='b')b_tree();
        else{
            printf("Invalid input!\n");
        }
    }
    else if(c=='g'){

    }
    else{
        printf("Invalid input!\n");
    }
    return 0;
}