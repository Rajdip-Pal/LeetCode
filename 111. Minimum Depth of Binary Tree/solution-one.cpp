#include <iostream>

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
    void find_minimum_Depth(const TreeNode *node, const int &height, int &minHeight)
    {
        if (node)
        {
            if (node->left == nullptr and node->right == nullptr)
                minHeight = std::min(minHeight, height);

            find_minimum_Depth(node->left, height + 1, minHeight);
            find_minimum_Depth(node->right, height + 1, minHeight);
        }
    }

public:
    int minDepth(const TreeNode *root)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        if (root == nullptr)
            return 0;

        int minHeight{INT32_MAX};
        find_minimum_Depth(root, 1, minHeight);
        return minHeight;
    }
};
