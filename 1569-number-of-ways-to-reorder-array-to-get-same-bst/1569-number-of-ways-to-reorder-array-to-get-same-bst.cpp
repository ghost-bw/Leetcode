class Solution {
public:
    int MOD=1e9+7;
    vector<vector<long long>>table;
    void ncr(int n){
        table.assign(n + 1, vector<long long>(n + 1, 1));
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                table[i][j]=(table[i-1][j]+table[i-1][j-1])%MOD;
            }
        }
    }
    long long solve(const vector<int>& arr){
        vector<int>left,right;
        int n=arr.size();
        if (n <= 2) return 1;
        int root=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]<root)left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }
        long long x=solve(left);
        long long y=solve(right);
        long long z=table[n-1][left.size()];
        return (((x*y)%MOD)*z)%MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        ncr(n);
        long long ans= solve(nums)%MOD;
        return ((ans-1)+MOD)%MOD;
    }
};