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
    std::vector<long long> levelSums;
    long long tree_height{};

    static int find_tree_height(TreeNode *&root)
    {
        if (root == nullptr)
            return 0;
        else
            return 1 + std::max(find_tree_height(root->left), find_tree_height(root->right));
    }

    static void generateSums(TreeNode *&root, const int &index, std::vector<long long> &levelSums)
    {
        if (index >= levelSums.size() or root == nullptr)
            return;
        else
        {
            levelSums[index] += root->val;
            generateSums(root->left, index + 1, levelSums);
            generateSums(root->right, index + 1, levelSums);
        }
    }

public:
    long long kthLargestLevelSum(TreeNode *&root, const int &k)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        tree_height = find_tree_height(root);

        if (k > tree_height)
            return -1;

        levelSums.resize(tree_height);
        generateSums(root, 0, levelSums);

        std::sort(levelSums.rbegin(), levelSums.rend());
        return levelSums[k - 1];
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
