class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size();
        int x =n;
        for(int i =0;i<n;i++){
            x = x^ i^ nums[i];
        }
        
        return x;
    }
};