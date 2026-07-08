class Solution {
public:
    bool isPalindrome(string s) {
       string str;

        for (char c : s) {
            if (isalnum(static_cast<unsigned char>(c))) {
                str += tolower(c);
            }
        }

        int n = str.size();

        int l = 0;
        int r = n-1;

        while(l < r){
            if(str[l] != str[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
