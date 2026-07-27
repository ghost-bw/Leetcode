class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs.back();
        int i=0;
        while(i<first.length()){
            if(first[i]==last[i])res+=first[i];
            else break;
            i++;
        }
        return res;
    }
};