class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        
        for (long i = 1; i <= n; i *= 10) {
            int a = n / i;
            int b = n % i;
            int x = a % 10;

            if (x == 1)
                count += (a / 10) * i + (b + 1);
            else if (x == 0)
                count += (a / 10) * i;
            else
                count += (a / 10 + 1) * i;
        }

        return count;
    }
};
