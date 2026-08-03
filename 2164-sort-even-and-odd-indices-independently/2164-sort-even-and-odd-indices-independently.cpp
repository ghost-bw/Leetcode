class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odds;
        vector<int> evens;
        for(int i=0;i<nums.size();i++){
            if(i%2==1)odds.push_back(nums[i]);
            else evens.push_back(nums[i]);
        }
        vector<int> ans;
        sort(odds.begin(),odds.end());
        sort(evens.begin(),evens.end());
        reverse(odds.begin(),odds.end());
        int j=0,k=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==1){
                ans.push_back(odds[j]);
                j++;
            }
            else {
                ans.push_back(evens[k]);
                k++;
            }
        }
        return ans;
    }
};