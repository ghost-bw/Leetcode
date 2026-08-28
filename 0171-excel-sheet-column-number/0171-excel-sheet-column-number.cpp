class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long pow=1;
        int ans=0;
        for(int i=columnTitle.length()-1;i>=0;i--){
            ans+=(columnTitle[i]-'A'+1)*pow;
            pow*=26;
        }
        return ans;
    }
};