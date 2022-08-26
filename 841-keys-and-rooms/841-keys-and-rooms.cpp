class Solution {
public:
    
    void dfs(int node, vector<int>adj[], vector<int>&vis){
        vis[node]=1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>nodes(rooms.size(),0);
        
        vector<int>adj[rooms.size()];
        
        for(int i = 0;i<rooms.size();i++){
            for(auto x : rooms[i]){
                adj[i].push_back(x);
            }
        }
        
      dfs(0,adj,nodes);
        
        for(int x : nodes)if(x==0)return false;
        
        return true;
        
    }
};