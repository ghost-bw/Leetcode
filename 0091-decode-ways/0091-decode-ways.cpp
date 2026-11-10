
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int a = 1, b = 0;

        for (int i = 1; i <= n; i++) {
            int c = 0;

            if (s[i - 1] != '0')
                c += a;

            if (i >= 2) {
                int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

                if (num >= 10 && num <= 26)
                    c += b;
            }

            b = a;
            a = c;
        }

        return a;
    }
};
