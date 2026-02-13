import time
from typing import List
from collections import Counter


class Solution:
    def longestBalanced(self, s: str) -> int:
        N = len(s)
        max_len = 0

        for i in range(N):
            counts = Counter()

            if max_len > N-i:
                break

            for j in range(i, N):
                counts[s[j]] += 1
                counts_set = set(counts.values())

                counts_set.add(0)
                counts_set.remove(0)

                if (len(counts_set) == 1):
                    max_len = max(max_len, j-i+1)

        return max_len


ans = Solution()
testcases = [
    "aabbab", "abc", "aabbcc", "aabc", "caacbbbbcaabbcbcbacccbacbbabbaaaccaaccacacccbbacababababccabbcccaccababbcbcacbcaabaaabcacaacbbaabbbbacccabbccccaaaabccaaaacaccaaaaccbccccaccbbccabccaaabbbcccbbbcccabccacbbaccabacbccbbabcbcabcacaccbccabbcaaccababccaacaacbbabaabaaacabacccababaccbcabbcabacccbbccbcbbbbaccaabaacccaaaccbcbacbaabaccccaaaabcbacacbcbcabbaacabbbcbabccabbbbaacbcbaaabbbccccccabbbacbaaabbacbbcabcccabcbcbbcaccbccbcbaabaababbbccaabbbacccccccacabcbbabbcbbbcabbabbcbcbaabaaabcaccaacaababbaccbbbababbbaaaaacccbabbcabacaccccaaaabbacacbbccacabbbbbababcccaabccbbccabbbacbacbcbbcaaaacccbcbaaccccababcbcbcaabcacaabcbbcbbccbbabcabacacbbbacbabaacaccabbacbbcbbbbcccaaacbbcacbcabbaabccaabcaaccccaaaaaacbbccbccabbcbbbcabccbaaaabbaacbacbacccbcbcaaaaababbaacccbbcbcbcbbbbbccbbaaabcabbaacbbbcabbcacabbbacbababaacaccaabababcbacacbccbbcacacbbcaacbccbbcaaacabbbbbcacabcbbacabbacbcacbbacbbcabbaaacbacbcbcacccabbabbcbcababbabccbcbcbaabccbcbabacacabcbbacabcab"]

total_time = time.perf_counter_ns()

for i in testcases:
    ans.longestBalanced(i)

print("Total Runtime : ", (time.perf_counter_ns() - total_time)/1e6, " ms")
