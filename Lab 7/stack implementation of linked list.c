#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;


void push(int value) {
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed onto the stack.\n", value);
}


void pop(void) {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    temp = top;
    top = top->next;

    printf("Popped element: %d\n", temp->data);
    free(temp);
}


void displayStack(void) {
    struct Node *temp = top;

    if (temp == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack (top to bottom): ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


void freeStack(void) {
    struct Node *temp;

    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

int main(void) {
    int choice, value;

    do {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                if (scanf("%d", &value) != 1) {
                    freeStack();
                    return 1;
                }
                push(value);
                break;

            case 2:
                pop();
                break;


            case 3:
                displayStack();
                break;

            case 4:
                printf("Exiting stack program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    freeStack();
    return 0;
}

