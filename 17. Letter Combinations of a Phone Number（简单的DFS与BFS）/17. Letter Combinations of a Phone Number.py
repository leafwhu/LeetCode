


class Solution:
    def letterCombinations(self, digits: str):
        keyboard = {2: "abc",
        3: "def",
        4: "ghi",
        5: "jkl",
        6: "mno",
        7: "pqrs",
        8: "tuv",
        9: "wxyz"}

        def dfs(input_index):
            nonlocal solutions, slt
            if input_index == len(digits):
                if input_index != 0:
                    solutions.append(slt)
            else:
                for x in keyboard[int(digits[input_index])]:
                    slt += x
                    dfs(input_index + 1)
                    slt = slt[:-1]

        solutions = []
        slt = ""
        
        dfs(0)
        return solutions


s = Solution()
print(s.letterCombinations(""))