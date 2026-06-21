#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

// Definition for a binary tree node.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

class Solution
{
public:
    static long long kthLargestLevelSum(TreeNode *&root, const int &k)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        long long levelSum{}, levelSize{};
        std::vector<long long> levelSums;
        std::queue<TreeNode *> levelNodes;

        levelSums.push_back(root->val);
        if (root->left)
            levelNodes.push(root->left);
        if (root->right)
            levelNodes.push(root->right);
        levelSize = levelNodes.size();

        while (levelSize)
        {
            levelSum = 0;
            while (levelSize--)
            {
                levelSum += levelNodes.front()->val;
                if (levelNodes.front()->left)
                    levelNodes.push(levelNodes.front()->left);
                if (levelNodes.front()->right)
                    levelNodes.push(levelNodes.front()->right);
                levelNodes.pop();
            }
            levelSums.push_back(levelSum);
            levelSize = levelNodes.size();
        }

        if (k > levelSums.size())
            return -1;

        std::sort(levelSums.rbegin(), levelSums.rend());
        return levelSums[k - 1];
    }
};
