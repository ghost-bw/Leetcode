class Solution {
public:
    int solve(string s,string t,int m,int n,vector<vector<int>> &dp){
        if(n==0 || m==0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        if(s[m-1]==t[n-1]){
            return dp[m][n]=1+solve(s,t,m-1,n-1,dp);
        }else{
            return dp[m][n]=max(solve(s,t,m-1,n,dp),solve(s,t,m,n-1,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int m=text1.length();
        int n=text2.length();
        // vector<vector<int>> dp(n+1);
        // for(int i=0;i<=n;i++){
        //     vector<int> t(m+1);
        //     dp[i]=t;
        // }
        // for(int i=0;i<n;i++) dp[i][m]=0;
        // for(int j=0;j<m;j++) dp[n][j]=0;
        // for(int i=n-1;i>=0;i--){
        //     for(int j=m-1;j>=0;j--){
                
        //         if(text1[i]==text2[j]){
        //             dp[i][j]=1+dp[i+1][j+1];
        //         }else{
        //             dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        //         }
        //     }
        // }
        // return dp[0][0];
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};