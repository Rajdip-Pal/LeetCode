#include <iostream>

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int maximumDepth{};

    void find_depth(const TreeNode *node, const int &depth, int &maxDepth)
    {
        if (node == nullptr)
            return;
        else
        {
            maxDepth = std::max(depth, maxDepth);
            find_depth(node->left, depth + 1, maxDepth);
            find_depth(node->right, depth + 1, maxDepth);
        }
    }

public:
    int maxDepth(const TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        else
        {
            maximumDepth = 0;
            find_depth(root, 1, maximumDepth);
            return maximumDepth;
        }
    }
};
