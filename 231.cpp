class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if(n <= 0){
        //     return false;
        // }
        
        // while(n>0){
        //     if(n%2==1 && n!=1){
        //         return false;
        //     }
        //     n = n/2;
        // }
        // return true;

        return n > 0 && ((n&(n-1)) == 0);
    }
};

//TC: O(1);
//SC: O(1);