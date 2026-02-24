class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        string s = to_string(num); // int to char

        for (char c : s) {
            int digit = c - '0'; // to conver char to int

            if (digit != 0 && num % digit == 0) {
                count++;
            }
        }
        return count;
    }
};