#include <iostream>
#include <vector>
#include <algorithm>

// Definition for a Node.
class Node
{
public:
    int val;
    std::vector<Node *> children;

    Node() : val(0) {}
    Node(int _val) : val(_val) {}
    Node(int _val, std::vector<Node *> _children) : val(_val), children(_children) {}
};

class Solution
{
public:
    int maxDepth(const Node *root)
    {
        if (root == nullptr)
            return 0;
        else
        {
            int maxDepthOfTree = 0;
            for (auto &&child : root->children)
                maxDepthOfTree = std::max(maxDepthOfTree, maxDepth(child));
            return 1 + maxDepthOfTree;
        }
    }
};

auto init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
};
