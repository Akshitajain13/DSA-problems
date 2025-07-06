#include <stdio.h>
#include <stdlib.h>
class Node{
    public:
    int data;
    Node *lchild;
    Node *rchild;
};
class queue{
private:
    int size;
    int front;
    int rear;
    Node **Q;
public:
    queue(){front=rear=0;size=10;Q=new Node*[size];}   
    queue(int size){front=rear=0;this->size=size;Q=new Node*[this->size];}   
    void enqueue(Node* x);
    Node* dequeue();
    int isEmpty();

};
void queue::enqueue(Node* x){
    if(rear==size-1){
        printf("Queue is full\n");
    }
    else{
        rear++;
        Q[rear]=x;
    }
}
Node* queue::dequeue(){
    Node* x=NULL;
    if(front==rear){
        printf("Queue is empty\n");
    }
    else{
        x=Q[front+1];
        front++;
    }
    return x;
}
int queue::isEmpty(){
    if(front==rear){
        return 1;
    }
    return 0;
}
class Tree{
public:
    Node* root;
    Tree(){root=NULL;}
    void createTree();
    void preorder(Node* p);
    void postorder(Node* p);
    void inorder(Node* p);
    void levelorder(Node* p);
    int height(Node *root);
};
void Tree::createTree(){
    Node *p,*t;
    int x;
    queue q(100);
    printf("Enter root value: ");
    scanf("%d",&x);
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);
    while(!q.isEmpty()){
        p=q.dequeue();
        printf("Enter left child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        printf("Enter right child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}
void Tree::preorder(Node* p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void Tree::inorder(Node* p){
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}
void Tree::postorder(Node* p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}
void Tree::levelorder(Node* p){
    queue q(100);
    printf("%d ",root->data);
    q.enqueue(root);
    while(!q.isEmpty()){
        root=q.dequeue();
        if(root->lchild){
            printf("%d ",root->lchild->data);
            q.enqueue(root->lchild);
        }
        if(root->rchild){
            printf("%d ",root->rchild->data);
            q.enqueue(root->rchild);
        }
    }  
}
int Tree::height(Node *root){
    if(root==NULL){
        return 0;
    }
    int lheight=height(root->lchild);
    int rheight=height(root->rchild);
    if(lheight>rheight)
        return(lheight+1);
    else 
        return(rheight+1);   
}