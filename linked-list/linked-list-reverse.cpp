// https://leetcode.com/problems/reverse-linked-list/solution/
// Description
// Reverse a singly linked list.

#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *tempNodeForTraversal = head,
                 *prevNode = NULL,
                 *tempPointer = NULL;

        while (tempNodeForTraversal != NULL)
        {
            tempPointer = tempNodeForTraversal->next;
            tempNodeForTraversal->next = prevNode;
            prevNode = tempNodeForTraversal;
            tempNodeForTraversal = tempPointer;
        }

        return prevNode;
    }
};