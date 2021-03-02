class Solution:
    def threeSum(self, nums):
        sorted_nums = sorted(nums)
        ans = []
        for i in range(len(nums)):
            if i > 0 and sorted_nums[i - 1] == sorted_nums[i]:
                continue
            j = i + 1
            k = len(nums) - 1

            while j < k:
               
                if sorted_nums[i] + sorted_nums[j] + sorted_nums[k] > 0:
                    k -= 1

                elif sorted_nums[i] + sorted_nums[j] + sorted_nums[k] < 0:
                    j += 1

                elif sorted_nums[i] + sorted_nums[j] + sorted_nums[k] == 0:
                    ans.append([sorted_nums[i], sorted_nums[j], sorted_nums[k]])
                    while j + 1 < len(nums) and sorted_nums[j + 1] == sorted_nums[j]:
                        j += 1
                    j += 1
        return ans
                


s = Solution()
print(s.threeSum([]))