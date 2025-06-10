use std::cmp::max;

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n == 0 {
            return 0;
        } else if n == 1 {
            return nums[0];
        }

        let mut robs = vec![0; n];
        robs[0] = nums[0];
        robs[1] = max(nums[0], nums[1]);

        for i in 2..n {
            robs[i] = max(robs[i - 1], robs[i - 2] + nums[i]);
        }

        robs[n - 1]
    }
}
