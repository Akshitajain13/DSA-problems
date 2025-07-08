#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
} *root = NULL;
void insert(int key){
    struct Node *t = root;
    struct Node *r = NULL, *p;
    if (root == NULL){
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL){
        r = t;
        if (key < t->data){
            t = t->lchild;
        } 
        else if (key > t->data){
            t = t->rchild;
        } 
        else {
            return;
        }
    }
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        if (key < r->data){
            r->lchild = p;
        } else {
            r->rchild = p;
        }
    
}
void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
struct Node *Inpre(struct Node *p){
    while(p&&p->rchild!=NULL)
        p=p->rchild;
    return p;
}
struct Node *Insucc(struct Node *p){
    while(p&&p->lchild!=NULL)
        p=p->lchild;
    return p;
}
int height(struct Node *p){
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
struct Node *Search(int key){
    struct Node *t = root;
    while (t != NULL)
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    return NULL;
}
 struct Node* RInsert(struct Node *p,int key){
     struct Node *t=NULL;
     if(p==NULL){
         t=(struct Node*)malloc(sizeof(struct Node));
         t->data=key;
         t->lchild=t->rchild=NULL;
         return t;
     }
     else if(key<p->data)
         p->lchild=RInsert(p->lchild,key);
     else if(key>p->data)
         p->rchild=RInsert(p->rchild,key);
     return p;
}
 struct Node *Delete(struct Node *p,int key){
    struct Node *q;
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
    
