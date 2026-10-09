class Solution {
public:
    bool search(vector<int>& nums,int target){
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return true;
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return false;
    }
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAlice=accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        int sumBob=accumulate(bobSizes.begin(),bobSizes.end(),0);
        int target=(sumBob-sumAlice)/2;
        sort(bobSizes.begin(),bobSizes.end());
        vector<int>ans(2);
        for(int i=0;i<aliceSizes.size();i++){
            int item=aliceSizes[i]+target;
            if(search(bobSizes,item)){
                ans[0]=aliceSizes[i];
                ans[1]=item;
                break;
            }
        }
        return ans;
    }
};