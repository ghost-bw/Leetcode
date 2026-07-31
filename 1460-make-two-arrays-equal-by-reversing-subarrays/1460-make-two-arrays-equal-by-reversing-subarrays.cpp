class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=arr.size();
        int sum1=0,sum2=0;
        sort(arr.begin(),arr.end());
        sort(target.begin(),target.end());
        if(arr!=target)return false;
        for(int i=0;i<n;i++){
            sum1+=target[i];
            sum2+=arr[i];
        }
        if(sum1!=sum2)return false;
        return true;
    }
};