class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0, flip_cnt = 0;
        std::vector<bool> flipped(n, false);
        for(int i=0; i<n; i++){
            if(i >= k){
                if(flipped[i-k])
                    flip_cnt--;
            }
            if((!(flip_cnt%2) && !nums[i]) || (flip_cnt%2 && nums[i])){
                if(i+k > n) return -1;

                flipped[i] = true;
                flip_cnt++;
                cnt++;
            }
        }

        return cnt;
    }
};