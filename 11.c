#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// ENQUEUE operation: Adds an element to the queue
void enqueue() {
    int val;
    if (isFull()) {
        printf("Queue Overflow! Cannot add more elements.\n");
    } else {
        printf("Enter the value to enqueue: ");
        scanf("%d", &val);
        if (front == -1) {
            front = 0;  // Initialize front to 0 if the queue is empty
        }
        queue[++rear] = val;  // Increment rear and insert the value
        printf("%d has been enqueued.\n", val);
    }
}

// DEQUEUE operation: Removes an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to dequeue.\n");
    } else {
        printf("%d has been dequeued.\n", queue[front]);
        front++;  // Increment front to remove the element
    }
}

// DISPLAY operation: Shows all the elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// COUNT operation: Returns the number of elements in the queue
void count() {
    if (isEmpty()) {
        printf("Queue is empty. No elements to count.\n");
    } else {
        printf("Number of elements in the queue: %d\n", rear - front + 1);
    }
}

int main() {
    int choice;

    while (1) {
        // Menu options
        printf("\nQueue Operations:\n");
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
