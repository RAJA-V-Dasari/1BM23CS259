#include<stdio.h>
#define size 3

int cqueue[size];
int front = -1;
int rear = -1;

void delete();
void insert(int x);
void display();

void insert(int n){
    if((rear+1)%size == front){
        printf("\nStack Overflow\n");
        return;
    }
    if(front == -1){
        front=0;
    }
    rear= (rear+1)%size;
    cqueue[rear] = n;
    printf("\n%d inserted successfully\n\n",n);
}

void delete() {
    if (front == -1) {
        printf("Queue underflow\n");
        return;
    }
    printf("\n %d deleted\n\n", cqueue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

void display(){
    if(front == -1 || front>rear){
        printf("\nQueue is empty \n");
        return;
    }
    printf("\nQueue elements are: ");
    int i = front;
    while(i!=rear){
        printf(" %d ",cqueue[i]);
        i = (i+1)%size;
    }
    printf(" %d",cqueue[i]);
    printf("\n");

}
int main(){
    int option, elem;
    int flag = 0;
    printf("Circular Queue implemenetation\n 1. Insert\n 2. Delete\n 3.Display\n4.Exit\n");
    while(flag==0){
        printf("Choose 1,2,3 or 4\n");
        scanf("%d",&option);
        switch(option){
            case 1: printf("Enter integer to be inserted:  ");
                    scanf("%d",&elem);
                    insert(elem);
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: flag = 1;
                    break;
            default: printf("Enter a valid option\n");
        }
    }
    return 0;

}
