class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        
        if(i<0 || i>= board.size() || j<0 || j>=board[0].size() || board[i][j]!='O')return;
        
        board[i][j]='Y';
        
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
        return;
        
    }
    

    
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        if(n==0)return;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i == n-1 || j==0 || j==m-1){
                    dfs(board, i, j); // 0,0
                }
            }
        }
        
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(board[i][j]=='O')board[i][j]='X';
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((board[i][j]=='Y') )board[i][j]='O';
            }
        }
    
        
    }
};