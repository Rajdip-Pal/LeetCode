#include <cstdint>
#include <vector>

class Solution
{
    /**
     * N-pointers solution;
     * O(n*m) time complexity;
     */
public:
    int kthSmallest(const std::vector<std::vector<int>> &matrix, const int &k)
    {
        if (k < 1 || k > matrix.size() * matrix.front().size())
            return -1;

        std::vector<std::vector<int>::const_iterator> pointers(matrix.size());
        for (int i = 0; i < matrix.size(); i++)
            pointers.at(i) = matrix.at(i).cbegin();

        int element_count = 0;
        int current_minium = INT32_MAX;
        int current_minium_at_pointer = -1;

        while (element_count < k)
        {
            current_minium = INT32_MAX;
            current_minium_at_pointer = -1;

            for (int i = 0; i < matrix.size(); i++)
                if (pointers.at(i) != matrix.at(i).cend() && *pointers.at(i) < current_minium)
                    current_minium = *pointers.at(i), current_minium_at_pointer = i;

            if (current_minium_at_pointer == -1)
                break;

            element_count++;
            pointers.at(current_minium_at_pointer)++;
        }
        return element_count < k ? -1 : current_minium;
    }
};
