class Solution {
public:

    string findLine(int i, int j, int ebs, int es, vector<string>& words,int maxWidth){
        string line;
        for(int k=i;k<j;k++){
            line+=words[k];
            if(k==j-1) continue;
            for(int z=1;z<=ebs;z++){
                line+=" ";
            }
            if(es>0){
                line+=" ";
                es--;
            }
        }
        while(line.length()<maxWidth){
            line+=" ";
        }
        return line;

    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n=words.size();
        
        int i=0;
        while(i<n){
            int lc=words[i].length();
            int j=i+1;
            int blanks=0;
            while(j<n && words[j].length()+1+blanks+lc<=maxWidth){
                lc+=words[j].length();
                blanks+=1;
                j++;
            }
            int rs=maxWidth-lc;
            int ebs=blanks==0?0:rs/blanks;
            int es=blanks==0?0:rs%blanks;

            if(j==n){
                ebs=1;
                es=0;
            }
            res.push_back(findLine(i,j,ebs,es,words,maxWidth));
            i=j;
        }
        return res;
    }
};