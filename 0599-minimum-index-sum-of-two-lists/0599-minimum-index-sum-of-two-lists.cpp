class Solution {
public:
    int sum(vector<int> &nums){
        return nums[0]+nums[1];
    }
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,vector<int>> mp;
        vector<string> ans;
        for(int i=0;i<list1.size();i++){
            mp[list1[i]].push_back(i);
        }
        for(int i=0;i<list2.size();i++){
            mp[list2[i]].push_back(i);
        }
        int mn=INT_MAX;
        for(auto &it: mp){
            if(it.second.size()==2){
                mn=min(mn,sum(it.second));
            }
        }
        for(auto &it: mp){
            if(it.second.size()==2 && sum(it.second)==mn){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};