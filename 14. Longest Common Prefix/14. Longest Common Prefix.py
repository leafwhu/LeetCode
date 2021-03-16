class Solution:
    def longestCommonPrefix(self, strs) -> str:
        if len(strs) == 0:
            return ""
        min_len = min(len(string) for string in strs)
        i = 0
        while i < min_len:
            if any(strs[j][i] != strs[j + 1][i] for j in range(len(strs) - 1)):
                return strs[0][:i]
            i += 1
        return strs[0][:i]

s = Solution()
print(s.longestCommonPrefix(["aa", "aa", "aa"]))