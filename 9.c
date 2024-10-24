#include<stdio.h>
#include<ctype.h>

#define Max 50

int top = -1;
char arr[Max];

void push(int x){
    if(top == Max - 1){
        printf("Stack is full");
    } else{
        arr[++top] = x;
    }
}

int pop(){
    if(top == -1){
        printf("Stack is empty");
    } else{
        return arr[top--];
    }
}
int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}

void infixToPostfix(char infix[]){
    char postfix[Max];
    int i = 0, j =0;
    char ch;

    while(infix[i] != '\0'){
        ch = infix[i];

        //operand
        if(isalnum(ch)){
            postfix[j++] = ch;
        } else if(ch == '('){
            push(ch);
        } else if (ch ==')'){
            while(arr[top] != '('){
                pop();
            }
            pop(); // pop (
        } else{
            while(top != -1 || precedence(arr[top]) >= precedence(ch) ){
                postfix[j++] = pop();
            }
        }
        i++;
    }
    while(top != -1){
            postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[Max];

    // Input the infix expression
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert the infix expression to postfix
    infixToPostfix(infix);

    return 0;
}