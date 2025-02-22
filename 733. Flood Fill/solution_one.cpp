#include <queue>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> floodFill(const std::vector<std::vector<int>> &image, const int &sr, const int &sc, const int &color)
    {
        if (image[sr][sc] != color)
        {
            std::vector<std::vector<bool>> visited(image.size(), std::vector<bool>(image.front().size(), false));
            std::vector<std::vector<int>> result(image.size(), std::vector<int>(image.front().size(), false));

            int dx[] = {0, 1, 0, -1},
                dy[] = {1, 0, -1, 0};

            std::queue<std::pair<int, int>> pixels;
            visited[sr][sc] = true;
            pixels.push({sr, sc});

            auto validate = [&](const int &nx, const int &ny) -> bool
            {
                return nx >= 0 and nx < image.size() and ny >= 0 and ny < image.front().size() and !visited[nx][ny] and image[nx][ny] == image[sr][sc];
            };

            while (!pixels.empty())
            {
                // Altough the leveling is not required still we used it;
                int level = pixels.size();
                for (int i = 0; i < level; ++i)
                {
                    auto &&[x, y] = pixels.front();
                    for (int i = 0; i < 4; i++)
                    {
                        auto &&[nx, ny] = std::pair{x + dx[i], y + dy[i]};
                        if (validate(nx, ny))
                        {
                            visited[nx][ny] = true;
                            pixels.push({nx, ny});
                        }
                    }
                    result[x][y] = color;
                    pixels.pop();
                }
            }

            for (int i = 0; i < image.size(); i++)
                for (int j = 0; j < image.front().size(); j++)
                    if (!visited[i][j])
                        result[i][j] = image[i][j];

            return result;
        }
        else
            return std::vector<std::vector<int>>(image.begin(), image.end());
    }
};
