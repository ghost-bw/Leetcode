class Solution {
public:
    const int MOD=1e9+7;
    int numberOfSets(int n, int k) {
        vector<long long>dp(n+1,1);
        for(int j=1;j<=k;j++){
            vector<long long>next(n+1,0);
            long long prefix=0;
            for(int i=1;i<=n;i++){
                next[i]=next[i-1];
                next[i]=(next[i]+prefix)%MOD;
                prefix=(prefix+dp[i])%MOD;
            }
            dp=move(next);
        }
        return dp[n];
    }
};