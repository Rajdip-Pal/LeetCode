#include <iostream>
#include <set>
#include <vector>

class Solution
{
public:
    int kthSmallest(const std::vector<std::vector<int>> &matrix, const int &k)
    {
        // For first element return first element;
        if (k == 1)
            return matrix[0][0];

        // Square Matrix n*n;
        int n = matrix.size();

        // For last element return last element;
        if (k == n * n)
            return matrix[n - 1][n - 1];

        // finding the element in which layer ...
        // assuming the element is in already the second layer...
        int total_element = 2 * n, layer = 1;
        while (k > total_element)
        {
            total_element += 2 * (n - layer) - 1;
            layer++;
        }

        // pushing all possible elements in set and find the smallest;
        std::multiset<int> elements_to_compare;
        elements_to_compare.insert(matrix[layer][layer]);
        for (int i = layer - 1; i < n; i++)
            elements_to_compare.insert(matrix[layer - 1][i]),
                elements_to_compare.insert(matrix[i][layer - 1]);

        auto it = elements_to_compare.rbegin();
        std::advance(it, (total_element - k));
        return *it;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::vector<std::vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    std::cout << "The " << k << "th smallest element in the matrix is: " << solution.kthSmallest(matrix, k) << std::endl;
    return 0;
}
