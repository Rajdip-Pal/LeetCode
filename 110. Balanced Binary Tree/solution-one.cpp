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
    int height_of_balanced_tree(const TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        else
        {
            int left_height = height_of_balanced_tree(node->left);
            int right_height = height_of_balanced_tree(node->right);

            if (left_height == -1 or right_height == -1)
                return -1;

            if (std::abs(left_height - right_height) >= 2)
                return -1;

            return 1 + std::max(left_height, right_height);
        }
    }

public:
    bool isBalanced(TreeNode *root)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        if (root == nullptr)
            return true;

        return height_of_balanced_tree(root) != -1;
    }
};
