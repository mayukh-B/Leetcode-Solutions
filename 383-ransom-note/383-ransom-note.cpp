class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char,int>mp1,mp2;
        
        for(char x : ransomNote) mp1[x]++;
        
        for(char x : magazine) mp2[x]++;
        
        
        for(char x : ransomNote){
            if(mp2[x]<mp1[x])return false;
        }
        
        return true;
    }
};