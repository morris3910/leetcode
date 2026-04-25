class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, oldFar = 0, newFar = 0;
        for(int i=0; i<n-1; i++){
            if(i + nums[i] > newFar)
                newFar = i+nums[i];
            if(i == oldFar){
                oldFar = newFar;
                ans++;
            }
        }
        return ans;
    }
};