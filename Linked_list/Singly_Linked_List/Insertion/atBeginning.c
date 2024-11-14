#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};
struct Node *head = NULL;

void beginning(int value)
{
    // make a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->value = value; // set the given value to the value of new Node
    newNode->next = head;   // set the next to the head
    head = newNode;         // update the head to the new node
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

    beginning(5);
    beginning(6);
    beginning(3);

    printList();
    return 0;
}