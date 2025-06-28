#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter size");
    if (scanf("%d", &st->size) != 1)
    {
        fprintf(stderr, "Input error\n");
        exit(1);
    }
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}
struct Node
{
    int data;
    struct Node *next;
} *top = NULL, *front = NULL, *rear = NULL;
void pushL(struct Node *top, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
int popL(struct Node *top)
{
    struct Node *t;
    int x = -1;
    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
void DisplayL(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void Display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}
void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}
int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}
int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Invalid Index \n");
    else
    {
        x = st.S[st.top - index + 1];
    }
    return x;
}
int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
int isFull(struct Stack st)
{
    if (st.top == st.size - 1)
        return 1;
    return 0;
}