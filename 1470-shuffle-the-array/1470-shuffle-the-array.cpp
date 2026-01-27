class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        result.reserve(2 * n);  // optional, avoids reallocation

        int i = 0;      // pointer for first half
        int j = n;      // pointer for second half

        for (int k = 0; k < n; k++) {
            result.push_back(nums[i]);
            result.push_back(nums[j]);
            i++;
            j++;
        }

        return result;
    }
};
