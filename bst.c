# include "bst.h"

void bst(void){
    
}

Node * bst_getnode(int x){
    Node * t = (Node*)malloc(sizeof(Node));
    t->data=x;
    t->left=NULL;
    t->right=NULL;
    return t;
}

void bst_addtree(Node* root,int t){
    if(t<=root->data){
        if(root->left==NULL){
            root->left=bst_getnode(t);
        } 
        else bst_addtree(root->left,t);
    }
    else{
        if(root->right==NULL) root->right=bst_getnode(t);
        else bst_addtree(root->right,t);
    }
}

Node* bst_delete(Node* root,int t){
    if(root==NULL)return NULL;
    else if(root->data==t){
        if(root->left==NULL&&root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left==NULL){
            Node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node*temp=root->left;
            free(root);
            return temp;
        }
        else{
            int m=bst_minimum(root->right);
            root->data=m;
            root->right=bst_delete(root->right,m);
            return root;
        }
    }
    else if(root->data>t)root->left=bst_delete(root->left,t);
    else if(root->data<t)root->right=bst_delete(root->right,t);
    return root;
}

Node * bst_search(Node* root, int x){
    if(root==NULL)return NULL;
    else if(root->data==x)return root;
    else if(root->data>x)return bst_search(root->left,x);
    else if(root->data<x)return bst_search(root->right,x);
}

int bst_minimum(Node* root){
    if(root->left==NULL)return root->data;
    else return bst_minimum(root->left);
}

int bst_maximum(Node* root){
    if(root->right==NULL)return root->data;
    else return bst_maximum(root->right);
}

void bst_preorder(Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        bst_preorder(root->left);
        bst_preorder(root->right);
    }
}

void bst_inorder(Node* root){
    if(root!=NULL){
        bst_inorder(root->left);
        printf("%d ",root->data);
        bst_inorder(root->right);
    }
}

void bst_postorder(Node* root){
    if(root!=NULL){
        bst_postorder(root->left);        
        bst_postorder(root->right);
        printf("%d ",root->data);
    }
}