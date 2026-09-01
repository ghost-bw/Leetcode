class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        vector<int>order(26,0);
        int val=26;
        for(int i=0;i<26;i++){
            order[i]=val;
            val--;
        }
        for(int i=0;i<s.length();i++){
            ans+=order[s[i]-'a']*(i+1);
        }
        return ans;
    }
};