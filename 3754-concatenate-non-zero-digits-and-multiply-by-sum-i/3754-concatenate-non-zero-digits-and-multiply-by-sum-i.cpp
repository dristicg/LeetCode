class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        vector<int> digits;
        int sum = 0;
        long long concat = 0;

        for(char c : s){
            int d = c - '0';
            if(d > 0){
                digits.push_back(d);
                sum += d;
            }
        }
        // Concatenate digits
        for(int d : digits){
            concat = concat * 10 + d;
        }
        return concat * sum;
    }
};