class Solution {
public:
        long long power(long long x, long long n, long long mod){
        if(n == 0){
            return 1;
        }

        long long half = power(x, n/2, mod);
        

        if(n % 2 == 0){
            return (half * half) % mod;
        }
        else{
            return (x * half * half) % mod;
        }
    }

    int countGoodNumbers(long long n) {
        long long mod = 1000000007;
        long long evenIndices = (n+1)/2;
        long oddIndices = n/2;
        

        long long ans = power(5, evenIndices, mod)  * power(4, oddIndices, mod);

        return ans % mod;
    }
};