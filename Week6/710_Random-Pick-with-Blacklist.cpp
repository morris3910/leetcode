class Solution {
public:
    int validRange;
    unordered_set<int> uset;
    unordered_map<int, int> umap;
    Solution(int n, vector<int>& blacklist) {
        validRange = n - blacklist.size();
        for(auto x : blacklist){
            uset.insert(x);
        }
        int valid = n-1;
        for(int b : blacklist){
            if(b < validRange){
                while(uset.count(valid))
                    valid--;
                umap[b] = valid--;
            }
        }
        
    }
    
    int pick() {
        int res = rand() % validRange;
        return uset.count(res) ? umap[res] : res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */