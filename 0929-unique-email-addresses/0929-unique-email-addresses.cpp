class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;

        for (string email : emails) {
            string local = "";
            string domain = "";
            bool plusFound = false;
            bool atFound = false;

            for (char c : email) {
                if (c == '@') {
                    atFound = true;
                    continue;
                }

                if (!atFound) { // processing local part
                    if (c == '+') {
                        plusFound = true;
                    }
                    else if (c == '.') {
                        continue;  // skip dots
                    }
                    else if (!plusFound) {
                        local += c;
                    }
                }
                else { // processing domain part
                    domain += c;
                }
            }

            uniqueEmails.insert(local + "@" + domain);
        }

        return uniqueEmails.size();
    }
};
