class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        vector<int> res;
        vector<pair<int, int>> vec(freq.begin(), freq.end());

        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            if(a.second==b.second) {
               return a.first>b.first;}
            return a.second < b.second;
        });
        for(auto &it: vec){
            while(it.second!=0){
                res.push_back(it.first);
                it.second--;
            }
            
        }
        return res;
    }
};