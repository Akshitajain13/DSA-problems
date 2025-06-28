#include <stdio.h>
#include <stdlib.h>
class Node{
    public:
        int data;
        Node *next;
    };
    class Stack{
    private:
        Node* top;
    public:
        Stack(){top=NULL;}
        void push(int x);
        int pop();
        void Display();
    };
    void Stack::push(int x){
        Node* t=new Node;
        if(t==NULL)
            printf("stack is full\n");
        else{
            t->data=x;
            t->next=top;
            top=t;}
        }