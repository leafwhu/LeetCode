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
        # O(nlogn)
        # d[i] is the minimun ending number of increasing subsequence of length i
        d = [float('-inf')]
        LIS_len = 0
        for num in nums:
            if num > d[LIS_len]:
                # increasing length of LIS
                LIS_len += 1
                d.append(num)
                # print("num: {} d[LIS_len]:{} num > d[LIS_len]".format(num, d[LIS_len]))
                # print("d:", d)
            else:
                j = self.binary_search(d, num)
                # print("j: {}".format(j))
                if j + 1 <= LIS_len and d[j + 1] > num and d[j] < num:
                    # update minimum ending number
                    d[j + 1] = num
                # print("d:", d)
                    
        print(d)
        return LIS_len, d[LIS_len]


x = [10, 9, 2, 5, 3, 7, 101, 18]
# x = [7,7,7,7,7,7,7]
s = Solution()
print(s.lengthOfLIS(x))


# d = [-18446744073709551616, 1, 2]
# print(s.binary_search(d, -10))