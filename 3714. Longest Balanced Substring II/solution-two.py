import time
from typing import List
from collections import Counter


class Solution:
    def longestBalanced(self, s: str) -> int:
        N = len(s)

        # Case 1 ( Single Char )
        max_case_1 = 0
        curr_substr_len = 1
        for i in range(1, N):
            if s[i] != s[i-1]:
                max_case_1 = max(max_case_1, curr_substr_len)
                curr_substr_len = 1
            else:
                curr_substr_len += 1
        max_case_1 = max(max_case_1, curr_substr_len)

        # Case 2 ( Double Char )

        def helper(ch1: bytes, ch2: bytes) -> int:
            local_max_len = 0
            mp_double = {}
            state = 0

            mp_double[0] = -1
            for i in range(N):
                if s[i] == ch1:
                    state += 1
                elif s[i] == ch2:
                    state -= 1
                else:
                    mp_double = {}
                    mp_double[0] = i
                    state = 0
                    continue

                if state not in mp_double:
                    mp_double[state] = i
                else:
                    local_max_len = max(
                        local_max_len, i - mp_double[state])

            return local_max_len

        max_case_2 = 0
        max_case_2 = max(max_case_2, helper('a', 'b'))
        max_case_2 = max(max_case_2, helper('b', 'c'))
        max_case_2 = max(max_case_2, helper('a', 'c'))

        # Case 3 ( All chars )

        max_case_3 = 0
        mp_tripple = Counter()
        mp_tripple[(0, 0)] = -1

        count_a, count_b, count_c = 0, 0, 0

        for i, ch in enumerate(s):
            if ch == 'a':
                count_a += 1
            elif ch == 'b':
                count_b += 1
            else:
                count_c += 1

            state = (count_a-count_b, count_c-count_b)
            if state not in mp_tripple:
                mp_tripple[state] = i
            else:
                max_case_3 = max(max_case_3, i-mp_tripple[state])

        return max(max_case_1, max_case_2, max_case_3)


def abc(s: str):
    count = [0, 0, 0]
    for ch in s:
        if ch == 'a':
            count[0] += 1
        elif ch == 'b':
            count[1] += 1
        else:
            count[2] += 1

    return count


ans = Solution()
testcases = ["a", "aa", "bbbcbaaababaaab", "aabbab", "abc", "aaabbbcc", "aabc", "ccbbcc", "caacbbbbcaabbcbcbacccbacbbabbaaaccaaccacacccbbacababababccabbcccaccababbcbcacbcaabaaabcacaacbbaabbbbacccabbccccaaaabccaaaacaccaaaaccbccccaccbbccabccaaabbbcccbbbcccabccacbbaccabacbccbbabcbcabcacaccbccabbcaaccababccaacaacbbabaabaaacabacccababaccbcabbcabacccbbccbcbbbbaccaabaacccaaaccbcbacbaabaccccaaaabcbacacbcbcabbaacabbbcbabccabbbbaacbcbaaabbbccccccabbbacbaaabbacbbcabcccabcbcbbcaccbccbcbaabaababbbccaabbbacccccccacabcbbabbcbbbcabbabbcbcbaabaaabcaccaacaababbaccbbbababbbaaaaacccbabbcabacaccccaaaabbacacbbccacabbbbbababcccaabccbbccabbbacbacbcbbcaaaacccbcbaaccccababcbcbcaabcacaabcbbcbbccbbabcabacacbbbacbabaacaccabbacbbcbbbbcccaaacbbcacbcabbaabccaabcaaccccaaaaaacbbccbccabbcbbbcabccbaaaabbaacbacbacccbcbcaaaaababbaacccbbcbcbcbbbbbccbbaaabcabbaacbbbcabbcacabbbacbababaacaccaabababcbacacbccbbcacacbbcaacbccbbcaaacabbbbbcacabcbbacabbacbcacbbacbbcabbaaacbacbcbcacccabbabbcbcababbabccbcbcbaabccbcbabacacabcbbacabcab"]

total_time = time.perf_counter_ns()

for i in testcases:
    print(ans.longestBalanced(i))

print("Total Runtime : ", (time.perf_counter_ns() - total_time)/1e6, " ms")

# ans.longestBalanced("aaaaa")


# def helper(s, ch1, ch2) -> int:
#     # nonlocal s

#     local_max_len = 0

#     mp_double = Counter()
#     counts = [0, 0]

#     mp_double[0] = -1
#     for i in range(len(s)):
#         if s[i] == ch1:
#             counts[0] += 1
#         elif s[i] == ch2:
#             counts[1] += 1
#         else:
#             mp_double.clear()
#             mp_double[0] = i
#             counts[0], counts[1] = 0, 0
#             continue

#         if (counts[0] - counts[1])not in mp_double:
#             mp_double[(counts[0] - counts[1])] = i
#             local_max_len = max(local_max_len, 2*min(counts))
#         else:
#             local_max_len = max(
#                 local_max_len, i - mp_double[(counts[0] - counts[1])])

#     return local_max_len


# trial_str = "aaabbbcaaababbb"
# print(helper(trial_str, 'a', 'b'))
