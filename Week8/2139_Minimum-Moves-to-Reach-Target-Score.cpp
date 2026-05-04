class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while(maxDoubles > 0){
            if(target == 1)
                return ans;

            if(!(target%2)){
                target /= 2;
                maxDoubles--;
            }else
                target -= 1;

            ans++;
        }
        return ans + target - 1;
    }
};