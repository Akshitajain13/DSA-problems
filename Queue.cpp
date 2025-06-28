#include <stdio.h>
#include <stdlib.h>
struct Queue{
int front;
int size;
int rear;
int *Q;
};
struct Node{
    int data;
  struct Node *next;
  }*top=NULL,*front=NULL,*rear=NULL;
  
void createQ(struct Queue* q){
    printf("Enter size");
    if (scanf("%d", &q->size) != 1) {
        fprintf(stderr, "Input error\n");
        exit(1);
    }
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
}
void enqueue(struct Queue* q,int x){
    if(q->rear==q->size-1){
        printf("Queue is Full");
    }
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct Queue* q){
    int x=-1;
    if(q->front==q->rear){
        printf("Queue is Empty\n");
    }
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
void DisplayQ(struct Queue q){
    int i;
    for(i=q.front+1;i<=q.rear;i++)
        printf("%d ",q.Q[i]);
    printf("\n");
}
void enqueueL(int x){
    struct Node* t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Queue is Full\n");
    }
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL){
            front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}
int dequeueL(){
    int x=-1;
    struct Node* t;
    if(front==NULL){
        printf("Queue is Empty\n");
    }
    else{
        x=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return x;
}
void createQC(struct Queue* q){
    printf("Enter size");
    if (scanf("%d", &q->size) != 1) {
        fprintf(stderr, "Input error\n");
        exit(1);
    }
    q->front=q->rear=0;
    q->Q=(int *)malloc(q->size*sizeof(int));
}
void enqueueC(struct Queue* q,int x){
    if((q->rear+1)%q->size==q->front){
        printf("Queue is Full");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
int dequeueC(struct Queue* q){
    int x=-1;
    if((q->front+1)%q->size==q->rear){
        printf("Queue is empty");
    }
    else{
        q->front=(q->front+1)%q->front;
        x=q->Q[q->front];
    }
    return x;
}
void DisplayQC(struct Queue q){
    int i=q.front+1;
    do{
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
}
