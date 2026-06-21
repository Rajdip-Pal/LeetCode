#include <iostream>
#include <vector>
#include <queue>

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
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> result;
        std::queue<TreeNode *> nodes;

        if (root == nullptr)
            return std::vector<std::vector<int>>();
        else
        {
            int levelLength{};
            nodes.push(root);
            levelLength = nodes.size();

            while (levelLength)
            {
                result.push_back(std::vector<int>());
                for (int i = 0; i < levelLength; i++)
                {
                    result.back().push_back(nodes.front()->val);
                    if (nodes.front()->left)
                        nodes.push(nodes.front()->left);
                    if (nodes.front()->right)
                        nodes.push(nodes.front()->right);
                    nodes.pop();
                }
                levelLength = nodes.size();
            }
        }

        return result;
    }
};
