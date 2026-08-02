class Solution {
public:
    string removeTrailingZeros(string num) {
        int index=-1;
       for(int i=num.length()-1;i>=0;i--){
            if(num[i]=='0')continue;
            else {
                index=i;
                break;}
        }
        return (index==-1)?num:num.substr(0,index+1);
    }
};