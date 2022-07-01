# include "tree.h"

void bst(){                 //Function to perform operations on BST
    printf("Menu of operations in Binary Search tree:\n");
    printf("Enter 1 to insert\n");
    printf("Enter 2 to delete\n");
    printf("Enter 3 to search a key\n");
    printf("Enter 4 to get minimum element in the tree\n");
    printf("Enter 5 to get maximum element in the tree\n");
    printf("Enter 6 for preorder traversal\n");
    printf("Enter 7 for inorder traversal\n");
    printf("Enter 8 for postorder traversal\n");
    printf("Enter 9 to quit\n");
    int s=0;
    int t;
    bstnode* root=NULL;
    while(s!=9){
        scanf("%d",&s);
        switch (s)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d",&t);
            if(root==NULL)root=bst_getbstnode(t);
            else bst_addtree(root,t);
            break;
        case 2:
            printf("Enter the value to delete: ");
            scanf("%d",&t);
            root=bst_delete(root,t);
            break;
        case 3:
            printf("Enter the value to search: ");
            scanf("%d",&t);
            if(bst_search(root,t)!=NULL)printf("Present\n");
            else printf("Not present\n");
            break;
        case 4:
            printf("The minimum element in the tree is: %d\n",bst_minimum(root));
            break;
        case 5:
            printf("The maximum element in the tree is: %d\n",bst_maximum(root));
            break;
        case 6:
            printf("The preorder traversal is: ");
            bst_preorder(root);
            printf("\n");
            break;
        case 7:
            printf("The inorder traversal is: ");
            bst_inorder(root);
            printf("\n");
            break;
        case 8:
            printf("The postorder traversal is: ");
            bst_postorder(root);
            printf("\n");
            break;
        case 9:
            break;
        default:
            printf("Invalid Option!\n");
            break;
        }
    }
}

void avl(){                     //Function to perform operations on AVL Tree
    printf("Menu of operations in AVL tree:\n");
    printf("Enter 1 to insert\n");
    printf("Enter 2 to delete\n");
    printf("Enter 3 to search a key\n");
    printf("Enter 4 to get minimum element in the tree\n");
    printf("Enter 5 to get maximum element in the tree\n");
    printf("Enter 6 for preorder traversal\n");
    printf("Enter 7 for inorder traversal\n");
    printf("Enter 8 for postorder traversal\n");
    printf("Enter 9 to quit\n");
    int s=0;
    int t;
    avlnode* root=NULL;
    while(s!=9){
        scanf("%d",&s);
        switch (s)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d",&t);
            if(root==NULL)root=avl_getavlnode(t);
            else root=avl_addtree(root,t);
            break;
        case 2:
            printf("Enter the value to delete: ");
            scanf("%d",&t);
            root=avl_delete(root,t);
            break;
        case 3:
            printf("Enter the value to search: ");
            scanf("%d",&t);
            if(avl_search(root,t)!=NULL)printf("Present\n");
            else printf("Not present\n");
            break;
        case 4:
            printf("The minimum element in the tree is: %d\n",avl_minimum(root));
            break;
        case 5:
            printf("The maximum element in the tree is: %d\n",avl_maximum(root));
            break;
        case 6:
            printf("The preorder traversal is: ");
            avl_preorder(root);
            printf("\n");
            break;
        case 7:
            printf("The inorder traversal is: ");
            avl_inorder(root);
            printf("\n");
            break;
        case 8:
            printf("The postorder traversal is: ");
            avl_postorder(root);
            printf("\n");
            break;
        case 9:
            break;
        default:
            printf("Invalid Option!\n");
            break;
        }
    }
}

void b_tree(){                          //Function to perform operations on B Tree
    int c;
    printf("Enter the minimum degree of the B-tree t: ");
    scanf("%d",&c);
    printf("Menu of operations in Btree:\n");
    printf("Enter 1 to insert\n");
    printf("Enter 2 to search a key\n");
    printf("Enter 3 to get minimum element in the tree\n");
    printf("Enter 4 for inorder traversal\n");
    printf("Enter 5 to quit\n");
    int s=0;
    int t;
    btree* root=B_TREE_CREATE(c);
    while(s!=5){
        scanf("%d",&s);
        switch (s)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d",&t);
            root=B_TREE_INSERT(root,t,c);
            break;
        case 2:
            printf("Enter the value to search: ");
            scanf("%d",&t);
            if(B_TREE_SEARCH(root,t)!=NULL)printf("Present\n");
            else printf("Not present\n");
            break;
        case 3:
            printf("The minimum element in the tree is: %d\n",B_TREE_MIN(root));
            break;
        case 4:
            printf("The inorder traversal is: ");
            B_TREE_INORDER_TRAVERSE(root);
            printf("\n");
            break;
        case 5:
            break;
        default:
            printf("Invalid Option!\n");
            break;
        }
    }
}