#include <stack>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        const ListNode *fast = head;
        const ListNode *slow = head;

        std::stack<int> s;

        while (fast && fast->next)
        {
            s.push(slow->val);

            fast = fast->next->next;
            slow = slow->next;
        }

        int ans = 0;
        while (!s.empty())
        {
            ans = std::max(ans, slow->val + s.top());
            s.pop();
            slow = slow->next;
        }

        return ans;
    }
};