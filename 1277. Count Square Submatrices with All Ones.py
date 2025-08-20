from typing import List

class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        ans = 0
        dp = [[0] * n for _ in range(2)]
        for i in range(m):
            dp[i % 2] = [0] * n
            for j in range(n):
                if matrix[i][j]:
                    if i * j:
                        dp[i % 2][j] = min(dp[(i - 1) % 2][j], dp[i % 2][j - 1], dp[(i - 1) % 2][j - 1]) + 1
                    else:
                        dp[i % 2][j] = 1
                    ans += dp[i % 2][j]
        return ans
