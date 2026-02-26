class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        for(auto &num : nums){
            if(seen.count(num))
                return true;
            else
                seen.insert(num);
        }
        return false;
    }
};