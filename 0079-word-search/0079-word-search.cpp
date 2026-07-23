class Solution {
public:
    bool dfs(int row,int col,int idx,vector<vector<char>>& board,string word,vector<vector<bool>> &vis){
        if(idx==word.length()-1) return true;
        vis[row][col]=true;
        int r=board.size();
        int c=board[0].size();
        int nr[]={0,-1,0,1};
        int nc[]={1,0,-1,0};
        for(int i=0;i<4;i++){
            int newr=row+nr[i];
            int newc=col+nc[i];
            if(newr>=0 && newr<r && newc>=0 && newc<c && !vis[newr][newc] && board[newr][newc]==word[idx+1]){
                if(dfs(newr,newc,idx+1,board,word,vis)) return true;
            }
        }
        vis[row][col]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0] && dfs(i,j,0,board,word,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};