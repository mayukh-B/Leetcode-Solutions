class Solution {
public:
  const vector<string>codes={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string>solve(string digits){
         if(digits.size() == 0)return {""};
        
        char ch = digits[0];
        string ros = digits.substr(1);

        
        vector<string>aros = solve(ros);
        vector<string>mans;
        // vector<string>aros ={"ug","gh","ij"};
        
         string codeForCh = codes[ch-'0'];
            for(int i =0 ;i<codeForCh.size();i++){
                 // if(codeForCh=="")continue;
               char chcode = codeForCh[i]   ;
                for(string rstr : aros){
                    
                    mans.push_back(chcode + rstr);
                    
                }
            }
    
        return mans;
    }
    
    vector<string> letterCombinations(string digits) {
    
        if(digits.size() == 0)return {};
        
        return solve(digits);
       
    }
};

