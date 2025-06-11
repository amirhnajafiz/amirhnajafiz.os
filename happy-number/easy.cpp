class Solution {
public:
    bool isHappy(int n) {
        while (true) {
            if (n == 1 || n == 7)
                return true;
            else if (n < 10)
                return false;

            // calculate pow of digits
            int ans = 0;
            while (n > 0) {
                int remain = n % 10;
                ans += remain * remain;
                n /= 10;
            }
            n = ans;
        }

        return false;
    }
};
