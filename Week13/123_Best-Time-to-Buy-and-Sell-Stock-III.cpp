class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), min_l = prices[0], max_r = prices[n-1];
        std::vector<int> profits_l(n, 0), profits_r(n, 0);
        for(int i=1, j=n-2; i<n && j>=0; i++, j--){
            profits_l[i] = std::max(profits_l[i-1], prices[i]-min_l);
            profits_r[j] = std::max(profits_r[j+1], max_r - prices[j]);
            min_l = std::min(min_l, prices[i]);
            max_r = std::max(max_r, prices[j]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = std::max(ans, profits_l[i] + profits_r[i]);
        }
        return ans;
    }
};