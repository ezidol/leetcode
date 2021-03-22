class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        answer = 0
        cnt = 0
        s_len = len(s)
        cnt_list =[0]
        c_list = []
        for i in range(s_len):
            sx = s[i:s_len]
            sx_len = len(sx)
            for x in sx:
                if x in c_list:
                    cnt_list.append(cnt)
                    c_list = []
                    cnt = 0
                    break
                c_list.append(x)
                cnt += 1
            if x == sx[sx_len-1]:
                c_list = []    
                cnt_list.append(cnt)
                cnt = 0        
        answer = max(cnt_list)
        
        return answer
