// https://leetcode.com/problems/odd-even-linked-list/

// Description
// Given a singly linked list, group all odd nodes together
// followed by the even nodes. Please note here we are talking
// about the node number and not the value in the nodes.

// You should try to do it in place. The program should run in
// O(1) space complexity and O(nodes) time complexity.

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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *evenTraversalNode = head->next,
                 *oddTraversalNode = head,
                 *evenHeadNode = evenTraversalNode;

        while (evenTraversalNode != NULL && evenTraversalNode->next != NULL)
        {
            oddTraversalNode->next = evenTraversalNode->next;
            oddTraversalNode = oddTraversalNode->next;
            evenTraversalNode->next = oddTraversalNode->next;
            evenTraversalNode = evenTraversalNode->next;
        }

        oddTraversalNode->next = evenHeadNode;

        return head;
    }
};