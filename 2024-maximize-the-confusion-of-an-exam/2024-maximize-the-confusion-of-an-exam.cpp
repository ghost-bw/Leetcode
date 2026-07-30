class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int countF=0;
        int countT=0;
        int ans=1;
        int j=0;
        for(int i=0;i<n;i++){
            if(answerKey[i]=='T'){
                countT++;
            }else{
                countF++;
            }

            int mini=min(countF,countT);
            while(mini>k){
                if(answerKey[j]=='T'){
                    countT--;
                }else{
                    countF--;
                }
                mini=min(countT,countF);
                j++;
            }
            ans=max(ans,countT+countF);
        }
        return ans;
    }
};