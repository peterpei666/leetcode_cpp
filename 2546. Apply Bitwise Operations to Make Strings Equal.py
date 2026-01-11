class Solution:
    def makeStringsEqual(self, s: str, t: str) -> bool:
        return not (all(c == '0' for c in s) ^ all(c == '0' for c in t))
