class Solution {
    public int lengthOfLIS(int[] a) {
         Set<Integer> set = new TreeSet<>();
    for(int x: a){
        set.add(x);
    }
    int[] b = new int[set.size()];
    int k = 0;
    for(int x: set){
        b[k] = x;
        k++;
    }
    int m = a.length;
    int n = b.length;
    
    int[][] dp = new int[m+1][n+1];
    for(int i = 0; i < m + 1; i++){
        for(int j = 0; j < n + 1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1; i < m + 1; i++){
        for(int j = 1;j < n + 1; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j]  = Math.max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
    
    
}
}
