class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long long num = 0;

        // Step 1: skip spaces
        while (i < s.size() && s[i] == ' ')
            i++;

        // Step 2: sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Step 3: digits
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 4: overflow check
            if (num > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return num * sign;
    }
};
