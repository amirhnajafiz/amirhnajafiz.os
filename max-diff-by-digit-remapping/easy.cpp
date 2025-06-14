class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> digits;
        while (num > 0) {
            digits.insert(digits.begin(), num % 10);
            num /= 10;
        }

        int index = 0;
        int maxValue = -1;
        int minValue = -1;

        while (index < digits.size()) {
            if (digits[index] != 9) {
                maxValue = digits[index];
                break;
            }

            index++;
        }

        index = 0;
        while (index < digits.size()) {
            if (digits[index] != 0) {
                minValue = digits[index];
                break;
            }

            index++;
        }

        int bigNum = 0;
        for (int num : digits) {
            if (num == maxValue)
                bigNum = bigNum * 10 + 9;
            else
                bigNum = bigNum * 10 + num;
        }

        int littleNum = 0;
        for (int num : digits) {
            if (num == minValue)
                littleNum = littleNum * 10 + 0;
            else
                littleNum = littleNum * 10 + num;
        }

        return bigNum - littleNum;
    }
};
