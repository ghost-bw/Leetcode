class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        int n=s.length();
        string ans="";
        int start,end;
        for(int i=0;i<n;i++){
            if(st.empty()){
                start=i;
            }
            if(s[i]=='(')st.push(s[i]);
            else st.pop();
            if(st.empty()){
                end=i;
                int len=end-start-1;
                ans+=s.substr(start+1,len);
            }
            
        }
        return ans;
    }
};