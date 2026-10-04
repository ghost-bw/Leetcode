class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int count=0;
        int start=INT_MAX;
        vector<vector<int>>ans;
        for(int i=0;i<s.length();i++){
            if(s[i]==s[i+1]){
                count++;
                start=min(start,i);
            }
            else {
                int end=i;
                if(count>=2){
                    ans.push_back({start,end});
                }
                count=0;
                start=INT_MAX;
            }
        }
        return ans;
    }
};