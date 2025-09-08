from typing import List

class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = [0] * n
        if n % 2:
            for i in range(n):
                ans[i] = i - n // 2
        else:
            for i in range(n // 2):
                ans[i] = i - n // 2
            for i in range(n // 2, n):
                ans[i] = i - n // 2 + 1
        return ans
