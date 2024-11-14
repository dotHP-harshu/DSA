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

void delete(int position)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    struct Node *temp = head;
    if (position == 1)
    {
        head = temp->next; // Update head
        free(temp);
        return;
    }
    struct Node *prev_node = NULL;
    for (int i = 1; i < position && temp != NULL; i++)
    {
        prev_node = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("List is out of bounds.\n");
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
    delete (3);
    printList();
    return 0;
}