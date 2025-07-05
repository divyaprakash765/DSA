class Solution {
public:
    bool isPowerOfThree(int n) {
     if(n == 0) return false;

     for(int i=1;i<100;i++){
        if(n%3 == 0){
            n /= 3;
        }
        else break;
        if(n == 1) break;
     }
     return n == 1;
    }
};