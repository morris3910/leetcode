class Solution {
public:
    
    int MOD = 1e9+7;
    int dp[100001];
    
    int helper(int ind, string &s){
        if(ind == s.size()){
            return 1;
        }
        
		// Not possible
        if(s[ind] == '0'){
            return 0;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        long long first = helper(ind+1, s);
		
		// We can use 9 diff characters inplace of *
        if(s[ind] == '*'){
            first = (first*9)%MOD;
        }
        
        long long second = 0;
        long long third = 0;
        
        if(ind+1 < s.size()){
            if(s[ind] == '1' || s[ind] == '*'){
				// We can use 9 diff characters inplace of *
                if(s[ind+1] == '*'){
                    second = helper(ind+2, s);
                    second = (second*9)%MOD;
                }
                else if(s[ind+1] != '*'){
                    second = helper(ind+2, s);
                }
            }
            if(s[ind] == '2' || s[ind] == '*'){
				// We can use only 6 diff characters inplace of *
                if(s[ind+1] == '*') {
                    third = helper(ind+2, s);
                    third = (third*6)%MOD;
                }
                else if(s[ind+1]-'0' <= 6){
                    third = helper(ind+2, s);
                }
            }
        }
        
        return dp[ind] = ((first+second)%MOD+third)%MOD;
    }
    
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(0, s);
    }
};