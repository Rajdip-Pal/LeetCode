#include <cstdlib>
#include <cstring>
#include <vector>

using ::std::vector;

class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val,
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

/*
    CODE START
*/

class Solution
{

public:
    Node *cloneGraph(Node *node)
    {
        std::vector<const Node *> visited(101, nullptr);

        auto recursive_clone = [&](auto &&self, Node *node) -> Node *
        {
            if (node)
            {
                Node *__node_outcome = new Node(node->val);
                visited[node->val] = __node_outcome;
                for (int i = 0; i < node->neighbors.size(); i++)
                    if (!visited[node->neighbors.at(i)->val])
                        __node_outcome->neighbors.push_back(self(self, node->neighbors.at(i)));
                    else
                        __node_outcome->neighbors.push_back((Node *)visited[node->neighbors.at(i)->val]);
                return __node_outcome;
            }
            else
                return nullptr;
        };

        return recursive_clone(recursive_clone, node);
    }
};

/*
    CODE END
*/
