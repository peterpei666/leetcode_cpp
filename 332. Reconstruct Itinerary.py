from typing import List
from collections import defaultdict

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        mp = defaultdict(list)
        cnt = dict()
        for ticket in tickets:
            mp[ticket[0]].append(ticket[1])
        for i in mp:
            mp[i].sort()
            cnt[i] = 0
        ans = []

        def dfs(cur: str) -> None:
            nonlocal cnt, ans
            n = len(mp[cur])
            while cur in cnt and cnt[cur] < n:
                cnt[cur] += 1
                dfs(mp[cur][cnt[cur] - 1])
            ans.append(cur)

        dfs("JFK")
        return ans[::-1]
