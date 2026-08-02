class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        for(string s:words){
            if(s.length()==1)return s;
            int left=0;
            int right=s.length()-1;
            bool flag=false;
            while(left<right){
                if(s[left]!=s[right]){
                    flag=false;
                    break;}
                else flag=true;
                left++;
                right--;
            }
            if(flag) return s;
        }
        return "";
    }
};