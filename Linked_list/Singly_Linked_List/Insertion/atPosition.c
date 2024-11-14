#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void atEnd(int value)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// For stepwise algorithm see its text file
void insertAtPosition(int position, int value)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;

    if (position == 1)
    {
        new_node->next = head;
        head = new_node;
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < position; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        free(new_node);
    }
    else
    {
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void printList()
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
    atEnd(3);
    atEnd(4);
    atEnd(5);
    insertAtPosition(2, 10);
    printList();
    return 0;
}