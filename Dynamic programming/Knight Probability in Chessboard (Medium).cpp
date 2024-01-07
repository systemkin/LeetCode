/*class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        if ((row < 0) || (column < 0) || (row >= n) || (column >= n))
            return 0;
        else if (k!= 0) {
            double res = (
                knightProbability(n, k-1, row-2, column-1) + 
                knightProbability(n, k-1, row-2, column+1) + 
                knightProbability(n, k-1, row-1, column-2) + 
                knightProbability(n, k-1, row-1, column+2) + 
                knightProbability(n, k-1, row+1, column-2) + 
                knightProbability(n, k-1, row+1, column+2) + 
                knightProbability(n, k-1, row+2, column-1) + 
                knightProbability(n, k-1, row+2, column+1) );
            return res/8;
        }
        else 
            return 1;
            
    }
};
*/

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        //Make 2 desks with additional 4 rows and columns. (like 2-sized border for knights who will go off from board)
        double dp[2][n+4][n+4];

        //Initialize both desks with 0
        for (int i = 0; i < n+4; i++)
            for (int j = 0; j < n+4; j++) {
                dp[0][i][j] = 0;
                dp[1][i][j] = 0;
            }
        //Set a probability of a knight to be on a starting square if 0 moves made on first desk is 1
        dp[0][row+2][column+2] = 1;
        
        //m is counter for steps, step №0 already made.
        for (int m = 1; m <= k; m++) {
            //i, j - column and row of board (except borders, them will stay 0, cause no knights can stay over the desk)
            for (int i = 2; i < n+2; i++)
                for (int j = 2; j < n+2; j++)
                    // count probability  of knight to be on i col and j row after m moves made based on previous desk. Then switch desks untill you made k moves
                    // m%2 cause we have 2 boards and m%2 will be 1, 0, 1, 0 - desk switching. (m-1)%2 - prev desk
                    dp[m%2][i][j] = ( 
                    dp[(m-1)%2][i-2][j-1] + 
                    dp[(m-1)%2][i-2][j+1] + 
                    dp[(m-1)%2][i-1][j-2] + 
                    dp[(m-1)%2][i-1][j+2] + 
                    dp[(m-1)%2][i+1][j-2] + 
                    dp[(m-1)%2][i+1][j+2] + 
                    dp[(m-1)%2][i+2][j-1] + 
                    dp[(m-1)%2][i+2][j+1])/8;
                    //Knight can move to square from 8 positions. borders have value == 0, so borders not interfere result, 
        }

        //count result as a sum of prob-ties of being on each square of a desk
        double result = 0;
        for (int i = 2; i < n+2; i++)
            for (int j = 2; j < n+2; j++)
                result += dp[k%2][i][j];
        return result;
    }
};
