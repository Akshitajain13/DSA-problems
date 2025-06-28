#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
struct Node *next;
}*first=NULL,*second=NULL,*third=NULL ,*head=NULL;
void create (int A[],int n){
  int i;
  struct Node *t,*last;
  first =(struct Node *)malloc(sizeof (struct Node));
  first->data=A[0];
  first ->next=NULL;
  last=first;
  for (i=1;i<n;i++){
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
  }
}
void create2 (int A[],int n){
  int i;
  struct Node *t,*last;
  second =(struct Node *)malloc(sizeof (struct Node));
  second->data=A[0];
  second ->next=NULL;
  last=second;
  for (i=1;i<n;i++){
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
  }
}
void Display(struct Node *p){
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
void insert(struct Node*p,int x,int index){
struct Node *t;
int i;
t=(struct Node*)malloc(sizeof(struct Node));
if(index==0){
  t->data=x;
  t->next=first;
  first=t;
}
else
{
  for(i=0;i<index-1;i++){
    p=p->next;
  }
  t->data=x;
  t->next=p->next;
  p->next=t;
}
}
void sortedlist(struct Node *p, int x){
  struct Node *t,*q=NULL;
  t=(struct Node*)malloc(sizeof(struct Node));
  t->data=x;
  t->next=NULL;
  if(first==NULL){
    t->next=first;
    first=t;
  }
  else{
    while(p&&p->data<x){
      q=p;
      p=p->next;
      }
    if(p==first){
      t->next=first;
      first=t;
    }
    else{
      t->next=q->next;
      q->next=t;
    }
  }
}
int deleting(struct Node*p,int index){
  struct Node *q=NULL;
  int x=-1,i;
  if(index<1||index>count(p)){
    return -1;
  }
  else{
    if(index==1){
      q=first;
      x=first->data;
      first=first->next;
      free(q);
      return x;
    }
    else{
      for(i=0;i<index-1;i++){
        q=p;
        p=p->next;
      }
      q->next=p->next;
      x=p->data;
      free(p);
      return x;
    }
  }
}
void removeduplicate(struct Node *p){
  struct Node *q=p->next;
  while(q!=NULL){
    if(p->data!=q->data){
      p=q;
      q=q->next;
      }
    else{
      p->next=q->next;
      free(q);
      q=p->next;       
    }
    }
  }
void concatenate(struct Node *p,struct Node *q){
  third=p;
  while(p->next!=NULL){
    p=p->next;
  }
  p->next=q;
  Display(third);  
}
void merge(struct Node *p,struct Node *q){
  struct Node *last;
  if(p->data<q->data){
    third=last=p;
    p=p->next;
    third->next=NULL;
    }
  else{
    third=last=q;
    q=q->next;
    third->next=NULL;
  }
  while(p&&q){
    if(p->data<q->data){
      last->next=p;
      last=p;
      p=p->next;
      last->next=NULL;
    }
    else{
      last->next=q;
      last=q;
      q=q->next;
      last->next=NULL;
    }
  }
  if(p) last->next=p;
  else last->next=q;
  }
  