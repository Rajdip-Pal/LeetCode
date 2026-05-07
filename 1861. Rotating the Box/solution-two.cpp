#include <vector>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <queue>

class Solution
{
public:
    static std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>> &boxGrid)
    {
        static const char empty = '.', stone = '#', stationary = '*';

        const std::size_t m = boxGrid.size();
        const std::size_t n = m == 0 ? 0 : boxGrid[0].size();

        std::vector<std::vector<char>> ans(n, std::vector<char>(m));

        for (std::size_t k = 0; k < m; k++)
        {
            auto &row = boxGrid[k];
            int empty_pos = n - 1;

            for (int i = n - 1; i >= 0; i--)
            {
                if (row[i] == stationary)
                    empty_pos = i - 1;
                else if (row[i] == stone)
                    std::swap(row[i], row[empty_pos--]);
            }

            for (std::size_t i = 0; i < n; i++)
                ans[i][m - k - 1] = row[i];
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<std::vector<char>> boxGrid = {
        {'#', '#', '*', '.', '*', '.'},
        {'#', '#', '#', '*', '.', '.'},
        {'#', '#', '#', '.', '#', '.'}};

    const auto ans = Solution::rotateTheBox(boxGrid);

    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            std::cout << j << ' ';
        }
        std::cout << "\n";
    }

    return 0;
}
