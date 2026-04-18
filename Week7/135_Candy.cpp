class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans = 0;
        std::vector<int> childs(n, 1);
        for(int i=0; i<n; i++){
            if(i && ratings[i-1] < ratings[i])
                childs[i] = childs[i-1] + 1;
        }
        for(int i=n-1; i>=0; i--){
            if(i != n-1 && ratings[i] > ratings[i+1])
                childs[i] = std::max(childs[i], childs[i+1] + 1);
        }
        for(int c : childs)
            ans += c;
        return ans;
    }
};