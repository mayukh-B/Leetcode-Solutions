class Solution {
public:
    
    bool solve(vector<int>adj[], vector<int> &vis, vector<int>&path , int node ){
            
        vis[node]=1;
        path[node]=1;
        
        for(auto it : adj[node]){
          if(!vis[it]){
              if(solve(adj,vis,path,it))
                  return true;
          }  
           else if(path[it])return true;
        }
        
        
        path[node]=0;
        return false;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        
        int n =prereq.size();
        
        vector<int>vis(numCourses,0);
        vector<int>path(numCourses,0);
        
        vector<int>adj[numCourses];
        
        for(int i=0;i<n;i++){
            int u = prereq[i][0];
            int v = prereq[i][1];
            adj[v].push_back(u);
            
        }
        
            for(int i=0;i<numCourses;i++){
                if(solve(adj,vis,path,i))return false;
            }
        return true;
        
    }
};