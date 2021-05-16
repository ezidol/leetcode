#include <regex>
#include <sstream>

class Solution {
public:
    int myAtoi(string s) {
        if ((s[1] >= 0x30 && s[1] <= 0x39) == false) {
            if (s[0] == '+' || s[0] == '-') return 0;    
        }
        if (s[0] == '.' || (s[0] >= 0x41 && s[0] <= 0x7A)) return 0;
        // first step
        int w_cnt = 0;
        for (char w: s) {
            if (w == 0x20) w_cnt++;
            else break;
        }
        if (w_cnt) s.erase(0, w_cnt);
        if ((s[1] >= 0x30 && s[1] <= 0x39) == false) {
            if (s[0] == '+' || s[0] == '-') return 0;    
        }
        if (s[0] == '.' || (s[0] >= 0x41 && s[0] <= 0x7A)) return 0;
        // second step
        bool isPos = true;
        if (s[1] >= 0x30 && s[1] <= 0x39) {
            if (s[0] == '-') {
                isPos = false;
                s.erase(0, 1);
            } else if (s[0] == '+') {
                isPos = true;
                s.erase(0, 1);
            }
        }        
        if ((s[1] >= 0x30 && s[1] <= 0x39) == false) {
            if (s[0] == '+' || s[0] == '-') return 0;    
        }
        if (s[0] == '.' || (s[0] >= 0x41 && s[0] <= 0x7A)) return 0;
        // third step
        long long ret;
        string ret_str;
        for (char c: s) {
            if (c >= 0x30 && c <= 0x39) ret_str += c;
            else break;
        }
        if (ret_str == "") return 0;
        else if (ret_str[0] != '0') {
            if (ret_str.length() > 10) {
                if (isPos == true) return 2147483647;
                else return -2147483648; 
            } else ret = stoll(ret_str);
        } else ret = stoll(ret_str);
        if (isPos == false && ret >= 2147483648) return -2147483648;
        else if(isPos == true && ret >= 2147483647) return 2147483647;
        if (isPos) return (int) ret;
        else return (int) ret * -1;
    }
};