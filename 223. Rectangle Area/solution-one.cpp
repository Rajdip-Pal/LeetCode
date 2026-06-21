#include <iostream>

/**
 * Solution 223. Rectangle Area
 *
 * @Start
 */

class Solution
{
    static int commonArea(const int &ax1, const int &ay1, const int &ax2, const int &ay2, const int &bx1, const int &by1, const int &bx2, const int &by2)
    {
        // Rectangle a between rectangle b
        if ((ax1 >= bx1 && ay1 >= by1) && (ax2 <= bx2 && ay2 <= by2))
            return std::abs((ax1 - ax2) * (ay1 - ay2));

        // Rectangle b between rectangle a
        if ((bx1 >= ax1 && by1 >= ay1) && (bx2 <= ax2 && by2 <= ay2))
            return std::abs((bx1 - bx2) * (by1 - by2));

        // No overlap
        if ((ax2 <= bx1) || (ax1 >= bx2) || (ay2 <= by1) || (ay1 >= by2))
            return 0;

        // Partial Overlap
        return std::abs((std::max(ax1, bx1) - std::min(ax2, bx2)) * (std::max(ay1, by1) - std::min(ay2, by2)));
    }

public:
    static int computeArea(const int &ax1, const int &ay1, const int &ax2, const int &ay2, const int &bx1, const int &by1, const int &bx2, const int &by2)
    {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);

        return std::abs((ax1 - ax2) * (ay1 - ay2)) + std::abs((bx1 - bx2) * (by1 - by2)) - commonArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    }
};

/**
 * @End
 */

int main(int argc, char const *argv[])
{
    return 0;
}
