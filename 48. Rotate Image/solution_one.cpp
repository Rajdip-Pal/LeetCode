#include <algorithm>
#include <vector>

class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        // Inplace rotation;
        int side_length = matrix.size();
        std::vector<int> copy_vector(side_length), paste_vector(side_length);

        int left = 0, right = side_length - 1;
        int top = 0, bottom = side_length - 1;
        int i = 0;

        while (left < right and top < bottom)
        {
            // Copy top row
            for (i = left; i <= right; i++)
                copy_vector[i] = matrix[top][i];

            paste_vector = copy_vector;

            // Copy right column
            for (i = top + 1; i <= bottom; i++)
                copy_vector[i] = matrix[i][right];

            // Paste right column
            for (i = top; i <= bottom; i++)
                matrix[i][right] = paste_vector[i];

            paste_vector = copy_vector;
            std::reverse(paste_vector.begin(), paste_vector.end());

            // Copy bottom row
            for (i = right - 1; i >= left; i--)
                copy_vector[i] = matrix[bottom][i];

            // Paste bottom row
            for (i = right - 1; i >= left; i--)
                matrix[bottom][i] = paste_vector[i];

            paste_vector = copy_vector;

            // Copy left column
            for (i = bottom - 1; i > top; i--)
                copy_vector[i] = matrix[i][left];

            // Paste left column
            for (i = bottom - 1; i >= top; i--)
                matrix[i][left] = paste_vector[i];

            paste_vector = copy_vector;
            std::reverse(paste_vector.begin(), paste_vector.end());

            // Paste top row
            for (i = left + 1; i < right; i++)
                matrix[top][i] = paste_vector[i];

            top++, bottom--;
            left++, right--;
        }
    }
};
