#include <stdio.h>
#include <ctype.h>  // for isdigit() function

#define MAX 100

int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = val;
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    int i = 0;
    char ch;
    int result;
    

    while(postfix[i] != '\0'){
        ch = postfix[i];

        if(isdigit(ch)){
            push(ch - '0');
        } else {
            int op2 = pop();
            int op1 = pop();

            switch (ch)
            {
            case '+':
                result = op1 + op2;
                break;

            case '-':
                result = op1 - op2;
                break;

            case '*':
                result = op1 * op2;
                break;

            case '/':
                result = op1 / op2;
                break;        
            
            default:
                printf("Invalid Expression");
                break;
            }
            push(result);
        }
        i++;
    }
    return pop();
}

int main() {
    char postfix[MAX];

    // Input the postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Evaluate the postfix expression and print the result
    int result = evaluatePostfix(postfix);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
