#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

/**
 * Solution 1233. Remove Sub-Folders from the Filesystem
 *
 * @Start
 */

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC optimize("-ffloat-store")

class Solution
{
    static bool isSubFolder(const std::string &path1, const std::string &path2)
    {
        if (path2.find(path1 + '/') == 0)
            return true;
        return false;
    }

public:
    static std::vector<std::string> removeSubfolders(std::vector<std::string> &folders)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        std::vector<std::string> ans;
        std::sort(folders.begin(), folders.end());

        ans.push_back(std::move(folders.front()));

        for (int i = 1; i < folders.size(); i++)
            if (!isSubFolder(ans.back(), folders[i]))
                ans.push_back(std::move(folders[i]));

        return ans;
    }
};

/**
 * @End
 */
