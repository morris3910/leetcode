class Solution {
public:
    int partitionString(string s) {
        int ans = 1, flag = 0;
        for(char c : s){
            if(1 << (c - 'a') & flag){
                flag = 0;
                flag |= (1 << (c - 'a'));
                ans++;
            }else
                flag |= (1 << (c - 'a'));
        }
        return ans;
    }
};