// https://leetcode.com/problems/binary-tree-inorder-traversal/

// Definition : Given the root of a binary tree,
// return the inorder traversal of its nodes' values.

#include <stdlib.h>
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
// Recursive / Trivial Solution
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> valueArray;
        recursiveTraversal(root, valueArray);
        return valueArray;
    }

    void recursiveTraversal(TreeNode *vRoot, vector<int> vArr)
    {
        if (vRoot != NULL)
        {
            if (vRoot->left != NULL)
                recursiveTraversal(vRoot->left, vArr);
            vArr.push_back(vRoot->val);
            if (vRoot->right != NULL)
                recursiveTraversal(vRoot->right, vArr);
        }
    }
};