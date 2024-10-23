#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Top pointer of the stack
struct Node* top = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push() {
    int value;
    printf("Enter the value to be pushed: ");
    scanf("%d", &value);

    struct Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;

    printf("%d pushed onto the stack.\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! No element to pop.\n");
    } else {
        struct Node* temp = top;
        printf("%d popped from the stack.\n", top->data);
        top = top->next;
        free(temp);
    }
}

// Function to display all elements of the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty!\n");
    } else {
        struct Node* temp = top;
        printf("Stack elements are:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

// Function to search for an element in the stack
void search() {
    if (top == NULL) {
        printf("Stack is empty!\n");
    } else {
        int value, pos = 1;
        printf("Enter the value to search: ");
        scanf("%d", &value);

        struct Node* temp = top;
        while (temp != NULL) {
            if (temp->data == value) {
                printf("%d found at position %d in the stack.\n", value, pos);
                return;
            }
            pos++;
            temp = temp->next;
        }
        printf("%d not found in the stack.\n", value);
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
        printf("4. SEARCH\n");
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
                search();
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
