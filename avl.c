# include "avl.h"

avlnode * avl_getavlnode(int x){
    avlnode * t = (avlnode*)malloc(sizeof(avlnode));
    t->data=x;
    t->left=NULL;
    t->right=NULL;
    t->height=0;
    return t;
}

int avl_getheight(avlnode* t){
    if(t==NULL) return 0;
    if(t->left==NULL && t->right==NULL) return 0;
    int left=avl_getheight(t->left);
    int right=avl_getheight(t->right);
    if(left>right)return 1+left;
    else return 1+right;
}

avlnode* avl_addtree(avlnode* root,int t){
    if(root==NULL){
        return avl_getavlnode(t);
    } 
    if(t<root->data){
        root->left=avl_addtree(root->left,t);
        root->left->height=avl_getheight(root->left);
    }
    else{
        root->right=avl_addtree(root->right,t);
        root->right->height=avl_getheight(root->right);
    }
    int bf=balancefactor(root);
    if(bf!=1&&bf!=0&&bf!=-1){
        if(bf<0){
            if(t>=root->right->data)root=RR(root);
            else root=RL(root);
        }
        else{
            if(t<root->left->data)root=LL(root);
            else root=LR(root);
        }
    }
    return root;
}  


avlnode* avl_delete(avlnode* root,int t){
    if(root==NULL)return NULL;
    else if(root->data==t){
        if(root->left==NULL&&root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left==NULL){
            avlnode*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            avlnode*temp=root->left;
            free(root);
            return temp;
        }
        else{
            int m=avl_minimum(root->right);
            root->data=m;
            root->right=avl_delete(root->right,m);
            root->height=avl_getheight(root);
            int bf=balancefactor(root);
            if(bf!=1&&bf!=0&&bf!=-1){
                if(bf<0){
                    if(t>=root->right->data)root=RR(root);
                    else root=RL(root);
                }
                else{
                    if(t<root->left->data)root=LL(root);
                    else root=LR(root);
                }
            }
            return root;
        }
    }
    else if(root->data>t)root->left=avl_delete(root->left,t);
    else if(root->data<t)root->right=avl_delete(root->right,t);
    root->height=avl_getheight(root);
    int bf=balancefactor(root);
    if(bf!=1&&bf!=0&&bf!=-1){
        if(bf<0){
            if(t>=root->right->data)root=RR(root);
            else root=RL(root);
        }
        else{
            if(t<root->left->data)root=LL(root);
            else root=LR(root);
        }
    }
    return root;
}

int balancefactor(avlnode * r){
    if(r==NULL) return 0;
    int lh,rh;
    if(r->left==NULL)lh=0;
    else lh=r->left->height;
    if(r->right==NULL) rh=0;
    else rh=r->right->height;
    return lh-rh;
}

avlnode* LL(avlnode* r){
    avlnode *temp =r->left;
    r->left=r->left->right;
    temp->right=r;
    r->height=avl_getheight(r);
    temp->height=avl_getheight(r);
    return temp;
}

avlnode* RR(avlnode* r){
    avlnode *temp =r->right;
    r->right=r->right->left;
    temp->left=r;
    r->height=avl_getheight(r);
    temp->height=avl_getheight(r);
    return temp;
}

avlnode* LR(avlnode* r){
    r->left=RR(r->left);
    avlnode*temp = LL(r);
    return temp;
}

avlnode* RL(avlnode* r){
    r->right=LL(r->right);
    avlnode* temp=RR(r);
    return temp;
}

avlnode * avl_search(avlnode* root, int x){
    if(root==NULL)return NULL;
    else if(root->data==x)return root;
    else if(root->data>x)return avl_search(root->left,x);
    else if(root->data<x)return avl_search(root->right,x);
}

int avl_minimum(avlnode* root){
    if(root->left==NULL)return root->data;
    else return avl_minimum(root->left);
}

int avl_maximum(avlnode* root){
    if(root->right==NULL)return root->data;
    else return avl_maximum(root->right);
}

void avl_preorder(avlnode* root){
    if(root!=NULL){
        printf("%d ",root->data);
        avl_preorder(root->left);
        avl_preorder(root->right);
    }
}

void avl_inorder(avlnode* root){
    if(root!=NULL){
        avl_inorder(root->left);
        printf("%d ",root->data);
        avl_inorder(root->right);
    }
}

void avl_postorder(avlnode* root){
    if(root!=NULL){
        avl_postorder(root->left);        
        avl_postorder(root->right);
        printf("%d ",root->data);
    }
}
