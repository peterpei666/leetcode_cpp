class Solution:
    def numSteps(self, s: str) -> int:
        n = len(s)
        ans = 0
        carry = 0
        for i in range(n - 1, 0, -1):
            if s[i] == '0':
                ans += 1 + carry
            else:
                ans += 2 - carry
                carry = 1
        return ans + carry
