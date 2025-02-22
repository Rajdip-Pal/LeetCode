// The API isBadVersion is defined for you.

extern bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(const int &n)
    {
        int firstVersion = 0, finalVersion = n, version;
        while (firstVersion <= finalVersion)
        {
            version = firstVersion + (finalVersion - firstVersion) / 2;
            if (isBadVersion(version))
                finalVersion = version - 1;
            else
                firstVersion = version + 1;
        }
        return firstVersion;
    }
};
