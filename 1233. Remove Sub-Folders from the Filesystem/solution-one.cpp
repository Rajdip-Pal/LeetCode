#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * Solution 1233. Remove Sub-Folders from the Filesystem
 *
 * @Start
 */

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

        ans.push_back(folders.front());

        for (int i = 1; i < folders.size(); i++)
            if (isSubFolder(ans.back(), folders[i]))
                continue;
            else
                ans.push_back(folders[i]);

        return ans;
    }
};

/**
 * @End
 */

/**
 * Trying to get into solution ...
 *
 * after sorting folders will be arranged
 *
 * /a /a/b /a/c /a/d /a/b/e
 */

int main(int argc, char const *argv[])
{
    /**
     * A normal LeetCode test Case 💀💀 ...... 🗿🗿
     */


    return 0;
}