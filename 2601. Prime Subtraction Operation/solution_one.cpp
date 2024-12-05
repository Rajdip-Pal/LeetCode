#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

class Solution
{
    static std::pair<bool, std::vector<int>> primes;

public:
    static void getPrimes(const int &n)
    {
        if (primes.first)
            return;

        primes.first = true;
        primes.second.clear();
        primes.second.reserve(n + 1);

        int range = std::sqrt(n);
        std::vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i <= range; ++i)
            if (isPrime.at(i))
                for (int j = i * i; j <= n; j += i)
                    isPrime.at(j) = false;

        for (int i = 2; i <= n; ++i)
            if (isPrime.at(i))
                primes.second.push_back(i);

        primes.second.shrink_to_fit();
    }

    static bool primeSubOperation(const std::vector<int> &nums)
    {
        if (nums.size() <= 1)
            return true;

        std::vector<int> increasing(nums.size());
        std::vector<int>::const_iterator it;
        increasing.back() = nums.back();

        for (int i = nums.size() - 2; i >= 0; i--)
            if (nums.at(i) >= increasing.at(i + 1))
            {
                it = std::upper_bound(primes.second.begin(), primes.second.end(), nums.at(i) - increasing.at(i + 1));

                if (it == primes.second.cend() or *it >= nums.at(i))
                    return false;

                increasing.at(i) = nums.at(i) - *it;
            }
            else
                increasing.at(i) = nums.at(i);

        return true;
    }
};

// Static member initialization
std::pair<bool, std::vector<int>> Solution::primes = {false, std::vector<int>()};

auto init = []()
{
    Solution::getPrimes(1000);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

int main(int argc, char const *argv[])
{
    std::vector<int> nums{4, 9, 6, 10};
    std::vector<int> nums2{5, 7, 11, 13};

    std::cout << std::boolalpha << Solution::primeSubOperation(nums) << " " << Solution::primeSubOperation(nums2);

    return 0;
}
