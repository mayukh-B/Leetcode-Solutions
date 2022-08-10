class Solution {
public:
    
  
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        vector<int>adj[numCourses];
        
        for(int i = 0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        
        queue<int>q;
        
        vector<int>indegree(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        
      for(int i=0;i<numCourses;i++)if(indegree[i]!=0)return{};
        
      reverse(ans.begin(),ans.end());
      return ans;
    }
};