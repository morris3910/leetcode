class Solution {
public:
    int split(vector<int>& nums, int max){
        int sum = 0, res = 0;
        for(int i=0; i<nums.size(); i++){
            if(sum + nums[i] > max){
                res++;
                sum = nums[i];
            } else
                sum += nums[i];
        }
        return res+1;
    }

    int splitArray(vector<int>& nums, int k) {
        int ans = INT_MAX, n = nums.size();
        int max = INT_MIN, sum = 0;
        std::vector<int> subs;
        for(int i=0; i<n; i++){
            sum += nums[i];
            max = std::max(max, nums[i]);
        }

        if(k == n) return max;

        int l = max, r = sum;
        while(l <= r){
            int mid = (r-l)/2 + l;
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            int arrs = split(nums, mid);
            if(arrs > k)
                l = mid+1;
            else if(arrs <= k){
                ans = std::min(ans, mid);
                r = mid-1;
            }
        }

        return ans;
    }
};