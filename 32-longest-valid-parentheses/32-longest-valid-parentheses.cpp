class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char>char_stack;
        stack<int>ind_stack;
        int len =0;
        
        ind_stack.push(-1);
        for(int i=0;i<s.size();i++){
            char x = s[i];
            if(x == '('){
                char_stack.push('(');
                ind_stack.push(i);
            }else{
               if(!char_stack.empty()){
                   char_stack.pop();
                   ind_stack.pop();
                   len = max(len, i-ind_stack.top());
               }else{
                   ind_stack.push(i);
               }
            }
        }
        return len;
    }
};