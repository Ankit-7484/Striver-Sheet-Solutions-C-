class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 2; i <= n; i++) {
            string ans = "";

            for (int j = 0; j < s.size(); j++) {
                int count = 1;

                while (j + 1 < s.size() && s[j] == s[j + 1]) {
                    count++;
                    j++;
                }

                // Append count followed by the character
                ans += to_string(count) + s[j];
            }

            s = ans;
        }

        return s;
    }
};
