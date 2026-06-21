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
    static int prepare_left_right_tree_hegiht_hashmap(const TreeNode *root, std::unordered_map<int, int> &leftMap, std::unordered_map<int, int> &rightMap)
    {
        if (root)
        {
            int leftHeight = prepare_left_right_tree_hegiht_hashmap(root->left, leftMap, rightMap);
            int rightHeight = prepare_left_right_tree_hegiht_hashmap(root->right, leftMap, rightMap);

            leftMap[root->val] = leftHeight;
            rightMap[root->val] = rightHeight;

            return 1 + std::max(leftHeight, rightHeight);
        }
        return 0;
    }

    static void prepare_final_height_map(const TreeNode *root, const int &maxHeight, const int &depth, std::unordered_map<int, int> &hashMap, const std::unordered_map<int, int> &leftMap, const std::unordered_map<int, int> &rightMap)
    {
        if (root)
        {
            hashMap[root->val] = maxHeight;

            prepare_final_height_map(root->left, std::max(maxHeight, depth + rightMap.at(root->val)), depth + 1, hashMap, leftMap, rightMap);
            prepare_final_height_map(root->right, std::max(maxHeight, depth + leftMap.at(root->val)), depth + 1, hashMap, leftMap, rightMap);
        }
    }

public:
    static std::vector<int>
    treeQueries(const TreeNode *root, const std::vector<int> &queries)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        std::vector<int> result;
        std::unordered_map<int, int> leftHeight, rightHeight, heightMap;
        prepare_left_right_tree_hegiht_hashmap(root, leftHeight, rightHeight);
        prepare_final_height_map(root->left, rightHeight[root->val], 1, heightMap, leftHeight, rightHeight);
        prepare_final_height_map(root->right, leftHeight[root->val], 1, heightMap, leftHeight, rightHeight);

        result.reserve(queries.size());
        for (int i = 0; i < queries.size(); i++)
            result.push_back(heightMap[queries[i]]);

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
