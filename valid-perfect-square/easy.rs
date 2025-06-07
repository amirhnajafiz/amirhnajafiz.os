impl Solution {
    pub fn is_perfect_square(num: i32) -> bool {
        if num == 1 {
            return true;
        }

        let mut left = 0;
        let mut right = 46340.min(num / 2);

        while left <= right {
            let mid = (left + right) / 2;
            let tmp = mid * mid;

            if tmp == num {
                return true;
            } else if tmp < num {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
}
