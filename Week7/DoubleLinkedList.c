#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *insert_left(struct node *head,int data, int val);
struct node *delete(struct node *head,int val);
struct node *create_ll(struct node *head);
struct node *createnode(int data);

void display_ll(struct node *head);

struct node *createnode(int data1){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data1;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    return newnode;
}
struct node *create_ll(struct node *head){
    int e_data;
    head = NULL;
    struct node* ptr = NULL;
    while(1){
            printf("Enter data: ");
            scanf("%d",&e_data);
            if(e_data == -1){
                break;
            }
            struct node *a_node = createnode(e_data);
            if(head == NULL){
                head = a_node;
                ptr = head;
            }
            else{
                ptr->next = a_node;
                a_node -> prev = ptr;
                ptr = ptr->next;

            }
        }
        return head;
}

void display(struct node *head){
    struct node *ptr = head;
    printf("Linked list is : ");
    while(ptr->next!=NULL){
        printf("%d  ",ptr->data);
        ptr = ptr->next;
    }
    printf("%d  \n",ptr->data);
}

struct node *insert_left(struct node *head, int data, int val){
    struct node *ptr = head;
    if(head == NULL){
        printf("No element in the list \n");
        return head;
    }
    while(ptr!=NULL && ptr->data != val){
        ptr = ptr ->next;
    }
    if(ptr==NULL){
        printf("%d not found",val );
        return head;

    }
    else{
        struct node *a_node = createnode(data);
        a_node ->next = ptr;
        if(ptr->prev != NULL){
            a_node->prev = ptr->prev;
            ptr->prev->next = a_node;

        }
        else{
            head = a_node;
        }
        ptr->prev = a_node;
        return head;
    }

}
struct node *delete(struct node* head, int data1){
    struct node* ptr = head;
    if(head == NULL){
            printf("Empty\n");
                return head;
       }
    else{
        while(ptr!=NULL && ptr->data!=data1){
            ptr = ptr->next;
        }
        if(ptr==NULL){
            printf("%d not in list\n",data1);
        }
        else{
            if(ptr->prev!=NULL){
                ptr->prev->next = ptr->next;
            }
            else{
                head = ptr->next;
            }
            if(ptr->next != NULL){
                ptr->next->prev = ptr->prev;
            }
        }
        free(ptr);
        return head;

    }
}

void main(){
    printf("1. Insert left\n 2. Delete\n3.display\n4.create list\n 5. exit");
    int opt;
    printf("\nEnter an option: ");
    scanf("%d",&opt);
    while(1){
        switch(opt){
            int val,data ;
            case 1:
                    printf("Value to insert: "); scanf("%d",&data);
                    printf("Value before which insertion: "); scanf("%d",&val);
                    head = insert_left(head,data,val);
                    break;
            case 2:
                    printf("Value to be deleted: "); scanf("%d",&val);
                    head = delete(head,val);
                    break;
            case 3: display(head);break;
            case 4: head = create_ll(head); break;
            case 5: break;
        }
         printf("\nEnter an option: ");
    scanf("%d",&opt);
    }
}
