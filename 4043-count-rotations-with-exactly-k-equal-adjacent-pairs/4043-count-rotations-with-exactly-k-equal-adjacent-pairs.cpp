class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            int score=0;
            int l=0;int r=l+1;
            while(r<n){
                if(s[l++]==s[r++])score++;
            }
            if(score==k)ans++;
            char first=s[0];
            s.erase(0,1);
            s+=first;
        }
        return ans;
    }
};