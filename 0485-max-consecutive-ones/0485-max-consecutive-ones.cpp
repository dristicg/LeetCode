class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0;
        int maxStreak = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                curr++;
            } else {
                maxStreak = max(maxStreak, curr);
                curr = 0;
            }
        }

        // in case array ends with 1s
        maxStreak = max(maxStreak, curr);

        return maxStreak;
    }
};
