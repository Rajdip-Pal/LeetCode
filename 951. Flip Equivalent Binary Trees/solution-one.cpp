#include <iostream>

/**
 * Solution 951. Flip Equivalent Binary Trees
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
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        if (!root1 and !root2)
            return true;
        else if ((!root1 and root2) or (root1 and !root2))
            return false;
        else if (root1->val == root2->val)
        {
            if (!root1->left and !root1->right and !root2->left and !root2->right)
                return true;
            else if (root1->left and !root1->right and root2->left and !root2->right)
                if (root1->left->val == root2->left->val)
                    return flipEquiv(root1->left, root2->left);
                else
                    return false;
            else if (!root1->left and root1->right and !root2->left and root2->right)
                if (root1->right->val == root2->right->val)
                    return flipEquiv(root1->right, root2->right);
                else
                    return false;
            else if (root1->left and !root1->right and !root2->left and root2->right)
                if (root1->left->val == root2->right->val)
                    return flipEquiv(root1->left, root2->right);
                else
                    return false;
            else if (!root1->left and root1->right and root2->left and !root2->right)
                if (root1->right->val == root2->left->val)
                    return flipEquiv(root1->right, root2->left);
                else
                    return false;
            else if (root1->left and root1->right and root2->left and root2->right)
                if (root1->left->val == root2->left->val and root1->right->val == root2->right->val)
                    return flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right);
                else if (root1->left and root2->right and root1->left->val == root2->right->val)
                    return flipEquiv(root1->left, root2->right) and flipEquiv(root1->right, root2->left);
                else
                    return false;
            else
                return false;
        }
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
