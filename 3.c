#include <stdio.h>
#include <stdlib.h>

// Definition of node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Start of doubly linked list
struct Node* head = NULL;

// Get a new node
struct Node* getNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeg() {
    int x;
    printf("Enter value to be inserted at the beginning: ");
    scanf("%d", &x);
    struct Node* newNode = getNode(x);
    
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at the beginning\n", x);
}

// Insert at the end
void insertAtEnd() {
    int x;
    printf("Enter value to be inserted at the end: ");
    scanf("%d", &x);
    struct Node* newNode = getNode(x);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at the end\n", x);
}

// Insert at a specific location
void insertAtLoc() {
    int x, pos, i = 1;
    printf("Enter value and position to insert: ");
    scanf("%d %d", &x, &pos);
    struct Node* newNode = getNode(x);
    struct Node* temp = head;

    if (pos == 1) {
        insertAtBeg();
        return;
    }

    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        printf("%d inserted at position %d\n", x, pos);
    }
}

// Delete at the beginning
void deleteAtBeg() {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        printf("Deleted element at beginning\n");
    }
}

// Delete at the end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->prev != NULL) {
            temp->prev->next = NULL;
        } else {
            head = NULL;
        }
        free(temp);
        printf("Deleted element at end\n");
    }
}

// Delete at a specific location
void deleteAtLoc() {
    int pos, i = 1;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    struct Node* temp = head;

    if (pos == 1) {
        deleteAtBeg();
        return;
    }

    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
    } else {
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        free(temp);
        printf("Deleted element at position %d\n", pos);
    }
}

// Display the list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
    } else {
        printf("Doubly Linked List: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Search for an element in the list
void search() {
    int x, pos = 1;
    printf("Enter value to search: ");
    scanf("%d", &x);
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == x) {
            printf("%d found at position %d\n", x, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d not found in the list\n", x);
}

// Count the elements in the list
void count() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total elements in the list: %d\n", count);
}

// Reverse the list
void reverse() {
    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }
    printf("List reversed\n");
}

// Main menu-driven function
void main() {
    int choice;
    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Location\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Location\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Count\n");
        printf("10. Reverse\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtBeg(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtLoc(); break;
            case 4: deleteAtBeg(); break;
            case 5: deleteAtEnd(); break;
            case 6: deleteAtLoc(); break;
            case 7: display(); break;
            case 8: search(); break;
            case 9: count(); break;
            case 10: reverse(); break;
            case 11: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
