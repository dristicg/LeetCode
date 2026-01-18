class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            for (int step = 1; step < n; step++) {
                int index = (i + step) % n;
                if (nums[index] > nums[i]) {
                    ans[i] = nums[index];
                    break;  
                }
            }
        }
        return ans;
    }
};
