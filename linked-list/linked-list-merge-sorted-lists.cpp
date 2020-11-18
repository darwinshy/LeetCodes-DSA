// https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1227/

// Description : Merge two sorted linked lists and return it
// as a new sorted list. The new list should be made by splicing
// together the nodes of the first two lists.

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *newList = new ListNode();
        ListNode *newNodeHead = newList;

        while (l1 != NULL || l2 != NULL)
        {
            if (l1->val > l2->val)
            {
                newList->next = l2;
                l2 = l2->next;
            }
            else
            {

                newList->next = l1;
                l1 = l1->next;
            }

            newList = newList->next;
        }

        newList->next = l1 ? l1 : l2;

        return newNodeHead->next;
    }
};