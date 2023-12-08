class Solution {
private:
    double solve(double x, int n, int count){
        if(count == n){
            return 1;
        }

        return x * (double)solve(x, n, count + 1);
    }

    double solve2(double x, int n){
        if(n == 1 || n == -1){
            return x;
        }

        if(n & 1){
            return x*solve2(x*x, n/2);
        }
        return solve2(x*x, n/2);
    }

public:
    double myPow(double x, int n) {
        if(x == 0 || x == 1){
            return x;
        }
        if(n == 0){
            return 1;
        }
        if(n < 0){
            x = 1/x;
            // n = -n;
        }

        // return solve(x, n, 0);
        return solve2(x, n);
    }
};

//TC: O(log n);
//SC: O(n);