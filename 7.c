#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure
struct Stack {
    int top;
    int capacity;
    char* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Stack is full when the top is equal to the last index
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is -1
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to the stack
void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to remove an item from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->array[stack->top--];
}

// Function to reverse the string using a stack
void reverseString(char* str) {
    int n = strlen(str);

    // Create a stack of capacity equal to string length
    struct Stack* stack = createStack(n);

    // Push all characters of the string to stack
    for (int i = 0; i < n; i++) {
        push(stack, str[i]);
    }

    // Pop all characters from stack and put them back to the string
    for (int i = 0; i < n; i++) {
        str[i] = pop(stack);
    }

    free(stack->array); // Free allocated memory
    free(stack);        // Free stack pointer
}

int main() {
    char str[100];

    // Input the string
    printf("Enter the string to be reversed: ");
    gets(str); // Gets the full string including spaces

    // Reverse the string
    reverseString(str);

    // Output the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
