impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        if x == 1 {
            return 1;
        }

        let mut left = 0;
        let mut right = 46340.min(x / 2);
        let mut ans = 0;

        while left <= right {
            let mid = (left + right) / 2;
            let tmp = mid * mid;

            if tmp == x {
                return mid;
            } else if tmp < x {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
}
