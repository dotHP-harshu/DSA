#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value)
{
    // make a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->value = value; // set the given value to the value of new Node
    newNode->next = head;   // set the next to the head
    head = newNode;         // update the head to the new node
}

void delete(int value)
{
    struct Node *temp = head;
    struct Node *prev_node = NULL;

    // If head node holds the key
    if (temp != NULL && temp->value == value)
    {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->value != value)
    {
        prev_node = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node is not found.\n");
    }
    else
    {
        prev_node->next = temp->next;
        free(temp);
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
    printf("null\n");
}

int main()
{
    insert(9);
    insert(8);
    insert(7);
    insert(6);
    delete (6);
    printList();
    return 0;
}