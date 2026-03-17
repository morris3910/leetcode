class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        std::nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        
        auto newindex = [&](int i){
            return (1+2*i)%(n|1);
        };

        int median = nums[n/2];
        int left = 0, right = n-1, i = 0;
        while(i <= right){
            if(nums[newindex(i)] > median){
                std::swap(nums[newindex(i)], nums[newindex(left)]);
                i++;
                left++;
            }
            else if(nums[newindex(i)] < median){
                std::swap(nums[newindex(i)], nums[newindex(right)]);
                right--;
            }
            else
                i++;
        }

    }
};