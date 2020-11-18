// https://leetcode.com/problems/add-two-numbers/solution/

// Description: You are given two non-empty linked lists representing two
// non-negative integers. The digits are stored in reverse order,
// and each of their nodes contains a single digit. Add the two
// numbers and return the sum as a linked list.
// You may assume the two numbers do not contain
// any leading zero, except the number 0 itself.

#include <stdlib.h>
#include <stack>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *newListHead = new ListNode(0),
                 *dummyHead = newListHead,
                 *head1 = l1,
                 *head2 = l2;
        int carry = 0;

        while (head1 != NULL || head2 != NULL)
        {

            int x = (head1 != NULL) ? head1->val : 0;
            int y = (head2 != NULL) ? head2->val : 0;

            int nodeSum = carry + x + y;
            carry = nodeSum / 10;

            ListNode *newNode = new ListNode(nodeSum % 10);
            dummyHead->next = newNode;
            dummyHead = dummyHead->next;

            if (head1 != NULL)
                head1 = head1->next;
            if (head2 != NULL)
                head2 = head2->next;
        }

        if (carry > 0)
        {
            dummyHead->next = new ListNode(carry);
        }
        return newListHead->next;
    }
};