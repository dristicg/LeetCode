class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=0, suff=0;
        int maximum=INT_MIN;

        for(int i=0; i<nums.size();i++){
            if(pre == 0) pre=1;
            if(suff == 0) suff=1;

            pre = pre*nums[i];
            suff = suff*nums[nums.size()-i-1];
            maximum = max(maximum, max(pre, suff)); 
        }
        return maximum;
    }
};