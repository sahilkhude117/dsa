#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Max size of the stack

int stack[MAX];
int top = -1;

// Function to push an element into the stack
void push() {
    int value;
    if (top == MAX - 1) {
        printf("Stack Overflow! Unable to push.\n");
    } else {
        printf("Enter the value to be pushed: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! No element to pop.\n");
    } else {
        printf("%d popped from the stack.\n", stack[top]);
        top--;
    }
}

// Function to display the elements of the stack
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Function to count the number of elements in the stack
void count() {
    if (top == -1) {
        printf("Stack is empty! No elements to count.\n");
    } else {
        printf("The number of elements in the stack: %d\n", top + 1);
    }
}

// Main function - Menu driven
int main() {
    int choice;

    while (1) {
        printf("\n----- Stack Operations Menu -----\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. COUNT\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                count();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
