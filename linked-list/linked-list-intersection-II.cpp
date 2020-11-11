// https://leetcode.com/problems/intersection-of-two-linked-lists/
// Description
// Write a program to find the node at which the
// intersection of two singly linked lists begins.

// Two Pointer Implementations

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

        ListNode *firstPointer = headA, *secondPointer = headB;

        while (firstPointer != secondPointer)
        {
            if (firstPointer == NULL)
                firstPointer = headB;
            else
                firstPointer = firstPointer->next;

            if (secondPointer == NULL)
                secondPointer = headA;
            else
                secondPointer = secondPointer->next;
        }
        if (firstPointer == secondPointer)
            return secondPointer;
        else
            return NULL;
    }
};