from typing import List

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        find = set()
        for i in range(len(nums)):
            if nums[i] in find:
                return True
            find.add(nums[i])
            if i - k >= 0:
                find.remove(nums[i - k])
        return False
