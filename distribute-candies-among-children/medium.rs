use std::cmp::{min, max};

impl Solution {
    pub fn distribute_candies(n: i32, limit: i32) -> i64 {
        let mut summation :i64 = 0;

        for i in 0..min(n, limit)+1 {
            let start = max(0, n - i - limit);
            let end = min(limit, n - i);
            let count = max(end - start + 1, 0);
            summation += count as i64;
        }

        return summation;
    }
}

/*
long long distributeCandies(int n, int limit) {
        long long sumation = 0;

        for (int i = 0; i <= min(n, limit); i++)
            sumation += max(min(limit, n - i) - max(0, n - i - limit) + 1, 0)

        return sumation;
    }
*/
