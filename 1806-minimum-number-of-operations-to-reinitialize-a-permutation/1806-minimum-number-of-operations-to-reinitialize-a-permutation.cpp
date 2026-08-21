class Solution {
public:
    int reinitializePermutation(int n) {
        int pos = 1;
        int ans = 0;

        do {
            if (pos < n / 2)
                pos = pos * 2;
            else
                pos = (pos - n / 2) * 2 + 1;

            ans++;
        } while (pos != 1);

        return ans;

    }
};