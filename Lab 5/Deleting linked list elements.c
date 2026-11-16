#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to create the linked list by appending nodes at the end
void createList(struct Node **head, int n) {
    struct Node *newNode, *temp;
    int i, value;
    
    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        
        // Allocate memory for a new node
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        newNode->data = value;
        newNode->next = NULL;
        
        // If the list is empty
        if (*head == NULL) {
            *head = newNode;
        } else {
            // Traverse to the last node
            temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            // Link the new node at the end
            temp->next = newNode;
        }
    }
}

// Delete a node from the beginning
void deleteBeginning(struct Node **head) {
    struct Node *temp;
    if (*head == NULL) {
        printf("List is empty. Deletion not possible!\n");
        return;
    }
    temp = *head;
    *head = (*head)->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete a node from a specified position
void deletePosition(struct Node **head, int position) {
    struct Node *temp, *prev;
    int i;
    if (*head == NULL) {
        printf("List is empty. Deletion not possible!\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }
    // If the first node is to be deleted
    if (position == 1) {
        deleteBeginning(head);
        return;
    }
    temp = *head;
    prev = NULL;
    // Traverse to the specified position
    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete a node from the end
void deleteEnd(struct Node **head) {
    struct Node *temp, *prev;
    if (*head == NULL) {
        printf("List is empty. Deletion not possible!\n");
        return;
    }
    // If there is only one node
    if ((*head)->next == NULL) {
        temp = *head;
        *head = NULL;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }
    temp = *head;
    prev = NULL;
    // Traverse to the last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display the linked list
void display(struct Node *head) {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int n, choice, position;
    
    
    do {
        printf("\n\n1. Append to / Create Linked List");
        printf("\n2. Delete from Beginning");
        printf("\n3. Delete from Specified Position");
        printf("\n4. Delete from End");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the number of nodes to add: ");
                scanf("%d", &n);
                if (n > 0) {
                    createList(&head, n);
                }
                break;
            case 2:
                deleteBeginning(&head);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deletePosition(&head, position);
                break;
            case 4:
                deleteEnd(&head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6); // FIXED: Changed from 5 to 6 to break out cleanly on exit

    // Release any remaining nodes before program termination
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
