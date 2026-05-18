class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = -1, r = -1;
        int min = INT_MAX, max = INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i] < max)
                r = i;
            max = std::max(max, nums[i]);
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i] > min)
                l = i;
            min = std::min(min, nums[i]);
        }

        return l == -1 ? 0 : r-l+1;
    }
};