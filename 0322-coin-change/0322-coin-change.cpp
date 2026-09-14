class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // Use INT_MAX - 1 as a placeholder for infinity to prevent addition overflow
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        
        // Base Case 1: If amount is > 0 and we have 0 coins, it's impossible
        for(int j = 0; j <= amount; j++) dp[0][j] = INT_MAX - 1;
        
        // Base Case 2: If amount is 0, we need exactly 0 coins
        for(int i = 1; i <= n; i++) dp[i][0] = 0;
        
        // Base Case 3: Initialize the first row (using only coins[0])
        for(int j = 1; j <= amount; j++){
            if(j % coins[0] == 0){
                dp[1][j] = j / coins[0];
            } else {
                dp[1][j] = INT_MAX - 1;
            }
        }
        
        // Build the rest of the table
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                if(coins[i - 1] <= j){ // Fixed to <= to catch exact matches
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        // If the answer is still our infinity placeholder, return -1
        return dp[n][amount] >= INT_MAX - 1 ? -1 : dp[n][amount];
    }
};
