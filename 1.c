#include<stdio.h>
#include<stdlib.h>

//node
struct Node
{
   int data;
   struct Node* next;
};

//start
struct Node* list = NULL;

//get node
struct Node* getNode(){
    return ((struct Node*)malloc(sizeof(struct Node)));
}

//free node
void freeNode(struct Node *p){
    free(p);
}

//insertBeg
void insertBeg(){
    int x;
    printf("Enter No to be inserted");
    scanf("%d ",&x);

    struct Node *newNode = getNode();
    newNode->data = x;
    newNode->next = list;
    list = newNode;
    printf("%d is inserted at Beginning ", x);
}

//insertEnd
void insertBeg(){
    int x;
    printf("Enter No to be inserted");
    scanf("%d ",&x);

    struct Node *newNode = getNode(),*temp;
    newNode->data = x;
    newNode->next = NULL;
    temp = list;
    if(temp = NULL){
        list = newNode;
    } else {
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d is inserted at End ", x);
}

//insertLoc
void insertLoc(){
    int x,p;
    printf("Enter number & location to insert at location:-");
    scanf("%d%d",&x,&p);
    struct Node *newNode = getNode(),*temp; 
    newNode->data = x;
    temp = list;

    if(temp == NULL){
        newNode->next = temp;
        list = newNode;
    } else{
        for(int i = 1; i < p-1;i++){
            if(temp->next == NULL){
                break;
            } else{
                temp = temp->next;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
}

//deletebeg
void deleteBeg(){
    struct Node *temp;
    temp = list;
    if(temp == NULL){
        printf("List is empty");
    } else{
        list = temp->next;
        freeNode(temp);
    }
}

//deleteEnd
void deleteEnd(){
    struct Node *temp,*pre;

    if(temp == NULL){
        printf("List Is Empty");
    } else{
        while(temp->next != NULL){
            pre = temp;
            temp = temp->next;
        }
        pre->next = NULL;
        freeNode(temp);
    }
}

//deleteLoc
void deleteLoc(){
    struct Node *temp,*pre;

    if(temp == NULL){
        printf("List Is Empty");
    } else{
        int p;
        printf("Enter location which you want to delete");
        scanf("%d",&p);
        if(p == 1){
            list = temp->next;
            freeNode(temp);
        } else{
            for(int i = 1 ; i< p;i++){
                if(temp->next ==NULL){
                    break;
                } else{
                    pre = temp;
                    temp = temp->next;
                }
            }
            if(temp->next != NULL){
                pre->next= temp->next;
                freeNode(temp);
            }
        }
    }
}
//display
void printList(){
    struct Node *temp;
    temp = list;
    if(temp==NULL){
        printf("List is Empty");
    } else{
        while(temp != NULL){
            printf("%d",temp->data);
            temp = temp->next;
        }
    }
}
//search
void search(){
    struct Node *temp = list;
    int n , i = 1;
    if(temp == NULL){
        printf("List is Empty");
    } else{
        printf("Enter a number to search");
        scanf("%d",&n); 
        while(temp!= NULL){
            if(temp->data == n){
                printf("%d is a element of linked list and it's position is %d",n,i);
                break;
            }
            i++;
            temp = temp->next;
        }
    }
}


void count(){
    struct Node *temp = list;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
}
// Reverse the linked list
void reverse() {
    struct Node *temp,*prev,*next;
    temp = list;
    prev = NULL;
    next = NULL;

    while(temp!= NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    list = prev;
}



//main
void main()
{
/*start of infinite while loop*/
while(1)
{
int c;
printf("\n/*Linked list Operations*/\n");
printf("1. insert a element at beginning\n");
printf("2. insert a element at end\n");
printf("3. insert a element at a given location\n");
printf("4. delete a element at beginning\n");
printf("5. delete a element at end\n");
printf("6. delete a element a given location\n");
printf("7. display the elements of linked list\n");
printf("8. search a element in linked list\n");
printf("9. Exit\n\n");
printf("Enter your choice");
scanf(" %d",&c);

/*Start of Switch case*/
switch(c)
{
case 1: insertbeg();printf("\n");break;
case 2: insertend();printf("\n");break;
case 3: insertloc();printf("\n");break;
case 4: deletebeg();printf("\n");break;
case 5: deleteend();printf("\n");break;
case 6: deleteloc();printf("\n");break;
case 7: display();printf("\n");break;
case 8: search();printf("\n");break;
case 9: exit(1);break;
}
/*End of switch case*/
}
/*End of infinite while loop*/
}