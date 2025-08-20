from typing import List

class Solution:
    def isSelfCrossing(self, distance: List[int]) -> bool:
        if len(distance) < 4:
            return False
        distance = [0] + distance
        n = len(distance)
        for i in range(3, n):
            if distance[i - 2] <= distance[i] and distance[i - 1] <= distance[i - 3]:
                return True
            if i >= 5:
                if distance[i - 4] <= distance[i - 2] <= distance[i - 4] + distance[i] and distance[i - 1] <= distance[i - 3] <= distance[i - 1] + distance[i - 5]:
                    return True
        return False
