class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] stores the max relative score player 1 can get over player 2 from nums[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: if there's only one number, the player just takes it
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        
        // Fill the DP table for subarrays of length 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                // The player chooses either the left end (nums[i]) or the right end (nums[j])
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        
        // If the score difference is >= 0, Player 1 can win or tie
        return dp[0][n - 1] >= 0;
    }
};