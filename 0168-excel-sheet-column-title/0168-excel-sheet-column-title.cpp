class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber>0){
            columnNumber--;
            int ch=columnNumber%26;
            ans+='A'+ch;
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};