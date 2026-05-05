class Solution {
public:
    using pii = std::pair<int, int>;
    int scheduleCourse(vector<vector<int>>& courses) {
        int day = 0;
        std::sort(courses.begin(), courses.end(), [](const std::vector<int> &a, const std::vector<int> &b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        std::priority_queue<int> pq;
        for(auto &course : courses){
            if(course[0] > course[1]) continue;

            if(day + course[0] <= course[1]){
                day += course[0];
                pq.push(course[0]);
            }else{
                if(course[0] < pq.top()){
                    day -= pq.top();
                    pq.pop();
                    day += course[0];
                    pq.push(course[0]);
                }
            }
        }
        
        return pq.size();
    }
};