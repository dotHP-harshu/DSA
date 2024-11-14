#include <stdio.h>
#include <stdlib.h>

// Creating a structure of a node that contains a integer value and a pointer of next node
struct Node
{
    int value;
    struct Node *next;
};

// traversing in a link list
void printlist(struct Node *node)
{
    struct Node *current = node;

    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
}

int main()
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->value = 4;
    head->next = second;

    second->value = 40;
    second->next = third;

    third->value = 7;
    third->next = fourth;

    fourth->value = 10;
    fourth->next = NULL;

    printlist(head);
    return 0;
}