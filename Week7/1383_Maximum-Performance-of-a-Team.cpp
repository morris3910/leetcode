class Solution {
public:
    const int MOD = 1e9 + 7;
    using pii = std::pair<int, int>;
    using ll = long long;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        std::vector<pii> v;
        for(int i=0; i<n; i++)
            v.push_back({efficiency[i], speed[i]});
        std::sort(v.begin(), v.end(), std::greater<pii>());

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        ll totalSpeed = 0, ans = 0;
        for(int i=0; i<n; i++){
            int curSpeed = v[i].second, curEff = v[i].first;
            if(pq.size() == k){
                totalSpeed -= pq.top();
                pq.pop();
            }
            pq.push(curSpeed);
            totalSpeed += curSpeed;
            ans = std::max(ans, totalSpeed * curEff);
        }
        return ans % MOD;
    }
};