class Solution {
public:
    using ll = long long;
    int minimumPairRemoval(vector<int>& nums) {
        int sorted = 0, n = nums.size();
        std::priority_queue<pair<ll, int>, std::vector<pair<ll, int>>, greater<>> pq;

        for(int i=1; i<n; i++){
            if(nums[i] >= nums[i-1])
                sorted++;
            pq.emplace(nums[i] + nums[i-1], i-1);   
        }

        if(sorted == n-1)
            return 0;

        std::vector<bool> remove(n, false);
        std::vector<int> prev(n), next(n);
        std::vector<ll> arr(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            prev[i] = i-1;
            next[i] = i+1;
        }

        int remain = n; //remain nums
        while(remain > 1){
            auto [sum, left] = pq.top();
            pq.pop();
            int right = next[left];

            if(right >= n || remove[left] || remove[right] || arr[left]+arr[right] != sum)
                continue;
            
            if(arr[left] <= arr[right])
                sorted--;
            if(prev[left] != -1 && arr[prev[left]] <= arr[left])
                sorted--;
            if(next[right] != n && arr[right] <= arr[next[right]])
                sorted--;

            arr[left] += arr[right];
            remove[right] = true;
            remain--;

            if(prev[left] != -1){
                pq.emplace(arr[prev[left]]+arr[left], prev[left]);
                if(arr[prev[left]] <= arr[left])
                    sorted++;
            }

            if(next[right] == n){
                next[left] = n;
            }
            else{
                next[left] = next[right];
                prev[next[right]] = left;
                pq.emplace(arr[left]+arr[next[right]], left);
                if(arr[left] <= arr[next[right]])
                    sorted++;
            }

            if(sorted == remain-1)
                return n-remain;
        }

        return n-1;
    }
};
