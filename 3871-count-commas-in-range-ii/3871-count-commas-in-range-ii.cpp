class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        if(n>=1e3 && n<1e6){
            return (n-1e3+1)*1;
        }else if(n>=1e6 && n<1e9){
            return (n-1e6+1)*2+(1e6-1e3)*1;
        }else if(n>=1e9 && n<1e12){
            return (n-1e9+1)*3+(1e9-1e6)*2+(1e6-1e3)*1;
        }else if(n>=1e12 && n<1e15){
            return (n-1e12+1)*4+(1e6-1e3)*1+(1e9-1e6)*2+(1e12-1e9)*3;
        }else{
            return (1e15-1e12)*4+(1e6-1e3)*1+(1e9-1e6)*2+(1e12-1e9)*3+5;
        };
    }
};