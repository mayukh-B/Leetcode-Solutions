class Solution {
public:
//     vector<string>solve(int n){
        
        
//         if(n==0){
//             return {"1"};
//         }
//         if(n<0)return {};
        
//         vector<string>p1 = solve(n-1);
//         vector<string>p2 = solve(n-2);
//         vector<string>p;
//         for(string x : p1){
//             p.push_back("1"+x);
//         }
//          for(string x : p2){
//             p.push_back("2"+x);
//         }
        
//         return p;
//     }
    
    
    
    int climbStairs(int n) {
        // vector<string>ans = solve(n);
        // return ans.size();
         if(n<1) return 0;
        int a[100];
        a[0]=1;
        a[1]=2;
        for(int i=2;i<n;i++)
            a[i]=a[i-1]+a[i-2];
        return a[n-1];
    }
};