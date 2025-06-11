# Random Pick Index

Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array. Implement the Solution class:

- Solution(int[] nums) Initializes the object with the array nums.
- int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.

## Example

```
Input
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
Output
[null, 4, 0, 2]
```

## Stats

- Lang: Python
- Runtime: 28ms (beats 96%)
- Mem: 28 Mb (beats 47%)
