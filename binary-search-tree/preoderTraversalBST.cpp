// https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/928/

// Definition : Given the root of a binary tree,
// return the preorder traversal of its nodes' values.

#include <stdlib.h>
#include <stack>
#include <bits/stdc++.h>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Iterative Method
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> valueArray;
        stack<TreeNode *> nodeStack;

        nodeStack.push(root);

        while (!nodeStack.empty())
        {
            TreeNode *current = nodeStack.top();
            nodeStack.pop();
            if (current != NULL)
            {
                valueArray.push_back(current->val);
                nodeStack.push(current->right);
                nodeStack.push(current->left);
            }
        }

        return valueArray;
    }
};

// Recursive Method
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> valueArray;
        if (root == NULL)
            return valueArray;

        traversal(root, valueArray);
        return valueArray;
    }

private:
    void traversal(TreeNode *root, vector<int> &val)
    {
        if (root == NULL)
            return;
        val.push_back(root->val);
        traversal(root->left, val);
        traversal(root->right, val);
    }
};

// Morris Traversal

class Solution
{

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> valueArray;

        TreeNode *traversalNode = root;

        while (traversalNode != NULL)
        {
            if (traversalNode->left)
            {
                /* Find the inorder predecessor of traversalNode */
                TreeNode *predecessor = traversalNode->left;
                while (predecessor->right != NULL && predecessor->right != traversalNode)
                    predecessor = predecessor->right;

                if (predecessor->right == NULL)
                {
                    predecessor->right = traversalNode;
                    valueArray.push_back(traversalNode->val);
                    traversalNode = traversalNode->left;
                }
                else
                {
                    predecessor->right = NULL;
                    traversalNode = traversalNode->right;
                }
            }
            else
            {
                valueArray.push_back(traversalNode->val);
                traversalNode = traversalNode->right;
            }
        }

        return valueArray;
    }
};