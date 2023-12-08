#define M 1000000007
class Solution {
private:
    int pow(int x, long long n){
        if(n == 1){
            return x%M;
        }
        if(n & 1){
            return (1LL * x%M * pow((1LL*x%M*x%M)%M, n/2)%M)%M;
        }
        return pow((1LL*x%M*x%M)%M, n/2)%M;
    }
public:
    int countGoodNumbers(long long n) {
        if(n == 1){
            return 5;
        }
        if(n & 1){
            return (1LL*5*pow(20, n/2))%M;
        }
        return pow(20, n/2);
    }
};

//TC: O(log n);
//SC: O(n);