// https://leetcode.com/problems/intersection-of-two-linked-lists/
// Description
// Write a program to find the node at which the
// intersection of two singly linked lists begins.

// Hash Map Implementations

#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode *tempNodeForTraversalA = headA, *tempNodeForTraversalB = headB;
        map<ListNode *, int> hashA;

        while (tempNodeForTraversalA != NULL)
        {
            hashA.insert({tempNodeForTraversalA, 1});
            tempNodeForTraversalA = tempNodeForTraversalA->next;
        }

        while (tempNodeForTraversalB != NULL && hashA.find(tempNodeForTraversalB) == hashA.end())
            tempNodeForTraversalB = tempNodeForTraversalB->next;

        if (hashA.find(tempNodeForTraversalB) != hashA.end())
            return tempNodeForTraversalB;

        return NULL;
    }
};