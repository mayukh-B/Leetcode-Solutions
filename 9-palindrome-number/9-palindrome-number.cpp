class Solution {
public:
    bool isPalindrome(int x) {
         if( x<0 || ( x % 10==0 &&x!=0))
        return false;

    int revno = 0;
    while(x>revno){
            revno=revno*10 + x%10;
                x=x/10;
        }
    return x==revno || x==revno/10;
    }
};