#include <iostream>

/**
 * Solution 993. Cousins in Binary Tree
 *
 * @Start
 */

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
    static void getLP(const TreeNode *root, const int &node_value, const int &level, std::pair<int, int> &result)
    {
        if (root)
        {
            if (root->val == node_value)
            {
                result = {level, INT32_MIN};
                return;
            }

            if ((root->left and root->left->val == node_value) or
                (root->right and root->right->val == node_value))
            {
                result = {level + 1, root->val};
                return;
            }

            getLP(root->left, node_value, level + 1, result);
            getLP(root->right, node_value, level + 1, result);
        }
    }

public:
    bool isCousins(TreeNode *root, const int &x, const int &y)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        std::pair<int, int> level_X, level_Y;
        getLP(root, x, 0, level_X);
        getLP(root, y, 0, level_Y);

        if ((level_X.first == level_Y.first) and (level_X.second != level_Y.second))
            return true;
        else
            return false;
    }
};

/**
 * @End
 */

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
