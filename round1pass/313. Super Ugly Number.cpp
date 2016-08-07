class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size = primes.size();
        vector<int> num(1, 1), index(size, 0);
        while(num.size() < n) {
            int temp = INT_MAX;
            for(int i = 0; i < size; i ++)
                temp = min(temp, num[index[i]] * primes[i]);
            num.push_back(temp);
            for(int i = 0; i < size; i ++)
                if(temp == num[index[i]] * primes[i])
                    index[i] ++;
        }
        return num.back();
    }
};