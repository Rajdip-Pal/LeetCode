#include <iostream>
#include <unordered_map>

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
    static void prepare_level_map(const TreeNode *root, const int &level, std::unordered_map<int, int> &level_map)
    {
        if (root)
        {
            level_map[root->val] = level;
            prepare_level_map(root->left, level + 1, level_map);
            prepare_level_map(root->right, level + 1, level_map);
        }
    }

    static TreeNode *find_parent(TreeNode *root, const int &val)
    {
        if ((root == nullptr) or (root->val == val))
            return nullptr;
        else if ((root->left and root->left->val == val) or (root->right and root->right->val == val))
            return root;
        else
            return std::max(find_parent(root->left, val), find_parent(root->right, val));
    }

public:
    bool isCousins(TreeNode *root, const int &x, const int &y)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        if (root == nullptr)
            return false;
        else
        {
            int level_x{}, level_y{};
            std::unordered_map<int, int> level_map;
            prepare_level_map(root, 0, level_map);

            level_x = level_map[x];
            level_y = level_map[y];

            if ((level_x != level_y) or (level_x == -1) or (level_y == -1))
                return false;
            else
            {
                TreeNode *parent_x = find_parent(root, x);
                if (((parent_x->left and parent_x->left->val == x) and (parent_x->right and parent_x->right->val == y)) or
                    ((parent_x->left and parent_x->left->val == y) and (parent_x->right and parent_x->right->val == x)))
                    return false;
                else
                    return true;
            }
        }
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
