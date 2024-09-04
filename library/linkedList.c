#include "linkedList.h"

void addNode(Node **start, int value)
{
    // create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    // if start is a NULL list (first condition)
    if (*start == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        *start = newNode;
    }
    else
    {
        // go to the end of list
        Node *current = *start;
        while (current->next != *start)
        {
            current = current->next;
        }
        // make links for the previous member
        (*start)->prev = newNode;
        newNode->prev = current;
        // make links for the next member
        current->next = newNode;
        newNode->next = *start;
    }
}

void insertNode(Node **start, int valueAfterInsert, int value)
{
    // create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    // if *start is a NULL list (first condition)
    if (*start == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        *start = newNode;
    }
    else
    {
        // go to the target of list
        Node *current = *start;
        while (current->data != valueAfterInsert)
        {
            current = current->next;
            // if valueAfterInsert can't be found after search whole list, delete newNode
            if (current == *start)
            {
                printf("[%s] Error! valueAfterInsert: \"%d\" is NOT exist in this linked list, DO NOTHING.\n", __func__, valueAfterInsert);
                free(newNode);
                return;
            }
        }
        // make links for the previous member
        newNode->prev = current;
        current->next->prev = newNode;
        // make links for the next member
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteNode(Node **start, int value)
{
    // if *start is a NULL list
    if (*start == NULL)
    {
        printf("[%s] Error! *start: \"%p\" is a NULL linked list, DO NOTHING.\n", __func__, *start);
        return;
    }
    // if *start has only one node
    else if ((*start)->next == (*start) && (*start)->prev == *start)
    {
        *start = NULL;
    }
    else
    {
        // go to the target of list
        Node *current = *start;
        while (current->data != value)
        {
            current = current->next;
            // if the value of target can't be found after search whole list, exit this function
            if (current == *start)
            {
                printf("[%s] Error! value: \"%d\" is NOT exist in this linked list, DO NOTHING.\n", __func__, value);
                return;
            }
        }
        // make links for the previous member
        current->prev->next = current->next;
        // make links for the next member
        current->next->prev = current->prev;

        // if the node to be delete is the start node, update *start
        if (current == *start)
        {
            *start = current->next;
        }

        // delete the node
        free(current);
    }
}

void printList(const Node *start, int isInvert)
{
    // if start is a NULL list
    if (start == NULL)
    {
        printf("[%s] Error! start: \"%p\" is a NULL linked list, PRINT NOTHING.\n", __func__, (void *)start);
        return;
    }
    const Node *current = isInvert ? start->prev : start;
    unsigned int counter = 0;
    do
    {
        printf("[%02d] %d\n", counter, current->data);
        counter++;
        current = isInvert ? current->prev : current->next;
    } while (current != start);
}

void freeList(Node **start)
{
    // if start is a NULL list
    if (*start == NULL)
    {
        printf("[%s] Error! *start: \"%p\" is a NULL linked list, DO NOTHING.\n", __func__, (void *)*start);
        return;
    }
    else
    {
        Node *current = (*start)->next, *ready_to_delete;
        do
        {
            ready_to_delete = current;
            current = current->next;
            free(ready_to_delete);
        }while(current != *start);

        *start = NULL;
    }
}
