// https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1207/

// Description
// Remove all elements from a linked
// list of integers that have value val.

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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *tempNodeForTraveral = head, *prevNode = NULL;

        while (tempNodeForTraveral != NULL)
        {

            if (tempNodeForTraveral->val == val)
            {
                if (tempNodeForTraveral == head)
                    head = tempNodeForTraveral->next;
                else
                    prevNode->next = tempNodeForTraveral->next;
            }
            else
                prevNode = tempNodeForTraveral;

            tempNodeForTraveral = tempNodeForTraveral->next;
        }

        return head;
    }
};