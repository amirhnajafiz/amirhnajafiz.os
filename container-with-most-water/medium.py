class Solution:
    def min(self, a: int, b: int) -> int:
        return a if a <= b else b

    def maxArea(self, height: List[int]) -> int:
        # two index handlers (start and end of the list)
        start = 0
        end = len(height) - 1

        # the result
        maximum_container_size = 0

        # O(n) loop
        while start < end:            
            # calculate the current container
            tmp_size = self.min(height[start], height[end]) * (end - start)

            # check the sizes
            if maximum_container_size < tmp_size:
                maximum_container_size = tmp_size
            
            # update the indeces
            if height[start] > height[end]:
                end -= 1
            else:
                start += 1

        return maximum_container_size
