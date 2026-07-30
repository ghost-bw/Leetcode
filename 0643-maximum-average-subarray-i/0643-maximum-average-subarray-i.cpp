class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0;
        int n=nums.size();
        double sum=0;
        double maxavg=INT_MIN;
        
        for(int r=0;r<n;r++){
           double len=r-l+1;
            if(len>k){
                sum-=nums[l];
                l++;
            }
            sum+=nums[r];
            len=r-l+1;
            double avg=sum/len;
            if(len==k) maxavg=max(maxavg,avg);
           
        }
        return maxavg;
    }
};