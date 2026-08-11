class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int check[26]={0};
        for(int i=0;i<s.length();i++){
            if(check[s[i]-'a']!=-1){
                check[s[i]-'a']=abs(check[s[i]-'a']-i);
            }
            if(check[t[i]-'a']!=-1){
                check[t[i]-'a']=abs(check[t[i]-'a']-i);
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=check[i];
        }
        return ans;
    }
};