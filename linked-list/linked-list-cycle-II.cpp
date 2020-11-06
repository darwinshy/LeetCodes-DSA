// Description :
// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
// There is a cycle in a linked list if there is some node in the list that can be reached again
// by continuously following the next pointer. Internally, pos is used to denote the index of the
// node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        ListNode *tempNodeForTraversal = head,
                 *cycleStartNode;

        map<ListNode *, int> hashMap;

        while (tempNodeForTraversal->next != NULL && hashMap.find(tempNodeForTraversal) == hashMap.end())
        {
            hashMap.insert({tempNodeForTraversal, 1});
            tempNodeForTraversal = tempNodeForTraversal->next;
        }

        if (tempNodeForTraversal == NULL)
            return NULL;
        if (hashMap.find(tempNodeForTraversal) != hashMap.end())
            return tempNodeForTraversal;

        return NULL;
    }
};