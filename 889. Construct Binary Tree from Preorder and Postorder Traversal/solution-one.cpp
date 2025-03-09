#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// [ 1, 2, 4, 5, 3, 6, 7 ]
// [ 4, 5, 2, 6, 7, 3, 1 ]

class Solution
{
    static TreeNode *formTree(const std::vector<int> &preorder, int preStart, int preEnd, const std::vector<int> &postorder, int postStart, int postEnd)
    {
        if (preStart >= preEnd and postStart >= postEnd)
            return new TreeNode(preorder[preStart]);
        else
        {
            int leftPreStart = preStart + 1, leftPreEnd, rightPreStart, rightPreEnd, leftPostStart, leftPostEnd, nextPostStart, nextPostEnd = postEnd - 1;

            leftPreEnd = leftPreStart;
            while (preorder[leftPreEnd] != postorder[nextPostEnd])
                leftPreEnd++;

            rightPreStart = leftPreEnd + 1;
            rightPreEnd =

                nextPostStart = nextPostEnd;
            while (preorder[preStart] != postorder[nextPostStart])
                nextPostStart--;

            TreeNode *left = nullptr, *right = nullptr;
            return new TreeNode(preorder[preStart], left, right);
        }
    }

public:
    TreeNode *constructFromPrePost(const std::vector<int> &preorder, const std::vector<int> &postorder)
    {
        int val{};
        TreeNode *left = new TreeNode();
        TreeNode *right = new TreeNode();

        return new TreeNode(val, left, right);
    }
};
