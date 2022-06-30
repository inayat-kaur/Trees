# include "btree.h"

int main(){
    int t,k;
    char ca;
    printf("Enter the minimum degree of the B-tree t: ");
    scanf("%d",&t);
    printf("Enter A or B: ");
    scanf(" %c",&ca);
    if(ca=='A'){
        btree * T;
        T=B_TREE_CREATE(t);         //Creating an empty tree
        for(int i=100;i>0;i--){
            T=B_TREE_INSERT(T,i,t);     //Inserting elements in the tree
        }
        printf("Inoder traversal is: ");
        B_TREE_INORDER_TRAVERSE(T);         //Inorder traversal of the tree
        printf("\nEnter an element to search: ");
        scanf("%d",&k);
        pair* p=B_TREE_SEARCH(T,k);         //pair p conatins pointer to the node in which key is present and the index at which it is present.
        if(p==NULL)printf("Not present\n");
        else printf("Present\n");
    }
    else if(ca=='B'){
            btree * T;
            T=B_TREE_CREATE(t);     //Creating an empty tree
        do{
            printf("options: I for insertion, S for search, M for finding minimum, T for traversing the B-tree, E for exit: ");
            scanf(" %c",&ca);
        if(ca=='I'){
            int p;
            printf("Enter number of elements you wanted to enter: ");
            scanf("%d",&k);
            printf("Enter %d numbers to insert: ",k);
            for(int i=0;i<k;i++){
                scanf("%d",&p);
                T=B_TREE_INSERT(T,p,t);             //Inserting elements in the tree
            }
        }
        else if(ca=='S'){
            printf("Enter element to search: ");
            scanf("%d",&k);
            pair* p=B_TREE_SEARCH(T,k);         //pair p conatins pointer to the node in which key is present and the index at which it is present.
            if(p==NULL)printf("Not present\n");
            else printf("Present\n");
        }
        else if(ca=='M'){
            printf("Minimum element is: %d\n",B_TREE_MIN(T));       //Printing minimum element of the tree
        }
        else if(ca=='T'){
            printf("Inorder traversal is: ");
            B_TREE_INORDER_TRAVERSE(T);         //Inorder traversal of the tree
            printf("\n");
        }
        }while(ca!='E');
    }
    return 0;
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