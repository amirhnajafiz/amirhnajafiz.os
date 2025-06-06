class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        rows, cols = len(dungeon), len(dungeon[0])
        
        dp = [[float('inf')] * (cols + 1) for _ in range(rows + 1)]
        dp[rows][cols - 1] = dp[rows - 1][cols] = 1  # Add a dummy border

        for i in reversed(range(rows)):
            for j in reversed(range(cols)):
                min_health_on_exit = min(dp[i + 1][j], dp[i][j + 1])
                dp[i][j] = max(1, min_health_on_exit - dungeon[i][j])

        return dp[0][0]
