class NFA:
        def __init__(self):
            self.ans = ""
            self.state = "start"
            self.table = {
                "start": ["start","signed","number","end"],
                "signed": ["end","end","number","end"],
                "number": ["end","end","number","end"],
                "end": ["end","end","end","end"]
            }

        def automation(self, string):
            for c in string:
                if c == ' ':
                    if self.state == "signed":
                        return 0
                    self.state = self.table[self.state][0]
                elif c == "+" or c == "-":
                    if self.state == "signed":
                        return 0
                    self.state = self.table[self.state][1]
                elif c.isdigit():
                    self.state = self.table[self.state][2]
                else:
                    if self.state == "signed":
                        return 0
                    self.state = self.table[self.state][3]
                if self.state == "signed" or self.state == "number":
                    self.ans += c
            if len(self.ans) == 0 or self.state == "signed":
                return 0
            else:
                return int(self.ans)

class Solution:   
    def myAtoi(self, s: str) -> int:
        nfa = NFA()
        ans = nfa.automation(s)
        if ans < -1 << 31:
            return -1 << 31
        elif ans > (1 << 31) - 1:
            return (1 << 31) - 1
        else:
            return ans
        
s = Solution()
print(s.myAtoi("-2345www"))