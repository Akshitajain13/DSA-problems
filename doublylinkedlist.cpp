#include <stdio.h>
#include <stdlib.h>
struct DouNode{
  struct DouNode *prev;
  int data;
struct DouNode *next;
}*one=NULL;
void createdou(int A[],int n){
  int i;
  struct DouNode *t,*last;
  one =new DouNode;
  one->data=A[0];
  one->next=NULL; 
  last=one;
  for (i=1;i<n;i++){
    t=new DouNode;
    t->prev=last;
    t->data=A[i];
    t->next=last->next;
    last->next=t;
    last=t;
  }
}

void DisplayDou(struct DouNode *p){
  while(p!=NULL){
    printf("%d ",p->data);
    p=p->next;
  }
}
int count(struct Node *p) {
    int length = 0;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}
void insertDou(struct DouNode*p,int x,int index){
  struct DouNode *t;
  int i;
  t=(struct DouNode*)malloc(sizeof(struct DouNode));
  if(index==0){
    t->data=x;
    t->next=one;
    one=t;
    one->prev=t;
    t->prev=NULL;
    one=t;
  }
  else
  {
    for(i=0;i<index-1;i++){
      p=p->next;
    }
    t->data=x;
    t->prev=p;
    t->next=p->next;
    if(p->next) p->next->prev=t;
    p->next=t;
  }

}
int deletingDou(struct DouNode*p,int index){
  struct DouNode *q=NULL;
  int x=-1,i;
  if(index==1){
    q=one;
    x=one->data;
    one=one->next;
    one->prev=NULL;
    free(p);
    return x;
    }
    else{
      for(i=0;i<index-1;i++){
        p=p->next;}
        p->prev->next=p->next;
        if(p->next) p->next->prev=p->prev;
      x=p->data;
      free(p);
      return x;
    }
  
}