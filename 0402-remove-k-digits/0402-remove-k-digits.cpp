class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        if(k==0)return num;
        if(num.length()==1 && k==1)return "0";

        st.push(num[0]-'0');
        for(int i=1;i<num.length();i++){
            int ch=num[i]-'0';
            
            while(!st.empty() && k>0 && st.top()>ch){   
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans+=to_string(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        while (i < ans.size() && ans[i] == '0')
            i++;

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};