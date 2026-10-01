class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int count=0;
        string s=to_string(num);
        
        for(int i=0;i+k<=s.length();i++){
            int high=i+k-1;
            int n=stoi(s.substr(i,k));
            if( n!=0 && num%n==0)count++;
        }
        return count;
    }
};