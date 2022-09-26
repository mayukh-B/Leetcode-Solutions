class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt =0;
        int elem;
        for(int num : nums){
            if(cnt == 0){
                elem = num;
            }
            if(num == elem)cnt+=1;
            if(num != elem)cnt-=1;
        }
        
        return elem;
    }
};