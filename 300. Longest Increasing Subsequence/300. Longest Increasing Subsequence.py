class Solution:
    def binary_search(self, d: list, key: int) -> int:
        left = 0
        right = len(d) - 1
        ans = 0
        while left <= right:
            mid = (left + right) // 2
            if d[mid] <= key:
                ans = mid
                left = mid + 1
            elif d[mid] > key:
                right = mid - 1
        # while ans - 1 >= 0 and d[ans - 1] == d[ans]:
            # ans -= 1
        return ans

    def lengthOfLIS(self, nums: list) -> int:
        d = [-2**64]
        LIS_len = 0
        for num in nums:
            if num > d[LIS_len]:
                LIS_len += 1
                d.append(num)
            else:
                j = self.binary_search(d, num)
                if j + 1 <= LIS_len  and d[j+1] > num and d[j] < num:
                    d[j+1] = num
        return LIS_len, d[LIS_len]


x = [7,7,7,7,7,7,7]
s = Solution()
print(s.lengthOfLIS(x))


# d = [-18446744073709551616, 1, 2]
# print(s.binary_search(d, -10))