class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        if (k == 0) {
            for (int i = 0; i < n; i++) {
                code[i] = 0;
            }
            return code;
        }

        vector<int> ans(n);
        int sum = 0;

        if (k > 0) {
            for (int i = 1; i <= k; i++) {
                sum += code[i % n];
            }

            ans[0] = sum;

            int left = 1;
            int right = (k + 1) % n;

            for (int i = 1; i < n; i++) {
                sum -= code[left];
                sum += code[right];

                ans[i] = sum;

                left = (left + 1) % n;
                right = (right + 1) % n;
            }
        }
        else {
            k = -k;

            int left = n - k;

            for (int i = left; i < n; i++) {
                sum += code[i];
            }

            ans[0] = sum;

            int right = 0;

            for (int i = 1; i < n; i++) {
                sum -= code[left];
                sum += code[right];

                ans[i] = sum;

                left = (left + 1) % n;
                right = (right + 1) % n;
            }
        }

        return ans;
    }
};