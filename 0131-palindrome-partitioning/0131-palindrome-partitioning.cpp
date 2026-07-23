class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        fun(0,s,path,res);
        return res;
    }
    void fun(int idx,string s, vector<string> &path,vector<vector<string>> &res){
        if(idx==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(ispal(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                fun(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
    bool ispal(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
};