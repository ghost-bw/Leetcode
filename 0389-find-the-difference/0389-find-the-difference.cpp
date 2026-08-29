class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        int n=t.length();
        for(int i=0;i<n;i++){
            mp[t[i]]++;
            if(i<n-1)mp[s[i]]--;
        }
        for(auto it:mp){
            if(it.second==1)return it.first;
        }
        return ' ';
    }
};