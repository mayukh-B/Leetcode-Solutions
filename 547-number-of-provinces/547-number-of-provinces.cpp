class Solution {
public:
    
    void dfs(int node, vector<int>&vis, vector<int>adj[] ){
        vis[node]=1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }
    
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<int>adj[isConnected.size()];
        
        for(int i=0;i<isConnected.size();i++){
            for(int j =0;j<isConnected.size();j++){
                if(isConnected[i][j]==1 and i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        
        
        
            vector<int>vis(isConnected.size()+1,0);
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }
        
        
        return count;
        
    }
};