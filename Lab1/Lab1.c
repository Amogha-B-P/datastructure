#include <stdio.h>
#include<stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int item;

    if(top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        printf("Enter the element: ");
        scanf("%d", &item);

        top++;
        stack[top] = item;

        printf("Element inserted\n");
    }
}

void pop()
{
    int item;

    if(top == -1)
        printf("Stack Underflow\n");
    else
    {
        item = stack[top];
        top--;

        printf("Deleted element: %d\n", item);
    }
}

void display()
{
    int i;

    if(top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements are:\n");

        for(i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice;

while(1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
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
