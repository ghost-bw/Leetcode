class Solution {
public:
    int findPoisonedDuration(vector<int>& num, int duration) {
        int n=num.size();
        int sum=0;
        for(int i=0;i<n-1;i++){
            int diff=num[i+1]-num[i];
            if(diff<duration){
                sum+=num[i+1]-num[i];
            }else{
                sum+=duration;
            }
        }
        sum+=duration;
        return sum;
    }
};