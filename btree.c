# include "btree.h"

pair* make_pair(btree * b,int i){                   //Function to make a pair structure.
    pair* p=(pair *)malloc(sizeof(btree*)+sizeof(int));
    p->x=b;
    p->index=i;
    return p;
}

btree* B_TREE_CREATE(int t){            //Creating an empty B-Tree
    btree* x=(btree*)malloc(sizeof(btree));
    x->leaf=true;
    x->n=0;
    x->keys=(int *)malloc(2*t*sizeof(int));
    x->c=(btree **)malloc(2*t*sizeof(btree*));
    return x;
}

void B_TREE_SPLIT_CHILD(btree* x, int i,int t){         //Spliting a node into two nodes with t-1 elements each
    btree* z=(btree*)malloc(sizeof(btree));
    z->keys=(int *)malloc(2*t*sizeof(int));
    z->c=(btree **)malloc(2*t*sizeof(btree*));
    btree* y=x->c[i];
    z->leaf=y->leaf;
    z->n=t-1;
    for(int j=0;j<t-1;j++){
        z->keys[j]=y->keys[j+t];
    }
    if(!y->leaf){
       for(int j=0;j<t;j++){
            z->c[j]=y->c[j+t];
        } 
    }
    y->n=t-1;
    for(int j=x->n;j>=i+1;j--){
        x->c[j+1]=x->c[j];
    }
    x->c[i+1]=z;
    for(int j=x->n-1;j>=i;j--){
        x->keys[j+1]=x->keys[j];
    }
    x->keys[i]=y->keys[t-1];
    x->n=x->n+1;
}

btree* B_TREE_INSERT(btree *x,int k,int t){         //Inserting a key in the node
    if(x->n==(2*t-1)){                  //Creating a new node in case root is full
        btree* s=(btree*)malloc(sizeof(btree));
        s->keys=(int *)malloc(2*t*sizeof(int));
        s->c=(btree **)malloc(2*t*sizeof(btree*));
        s->leaf=false;
        s->n=0;
        s->c[0]=x;
        B_TREE_SPLIT_CHILD(s,0,t);
        B_TREE_INSERT_NONFULL(s,k,t);
        return s;
    }
    else{
        B_TREE_INSERT_NONFULL(x,k,t);
        return x;
    } 
}

void B_TREE_INSERT_NONFULL(btree* x,int k, int t){
    int i=x->n-1;
    if(x->leaf){                            //Inserting the key in the node in case it is leaf
        while(i>=0&&k<x->keys[i]){
            x->keys[i+1]=x->keys[i];
            i--;
        }
        x->keys[i+1]=k;
        x->n=x->n+1;
    }
    else{
        while(i>=0&&k<x->keys[i]){
            i=i-1;
        }
        i=i+1;
        if(x->c[i]->n==2*t-1){                  //Finding the node for the key to be inserted and splitting it in case it is full.
            B_TREE_SPLIT_CHILD(x,i,t);
            if(k>x->keys[i])i++;
        }
        B_TREE_INSERT_NONFULL(x->c[i],k,t);
    }
}

pair* B_TREE_SEARCH(btree*x,int k){             //Searching a key in the B-Tree
    int i=0;
    while(i<x->n&&k>x->keys[i])i++;
    if(i<x->n&&k==x->keys[i]) return make_pair(x,i);
    else if(x->leaf)return NULL;
    return B_TREE_SEARCH(x->c[i],k);
}

int B_TREE_MIN(btree* x){               //Finding minimum key in the tree
    if(x->n==0){
        printf("Tree is empty\n");
        return -1;
    }
    while(!x->leaf)x=x->c[0];
    return x->keys[0];
}

void B_TREE_INORDER_TRAVERSE(btree* x){                 //Inorder traversal of the B-Tree
    if(x->n==0){
        printf("Tree is empty\n");
        return;
    }
    if(x->leaf){
        for(int i=0;i<x->n;i++){
            printf("%d ",x->keys[i]);
        }
    }
    else{
        for(int i=0;i<x->n;i++){
            B_TREE_INORDER_TRAVERSE(x->c[i]);
            printf("%d ",x->keys[i]);
        }
        B_TREE_INORDER_TRAVERSE(x->c[x->n]);
    }
}