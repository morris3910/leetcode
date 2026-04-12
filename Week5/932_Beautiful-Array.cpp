class Solution {
public:
    unordered_map<int, std::vector<int>> ans;
    vector<int> beautifulArray(int n) {
        if(ans.count(n)) return ans[n];
        if(n == 1) return {1};
        else if(n == 2) return {1, 2};

        std::vector<int> res;
        res.reserve(n);

        for(auto n : beautifulArray((n+1)/2))
            res.push_back(2*n - 1);
        for(auto n : beautifulArray(n/2))
            res.push_back(2*n);

        ans[n] = res;
        return res;
    }
};