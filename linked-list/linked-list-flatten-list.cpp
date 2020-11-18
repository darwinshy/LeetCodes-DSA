// https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1228/

// Description : You are given two non-empty linked lists
// representing two non-negative integers. The digits are
// stored in reverse order, and each of their nodes contains
// a single digit. Add the two numbers and return the sum
// as a linked list.
// You may assume the two numbers do not contain any leading
// zero, except the number 0 itself.

#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (head == NULL)
            return head;
        Node *traversalNode = head;

        while (traversalNode != NULL)
        {
            if (traversalNode->child == NULL)
            {
                traversalNode = traversalNode->next;
                continue;
            }

            Node *childTraversalNode = traversalNode->child;

            while (childTraversalNode->next != NULL)
                childTraversalNode = childTraversalNode->next;

            childTraversalNode->next = traversalNode->next;

            if (traversalNode->next != NULL)
                traversalNode->next->prev = childTraversalNode;

            traversalNode->next = traversalNode->child;
            traversalNode->child->prev = traversalNode;
            traversalNode->child = NULL;

            traversalNode = traversalNode->next;
        }
        return head;
    }
};