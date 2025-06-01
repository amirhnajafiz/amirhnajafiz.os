#include <limits.h> // Include this to access INT_MAX and INT_MIN

int reverse(int x) {
    int result = 0;

    while (x != 0) {
        int remain = x % 10;
        x = x / 10;

        // Check for overflow/underflow before multiplying
        if (result > (INT_MAX / 10) || (result == (INT_MAX / 10) && remain > 7) ||
            result < (INT_MIN / 10) || (result == (INT_MIN / 10) && remain < -8)) {
            return 0; // Return 0 in case of overflow/underflow
        }

        result = 10 * result + remain;
    }

    return result;
}
