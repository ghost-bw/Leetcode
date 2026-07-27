class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int res=INT_MIN;
        int product=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                product=((nums[i]-1)*(nums[j]-1));
                res=max(res,product);
            }
            
        }
        return res;
    }
};