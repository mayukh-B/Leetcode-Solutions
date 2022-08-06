class Solution {
public:
    
    string converter(string s){
        string str="";
        for(int i=0;i<=s.size();i++){
            char x = s[i];
           if((x >= 'a' and x<='z')or(x>='A' and x<='Z') or (x>='0' and x<='9')){
                str+=tolower(x);
           }
        }
        cout<<str;
        return str;
    }
    bool isPalindrome(string s) {
       string str= converter(s);
        
        int l=0,h=str.size()-1;
        while(l<=h){
            // cout<<str[l]<<" "<<str[h]<<endl;
            if(str[l++]!=str[h--])return false;
        }
        
        return true;
    }
};