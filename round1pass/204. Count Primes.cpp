class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
	            return 0;
	        bool * notPrime = new bool [n];
	        memset(notPrime, false, sizeof(bool) * n);
	        for(int i = 4; i < n; i = i + 2)
	            notPrime[i] = true;
	        for(int i = 3; i < sqrt(n); i = i + 2) {
	            if(!notPrime[i]) {
	                for(int j = i * i; j < n; j = j + 2 * i) {
	                    notPrime[j] = true;
	                }
	            }
	        }
	        int count = 0;
	        for(int i = 2; i < n; i ++)
	            if(!notPrime[i])
	                count ++;
	        return count;
    }
};