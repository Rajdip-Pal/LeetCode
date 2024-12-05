#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

/**
 * Leet Code Problem 1914. Cyclically Rotating a Grid
 *
 * @Start
 */

class Solution
{
public:
    static std::vector<std::vector<int>> rotateGrid(std::vector<std::vector<int>> &grid, const int k)
    {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);

        int temp_value {}, needed_rotation {};
        int rows = grid.size(), cols = grid[0].size();
        std::vector<std::vector<int>> layers;

        for (int x = 0; x < std::min(rows, cols) / 2; x++)
        {
            std::vector<int> tempLayer;
            for (int i = x; i < rows - x; i++)
                tempLayer.push_back(grid[i][x]);
            for (int i = x + 1; i < cols - x; i++)
                tempLayer.push_back(grid[rows - 1 - x][i]);
            for (int i = rows - 2 - x; i >= x; i--)
                tempLayer.push_back(grid[i][cols - 1 - x]);
            for (int i = cols - 2 - x; i > x; i--)
                tempLayer.push_back(grid[x][i]);
            layers.push_back(tempLayer);
        }

        for (auto &&x : layers)
        {
            needed_rotation = k % x.size();
            std::rotate(x.begin(), x.begin()+(x.size() - needed_rotation), x.end());
        }

        for (int x = 0; x < std::min(rows, cols) / 2; x++)
        {
            std::vector<int> tempLayer;
            for (int i = x; i < rows - x; i++)
                grid[i][x] = layers[x][0], layers[x].erase(layers[x].begin());
            for (int i = x + 1; i < cols - x; i++)
                grid[rows - 1 - x][i] = layers[x][0], layers[x].erase(layers[x].begin());
            for (int i = rows - 2 - x; i >= x; i--)
                grid[i][cols - 1 - x] = layers[x][0], layers[x].erase(layers[x].begin());
            for (int i = cols - 2 - x; i > x; i--)
                grid[x][i] = layers[x][0], layers[x].erase(layers[x].begin());
        }

        return grid;
    }
};

/**
 * @End
 */

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> example = {
     { 3970, 1906, 3608, 298, 3072, 3546, 1502, 773, 4388, 3115, 747, 3937 },
     { 2822, 304, 4179, 1780, 1709, 1058, 3645, 681, 2910, 2513, 4357, 1038 },
     { 4471, 2443, 218, 550, 2766, 4780, 1997, 1672, 4095, 161, 4645, 3838 },
     { 2035, 2350, 3653, 4127, 3208, 4717, 4347, 3452, 1601, 3725, 3060, 2270 },
     { 188, 2278, 81, 3454, 3204, 1897, 2862, 4381, 3704, 2587, 743, 3832 },
     { 996, 4499, 66, 2742, 1761, 1189, 608, 509, 2344, 3271, 3076, 108 },
     { 3274, 2042, 2157, 3226, 2938, 3766, 2610, 4510, 219, 1276, 3712, 4143 },
     { 744, 234, 2159, 4478, 4161, 4549, 4214, 4272, 701, 4376, 3110, 4896 },
     { 4431, 1011, 757, 2690, 83, 3546, 946, 1122, 2216, 3944, 2715, 2842 },
     { 898, 4087, 703, 4153, 3297, 2968, 3268, 4717, 1922, 2527, 3139, 1516 },
     { 1086, 1090, 302, 1273, 2292, 234, 3268, 2284, 4203, 3838, 2227, 3651 },
     { 2055, 4406, 2278, 3351, 3217, 2506, 4525, 233, 3829, 63, 4470, 3170 },
     { 3797, 3276, 1755, 1727, 1131, 4108, 3633, 1835, 1345, 1293, 2778, 2805 },
     { 1215, 84, 282, 2721, 2360, 2321, 1435, 2617, 1202, 2876, 3420, 3034 }
    };
    Solution::rotateGrid(example, 405548684);
    /**
     *  1  2  3  4
     *  5  6  7  8
     *  9 10 11 12
     * 13 14 15 16
     * 17 18 19 20
     * 21 22 23 24
     *
     */
    return 0;
}
