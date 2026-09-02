class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<long long >nums(n,1);
        int MOD = 1e9 + 7;
        while(k>0){
            for(int i=1;i<n;i++){
                nums[i]=(nums[i]+nums[i-1])%MOD;
            }
            k--;
        }
        return nums[n-1];
    }
};