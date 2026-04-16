class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = l + (r-l) / 2;
            if(nums[mid] > nums[r])
                l = mid+1;
            else if(nums[mid] < nums[r])
                r = mid;
            else{
                if(l == mid) return nums[l];

                for(int i=mid; i<=r; i++){
                    if(nums[i] < nums[mid])
                        l = mid + 1;
                }
                if(l != mid + 1)
                    r = mid;
            }
        }
        return nums[l];
    }
};