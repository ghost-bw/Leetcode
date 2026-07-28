class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>res(candies.size(),false);
        int maxs=INT_MIN;
        for(int i=0;i<candies.size();i++){
            maxs=max(candies[i],maxs);
        }
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=maxs)res[i]=true;
        }
        return res;
    }
};