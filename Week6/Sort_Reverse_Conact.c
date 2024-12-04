

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int val;
    struct Node* next;
};

// Create a new node
struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->next = NULL;
    return n;
}

// Insert a node at the end
struct Node* insert(struct Node* head, int val) {
    struct Node* n = newNode(val);
    if (!head) return n;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    return head;
}


struct Node* sort(struct Node* head) { if (!head || !head->next) return head;
struct Node *i, *j; int temp;
for (i = head; i; i = i->next) {
for (j = i->next; j; j = j->next) {
if (i->val > j->val) {
temp = i->val; i->val = j->val; j->val = temp;
}
}
 } return head;
 }

// Reverse the list
struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Concatenate two lists
struct Node* concatenate(struct Node* list1, struct Node* list2) {
    if (!list1) return list2;
    struct Node* temp = list1;
    while (temp->next) temp = temp->next;
    temp->next = list2;
    return list1;
}

// Print the list
void print(struct Node* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, val;


        printf("\n1. Insert to List 1\n2. Insert to List 2\n3. Sort List 1\n4. Sort List 2\n");
        printf("5. Reverse List 1\n6. Reverse List 2\n7. Concatenate Lists\n8. Print List 1\n9. Print List 2\n10. Exit\n");

         while (1) {printf("Enter choice: ");
         scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert in List 1: ");
                scanf("%d", &val);
                list1 = insert(list1, val);
                break;
            case 2:
                printf("Enter value to insert in List 2: ");
                scanf("%d", &val);
                list2 = insert(list2, val);
                break;
            case 3:
                list1 = sort(list1);
                printf("List 1 sorted.\n");
                break;
            case 4:
                list2 = sort(list2);
                printf("List 2 sorted.\n");
                break;
            case 5:
                list1 = reverse(list1);
                printf("List 1 reversed.\n");
                break;
            case 6:
                list2 = reverse(list2);
                printf("List 2 reversed.\n");
                break;
            case 7:
                list1 = concatenate(list1, list2);
                printf("Lists concatenated.\n");
                break;
            case 8:
                printf("List 1: ");
                print(list1);
                break;
            case 9:
                printf("List 2: ");
                print(list2);
                break;
            case 10:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
