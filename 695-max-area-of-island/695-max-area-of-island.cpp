class Solution {
    private:
    int bfs(vector<vector<int>>&grid, int I, int J){
            
        grid[I][J]=0;
        int n = grid.size();
        int m=grid[0].size();
        
        int count=1;
        queue<pair<int,int>>q;
        
        q.push({I,J});
        int dx[4] ={1,-1,0,0};
        int dy[4] ={0,0,1,-1};
        
        while(!q.empty()){
            int nr = q.front().first;
            int nc = q.front().second;
            
            q.pop();
            
            for(int i=0;i<4;i++){
                int newI = nr+dx[i];
                int newJ= nc+dy[i];
                
                if(newI>=0 && newI<n && newJ>=0 && newJ<m && grid[newI][newJ]==1){
                    q.push({newI,newJ});
                    count++;
                    grid[newI][newJ]=0;
                }
            }
        }
        
        return count;
        
    }
public:
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        int m = grid[0].size();
        
    
        
        int count=0, maxCount=0;
        
        
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count = bfs(grid,i,j);
                    maxCount= max(count,maxCount);
                }
            }
        }
        
      return maxCount;  
    }
};