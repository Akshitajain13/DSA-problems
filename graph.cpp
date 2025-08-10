#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
} *front = nullptr, *rear = nullptr;

void enqueueL(int x) {
    Node* t = new Node;
    if (t == nullptr) {
        cout << "Queue is Full\n";
    } else {
        t->data = x;
        t->next = nullptr;
        if (front == nullptr) {
            front = rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeueL() {
    int x = -1;
    if (front == nullptr) {
        cout << "Queue is Empty\n";
    } else {
        Node* t = front;
        x = front->data;
        front = front->next;
        delete t;
    }
    return x;
}

bool isEmpty() {
    return front == nullptr;
}

void BFS(int G[][7], int start, int n) {
    int visited[7] = {0};
    cout << start << " ";
    visited[start] = 1;
    enqueueL(start);

    while (!isEmpty()) {
        int i = dequeueL();
        for (int j = 1; j < n; j++) {
            if (G[i][j] == 1 && visited[j] == 0) {
                cout << j << " ";
                visited[j] = 1;
                enqueueL(j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n) {
    static int visited[7] = {0};
    if (visited[start] == 0) {
        cout << start << " ";
        visited[start] = 1;
        for (int j = 1; j < n; j++) {
            if (G[start][j] == 1 && visited[j] == 0) {
                DFS(G, j, n);
            }
        }
    }
}

int main() {
    int G[7][7] = {
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    cout << "BFS Traversal: ";
    BFS(G, 1, 7);
    cout << "\nDFS Traversal: ";
    DFS(G, 1, 7);
    cout << endl;

    return 0;
}