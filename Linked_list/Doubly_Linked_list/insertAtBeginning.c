#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void inserAtBeginning(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
}

int main()
{
    struct Node *head = NULL;
    inserAtBeginning(&head, 5);
    inserAtBeginning(&head, 10);
    inserAtBeginning(&head, 30);
    inserAtBeginning(&head, 2);
    printList(head);
    return 0;
}