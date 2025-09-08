from typing import List

class Solution:
    def check(self, x: int) -> bool:
        while x:
            if x % 10 == 0:
                return False
            x //= 10
        return True
    
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1, n):
            if self.check(i) and self.check(n - i):
                return [i, n - i]
        return []
