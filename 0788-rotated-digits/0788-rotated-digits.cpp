class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            bool valid = false, invalid = false;
            int num = i;
            while (num > 0) {
                int digit = num % 10;
                if (digit == 3 || digit == 4 || digit == 7) {
                    invalid = true;
                    break;
                }
                if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    valid = true;
                }
                num /= 10;
            }
            if (valid && !invalid) count++;
        }
        return count;
    }
};