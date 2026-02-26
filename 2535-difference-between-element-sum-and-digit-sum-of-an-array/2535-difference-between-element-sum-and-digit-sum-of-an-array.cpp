class Solution {
public:
    int differenceOfSum(vector<int>& nums) {

        int elementSum = 0;
        int digitSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            elementSum += nums[i];

            int temp = nums[i];
            while (temp > 0) {
                digitSum += temp % 10;
                temp = temp/10;
            }
        }
        return abs(elementSum-digitSum);
    }
};