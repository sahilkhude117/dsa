#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(){
    int val;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to enqueue: ");
    scanf("%d",&val);
    newNode->data = val;
    newNode->next = NULL;

    if(rear == NULL){
        front = rear = newNode;
    } else{
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue underflow");
    } else {
        struct Node* temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear == NULL;
        }
        free(temp);
    }
}

void display(){
    if(front == NULL){
        printf("Queue underflow");
    } else{
        struct Node* temp = front;
        while(temp != NULL){
            printf("%d",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void search(){
    if(front == NULL){
        printf("Queue underflow");
    } else {
        int val,found = 0;
        printf("Enter the value to search: ");
        scanf("%d",&val);
        struct Node* temp = front;
        while(temp != NULL){
            if(temp->data == val){
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if(found){
           printf("%d is found in the queue.\n", val);
        } else {
            printf("%d is not found in the queue.\n", val);
        }   
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. SEARCH\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
