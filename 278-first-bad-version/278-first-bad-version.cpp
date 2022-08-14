// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=0;
        int e=n;
        
        while(e-s>1){
            int m = s+(e-s)/2;
            
            if(isBadVersion(m))e=m;
            else
                s=m;
        }
        
        return e;
    }
};