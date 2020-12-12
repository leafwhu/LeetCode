class Solution:
    def lengthOfLIS(self, nums: list) -> int:
        d = []
        for n in nums:
            if not d or n > d[-1]:
                d.append(n)
            else:
                l, r = 0, len(d) - 1
                loc = r
                while l <= r:
                    mid = (l + r) // 2
                    if d[mid] >= n:
                        loc = mid
                        r = mid - 1
                    else:
                        l = mid + 1
                d[loc] = n
        return len(d)

x = [0,8,4,12,2]
s = Solution()
print(s.lengthOfLIS(x))


# d = [-18446744073709551616, 1, 2]
# print(s.binary_search(d, -10))