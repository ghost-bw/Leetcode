class Solution {
public:
    int solve(string &answerKey, int k, char target) {
        int l = 0;
        int targetCount = 0;
        int otherCount = 0;
        int ans = 0;

        for (int r = 0; r < answerKey.size(); r++) {

            if (answerKey[r] == target)
                targetCount++;
            else
                otherCount++;

            while (otherCount > k) {
                if (answerKey[l] == target)
                    targetCount--;
                else
                    otherCount--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey, k, 'T'),
                   solve(answerKey, k, 'F'));
    }
};