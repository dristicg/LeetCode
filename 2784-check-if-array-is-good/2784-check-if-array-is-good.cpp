class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        if (n != nums[n - 1] + 1 || n < 2)
            return false;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (auto& it : mp) {

            // n-1 should appear twice
            if (it.first == n - 1) {
                if (it.second != 2)
                    return false;
            }

            // all others should appear once
            else if (it.second != 1) {
                return false;
            }
        }

        return true;
    }
};