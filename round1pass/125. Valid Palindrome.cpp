class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() < 2)
            return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i = 0, j = s.size() - 1;
        while(i < j) {
            while(i < j && !isalnum(s[i]))
                i ++;
            while(i < j && !isalnum(s[j]))
                j --;
            while(s[i] == s[j]) {
                i ++;
                j --;
                if(i > j)
                    break;
            }
            if(i < j && isalnum(s[i]) && isalnum(s[j]))
                return false;
        }
        return true;
    }
};