#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

struct Queue {
    int items[MAX];
    int front, rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}
void BFS(int adj_graph[MAX][MAX], int n, int start) {
    bool visited[MAX] = {false};
    struct Queue* q = createQueue();

    printf("BFS Traversal: ");
    visited[start] = true;
    enqueue(q, start);

    while (!isEmpty(q)) {
        int current = dequeue(q);
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj_graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}
int main() {
    int n, start, adj_graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj_graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    BFS(adj_graph, n, start);

    return 0;
}
