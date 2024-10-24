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
    int original,reversed,num;

    printf("Enter Number " );
    Scanf("%d",&num);

    //push
    original = num;
    while(num >= 0){
        int reminder = num % 10;
        push(reminder);
        num /= 10;
    }
    //pop
    int multiplier = 1;
    while(top != -1){
        reversed += pop()*multiplier;
        multiplier *= 10;
    }

    if (original == reversed) {
        printf("%d is a palindrome number.\n", original);
    } else {
        printf("%d is not a palindrome number.\n", original);
    }

    return 0;
}