#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;
struct node* createnode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

struct node* insert_node(struct node* root, int val){
    if (root == NULL) {
        return createnode(val);
    }

    if (val < root->data) {
        root->left = insert_node(root->left, val);
    } else {
        root->right = insert_node(root->right, val);
    }
    return root;
}

struct node* in_order(struct node* root){
    if(root!=NULL){
        in_order(root->left);
        printf("%d  ",root->data);
        in_order(root->right);
    }
    return root;
}
struct node* pre_order(struct node* root){
    if(root!=NULL){

        printf("%d  ",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
    return root;
}
struct node* post_order(struct node* root){
    if(root!=NULL){
        post_order(root->left);
        post_order(root->right);
        printf("%d  ",root->data);
    }
    return root;
}

void main(){
    printf("1.Insert\n2.In_order\n3.Pre_order\n4.Post_order\n5.Exit\n");
    int flag = 0;
    while(flag == 0){
        int opt;
        printf("\nEnter choice:");
        scanf("%d",&opt);
        switch(opt){
            case 1: printf("Enter value to be inserted: ");
                    int val;
                    scanf("%d",&val);
                    root = insert_node(root,val);
                    break;
            case 2: root = in_order(root); break;
            case 3: root = pre_order(root); break;
            case 4: root = post_order(root); break;
            case 5: flag = 1;break;
        }
    }
}

