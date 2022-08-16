class Solution {
public:
    int firstUniqChar(string s) {
        map<int,int>mp;
        
        for(auto x : s){
            mp[x]++;
        }
        int i=0;
        for(auto x : s){
            if(mp[x]==1)return i;
            i++;
        }
        
        return -1 ;
    }
};