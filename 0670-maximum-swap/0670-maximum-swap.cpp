class Solution {
public:
    int maximumSwap(int num) {
        string str=to_string(num);
        int l=0;
        int ans=num;
        for(int i=0;i<str.length();i++){
            for(int j=i+1;j<str.length();j++){
                if(str[i]<str[j]){
                    swap(str[i],str[j]);
                    ans=max(ans,stoi(str));
                    swap(str[i],str[j]);
                }
            }
        }
        return ans;
    }
};