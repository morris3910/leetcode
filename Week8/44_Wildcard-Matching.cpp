class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length(), p_len = p.length(), s_idx = 0, p_idx = 0, star_idx = -1, star_pos = 0;
        while(s_idx < s_len){
            if(p_idx < p_len && (p[p_idx] == '?' || s[s_idx] == p[p_idx])){
                s_idx++;
                p_idx++;
            } else if(p_idx < p_len && p[p_idx] == '*'){
                star_idx = p_idx;
                star_pos = s_idx;
                p_idx++;
            } else{
                if(star_idx == -1) return false;
                else {
                    star_pos++;
                    p_idx = star_idx+1;
                    s_idx = star_pos;
                }
            }
        }

        while(p_idx != p_len && p[p_idx] == '*')
            p_idx++;

        return p_idx == p_len;
    }
};