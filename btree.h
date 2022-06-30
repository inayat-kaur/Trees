# include <stdio.h>
# include <stdlib.h>        
# include <stdbool.h>       //For using bool data type

struct Btree{           
    int n;
    int *keys;      //Array containing keys
    bool leaf;
    struct Btree **c;       //Array containing pointers to Btree structures which are children of the current node
}typedef btree;

struct Pair{
    btree * x;          //Return type for B_TREE_SEARCH() function
    int index;          //It contains pointer to the node which contains the given key and index at which it is present. 
}typedef pair;

pair* make_pair(btree * b,int i){                   //Function to make a pair structure.
    pair* p=(pair *)malloc(sizeof(btree*)+sizeof(int));
    p->x=b;
    p->index=i;
    return p;
}

btree* B_TREE_CREATE(int t);                //To create an empty B-tree
void B_TREE_SPLIT_CHILD(btree* x, int i,int t);             //To split a completely filled node
btree* B_TREE_INSERT(btree *x,int k,int t);                 //To insert a key in the B-Tree
void B_TREE_INSERT_NONFULL(btree* x,int k,int t);           //To insert a key in a non full node
pair* B_TREE_SEARCH(btree* x,int k);                    //To search a given key in the B-Tree
int B_TREE_MIN(btree* x);                   //To find the minimum key present in the B-Tree
void B_TREE_INORDER_TRAVERSE(btree* x);                 //To print the inorder traversal of the B-tree
