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
    int maxDepth(Node *root)
    {
        if (root == nullptr)
            return 0;
        else if (root->children.size() == 0)
            return 1;
        else
        {
            std::vector<int> heigths;
            for (int i = 0; i < root->children.size(); ++i)
                heigths.push_back(maxDepth(root->children.at(i)));
            return 1 + *std::max_element(heigths.begin(), heigths.end());
        }
    }
};
