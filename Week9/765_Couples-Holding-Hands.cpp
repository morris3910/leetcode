class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int s = row.size(), ans = 0;
        for(int i=0; i<s-2; i+=2){
            if(row[i] / 2 != row[i+1] / 2){
                int j = i+2;
                while(j < s-1 && row[j]/2 != row[i]/2)
                    j++;
                std::swap(row[i+1], row[j]);
                ans++;
            }
        }
        return ans;
    }
};