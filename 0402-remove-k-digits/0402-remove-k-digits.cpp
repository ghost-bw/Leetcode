class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for (char c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        if (k > 0)
            st.erase(st.size() - k);

        int i = 0;
        while (i < st.size() && st[i] == '0')
            i++;

        return i == st.size() ? "0" : st.substr(i);
    }
};