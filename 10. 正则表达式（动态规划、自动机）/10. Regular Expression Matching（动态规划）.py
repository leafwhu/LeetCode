class Solution:
    def isMatch(self, s: str, p:str)->bool:
        def match(si, pi):
            if si == pi:
                return True
            if pi == '.' and si != '':
                return True
            return False

        def subscript(s, i):
            if i >= 0:
                return s[i]
            elif i < 0:
                return ""
        
        s_len, p_len = len(s), len(p)
        f = [[False]*(p_len+1) for i in range(s_len+1)]
        f[-1][-1] = True

        for i in range(0, s_len+1):
            for j in range(0, p_len+1):
                if subscript(p, j-1) != "*":
                    if match(subscript(s, i-1), subscript(p, j-1)):
                        f[i][j] = f[i-1][j-1]
                    else:
                        f[i][j] = False
                elif  subscript(p, j-1) == '*':
                    if match(subscript(s, i-1), subscript(p, j-2)):
                        f[i][j] = f[i][j-2] or f[i-1][j]
                    else:
                        f[i][j] = f[i][j-2]


        return f[s_len][p_len]


s = Solution()
# print(s.isMatch("222272222722227", "2.*7*"))
print(s.isMatch("", "."))