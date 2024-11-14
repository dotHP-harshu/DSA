#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value)
{
    // Make a new node using struct
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // set the given value to the node and give null to next because it is the last node
    newNode->data = value;
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

int search(int value)
{
    int position = 1;
    struct Node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->data == value)
        {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

void printList()
{
    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL");
}

int main()
{
    insert(2);
    insert(9);
    insert(4);
    insert(5);
    insert(67);
    insert(1);

    printList();
    printf("\n");

    int position = search(1);
    if (position != -1)
    {
        printf("Node found in position %d.\n", position);
    }
    else
    {
        printf("Node is noe found.\n");
    }
    return 0;
}