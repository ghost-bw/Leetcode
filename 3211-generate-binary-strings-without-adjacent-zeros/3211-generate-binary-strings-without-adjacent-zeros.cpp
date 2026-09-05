class Solution {
public:
    void generate(int n,string s,vector<string> &result){
        if(s.length()==n){
            result.push_back(s);
            return;
        }
        generate(n,s+"1",result);
        if(s.empty() || s.back()!='0'){
            generate(n,s+"0",result);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> result;
        generate(n,"",result);
        return result;
    }
};