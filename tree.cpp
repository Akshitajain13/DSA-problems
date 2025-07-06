#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
} *root = NULL;
struct Queue {
    int front;
    int size;
    int rear;
    struct Node **Q;
};
struct Stack{
    int top;
    int size;
    Node **S;
};
int count(struct Node *p){
    int x,y;
    if(p){
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
    return 0;
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
int nonleafnode(struct Node *p){
    int x,y;
    if(p){
        x=nonleafnode(p->lchild);
        y=nonleafnode(p->rchild);
        if(p->lchild||p->rchild){
            return x+y+1;
        }
        else
            return x+y;  
    }
    return 0;  
}
void createQueue(struct Queue *q) {
    printf("Enter queue size: ");
    if (scanf("%d", &q->size) != 1) {
    fprintf(stderr, "Error reading input\n");}
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}
void createStack(struct Stack *st){
    printf("Enter size");
    if (scanf("%d", &st->size) != 1)
    {
        fprintf(stderr, "Input error\n");
        exit(1);
    }
    st->top = -1;
    st->S = (Node **)malloc(st->size * sizeof(Node));
}
void pushStack(struct Stack *st, Node* x){
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}
Node* popStack(struct Stack *st){
    Node* x = NULL;
    if (st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}
void enqueueQueue(struct Queue *q, struct Node *x) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full\n");
    }
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}
struct Node *dequeueQueue(struct Queue *q) {
    struct Node *x = NULL;
    if (q->front == q->rear) {
        printf("Queue is empty\n");
    }
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
int isEmptyQueue(struct Queue q) {
    return q.front == q.rear;
}
int isEmpty(struct Stack st){
    if (st.top == -1)
        return 1;
    return 0;
}
void createTree() {
    struct Node *p, *t;
    int x;
    struct Queue q;
    createQueue(&q);
    printf("Enter root value: ");
    if (scanf("%d", &x) != 1) {
        fprintf(stderr, "Error reading integer\n");
    }
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueueC(&q, root);
    while (!isEmpty(q)) {
        p = dequeueQueue(&q);
        printf("Enter left child of %d (-1 for NULL): ", p->data);
        if (scanf("%d", &x) != 1) {
            fprintf(stderr, "Error reading integer\n");
        }
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueueQueue(&q, t);
        }
        printf("Enter right child of %d (-1 for NULL): ", p->data);
        if (scanf("%d", &x) != 1) {
            fprintf(stderr, "Error reading integer\n");
        }
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueueQueue(&q, t);
        }
    }
}
void preorder(struct Node *p) {
    if (p) {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void preorderIterative(struct Node *p){
    struct Stack st;
    createStack(&st);
    while(p||!isEmpty(st)){
        if(p){
            printf("%d ",p->data);
            pushStack(&st,p);
            p=p->lchild;
        }
        else{
            p=popStack(&st);
            p=p->rchild;
        }
    }
}
void InorderIterative(struct Node *p){
    struct Stack st;
    createStack(&st);
    while(p||!isEmpty(st)){
        if(p){
            pushStack(&st,p);
            p=p->lchild;
        }
        else{
            p=popStack(&st);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }
}
void PostorderIterative(struct Node *p){
    struct Stack st;
    createStack(&st);
    long long temp;
    while(p||!isEmpty(st)){
        if(p){
            pushStack(&st,p);
            p=p->lchild;
        }
        else{
            temp=(long long)popStack(&st);   
            if(temp>0){
                pushStack(&st,(Node*)(-1*temp));
                p=((Node*)temp)->rchild;
            }
            else{
                printf("%d ",((Node*)(-1*temp))->data);
                p=NULL;
            }
        }
    }
}
void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
    
}
void levelorder(struct Node *root){
    struct Queue q;
    createQueue(&q);
    printf("%d ",root->data);
    enqueueQueue(&q,root);
    while(!isEmptyQueue(q)){
        root=dequeueQueue(&q);
        if(root->lchild){
            printf("%d ",root->lchild->data);
            enqueueQueue(&q,root->lchild);
        }
        if(root->rchild){
            printf("%d ",root->rchild->data);
            enqueueQueue(&q,root->rchild);
        }
    }
}
