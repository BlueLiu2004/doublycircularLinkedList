#include "main.h"

int main()
{
    Node *head = NULL;
    srand(time(NULL));
    for (int i = 0; i < 20; i++)
    {
        addNode(&head, rand());
    }

    printList(head, 0);
    return EXIT_SUCCESS;
}