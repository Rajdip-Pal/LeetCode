#include <array>
#include <string>

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
    int fetchNumber(const std::string &str, int &idx)
    {
        std::string number = "";
        while (idx < str.length() and str[idx] != '-')
            number += str[idx++];
        return std::atoi(number.c_str());
    }

    int fetchLevel(const std::string &str, int &idx)
    {
        int level{};
        while (idx < str.length() and str[idx] == '-')
            level++, idx++;
        return level;
    }

public:
    TreeNode *recoverFromPreorder(const std::string &traversal)
    {
        int index{};
        std::array<TreeNode *, 1000> parents;

        while (index < traversal.length())
        {
            int level = fetchLevel(traversal, index);
            int number = fetchNumber(traversal, index);

            parents[level] = new TreeNode(number);
            if (level > 0)
                parents[level - 1]->left == nullptr ? parents[level - 1]->left = parents[level] : parents[level - 1]->right = parents[level];
        }

        return parents.front();
    }
};
