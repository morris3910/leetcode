class Solution {
public:
    using ll = long long;
    int combinationSum4(vector<int>& nums, int target) {
        std::vector<int> dp(target+1, 0);
        int n = nums.size();
        dp[0] = 1;

        for(int i=1; i<=target; i++){
            ll ans = 0;
            for(int j=0; j<n; j++){
                if(i - nums[j] >= 0)
                    ans += dp[i - nums[j]];
            }
            dp[i] = ans;
        }
        return dp[target];
    }
};