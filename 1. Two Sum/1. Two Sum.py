class Solution:
    def twoSum(self, nums, target: int):
        hashtable = dict()
        for (i,num) in enumerate(nums):
            if (target - num) in hashtable:
                return [i, hashtable[target - num]]
            hashtable[num] = i
        return [-1, -1]
        
s = Solution()
print(s.twoSum([1, 2], 2))


