class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }else{
                st.pop();
            }
        }
        string res="";
        while(!st.empty()){
            char top=st.top();
            st.pop();
            res+=top;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};