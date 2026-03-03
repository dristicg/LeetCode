class Solution {
public:
    string triangleType(vector<int>& nums) {

        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        // Check if valid triangle
        if (a + b <= c || a + c <= b || b + c <= a) {
            return "none";
        }

        // Check types
        if (a == b && b == c) {
            return "equilateral";
        }
        else if (a == b || b == c || a == c) {
            return "isosceles";
        }
        else {
            return "scalene";
        }
    }
};