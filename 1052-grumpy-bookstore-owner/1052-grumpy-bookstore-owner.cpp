class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int satisfied=0;
        int extra=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0)satisfied+=customers[i];
        }
        int l=0;
        int maxextras=0;
        for(int r=0;r<n;r++){
            int len=r-l+1;
            if(len>minutes){
                if(grumpy[l]==1)extra-=customers[l];
                l++;
            }
            len=r-l+1;
            if(grumpy[r]==1)extra+=customers[r];
            maxextras=max(maxextras,extra);
        }
        return maxextras+satisfied;
    }
};