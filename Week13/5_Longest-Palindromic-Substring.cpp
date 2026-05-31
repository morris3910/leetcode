class Solution {
public:
    int expand(const std::string s, int n, int c1, int c2){
        while(c1 >= 0 && c2 < n && s[c1] == s[c2]){
            c1--;c2++;
        }
        return (c2-c1+1)-2;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        std::string ans;

        for(int i=0; i<n; i++){
            int odd_p = expand(s, n, i, i);
            int even_p = expand(s, n, i, i+1);
            if(odd_p >= even_p && odd_p > ans.length()){
                int l = i - odd_p/2;
                ans = s.substr(l, odd_p);
            }
            if(even_p > odd_p && even_p > ans.length()){
                int l = i - even_p/2 + 1;
                ans = s.substr(l, even_p);
            }
        }
        return ans;
    }
};