class Solution {
public:
    using ll = long long;
    void mergeSort(std::vector<int>& nums, int& ans, int l, int r){
        if(l >= r)
            return;

        int mid = std::floor((l+r)/2);
        mergeSort(nums, ans, l, mid);
        mergeSort(nums, ans, mid+1, r);
        merge(nums, ans, l, mid, r);
    }

    void merge(std::vector<int>& nums, int& ans, int l, int mid, int r){
        int j = mid+1;
        for(int i=l; i<=mid; i++){
            while(j<=r && nums[i] > (ll)2*nums[j])
                j++;
            ans += j-mid-1;
        }


        std::vector<int> result;
        int l_start = l, r_start = mid+1;
        while(l_start <= mid && r_start <= r){
            if(nums[l_start] <= nums[r_start])
                result.push_back(nums[l_start++]);
            else
                result.push_back(nums[r_start++]);
        }

        while(l_start <= mid)
            result.push_back(nums[l_start++]);
        while(r_start <= r)
            result.push_back(nums[r_start++]);

        for(int i = l; i <= r; i++)
            nums[i] = result[i - l];
    }

    int reversePairs(std::vector<int>& nums) {
        int ans = 0, n = nums.size();
        mergeSort(nums, ans, 0, n-1);
        return ans;
    }
};