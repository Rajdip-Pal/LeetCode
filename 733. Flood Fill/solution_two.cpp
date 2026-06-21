#include <queue>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image, const int &sr, const int &sc, const int &color)
    {
        if (image[sr][sc] != color)
        {
            int previous_colour = image[sr][sc];
            std::vector<std::vector<bool>> visited(image.size(), std::vector<bool>(image.front().size(), false));

            int dx[] = {0, 1, 0, -1},
                dy[] = {1, 0, -1, 0};

            std::queue<std::pair<int, int>> pixels;
            visited[sr][sc] = true;
            pixels.push({sr, sc});

            auto validate = [&](const int &nx, const int &ny) -> bool
            {
                return nx >= 0 and nx < image.size() and
                       ny >= 0 and ny < image.front().size() and
                       !visited[nx][ny] and
                       image[nx][ny] == previous_colour;
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
                    image[x][y] = color;
                    pixels.pop();
                }
            }
        }

        return image;
    }
};
