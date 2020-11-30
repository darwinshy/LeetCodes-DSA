// https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1229/

// Description : A linked list is given such that each node contains
// an additional random pointer which could point to any
// node in the list or null. Return a deep copy of the list.

#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *traversalNode = head,
             *originalNext;

        // Copying original nodes

        while (traversalNode != NULL)
        {
            originalNext = traversalNode->next;
            Node *copiedNode = new Node(traversalNode->val);
            traversalNode->next = copiedNode;
            copiedNode->next = originalNext;

            traversalNode = originalNext;
        }

        traversalNode = head;

        // Assiging Random Pointers to the copied nodes

        while (traversalNode != NULL)
        {
            if (traversalNode->random != NULL)
                traversalNode->next->random = traversalNode->random->next;

            traversalNode = traversalNode->next->next;
        }

        traversalNode = head;

        Node *copiedHead = new Node(0),
             *copiedHead = head->next,
             *copyTraversalNode = copiedHead,
             *tempNode;

        // Restoring the Original List

        while (copyTraversalNode->next != NULL)
        {
            traversalNode->next = traversalNode->next->next;
            traversalNode = traversalNode->next;

            copyTraversalNode->next = copyTraversalNode->next->next;
            copyTraversalNode = copyTraversalNode->next;
        }

        traversalNode->next = traversalNode->next->next;
        return copiedHead;
    }
};