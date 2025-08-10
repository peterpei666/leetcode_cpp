class Solution:
    def calculate(self, s: str) -> int:
        i, sum, sign = 0, 0, 1
        n = len(s)
        stk = []
        while i < n:
            if s[i].isdigit():
                num = 0
                while i < n and s[i].isdigit():
                    num = num * 10 + ord(s[i]) - ord('0')
                    i += 1
                i -= 1
                sum += num * sign
                sign = 1
            elif s[i] == '(':
                stk.append((sum, sign))
                sum = 0
                sign = 1
            elif s[i] == ')':
                sum = stk[-1][0] + stk[-1][1] * sum
                stk.pop()
            elif s[i] == '-':
                sign = -sign
            i += 1
        return sum
