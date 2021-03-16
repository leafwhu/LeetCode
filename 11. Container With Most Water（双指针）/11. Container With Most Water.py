class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = len(height)
        max_area = 0
        i = 0
        j = l - 1
        while i != j:
            area = (j-1) * min(height[i], height[j])
            if area > max_area:
                max_area = area
            if height[i] <= height[j]:
                i += 1
            elif height[i] > height[j]:
                j -= 1
        return max_area

s = Solution()
s.maxArea([1,8,6,2,5,4,8,3,7])