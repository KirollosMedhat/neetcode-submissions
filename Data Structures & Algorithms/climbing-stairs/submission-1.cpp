class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        
        vector<int> cache(n+1);
        cache[2] = 2;
        cache[1] = 1;
        for(int i = 3; i <= n; i++){
            cache[i] = cache[i-1] +  cache[i-2] ;
        }

        return cache[n];
    }
};
