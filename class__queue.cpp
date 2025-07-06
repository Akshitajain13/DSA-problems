#include <stdio.h>
#include <stdlib.h>
class queue{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    queue(){front=rear=0;size=10;Q=new int[size];}   
    queue(int size){front=rear=0;this->size=size;Q=new int[this->size];}
    void enqueue(int x);
    int dequeue();
    void display();
    int isEmpty();
    int isFull();

};
void queue::enqueue(int x){
    if(rear==size-1){
        printf("Queue is full\n");
    }
    else{
        rear++;
        Q[rear]=x;
    }
}
int queue::dequeue(){
    int x=-1;
    if(front==rear){
        printf("Queue is empty\n");
    }
    else{
        x=Q[front+1];
        front++;
    }
    return x;
}
void queue::display(){
    for(int i=front+1;i<=rear;i++){
        printf("%d ",Q[i]);
    }
    printf("\n");
}
int queue::isEmpty(){
    if(front==rear){
        return 1;
    }
    return 0;
}
int queue::isFull(){
    if(rear==size-1){
        return 1;
    }
    return 0;
}
