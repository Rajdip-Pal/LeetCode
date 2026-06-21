#include <iostream>
#include <queue>
#include <unordered_map>

/**
 * Solution 2641. Cousins in Binary Tree II
 *
 * @Start
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
    static void prepare_level_order_sum(const TreeNode *root, std::queue<const TreeNode *> &nodeQueue, std::vector<int> &result)
    {
        if (root)
        {
            int levelNodeCount{};
            size_t levelSum{};
            nodeQueue.push(root);
            levelNodeCount = nodeQueue.size();
            while (levelNodeCount)
            {
                for (int i = 0; i < levelNodeCount; i++)
                {
                    levelSum += nodeQueue.front()->val;
                    if (nodeQueue.front()->left)
                        nodeQueue.push(nodeQueue.front()->left);
                    if (nodeQueue.front()->right)
                        nodeQueue.push(nodeQueue.front()->right);
                    nodeQueue.pop();
                }
                result.push_back(levelSum);
                levelSum = 0, levelNodeCount = nodeQueue.size();
            }
        }
    }

    static void update_tree_from_parent(TreeNode *root, const int &level, const std::vector<int> &levelOrderSumMap)
    {
        if (root->left and root->right)
        {
            size_t value = levelOrderSumMap.at(level) - root->left->val - root->right->val;
            root->left->val = root->right->val = value;
            update_tree_from_parent(root->left, level + 1, levelOrderSumMap);
            update_tree_from_parent(root->right, level + 1, levelOrderSumMap);
        }
        else if (root->left)
        {
            root->left->val = levelOrderSumMap.at(level) - root->left->val;
            update_tree_from_parent(root->left, level + 1, levelOrderSumMap);
        }
        else if (root->right)
        {
            root->right->val = levelOrderSumMap.at(level) - root->right->val;
            update_tree_from_parent(root->right, level + 1, levelOrderSumMap);
        }
    }

    static void update_tree(TreeNode *root, const int &level, const std::vector<int> &levelOrderSumMap)
    {
        if (root)
        {
            root->val = 0;
            update_tree_from_parent(root, level + 1, levelOrderSumMap);
        }
    }

public:
    static TreeNode *replaceValueInTree(TreeNode *root)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        std::vector<int> levelOrderSumMap;
        std::queue<const TreeNode *> nodeQueue;
        prepare_level_order_sum(root, nodeQueue, levelOrderSumMap);
        update_tree(root, 0, levelOrderSumMap);

        return root;
    }
};

/**
 * @End
 */
