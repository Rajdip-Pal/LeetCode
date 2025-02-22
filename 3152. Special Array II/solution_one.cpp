#include <iostream>
#include <ostream>
#include <vector>

using ::std::vector;

template <typename type>
std::ostream &operator<<(std::ostream &os, const std::vector<type> &temp)
{
    os << std::boolalpha << "[";
    for (int i = 0; i < temp.size() - 1; i++)
        os << temp.at(i) << ",";
    os << temp.at(temp.size() - 1) << "]";
    return os;
}

class Solution
{
public:
    vector<bool> isArraySpecial(const vector<int> &nums, const vector<vector<int>> &queries)
    {
        vector<bool> is_odd, result;
        vector<int> parities;

        is_odd.reserve(nums.size());
        parities.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++)
            is_odd.push_back(nums.at(i) bitand 1);

        parities.push_back(1);
        for (int i = 1; i < is_odd.size(); i++)
            (is_odd.at(i - 1) == is_odd.at(i)) ? parities.push_back(parities.at(i - 1))
                                               : parities.push_back(parities.at(i - 1) + 1);

        for (int i = 0; i < queries.size(); i++)
            result.push_back(
                parities.at(queries.at(i).back()) - parities.at(queries.at(i).front()) ==
                queries.at(i).back() - queries.at(i).front());

        return result;
    }
};
