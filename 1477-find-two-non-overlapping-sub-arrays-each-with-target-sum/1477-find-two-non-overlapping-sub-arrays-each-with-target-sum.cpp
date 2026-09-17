class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>dp(n,INT_MAX);
        int left=0,currsum=0;
        int minlen=INT_MAX;
        for(int r=0;r<n;r++){
            currsum+=arr[r];
            while (currsum > target) {
                currsum -= arr[left++];
            }
            if(currsum==target){
                int len=r-left+1;
                if(left>0 && dp[left-1]!=INT_MAX){
                    minlen=min(minlen,dp[left-1]+len);
                }
                dp[r]=min(dp[r],len);
            }
            if(r>0){
                dp[r]=min(dp[r-1],dp[r]);
            }
        }
        return minlen==INT_MAX?-1:minlen;
    }
};