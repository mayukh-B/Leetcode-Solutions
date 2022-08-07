class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int x : nums)mp[x]++;
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        
        for(auto it=mp.begin() ; it!=mp.end(); it++){
             pq.push({it->second,it->first});
            if(pq.size()>(int)mp.size()-k){
                int t = pq.top().second;
                ans.push_back(t);
                pq.pop();
            }
            
          
        }
        return ans;
    }
};