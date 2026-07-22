class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftsum;
        vector<int> rightsum;
        vector<int> ans;
        int ls=0, rs=0;
        
        for(int i=n-1;i>=0;i--){
            rightsum.push_back(rs);
            rs+=nums[i];
        }
        reverse(rightsum.begin(),rightsum.end());
        for(int i=0;i<n;i++){
            leftsum.push_back(ls);
            ls+=nums[i];
        }
        for(int i=0;i<n;i++){
            int res=abs(leftsum[i]-rightsum[i]);
            ans.push_back(res);
        }
        return ans;
    }
};