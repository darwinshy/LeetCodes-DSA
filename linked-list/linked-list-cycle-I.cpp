// https://leetcode.com/problems/linked-list-cycle/solution/
// Description
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached
// again by continuously following the next pointer. Internally, pos is used to denote the index
// of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list.Otherwise, return false.

#include <stdlib.h>

// A Generic Node Structure
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {

        if (head == NULL)
            return false;

        ListNode *pointerOne = head,
                 *pointerTwo = head->next;

        while (pointerOne != pointerTwo)
        {

            if (pointerOne == NULL || pointerOne->next == NULL || pointerTwo == NULL || pointerTwo->next == NULL)
                return false;

            pointerOne = pointerOne->next;

            pointerTwo = pointerTwo->next->next;
        }
        return true;
    }
};