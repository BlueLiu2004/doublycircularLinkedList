#include "main.h"

int main()
{
    // create a NULL head node for linked list
    Node *head = NULL;
    size_t LIST_LENGTH = 0;

    // random number generator seed
    srand(time(NULL));
    
    printf("Input the length that you want: ");
    scanf("%u", &LIST_LENGTH);
    fflush(stdin);

    // create nodes by random number
    for (uint32_t i = 0; i < LIST_LENGTH; i++)
    {
        addNode(&head, rand());
    }

    // if want to print linked list from tail, edit second argument to 1 (or any not zero integer)
    printList(head, 0);

    // free the linked list to avoid memory leak
    freeList(&head);
    return EXIT_SUCCESS;
}