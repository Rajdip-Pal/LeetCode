#include <vector>

class Solution {
public:
  bool searchMatrix(const std::vector<std::vector<int>> &matrix,
                    const int &target) {
    int leftRow = 0, rightRow = matrix.size() - 1, midRow;
    int leftCol = 0, rightCol = matrix[0].size() - 1, midCol;

    int resultRow{};

    while (leftRow <= rightRow) {
      midRow = leftRow + (rightRow - leftRow) / 2;
      if (matrix.at(midRow).front() <= target and
          target <= matrix.at(midRow).back()) {
        resultRow = midRow;
        break;
      } else if (matrix.at(midRow).front() > target) {
        rightRow = midRow - 1;
      } else {
        leftRow = midRow + 1;
      }
    }

    while (leftCol <= rightCol) {
      midCol = leftCol + (rightCol - leftCol) / 2;
      if (matrix.at(resultRow).at(midCol) == target) {
        return true;
      } else if (matrix.at(resultRow).at(midCol) < target) {
        leftCol = midCol + 1;
      } else {
        rightCol = midCol - 1;
      }
    }

    return false;
  }
};
