class Solution {
public:
    string removeStars(string s) {
        int stars=0;
        string ans="";
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='*'){
                stars++;
            }else if(stars>0){
                stars--;
            }else{
                ans+=s[i];
            }
        }
            reverse(ans.begin(),ans.end());
            return ans;
        
    }
};