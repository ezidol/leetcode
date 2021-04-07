#include <string.h>

char * longestPalindrome(char * s){
    int i, j, k, l, cnt, max, start, end, n;
    int s_len = strlen(s);
    cnt = 0;
    max = 0;
    n = 0;
    start = 0;
    end = 0;
    
    for (i = 0; i < s_len; i++) {
        if (max >= s_len - i + 1) break;
        for (j = i; j < s_len; j++) {
            if (s[i] == s[j]) {
                l = 0;
                for (k = i; k <= j; k++) {
                    if (s[k] != s[j - l]) break;
                    l += 1;
                    if (k == j) {
                        cnt = j - i + 1;
                        if (cnt > max) {
                            start = i;
                            end = j;
                            max = cnt;
                        }
                    }
                }
            }
        }
    }
    char *answer = (char *)malloc(sizeof(char *)*max);
    memset(answer, 0, sizeof(char *)*max);
    for (i = start; i <= end; i++) {
        answer[n] = s[i];
        n += 1;
    }
    
    return answer;
}
