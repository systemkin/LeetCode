//Struggled for this a night cause i was thhinking we need 10*n (alot memory) matrix but real we need only previous step.
//checked solutions page but really nothing was heelpful. idk why people use so strange methods.
//this beats 90% reliable
class Solution {
public:

    int knightDialer(int n) {
        int dp[2][10];
        for (int i = 0; i < 10; i++)
            dp[0][i] = 1;
        for (int i = 1; i < n; i++) {
            int currRow = i%2;
            int prevRow = (i-1)%2;
            dp[currRow][0] = (dp[prevRow][4] + dp[prevRow][6])%1000000007;
            dp[currRow][1] = (dp[prevRow][6] + dp[prevRow][8])%1000000007;
            dp[currRow][2] = (dp[prevRow][7] + dp[prevRow][9])%1000000007;
            dp[currRow][3] = (dp[prevRow][4] + dp[prevRow][8])%1000000007;
            dp[currRow][4] = ((dp[prevRow][3] + dp[prevRow][9])%1000000007 + dp[prevRow][0])%1000000007;
            dp[currRow][5] = 0;
            dp[currRow][6] = ((dp[prevRow][1] + dp[prevRow][7])%1000000007 + dp[prevRow][0])%1000000007;
            dp[currRow][7] = (dp[prevRow][2] + dp[prevRow][6])%1000000007;
            dp[currRow][8] = (dp[prevRow][1] + dp[prevRow][3])%1000000007;
            dp[currRow][9] = (dp[prevRow][2] + dp[prevRow][4])%1000000007;
        }
    int result = 0;
    
    for (int i = 0; i < 10; i++)
            result = (result + dp[(n-1)%2][i])%1000000007;;
    return (result)%1000000007;
    }
};
