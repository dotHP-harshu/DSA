#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node *head = NULL; // Initially list is empty

void insert(int value)
{
    // Make a new node using struct
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // set the given value to the node and give null to next because it is the last node
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        // if the head is null or it is a empty list then update head to the newNode
        head = newNode;
    }
    else
    {
        // else make a tempory node that find the last node before the insertin
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        // start from head
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList()
{
    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d-> ", current->value);
        current = current->next;
    }
}

int main()
{
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    printList();
    return 0;
}