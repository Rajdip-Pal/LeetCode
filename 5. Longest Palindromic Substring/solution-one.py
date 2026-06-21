class Solution:
    def longestPalindrome(self, s: str) -> str:
        longest: str = ""

        for i in range(len(s)):
            # odd length palindromes
            l, r = i, i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            odd_palindrome = s[l + 1:r]

            # even length palindromes
            l, r = i, i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            even_palindrome = s[l + 1:r]

            # update the longest palindrome found so far
            if len(odd_palindrome) > len(longest):
                longest = odd_palindrome
            if len(even_palindrome) > len(longest):
                longest = even_palindrome

        return longest
