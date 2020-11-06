#include <stdlib.h>
class MyLinkedList
{
private:
    struct LNode
    {
        int data;
        LNode *nextNodePointer;
        LNode(int inputData) : data(inputData), nextNodePointer(NULL){};
    };
    int size;
    LNode *headNode;

public:
    /** Initialize your data structure here. */

    MyLinkedList()
    {
        size = 0;
        headNode = NULL;
    }

    int get(int index)
    {
        if (index >= size)
            return -1;
        LNode *tempNodeForTraversal = headNode;
        for (int i = 0; i < index; i++)
        {
            tempNodeForTraversal = tempNodeForTraversal->nextNodePointer;
        }
        return tempNodeForTraversal->data;
    }

    void addAtHead(int data)
    {

        LNode *newNode = new LNode(data);
        newNode->nextNodePointer = headNode;
        headNode = newNode;
        size++;
    }

    void addAtTail(int data)
    {
        if (size == 0)
        {
            addAtHead(data);
            return;
        }
        else
        {
            LNode *tempNodeForTraversal = headNode;
            LNode *newNode = new LNode(data);
            while (tempNodeForTraversal->nextNodePointer != NULL)
                tempNodeForTraversal = tempNodeForTraversal->nextNodePointer;
            tempNodeForTraversal->nextNodePointer = newNode;
            size++;
            return;
        }
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        else
        {
            LNode *newNode = new LNode(val);
            LNode *tempNodeForTraversal = headNode;

            for (int i = 0; i < index - 1; i++)
            {
                tempNodeForTraversal = tempNodeForTraversal->nextNodePointer;
            }

            newNode->nextNodePointer = tempNodeForTraversal->nextNodePointer;
            tempNodeForTraversal->nextNodePointer = newNode;
            size++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;
        if (index == 0)
        {
            headNode = headNode->nextNodePointer;
            size--;
            return;
        }
        else
        {
            LNode *tempNodeForTraversal = headNode;
            for (int i = 0; i < index - 1; i++)
            {
                tempNodeForTraversal = tempNodeForTraversal->nextNodePointer;
            }

            tempNodeForTraversal->nextNodePointer = tempNodeForTraversal->nextNodePointer->nextNodePointer;
            size--;
            return;
        }
    }
};
