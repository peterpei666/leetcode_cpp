class Solution:
    def minOperations(self, s: str) -> int:
        return max((26 + ord('a') - ord(c)) % 26  for c in s)
