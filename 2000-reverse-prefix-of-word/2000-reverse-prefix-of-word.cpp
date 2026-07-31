class Solution {
public:
    string reversePrefix(string s, char ch) {
        int n=s.length();
        int left=0;
        int right=-1;
        for(int i=0;i<n;i++){
            if(s[i]==ch){
                right=i;
                break;
            }
        }
        if(right==-1) return s;
        while(left<right){
            swap(s[left++],s[right--]);
        }
        return s;
    }
};