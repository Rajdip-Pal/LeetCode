#include <iostream>
#include <vector>
#include <unordered_map>

/**
 * Solution 2458. Height of Binary Tree After Subtree Removal Queries
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
    int maxHeight{};
    int heightAfterRemoval[100000];

    void left_to_right(const TreeNode *node, const int &height)
    {
        if (node)
        {
            heightAfterRemoval[node->val] = maxHeight;
            maxHeight = std::max(height, maxHeight);

            left_to_right(node->left, height + 1);
            left_to_right(node->right, height + 1);
        }
    }

    void right_to_left(const TreeNode *node, const int &height)
    {
        if (node)
        {
            heightAfterRemoval[node->val] = std::max(maxHeight, heightAfterRemoval[node->val]);
            maxHeight = std::max(height, maxHeight);

            right_to_left(node->right, height + 1);
            right_to_left(node->left, height + 1);
        }
    }

public:
    std::vector<int> treeQueries(const TreeNode *root, const std::vector<int> &queries)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        std::vector<int> result;

        result.reserve(queries.size());

        left_to_right(root, 0);
        maxHeight = 0;
        right_to_left(root, 0);

        for (int i = 0; i < queries.size(); i++)
            result.push_back(heightAfterRemoval[queries[i]]);

        return result;
    }
};

/**
 * @End
 */

int main(int argc, char const *argv[])
{

    return 0;
}
