class Solution {
public:
    
    struct node{
        int x,y;
        
        node(int _x, int _y ){
            x=_x;
            y=_y;
        }
    };
    
    void solve(int I, int J, vector<vector<char>> &grid){
        
        queue<node>q;
        grid[I][J]='2';
        q.push(node(I,J));
        
        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            q.pop();
            int dx[4]= {1,-1,0,0};
            int dy[4]= {0,0,1,-1};
            
            for(int i=0;i<4;i++){
                int newx = dx[i]+x;
                int newy =dy[i]+y;
                
                if(newx>=0 and newx<grid.size() and newy >=0 and newy < grid[0].size() and grid[newx][newy]=='1'){
                    q.push(node(newx,newy));
                    grid[newx][newy]='2';
                }
            }
        }
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        
     queue<node>q;
        
     int n = grid.size();
     int m = grid[0].size();
     int count =0;
        
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(grid[i][j] == '1'){
                solve(i,j,grid);
                 count++;
             }
         }
     }
        
        return count;
    }
};