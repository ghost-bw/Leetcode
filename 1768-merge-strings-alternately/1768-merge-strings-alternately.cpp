class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len=min(word1.length(),word2.length());
        string ans="";
        for(int i=0;i<len;i++){
            ans+=word1[i];
            ans+=word2[i];
        }
        if(word1.length()>word2.length()){
            for(int i=len;i<word1.length();i++){
                ans+=word1[i];
            }
        }else{
            for(int i=len;i<word2.length();i++){
                ans+=word2[i];
            }
        }
        return ans;
    }
};