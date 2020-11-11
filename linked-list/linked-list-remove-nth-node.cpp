// https://leetcode.com/problems/remove-nth-node-from-end-of-list/solution/
// Description
// Given the head of a linked list, remove the
// nth node from the end of the list and return
// its head.

// One-Pass Algorithm

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
            return NULL;

        ListNode *dummyNode = new ListNode(0, head);
        ListNode *pointerOne = dummyNode,
                 *pointerTwo = dummyNode;

        for (int i = 0; i <= n; i++)
        {
            if (pointerTwo != NULL)
                pointerTwo = pointerTwo->next;
            else
                return NULL;
        }

        while (pointerTwo != NULL)
        {
            pointerOne = pointerOne->next;
            pointerTwo = pointerTwo->next;
        }

        pointerOne->next = pointerOne->next->next;
        return dummyNode->next;
    }
};