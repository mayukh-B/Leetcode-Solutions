class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n= image.size();
        int m= image[n-1].size();
        
        vector<vector<int>>arr = image;
        queue<pair<int,int>>q;
        
        q.push({sr,sc});
         char ch = arr[sr][sc];
        
        while(!q.empty()){
            
            int r = q.front().first;
            int c = q.front().second;
            
            arr[r][c]=color;
            q.pop();
           
            int dx[4]={-1, 0, 1, 0};
            int dy[4]={0, 1, 0, -1};
            
            for(int i=0;i<4;i++){
                int nrow = r+dx[i];
                int ncol = c+dy[i];
                
                if(nrow>=0 && nrow< n && ncol>=0 && ncol<m && ch == arr[nrow][ncol] && arr[nrow][ncol]!=color){
                    q.push({nrow,ncol});
                    arr[nrow][ncol]=color;
                }
            }
        }
        
        return arr;
        
        
    }
};