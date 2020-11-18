#include <stdio.h>
#include <stdlib.h>

struct SinglyListNode
{
    int data;
    struct SinglyListNode *next;
};

// In order to add a node in the list we need the address of
// the previous node, after where we want to add the new one.
// Note: This function return the SinglyListNode Pointer created after the previous one
struct SinglyListNode *insertNode(struct SinglyListNode *prevNode, int newItem)
{
    if (prevNode == NULL)
        return NULL;

    struct SinglyListNode *newNode = (struct SinglyListNode *)malloc(sizeof(struct SinglyListNode));
    // Assign newNode's next pointer value to the previous pointer's next pointer.
    newNode->next = prevNode->next;
    // Assign previousNode's next pointer value to the new one.
    prevNode->next = newNode;
    // Assign the newNode data as the newItem
    newNode->data = newItem;

    return newNode;
}

// In order to delete a node in the list we need the
// address of the previous node and the current node.
void deleteNode(struct SinglyListNode *prevNode, struct SinglyListNode *currentNode)
{
    if (prevNode == NULL || currentNode == NULL)
        return;

    prevNode->next = currentNode->next;
}

int main()
{
    // Create a head node with NULL pointer;
    struct SinglyListNode *headNode = NULL,
                          *secondNode = NULL,
                          *thirdNode = NULL;

    headNode = (struct SinglyListNode *)malloc(sizeof(struct SinglyListNode));
    secondNode = (struct SinglyListNode *)malloc(sizeof(struct SinglyListNode));
    thirdNode = (struct SinglyListNode *)malloc(sizeof(struct SinglyListNode));

    headNode->data = 1;
    headNode->next = secondNode;
    secondNode->data = 2;
    secondNode = thirdNode;
    thirdNode->data = 3;
    thirdNode->next = NULL;
}