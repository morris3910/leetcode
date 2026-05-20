class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;

        int n = stones.size(), step = 1;
        std::unordered_map<int, int> umap;
        for(int i=0; i<n; i++)
            umap[stones[i]] = i;

        std::vector<std::unordered_set<int>> memo(n);
        memo[1].insert(1);
        for(int i=1; i<n-1; i++){
            if(memo[i].empty()) continue;
            for(int step : memo[i]){
                for(int j=-1; j<2; j++){
                    if(umap.count(stones[i]+step+j))
                        memo[umap[stones[i]+step+j]].insert(step+j);
                }
            }
        }
        return !memo[n-1].empty();
    }
};