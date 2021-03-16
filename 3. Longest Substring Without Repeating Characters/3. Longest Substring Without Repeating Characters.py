class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        j = -1
        max_len = 0
        hashtab = dict()
        while j < len(s) - 1:
            j += 1
            if s[j] not in hashtab:
                hashtab[s[j]] = 1
                if j-i+1 > max_len:
                    max_len = j - i + 1
            else:
                while s[j] in hashtab:
                    del hashtab[s[i]]
                    i += 1
                hashtab[s[j]] = 1
        return max_len

s = Solution()
print(s.lengthOfLongestSubstring("abcabcbb"))