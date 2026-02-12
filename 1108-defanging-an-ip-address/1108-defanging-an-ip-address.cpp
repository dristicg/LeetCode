class Solution {
public:
    string defangIPaddr(string address) {
        string result = "";
        int n = address.length();
        for (int i = 0; i < n; i++) {
            if (address[i] == '.') {
                result += "[.]";
            } else {
                result = result + address[i];
            }
        }
        return result;
    }
};