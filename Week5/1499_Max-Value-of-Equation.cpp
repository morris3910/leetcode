class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size(), ans = INT_MIN;
        std::deque<int> dq;
        for(int i=0; i<n; i++){
            while(!dq.empty() && points[i][0] - points[dq.front()][0] > k)
                dq.pop_front();
            if(!dq.empty())
                ans = std::max(ans, points[dq.front()][1] - points[dq.front()][0] + points[i][0] + points[i][1]);

            while(!dq.empty() && points[dq.back()][1] - points[dq.back()][0] <= points[i][1] - points[i][0])
                dq.pop_back();
            dq.push_back(i);
        }
        return ans;
    }
};