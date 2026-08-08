class Solution {
public:
    int numSub(string s) {
        
        long long ones=0;
        long long ans=0;
        for(char c: s){
            if(c=='1'){
                ones++;
                ans+=ones;
            }else{
                ones=0;
            }
        }
        return ans%1000000007;

    }
};