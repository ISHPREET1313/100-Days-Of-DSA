/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

int queue[MAX], front = 0, rear = 0;

void enqueue(int v) {
    queue[rear++] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void bfs(int s) {
    enqueue(s);
    visited[s] = 1;
    while (!isEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {
                enqueue(neighbor);
                visited[neighbor] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m, u, v, s;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    scanf("%d", &s);
    bfs(s);
    return 0;
}