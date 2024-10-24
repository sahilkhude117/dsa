#include<stdio.h>
#include<string.h>

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

int main(){
    char str[Max];

    printf("enter string");
    gets(str);

    for(int i = 0; i < strlen(str);i++){
        push(str[i]);
    }

    while(top != -1){
        printf("%c",pop());
    }
}
