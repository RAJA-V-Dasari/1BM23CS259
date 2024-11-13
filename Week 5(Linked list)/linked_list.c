#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create_ll(struct node *start) {
    int value;
    struct node *newnode, *ptr;

    printf("Enter values for the nodes. Enter -1 to stop.\n");

    while (1) {
        printf("Enter value: ");
        scanf("%d", &value);

        if (value == -1) {
            break;
        }

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if (start == NULL) {
            start = newnode;
        } else {
            ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
    }

    return start;
}

struct node *insert_beg(struct node *start) {
    int val;
    struct node *newnode;
    printf("Enter the value to be inserted at the beginning:\n");
    scanf("%d", &val);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = start;
    start = newnode;
    return start;
}

struct node *insert_last(struct node *start) {
    int num;
    struct node *newnode, *ptr;
    printf("Enter the value to be inserted at last:\n");
    scanf("%d", &num);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
    } else {
        ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }

    return start;
}

struct node *insert_pos(struct node *start) {
    int num, pos;
    struct node *newnode;
    printf("Enter value to be inserted:\n");
    scanf("%d", &num);
    printf("Enter position to be inserted:\n");
    scanf("%d", &pos);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;

    if (pos == 1) {
        start = insert_beg(start);
        return start;
    }

    struct node *ptr = start;
    for (int i = 1; i < pos - 1; i++) {
        if (ptr == NULL) {
            printf("Position out of range.\n");
            return start;
        }
        ptr = ptr->next;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;

    return start;
}

struct node *display(struct node *start) {
    struct node *ptr;
    ptr = start;

    if (ptr == NULL) {
        printf("List is empty.\n");
        return start;
    }

    printf("List: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return start;
}

struct node *delete_beg(struct node *start) {
    if (start == NULL) {
        printf("Empty list, nothing to delete.\n");
        return start;
    }

    struct node *ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

struct node *delete_last(struct node *start) {
    if (start == NULL) {
        printf("Empty list, nothing to delete.\n");
        return start;
    }

    struct node *ptr = start, *preptr = NULL;
    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (preptr == NULL) {
        free(ptr);
        return NULL;
    }

    preptr->next = NULL;
    free(ptr);
    return start;
}

struct node *delete_pos(struct node *start) {
    int pos;
    printf("Enter the position to be deleted: ");
    scanf("%d", &pos);

    if (pos == 1) {
        start = delete_beg(start);
        return start;
    }

    struct node *ptr = start, *preptr = NULL;
    for (int i = 1; i < pos; i++) {
        if (ptr == NULL) {
            printf("Position out of range.\n");
            return start;
        }
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = ptr->next;
    free(ptr);
    return start;
}

int main() {
    int choice;
    printf("1. Insert at beg\n2. Insert at last\n3. Insert at pos\n4. Delete beg\n5. Delete last\n6. Delete pos\n7. Display\n8. Create Linked List\n9. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: start = insert_beg(start); break;
            case 2: start = insert_last(start); break;
            case 3: start = insert_pos(start); break;
            case 4: start = delete_beg(start); break;
            case 5: start = delete_last(start); break;
            case 6: start = delete_pos(start); break;
            case 7: start = display(start); break;
            case 8: start = create_ll(start); break;  // Create a new linked list
            case 9: return 0;  // Exit the program
            default: printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
