#include <iostream>

/**
 * Solution 203. Remove Linked List Elements
 *
 * @Start
 */

/**
 * Definition for singly-linked list.
 */
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
    ListNode *removeElements(ListNode *head, int val)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        ListNode *dummy = new ListNode(-1, head);
        ListNode *dummyHead = dummy;

        while (dummy->next != nullptr)
        {
            if (dummy->next->val == val)
            {
                dummy->next = dummy->next->next;
                continue;
            }
            dummy = dummy->next;
        }
        return dummyHead->next;
    }
};

/**
 * @End
 */

int main(int argc, char const *argv[])
{
    return 0;
}
