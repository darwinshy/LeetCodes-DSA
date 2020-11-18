// https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1209/

// Description : Given a singly linked list, determine if it is a palindrome.

// Code : Build the Stack so that we can reverse to start of
// the list check one by one  for equality.

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
    bool isPalindrome(ListNode *head)
    {

        ListNode *traversalNode = head,
                 *dummyHead = head;
        stack<int> valueStack;

        while (traversalNode != NULL)
        {
            valueStack.push(traversalNode->val);
            traversalNode = traversalNode->next;
        }

        while (dummyHead != NULL)
        {
            if (dummyHead->val != valueStack.top())
            {
                return false;
            }
            valueStack.pop();
            dummyHead = dummyHead->next;
        }
        return true;
    }
};