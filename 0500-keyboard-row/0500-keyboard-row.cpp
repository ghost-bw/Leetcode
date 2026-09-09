class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string top="qwertyuiopQWERTYUIOP";
        string middle="asdfghjklASDFGHJKL";
        string end="zxcvbnmZXCVBNM";
        vector<string>ans;
        for(string s:words){
            bool search=true;
            for(int i=0;i<s.length();i++){
                if(top.find(s[i])==string::npos)search=false;
            }
            if(search){
                ans.push_back(s);
                continue;
            }
             search=true;
            for(int i=0;i<s.length();i++){
                if(middle.find(s[i])==string::npos)search=false;
            }
            if(search){
                ans.push_back(s);
                continue;
            }
             search=true;
            for(int i=0;i<s.length();i++){
                if(end.find(s[i])==string::npos)search=false;
            }
            if(search){
                ans.push_back(s);
                continue;
            }
        }
        return ans;
    }
};