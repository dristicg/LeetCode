class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1;
        int i = 0;

        while (k > 0) {
            if (i < arr.size() && arr[i] == num) {
                i++;        // number exists
            } else {
                k--;        // number is missing
                if (k == 0) return num;
            }
            num++;
        }
        return -1;
    }
};
