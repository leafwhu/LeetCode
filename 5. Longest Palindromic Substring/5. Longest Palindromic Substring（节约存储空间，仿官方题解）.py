class Solution:
    def expandRoundCenter(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return left+1, right-1

    def longestPalindrome(self, s: str) -> str:
        left = right = 0
        for i in range(len(s)):
            left1, right1 = self.expandRoundCenter(s, i, i)
            left2, right2 = self.expandRoundCenter(s, i, i + 1)
            if right1 - left1 > right - left:
                right = right1
                left = left1
            if right2 - left2 > right - left:
                right = right2
                left = left2
        return s[left:right+1]



s = Solution()
print(s.longestPalindrome("bb"))