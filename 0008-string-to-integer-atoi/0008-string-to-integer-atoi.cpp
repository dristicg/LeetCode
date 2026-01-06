class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int l = s.length();

        // for leading whitespace
        while (i < l && isspace(s[i])) {
            i++;
        }

        // if o more characters
        if (i == l) {
            return 0;
        }

        // check for sign
        bool negative = false;
        if (s[i] == '-') {
            negative = true;
            i++;
        } else if (s[i] == '+') {
            i++;
        } else if (!isdigit(s[i])) {
            return 0;
        }
        // if no more characters
        if (i == l) {
            return 0;
        }

        // skip the leading zeros
        while (i < l && s[i] == '0') {
            i++;
        }
        // if o more characters
        if (i == l) {
            return 0;
        }

        // extract  numbsers nad return int value
        int value = 0;

        while (i < l && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (!negative) {
                // check overflow for positive
                if (value > INT_MAX / 10 ||
                    (value == INT_MAX / 10 && digit > 7)) {
                    return INT_MAX;
                }
                value = value * 10 + digit;
            } else {
                // check overflow for negative
                if (value < INT_MIN / 10 ||
                    (value == INT_MIN / 10 && digit > 8)) {
                    return INT_MIN;
                }
                value = value * 10 - digit;
            }

            i++;
        }
         return value;
    }
};
