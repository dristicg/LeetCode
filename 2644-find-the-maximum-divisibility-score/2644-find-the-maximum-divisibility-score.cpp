class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int maxCount = -1;
        int result = INT_MAX;

        for (int d : divisors) {
            int count = 0;

            for (int num : nums) {
                if (num % d == 0) {
                    count++;
                }
            }

            if (count > maxCount) {
                maxCount = count;
                result = d;
            } 
            else if (count == maxCount) {
                result = min(result, d);
            }
        }

        return result;
    }
};