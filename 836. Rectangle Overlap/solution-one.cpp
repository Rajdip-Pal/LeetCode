#include <iostream>
#include <vector>

/**
 * Solution 836. Rectangle Overlap
 *
 * @Start
 */

class Solution
{
public:
    bool isRectangleOverlap(const std::vector<int> &rec1, const std::vector<int> &rec2)
    {
        return !((rec1[2] <= rec2[0]) || (rec1[0] >= rec2[2]) || (rec1[3] <= rec2[1]) || (rec1[1] >= rec2[3]));
    }
};

/**
 * @End
 */

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
