class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int answer = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int diff = abs(nums[i+1] - nums[i]);
            answer = answer > diff ? answer : diff;
        }

        if (nums.size() > 1) {
            int lastTwo = abs(nums[0] - nums[nums.size() - 1]);
            answer = answer > lastTwo ? answer : lastTwo;
        }

        return answer;
    }
};
