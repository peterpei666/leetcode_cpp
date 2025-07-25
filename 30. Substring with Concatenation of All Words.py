from typing import List
from collections import defaultdict

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n = len(s)
        wlen, wcnt = len(words[0]), len(words)
        if wlen * wcnt > n:
            return []
        mp = defaultdict(int)
        for w in words:
            mp[w] += 1
        ans = []
        for i in range(wlen):
            l, r = i, i
            cnt = 0
            temp = defaultdict(int)
            while r + wlen <= n:
                wr = s[r:r + wlen]
                r += wlen
                if wr in mp:
                    temp[wr] += 1
                    cnt += 1
                    while temp[wr] > mp[wr]:
                        wl = s[l:l + wlen]
                        temp[wl] -= 1
                        cnt -= 1
                        l += wlen
                    if cnt == wcnt:
                        ans.append(l)
                else:
                    l = r
                    cnt = 0
                    temp.clear()
        return ans
