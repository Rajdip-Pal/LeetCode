#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

/**
 * Solution 2. Add Two Numbers
 *
 * @start
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
    static std::vector<int> generateNumber(const ListNode *list)
    {
        std::vector<int> number;
        while (list != nullptr)
        {
            number.push_back(list->val);
            list = list->next;
        }
        std::reverse(number.begin(), number.end());
        return number;
    }

    static ListNode *makeList(const std::vector<int> &vec)
    {
        ListNode *headPtr, *tempPtr;
        headPtr = tempPtr = new ListNode(vec[0]);

        for (int i = 1; i < vec.size(); i++)
        {
            tempPtr->next = new ListNode(vec[i]);
            tempPtr = tempPtr->next;
        }

        return headPtr;
    }

public:
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);

        std::vector<int> number1 = generateNumber(l1),
                         number2 = generateNumber(l2),
                         result;

        int number1Length = number1.size(), number2Length = number2.size();

        int carry = 0, sum = 0;
        int diff = std::abs(number1Length - number2Length);
        if (number1Length >= number2Length)
            for (int i = 0; i < diff; i++)
                number2.insert(number2.begin(), 0);
        else
            for (int i = 0; i < diff; i++)
                number1.insert(number1.begin(), 0);

        for (int i = std::max(number1Length, number2Length) - 1; i >= 0; --i)
        {
            sum = number1[i] + number2[i] + carry;
            result.push_back(sum % 10);
            carry = sum / 10;
        }

        if (carry)
            result.push_back(carry);

        return makeList(result);
    }
};

/**
 * @end
 */
