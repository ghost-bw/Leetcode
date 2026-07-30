class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l=0;
        int n=arr.size();
        int count=0;
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
            
        }
        if(sum>=threshold*k)count++;
        for(int r=k;r<n;r++){
            sum-=arr[l];
            l++;
            sum+=arr[r];
            if(sum>=threshold*k)count++;
        }
        return count;
    }
};