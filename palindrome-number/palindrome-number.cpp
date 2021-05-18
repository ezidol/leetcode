class Solution {
public:
    bool isPalindrome(int x){
        bool ret = true;
        stringstream ssInt;
        ssInt << x;
        string str_x = ssInt.str();
        string pstr_x = str_x;
        reverse(pstr_x.begin(), pstr_x.end());
        for (int i = 0; i < str_x.length(); i++) {
            if (str_x[i] != pstr_x[i]) {
                ret = false;
            }
        }
        return ret;
    }
};