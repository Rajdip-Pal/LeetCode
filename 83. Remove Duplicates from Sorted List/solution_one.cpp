
//  Definition for singly-linked list.

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        int curr_val;
        ListNode *result = head;

        while (head and head->next)
        {
            curr_val = head->val;
            curr_val == head->next->val ? head->next = head->next->next
                                        : head = head->next;
        }

        return result;
    }
};
