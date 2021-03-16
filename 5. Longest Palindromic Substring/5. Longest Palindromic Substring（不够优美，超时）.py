class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)
        P = []
        for i in range(length):
            P.append([0]*length)
        for i in range(length):
            for j in range(length):
                if i == j:
                    P[i][j] = 1
                else:
                    P[i][j] = 0
        max_len = 1
        maxi = maxj = 0                    
        for i in range(length-1):
            if s[i] == s[i+1]:
                P[i][i+1] = 2
                if P[i][i+1] > max_len:
                    maxi = i
                    maxj = i + 1
                    max_len = P[i][i + 1]
        for i in range(1,length-1):
            j = i
            while i-1 >= 0 and j+1 < length:
                i -= 1
                j += 1
                if s[i] == s[j] and P[i+1][j-1] > 0:
                    P[i][j] = P[i+1][j-1] + 2
                    if P[i][j] > max_len:
                        maxi = i
                        maxj = j
                        max_len = P[i][j]
        
        for i in range(1,length-1):
            j = i + 1
            while i-1 >= 0 and j+1 < length:
                i -= 1
                j += 1
                if s[i] == s[j] and P[i+1][j-1] > 0:
                    P[i][j] = P[i+1][j-1] + 2
                    if P[i][j] > max_len:
                        maxi = i
                        maxj = j
                        max_len = P[i][j]

        return s[maxi:maxj+1]



s = Solution()
print(s.longestPalindrome("abba"))