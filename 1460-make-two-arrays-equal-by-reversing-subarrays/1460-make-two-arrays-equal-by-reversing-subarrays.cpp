class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        sort(target.begin(),target.end());
        if(arr!=target)return false;

        return true;
    }
};