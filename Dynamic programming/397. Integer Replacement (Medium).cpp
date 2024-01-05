/*
class Solution {
public:
    int integerReplacement(int n) {
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <=n; i++)
            if (i%2 == 0)
                dp[i] = dp[i/2] + 1;
            else
                dp[i] = min(dp[(i-1)/2]+2, dp[(i+1)/2]+2);
        return dp[n];
    }
};
*/
class Solution {
public:
    int integerReplacement(long n) {
        if (n==1)
            return 0;
        if (n%2 != 0)
            return 2+min(integerReplacement((n-1)/2) , integerReplacement((n+1)/2));
        else
            return 1+integerReplacement(n/2);
    }
};
