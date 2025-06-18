from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left, right, n = 0, 0, len(nums)
        while right < n:
            if nums[right] != 0:
                nums[right], nums[left] = nums[left], nums[right]
                left+=1
            right+=1

