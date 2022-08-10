class Solution {
public:
    

    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(source == destination)return true;
        vector<int>vis(n,0);
        vector<int>adj[n];
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        vis[source]=1;

        queue<int>q; 
        q.push(source);
        
        while(!q.empty()){
            int s = q.front();
            q.pop();
            
            for(auto it : adj[s]){
                if(it == destination)return true;
                
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        
        return false;
    }
};