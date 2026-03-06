class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sumSingle = 0;
        int sumDouble = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 9) {
                sumDouble += nums[i];
            } else {
                sumSingle += nums[i];
            }
        }
        return sumSingle != sumDouble;
    }
};