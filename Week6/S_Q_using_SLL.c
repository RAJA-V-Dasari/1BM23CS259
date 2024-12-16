#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Stack functions
struct Node* push(struct Node* top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = top;
    return newNode;
}

struct Node* pop(struct Node* top, int* poppedData) {
    if (top == NULL) {
        *poppedData = -1;
        return NULL;
    }
    struct Node* temp = top;
    *poppedData = temp->data;
    top = temp->next;
    free(temp);
    return top;
}

// Queue functions
struct Node* enqueue(struct Node* rear, int data) {
    struct Node* newNode = createNode(data);
    if (rear) rear->next = newNode;
    return newNode;
}

struct Node* dequeue(struct Node* front, int* dequeuedData) {
    if (front == NULL) {
        *dequeuedData = -1;
        return NULL;
    }
    struct Node* temp = front;
    *dequeuedData = temp->data;
    front = temp->next;
    free(temp);
    return front;
}

// Display functions
void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack: Empty\n");
        return;
    }
    printf("Stack: ");
    while (top) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue: Empty\n");
        return;
    }
    printf("Queue: ");
    while (front) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}


int main() {
    struct Node* stackTop = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;
    int choice, value;

    printf("1: Push  2: Pop  3: Enqueue  4: Dequeue  5: Show Stack  6: Show Queue  7: Exit\n");

    while (1) {
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: ");
                scanf("%d", &value);
                stackTop = push(stackTop, value);
                break;

            case 2: {
                int poppedData;
                stackTop = pop(stackTop, &poppedData);
                if (poppedData == -1) printf("Stack: Empty\n");
                else printf("Popped: %d\n", poppedData);
                break;
            }

            case 3:
                printf("Value: ");
                scanf("%d", &value);
                queueRear = enqueue(queueRear, value);
                if (queueFront == NULL) queueFront = queueRear; // Initialize front if queue was empty
                break;

            case 4: {
                int dequeuedData;
                queueFront = dequeue(queueFront, &dequeuedData);
                if (queueFront == NULL) queueRear = NULL; // Reset rear if queue is now empty
                if (dequeuedData == -1) printf("Queue: Empty\n");
                else printf("Dequeued: %d\n", dequeuedData);
                break;
            }

            case 5:
                displayStack(stackTop);
                break;

            case 6:
                displayQueue(queueFront);
                break;

            case 7:
                printf("Exit\n");
                exit(0);

            default:
                printf("Invalid\n");
        }
    }

    return 0;
}
