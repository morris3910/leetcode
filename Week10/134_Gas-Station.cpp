class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_gas = 0, total_cost = 0;
        int curgas = 0, ans = 0;
        for(int i=0; i<n; i++){
            total_gas += gas[i];
            total_cost += cost[i];
            
            curgas += gas[i];
            curgas -= cost[i];
            if(curgas < 0){
                curgas = 0;
                ans = i+1;
            }
        }
        return total_gas < total_cost ? -1 : ans;
    }
};