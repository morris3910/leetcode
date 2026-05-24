class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), ans;
        if(n == 1) return 0;

        int prev = 0, sum = 0;
        for(int i=0; i<n; i++){
            prev += i*nums[i];
            sum += nums[i];
        }
        ans = prev;

        for(int i=n-1; i>0; i--){
            int res = prev + sum - n*nums[i];
            ans = std::max(ans, res);
            prev = res;
        }

        return ans;
    }
};