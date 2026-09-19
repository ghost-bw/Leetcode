class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total=0;
        int diff=0;
        int tank=0;
        int ans=0;
        for(int i=0;i<n;i++){
            diff=gas[i]-cost[i];
            total+=diff;
            tank+=diff;
            if(tank<0){
                ans=i+1;
                tank=0;
            }
        }
        return (total>=0)?ans:-1;
    }
};