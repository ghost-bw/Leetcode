class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,vector<int>> mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }
        for(auto &it:mp){
            int diff=it.second[1]-it.second[0]-1;
            if(diff!=distance[it.first-'a'])return false;
        }
        return true;
    }
};