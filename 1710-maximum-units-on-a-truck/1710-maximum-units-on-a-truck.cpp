class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](auto &a,auto &b){
            return a[1]>b[1];
        });
        int sum=0;
        for(int i=0;i<boxTypes.size();i++){
            if(truckSize>=boxTypes[i][0]){
                sum+=boxTypes[i][0]*boxTypes[i][1];
                truckSize=truckSize-boxTypes[i][0];
            }else{
                sum+=truckSize*boxTypes[i][1];
                break;
            }
        }
        return sum;
    }
};