class Solution {
public:
    int minFlips(vector<int> nums, int target) {
        int flips = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] != target) {
                // Flip nums[i] and nums[i+1]
                nums[i] *= -1;
                nums[i + 1] *= -1;
                flips++;
            }
        }

        // After all flips, are all elements == target?
        for (int i = 0; i < n; ++i)
            if (nums[i] != target) return 1e9;  // impossible
        return flips;
    }

    bool canMakeEqual(vector<int>& nums, int k) {
        int f1 = minFlips(nums, 1);
        int f2 = minFlips(nums, -1);
        return std::min(f1, f2) <= k;
    }
};
