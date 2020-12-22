
alphabet = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000,
}

class Solution:
    def romanToInt(self, s: str) -> int:
        i = 0
        ans = 0
        while i < len(s) - 1:
            if alphabet[s[i]] < alphabet[s[i + 1]]:
               ans += alphabet[s[i + 1]] - alphabet[s[i]]
               i += 2
            elif alphabet[s[i]] >= alphabet[s[i + 1]]:
                ans += alphabet[s[i]]
                i += 1
        if i < len(s):
            ans += alphabet[s[i]]
        return ans


s = Solution()
print(s.romanToInt("XLIII"))     # 1994