class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        int m=s.length();
        
        vector<vector<int>> dp(m+1,vector<int>(m+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==rev[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][m];
    }
};