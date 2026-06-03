class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ballons;
        ballons.push_back(1);
        for(int num : nums) ballons.push_back(num);
        ballons.push_back(1);

        std::vector<std::vector<int>> dp(n+2, std::vector<int>(n+2, 0));
        for(int i=2; i<n+2; i++){
            for(int j=i-2; j>=0; j--){
                // j~i max coins
                int max = INT_MIN;
                for(int k=j+1; k<i; k++){
                    max = std::max(max, dp[j][k]+dp[k][i]+ballons[j]*ballons[k]*ballons[i]);
                }
                dp[j][i] = max;
            }
        }
        return dp[0][n+1];
    }
};