class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>right,left;
        int temp=1;
        
        for(int i=0;i<nums.size();i++){
            if(i>0){
                temp = temp*nums[i-1];
            }
            
            left.push_back(temp);
        }
        
        
        // for(auto x : left)cout<<x<<" ";
        
        temp=1;
        
        for(int i=nums.size()-1;i>=0;i--){
            if(i<nums.size()-1)temp*=nums[i+1];
            
            right.push_back(temp);
        }
        
        reverse(right.begin(),right.end());
        
         // for(auto x : right)cout<<x<<" ";
        
        for(int i=0;i<nums.size();i++){
            left[i]*=right[i];
        }
        
        return left;
    }
};