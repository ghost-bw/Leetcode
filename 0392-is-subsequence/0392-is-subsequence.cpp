class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.empty())return true;
        int i=0;
        int j=0;
        while(i<t.length() && j<s.length()){
            if(s[j]==t[i]){
                j++;
            }
            i++;
        }
        return (j==s.length());
    }
};