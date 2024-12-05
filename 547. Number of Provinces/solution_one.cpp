#include <vector>

using ::std::vector;

class Solution
{
    void dfs(vector<vector<int>> &graph, vector<bool> &list, const int &node)
    {
        list[node] = true;
        for (int i = 0; i < graph[node].size(); i++)
        {
            if (!list[graph[node][i]])
                dfs(graph, list, graph[node][i]);
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<bool> cities(isConnected.size(), false);
        int count = 0;
        for (int i = 0; i < isConnected.size(); ++i)
        {
            if (!cities.at(i))
            {
                dfs(isConnected, cities, i),
                    ++count;
            }
        }
        return count;
    }
};
