from typing import List
from collections import defaultdict

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        mp = defaultdict(int)
        for w in words:
            mp[w] += 1
        return [s for s, _ in sorted([(s, n) for s, n in mp.items()], key=lambda x : (-x[1], x[0]))[:k]]
