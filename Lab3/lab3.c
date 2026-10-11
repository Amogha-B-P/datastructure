#include <stdio.h>
#include<stdlib.h>

#define MAX 3

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    int item;

    if(rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        printf("Enter the element: ");
        scanf("%d", &item);

        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = item;

        printf("Element inserted\n");
    }
}

void dequeue()
{
    int item;

    if(front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
    {
        item = queue[front];
        front++;

        printf("Deleted element: %d\n", item);

        if(front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void display()
{
    int i;

    if(front == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue elements are:\n");

        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);

        printf("\n");
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

    }

    return 0;
}
