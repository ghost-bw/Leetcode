class Solution {
public:
    int hammingWeight(int n) {
        if(n==0) return 0;
        string res="";
        while(n){
            res+=(n&1)+'0';
            n=n>>1;
        }
        reverse(res.begin(),res.end());
        int count=0;
        for(int i=0;i<res.length();i++){
            if(res[i]=='1')count++;
        }
        return count;
    }
};