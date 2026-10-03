class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[101] = {};
        
        for(int x : nums)
            cnt[x]++;
        
        for(int i = 1; i <= 100; i++){
            cnt[i] += cnt[i - 1];
            if(cnt[i]==nums.size())break;
        }
        
        for(int &x : nums)
            x = x == 0 ? 0 : cnt[x - 1];
        
        return nums;
    }
};