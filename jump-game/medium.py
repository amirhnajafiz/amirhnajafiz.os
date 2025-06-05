class Solution:
    def canJump(self, nums: List[int]) -> bool:
        size = len(nums)

        # Starting from the end of our list
        # Keep track the results
        dp = [False]*size

        i = size - 1
        while i > -1:
            for j in range(i, i+nums[i]+1):
                if j >= size-1 or dp[j]:
                    dp[i] = True
                    break
            i -= 1
        
        return dp[0]
