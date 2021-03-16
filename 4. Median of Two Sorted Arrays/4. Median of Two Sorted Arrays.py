class Solution:
    
    def findMedianSortedArrays(self, nums1: list, nums2: list) -> float:
        def findKthSmallNumber(k):
            # offset
            index1 = index2 = 0

            while k >= 1:
                if index1 >= m:
                    return nums2[index2 + k - 1]
                elif index2 >= n:
                    return nums1[index1 + k - 1]
                elif k == 1:
                    return min(nums1[index1], nums2[index2])
            
                itr1 = min(index1 + k//2 - 1, m-1)
                itr2 = min(index2 + k//2 - 1, n-1)
                if nums1[itr1] <= nums2[itr2]:
                    k -= itr1 + 1 - index1
                    index1 = itr1 + 1
                elif nums1[itr1] > nums2[itr2]:
                    k -= itr2 + 1 - index2
                    index2 = itr2 + 1
        
        
        m = len(nums1)
        n = len(nums2)
        if (m + n) % 2 == 1:
            return findKthSmallNumber( (m + n) // 2 + 1)
        else:
            return ( findKthSmallNumber( (m + n) // 2 ) + findKthSmallNumber( (m + n) // 2 + 1 ) ) / 2

s = Solution()
print(s.findMedianSortedArrays([1,3],[2]))