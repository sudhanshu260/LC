class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for(const int n:nums){
        if(us.count(n))
        return true;
        us.insert(n);
        }
        return false;
    }
};