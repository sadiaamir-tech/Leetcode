class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + 32;

            if ((s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '0' && s[i] <= '9'))
                str += s[i];
        }

        int start = 0;
        int end = str.length() - 1;

        while (start < end) {
            if (str[start] != str[end])
                return false;

            start++;
            end--;
        }

        return true;
    }
};
