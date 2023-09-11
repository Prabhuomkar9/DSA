#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// User defined data type for a Node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new node with data set as `data` and next set as `NULL`
Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Checks if the linked list `head` is empty
int isEmpty(Node *head)
{
    if (head == NULL)
        return 1;
    return 0;
}

// Returns the length of linked list `head`
int len(Node *head)
{
    if (isEmpty(head))
        return 0;
    int count = 0;
    do
    {
        count++;
        head = head->next;
    } while (!isEmpty(head));
    return count;
}

// Function to display the linked list `head`
void display(Node *head)
{
    if (isEmpty(head))
    {
        printf("NULL\n");
        return;
    }
    do
    {
        printf("%d\n", head->data);
        head = head->next;
    } while (!isEmpty(head));
}

// Function that returns pointer to last node of linked list `head`
Node *lastNode(Node *head)
{
    if (isEmpty(head))
        return head;
    Node *last;
    do
    {
        last = head;
        head = head->next;
    } while (!isEmpty(head));
    return last;
}

// Function that returns nth node from linked list `head`
Node *nthNode(Node *head, int pos)
{
    if (pos == 0)
        return head;
    if (pos == -1 || pos >= len(head) - 1)
        return lastNode(head);
    do
    {
        head = head->next;
        pos--;
    } while (pos > 0);
    return head;
}

// Fucntion to insert `data` at the beginning of linked list `head`
void insertStart(Node **head, int data)
{
    Node *temp = newNode(data);
    if (!isEmpty(*head))
        temp->next = *head;
    *head = temp;
}

// Fucntion to insert `data` at the end of linked list `head`
void insertEnd(Node **head, int data)
{
    Node *last = lastNode(*head);
    if (isEmpty(last))
        return insertStart(head, data);
    Node *temp = newNode(data);
    last->next = temp;
}

// Function to insert data `data` at position `pos` in the linked list `head`
void insertAt(Node **head, int data, int pos)
{
    if (pos == 0)
        return insertStart(head, data);
    if (pos == -1 || pos >= len(*head))
        return insertEnd(head, data);
    Node *temp = newNode(data), *before, *after = *head;
    do
    {
        before = after;
        after = after->next;
        pos--;
    } while (pos > 0);
    temp->next = before->next;
    before->next = temp;
}

// Function to delete the first node of linked list `head`
int deleteStart(Node **head)
{
    if (isEmpty(*head))
        return INT_MIN;
    int data = (*head)->data;
    *head = (*head)->next;
    return data;
}

// Function to delete the last node in linked list `head`
int deleteEnd(Node **head)
{
    if (isEmpty(*head))
        return INT_MIN;
    if (isEmpty((*head)->next))
    {
        int data = (*head)->data;
        *head = NULL;
        return data;
    }
    Node *secondLast = nthNode(*head, len(*head) - 2);
    int data = secondLast->next->data;
    secondLast->next = NULL;
    return data;
}

// Fucntion to delete a node at `pos` in linked list `head`
int deleteAt(Node **head, int pos)
{
    if (pos == 0)
        return deleteStart(head);
    if (pos == -1 || pos >= len(*head) - 1)
        return deleteEnd(head);
    Node *before = nthNode(*head, pos - 1);
    int data = before->next->data;
    before->next = before->next->next;
    return data;
}
