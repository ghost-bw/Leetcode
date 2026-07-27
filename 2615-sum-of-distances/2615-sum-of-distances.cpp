
class Solution {
public:
    typedef long long ll;
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,ll> indexsum;
        unordered_map<int,ll> indexcount;
        vector<ll> arr(nums.size(),0);
        //left to right
        for(int i=0;i<nums.size();i++){
            ll sum=indexsum[nums[i]];
            ll freq=indexcount[nums[i]];
            arr[i]+=freq*i-sum;
            indexcount[nums[i]]++;
            indexsum[nums[i]]+=i;
        }
        indexcount.clear();
        indexsum.clear();
        for(int i=nums.size()-1;i>=0;i--){
            ll sum=indexsum[nums[i]];
            ll freq=indexcount[nums[i]];
            arr[i]+=sum-freq*i;
            indexcount[nums[i]]++;
            indexsum[nums[i]]+=i;
        }
        return arr;
    }
};
