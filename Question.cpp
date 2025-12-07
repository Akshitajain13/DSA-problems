#include <stdio.h>
#include <stdlib.h>
struct AVLNode {
    int data;
    struct AVLNode *lchild;
    int height;
    struct AVLNode *rchild;
}*root1 =NULL;
int NodeHeight(struct AVLNode *p){
    int hl,hr;
    hl=p&&p->lchild?p->lchild->height:0;
    hr=p&&p->rchild?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}
int BalanceFactor(struct AVLNode *p){
    int hl,hr;
    hl=p&&p->lchild?p->lchild->height:0;
    hr=p&&p->rchild?p->rchild->height:0;
    return hl-hr;
}
struct AVLNode *LLRotation(struct AVLNode *p){
    struct AVLNode *pl=p->lchild;
    struct AVLNode *plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    if(root1==p)
        root1=pl;
    return pl;
}
struct AVLNode *RRRotation(struct AVLNode *p){
    struct AVLNode *pl=p->rchild;
    struct AVLNode *plr=pl->lchild;
    pl->lchild=p;
    p->rchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    if(root1==p)
        root1=pl;
    return pl;
}
struct AVLNode *LRRotation(struct AVLNode *p){
    struct AVLNode *pl=p->lchild;
    struct AVLNode *plr=pl->rchild;
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;
    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);
    if(root1==p)
        root1=plr;
    return plr;
}
struct AVLNode *RLRotation(struct AVLNode *p){
    struct AVLNode *pl=p->rchild;
    struct AVLNode *plr=pl->lchild;
    pl->lchild=plr->rchild;
    p->rchild=plr->lchild;
    plr->rchild=pl;
    plr->lchild=p;
    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);
    if(root1==p)
        root1=plr;
    return plr;
}
 struct AVLNode* AVLrInsert(struct AVLNode *p,int key){
     struct AVLNode *t=NULL;
     if(p==NULL){
         t=(struct AVLNode*)malloc(sizeof(struct AVLNode));
         t->data=key;
         t->height=1;
         t->lchild=t->rchild=NULL;
         return t;
     }
     else if(key<p->data)
         p->lchild=AVLrInsert(p->lchild,key);
     else if(key>p->data)
         p->rchild=AVLrInsert(p->rchild,key);
     p->height=NodeHeight(p);
     if(BalanceFactor(p)==2&&BalanceFactor(p->lchild)==1){
         return LLrotation(p);
     }
     else if(BalanceFactor(p)==2&&BalanceFactor(p->lchild)==-1){
         return LRrotation(p);
     }
     else if(BalanceFactor(p)==-2&&BalanceFactor(p->rchild)==-1){
         return RRrotation(p);
     }
     else if(BalanceFactor(p)==-2&&BalanceFactor(p->rchild)==1){
         return RLrotation(p);
     }
}

void Inorder(struct AVLNode *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
struct AVLNode *Inpre(struct AVLNode *p){
    while(p&&p->rchild!=NULL)
        p=p->rchild;
    return p;
}
struct AVLNode *Insucc(struct AVLNode *p){
    while(p&&p->lchild!=NULL)
        p=p->lchild;
    return p;
}
int height(struct AVLNode *p){
    int x=0,y=0;
    if(p){
        x=height(p->lchild);
        y=height(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}
struct AVLNode *Search(int key){
    struct AVLNode *t ;
    while (t != NULL)
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    return NULL;
}

 struct AVLNode *Delete(struct AVLNode *p,int key){
    struct AVLNode *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL&&p->rchild==NULL){
        if(p==root)
         root=NULL;
        free(p);
        return NULL;
    }
    if(key<p->data){
        p->lchild=Delete(p->lchild,key);
    }
    else if(key>p->data){
        p->rchild=Delete(p->rchild,key);
    }
    else{
        if(height(p->lchild)>height(p->rchild)){
            q=Inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        } 
        else{
            q=Insucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
     return p;
}
int main(){

    return 0;
}