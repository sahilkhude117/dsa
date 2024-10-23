#include<stdio.h>
#include<stdlib.h>

// Circular linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Pointer to start of the list
struct Node* list = NULL;

// Get a new node
struct Node* getNode() {
    return (struct Node*)malloc(sizeof(struct Node));
}

// Free a node
void freeNode(struct Node* p) {
    free(p);
}

// Insert at the beginning
void insertBeg() {
    int x;
    printf("Enter the number to be inserted: ");
    scanf("%d", &x);

    struct Node* newNode = getNode();
    newNode->data = x;

    if (list == NULL) {
        newNode->next = newNode; // First node points to itself
        list = newNode;
    } else {
        struct Node* temp = list;
        while (temp->next != list) {
            temp = temp->next;
        }
        newNode->next = list;
        temp->next = newNode;
        list = newNode;
    }
    printf("%d is inserted at the beginning.\n", x);
}

// Insert at the end
void insertEnd() {
    int x;
    printf("Enter the number to be inserted: ");
    scanf("%d", &x);

    struct Node* newNode = getNode();
    newNode->data = x;

    if (list == NULL) {
        newNode->next = newNode; // First node points to itself
        list = newNode;
    } else {
        struct Node* temp = list;
        while (temp->next != list) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = list;
    }
    printf("%d is inserted at the end.\n", x);
}

// Insert at a specific location
void insertLoc() {
    int x, p;
    printf("Enter the number and the location to insert: ");
    scanf("%d%d", &x, &p);

    struct Node* newNode = getNode();
    newNode->data = x;

    if (list == NULL) {
        newNode->next = newNode;
        list = newNode;
    } else {
        struct Node* temp = list;
        for (int i = 1; i < p - 1 && temp->next != list; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("%d is inserted at location %d.\n", x, p);
}

// Delete from the beginning
void deleteBeg() {
    if (list == NULL) {
        printf("List is empty.\n");
    } else if (list->next == list) { // Only one node
        freeNode(list);
        list = NULL;
        printf("First element deleted.\n");
    } else {
        struct Node* temp = list;
        struct Node* last = list;

        while (last->next != list) {
            last = last->next;
        }
        list = list->next;
        last->next = list;
        freeNode(temp);
        printf("First element deleted.\n");
    }
}

// Delete from the end
void deleteEnd() {
    if (list == NULL) {
        printf("List is empty.\n");
    } else if (list->next == list) { // Only one node
        freeNode(list);
        list = NULL;
        printf("Last element deleted.\n");
    } else {
        struct Node* temp = list;
        struct Node* pre;

        while (temp->next != list) {
            pre = temp;
            temp = temp->next;
        }
        pre->next = list;
        freeNode(temp);
        printf("Last element deleted.\n");
    }
}

// Delete from a specific location
void deleteLoc() {
    if (list == NULL) {
        printf("List is empty.\n");
    } else {
        int p;
        printf("Enter the location to delete: ");
        scanf("%d", &p);

        struct Node* temp = list;
        struct Node* pre;

        if (p == 1) {
            deleteBeg();
        } else {
            for (int i = 1; i < p && temp->next != list; i++) {
                pre = temp;
                temp = temp->next;
            }
            if (temp->next != list) {
                pre->next = temp->next;
                freeNode(temp);
                printf("Element at location %d deleted.\n", p);
            }
        }
    }
}

// Display the circular linked list
void display() {
    if (list == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = list;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != list);
        printf("HEAD\n");
    }
}

// Search for an element
void search() {
    if (list == NULL) {
        printf("List is empty.\n");
    } else {
        int x, i = 1;
        printf("Enter the number to search: ");
        scanf("%d", &x);

        struct Node* temp = list;
        do {
            if (temp->data == x) {
                printf("%d is found at position %d.\n", x, i);
                return;
            }
            i++;
            temp = temp->next;
        } while (temp != list);
        printf("%d is not found in the list.\n", x);
    }
}

// Count the number of nodes in the circular linked list
void count() {
    if (list == NULL) {
        printf("List is empty.\n");
    } else {
        int cnt = 0;
        struct Node* temp = list;
        do {
            cnt++;
            temp = temp->next;
        } while (temp != list);
        printf("There are %d nodes in the list.\n", cnt);
    }
}

// Reverse the circular linked list
void reverse() {
    if (list == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node *prev = NULL, *current = list, *next = NULL, *last = list;

        while (last->next != list) {
            last = last->next;
        }

        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != list);

        last->next = prev;
        list = prev;
        printf("List has been reversed.\n");
    }
}

// Main program
int main() {
    int c;

    while (1) {
        printf("\n/* Circular Linked List Operations */\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at a given location\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from a given location\n");
        printf("7. Display the list\n");
        printf("8. Search in the list\n");
        printf("9. Count nodes in the list\n");
        printf("10. Reverse the list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: insertLoc(); break;
            case 4: deleteBeg(); break;
            case 5: deleteEnd(); break;
            case 6: deleteLoc(); break;
            case 7: display(); break;
            case 8: search(); break;
            case 9: count(); break;
            case 10: reverse(); break;
            case 11: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
