#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 

int queue[SIZE];
int front = -1;
int rear = -1;


int isFull() {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
        return 1;
    }
    return 0;
}


int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}


void insert(int element) {
    if (isFull()) {
        printf("\nQueue Overflow! Cannot insert %d.\n", element);
        return;
    }

    
    if (front == -1) {
        front = rear = 0;
    }
    // Circular increment of rear
    else if (rear == SIZE - 1 && front != 0) {
        rear = 0;
    }
    else {
        rear++;
    }

    queue[rear] = element;
    printf("\nInserted %d into the queue.", element);
}


void delete() {
    if (isEmpty()) {
        printf("\nQueue Underflow! Nothing to delete.\n");
        return;
    }

    int deletedElement = queue[front];

    
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    
    else if (front == SIZE - 1) {
        front = 0;
    }
    else {
        front++;
    }

    printf("\nDeleted element: %d", deletedElement);
}


void display() {
    if (isEmpty()) {
        printf("\nQueue is Empty!");
        return;
    }

    printf("\nQueue elements are: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    else {
        for (int i = front; i < SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n\n*** CIRCULAR QUEUE MENU ***");
        printf("\n1. Insert (Enqueue)");
        printf("\n2. Delete (Dequeue)");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the integer to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}
