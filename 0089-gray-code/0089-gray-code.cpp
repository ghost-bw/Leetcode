class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(pow(2,n));
        for(int i=0;i<ans.size();i++){
            ans[i]=i^(i>>1);
        }
        return ans;
    }
};