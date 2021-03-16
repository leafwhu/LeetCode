class Solution:
    def longestPalindrome(self, s: str) -> str:
        P = [[False]*len(s) for i in range(len(s))]
        maxi = maxj = 0
        max_len = 1
        for l in range(len(s)):
            for i in range(len(s)):
                j = i + l
                if j >= len(s):
                    break
                if i == j:
                    P[i][j] = True
                elif j == i + 1 and s[i] == s[j]:
                    P[i][j] = True
                    maxi = i
                    maxj = j
                    max_len = 2
                elif i + 1 < len(s):        # 白写，不满足这个条件的话第一个if就break了
                    if P[i+1][j-1] and s[i] == s[j]:
                        P[i][j] = True
                        if j - i > maxj - maxi:
                            maxi = i
                            maxj = j
                            max_len = j - i + 1
        return s[maxi:maxj+1]



s = Solution()
print(s.longestPalindrome("cbbd"))