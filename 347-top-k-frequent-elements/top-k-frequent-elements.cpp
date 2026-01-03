class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int x : nums){
        freq[x]++;
        }
        vector<int> result;
        for(int i=0;i<k;i++){
        int maxFreq = 0;
        int element = 0;
        for(auto it: freq){
            if(it.second > maxFreq){
                maxFreq = it.second;
                element = it.first;
            }
        }
        result.push_back(element);
        freq.erase(element);
        }
        return result;
    }
};