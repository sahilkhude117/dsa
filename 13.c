#include<stdio.h>
#include<stdlib.h>

#define max 5

int queue[max];
int front = -1,rear = -1;

int isFull(){
    return (front == (rear+1) % max);
}

int isEmpty(){
    return front == -1;
}

void enqueue(){
    int val;
    if(isFull()){
        printf("Queue Overflow");
        return;
    }
    printf("Enter value to enqueue :");
    scanf("%d",&val);

    if(isEmpty()){
        front = rear = 0;
    } else{
        rear = (rear + 1)%max;
    }
    queue[rear] = val;
    printf("%d has been enqueued.\n", val);
}

void dequeue(){
    if(isEmpty()){
        printf("Queue Underflow! Cannot dequeue.\n");
        return;
    }
    printf("%d has been dequeued. \n",queue[front]);

    if(front == rear){
        front = rear = -1;
    } else{
        front = (front + 1)%max;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % max;
    }
    printf("\n");
}

// Function to count the number of elements in the queue
void count() {
    if (isEmpty()) {
        printf("Queue is empty. Count is 0.\n");
    } else {
        int count = (rear + max - front) % max + 1;
        printf("Number of elements in the queue: %d\n", count);
    }
}

// Main menu-driven program
int main() {
    int choice;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. COUNT\n");
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
                count();
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