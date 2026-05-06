class Solution {
public:
    using ll = long long;
    long long minimumReplacement(vector<int>& nums) {
        int s = nums.size();
        ll ans = 0;
        for(int i=s-2; i>=0; i--){
            int next = nums[i+1];
            if(nums[i] > next){
                ll times = nums[i] / next;
                if(nums[i] % next) times++;
                nums[i] /= times;
                ans += (times-1);
            }
        }
        return ans;
    }
};