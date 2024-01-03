class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        float result = 1;
        float sum = 1;
        for (int i = 2; i <= n; i++)
        {
            result = sum/i;
            sum += result;
        }
        return result;
    }
};

//If first picks randomly first seat its okay. 1.0000
//...
//,,,
//Picks last - 0.00000

//If first picks second seat then plane have (n-1) avaliable seats. Second picks randomly
    //Pick of a second: 1/n for fist seat its okay - 1.0000
    //Pick of second: third then plane have (n-2) seats and third picks randomly
        // picks 1 - 1.00000
        /// pick another - (n-3) ... 
        // pick last - 0.000
    //Pick of second: last seat - 0.00000
//First picks Third seat - second picks second (like F(n-1) cause we just lose 1 passenger and seat from a task)


//Final answer is 1 - *probabilities of everybody except last picks last seat*\
//So the probability for somebody pick seat of first and end  the curious loop of seat changes - 1/(n-its number + 1)
//+1 cause list of passengers 1-indexed

//Lets think how we acn solve this if we know dp[1....n-1] and wants dp[n] where dp[n] - output for n as input of a problem
// dp[n] = 1/n * (1 + (???) + dp[n-1] ... + dp[1]);
// we will use dp[0] as a sum for dp[n-1] + ... + dp[1];

//So lets think whats (???) is.
// This is probability if first picks second seat
// So second BECOMES FIRST cause we have 1 "good" seat - first and cau think like we have F(n-1) task.
//Is dp[n] = 1/n * (1 + 2 * dp[n-1] ... + dp[1]); ??
//lets check
//n = 1 - base case return 1;
//n = 2. dp[2] = 1/2*(1+2) = 1.5. Its wrong.


//If first picks first we have 1.0 probability. its okay
//If first pick second, second becomes first BUTTTTT if somebody - last it cant become anybody else and become a dp[n-1] task.
//We can change it. in basic sum we need do change dp[1] to 0. If anybody pick last seat its 0% chance for last to sat on last seat
//sooo
//dp[n] = 1/n * (1 + 2 * dp[n-1] ... + dp[2] + 0]);
//lest think. dp[2] means first pick last-1 passengers so all between them will seat correctly.
// it will be 3 important passengenrs:
// first, who sat at second place
//second can sat at first and last 50/50 
// third will sat at last seat with 0.5 probability. yes. its dp[2]; (task for 2 passengenrs. We have 3 but first already pick second seat and it become task for 2 passengers).
//lets check
//n = 1 - base case return 1;
//n = 2. dp[2] = 1/2*(1+0) = 0.5. Good.
//n = 3 dp[3] = 1/3*(1 + 2*0.5 + 0) = 1/3*2 = 0.66. Idk is it true, If we simulate in mind we have
// if first picks first - 1.000
//if first picks second - second can pick 50/50 adn chance for third to seat correctly - 0.5
// dp[3] = 1/3 + 0.5/3 + 0.5/3 = 2/3. So in-miind corresponds to formula. LETS IMPLEMENT

//OKAY we have 
// dp[n] = 1/n * (1 + 2 * dp[n-1] + ... + dp[2] + 0]);
// 
// We will use dp[n] for sum 1 + 2 * dp[n-1] + ... + dp[2]

//are we need int dp[n]? i think no. just iterate by n and increase sum

// What a shame. dp[3] != 0.66667
// What i make wrong?
//sets simulate in-mind
// p = 1/3 (1 + p12 + 0)
//p12 = 1/2
// 0 = 1/3 * 3/2 = 1/2. What i made wrong?
//AH not 2*dp[n-1] + .. + . dp[n-1] + dp[n-2] + ... +
//Why? cause if forst pick second then yes its task for n-1 passenger
// BUT IF FIRST PICKS THIRD, THEN NOT ONLY SECOND ELEMINATES, also first
//dp[n] = (1+ dp[n-1] + ... + dp[2])/n
//dp[n] = (    1 + (1 + dp[n-2] + ... + dp[2])/n + dp[n-2] + ... + dp[2]    )/n
//dp[n] = (1*n-2)


//AFTER "Hint" check
//WHAT? prob === 1/2 for n >= 2;
//How?
//
//for n = 2 res = 2
// for n = 3:
// we add 0.5 to sum and 1 to divisor
// so formula is (1 + 0.5 + 0)/3
//WARNING 1 + 0 = 0.5 + 0.5!!!!!!!!!!!!!!!!!!!!!!!!!!! OH MY GOD
//for n  = 4 we add 0.5 and 1....
// (1+ 2*0,5)/4 = 0.5
//and continiously add 0.5 and 1. always 0.5
