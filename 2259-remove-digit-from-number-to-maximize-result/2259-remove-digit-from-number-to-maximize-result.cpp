class Solution {
public:
    string removeDigit(string number, char digit) {
        int index=-1;
        string ans="";
        for(int i=0;i<number.length();i++){
            if(number[i]==digit){
                index=i;
                ans=max(ans,number.substr(0,index)+number.substr(index+1,number.length()-index));
            }
        }
        return ans;
    }
};