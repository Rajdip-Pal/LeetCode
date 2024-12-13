#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
            graph[prerequisites[i].back()].push_back(prerequisites[i].front());

        queue<int> nodes;
        vector<int> indegree(numCourses);

        for (int i = 0; i < numCourses; i++)
            for (int j = 0; j < graph[i].size(); j++)
                indegree[graph[i][j]]++;

        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                nodes.push(i);

        int count{}; // Instead of having a topo list we try to maintain the count;
        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();
            count++;
            for (int i = 0; i < graph[node].size(); i++)
            {
                indegree[graph[node][i]]--;
                if (indegree[graph[node][i]] == 0)
                    nodes.push(graph[node][i]);
            }
        }

        return count == numCourses;
    }
};
