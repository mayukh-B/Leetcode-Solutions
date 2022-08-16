class Solution {
  
    struct node{
        int x,y,time;
        
        node(int _x, int _y, int _time){
            x=_x;
            y=_y;
            time=_time;
        }
    };

public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        
         queue<node>q;
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push(node(i,j,0));
                if(grid[i][j]!=0)count++;
            }
        }
        
        int cnt =0,ans=0;
        while(!q.empty()){
            int x_cor = q.front().x;
            int y_cor= q.front().y;
            int time = q.front().time;
            q.pop();
            
            int dx[4]= {1,-1,0,0};
            int dy[4]= {0,0,1,-1};
            
            cnt++;
            
            ans = max(ans, time);
            
            for(int i =0; i<4 ;i++){
                int newX = dx[i]+x_cor;
                int newY = dy[i]+y_cor;
                
                if(newX>=0 and newX<n and newY>=0 and newY<m and grid[newX][newY]==1){
                    q.push(node(newX,newY,time+1));
                grid[newX][newY]=2;
                }
                
            }
        }
        
        
        if(cnt == count)
        return ans;
        
        return -1;
    }
};