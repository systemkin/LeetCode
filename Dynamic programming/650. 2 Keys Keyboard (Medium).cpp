class Solution {
public:
    int minSteps(int n) {
        if (n==1)
            return 0;
        //Prime numbers?
        //Find prime*n
        //24 = 2*12 then f(24) = F(2) + F(12) (almost)
        for (int i = 2; i < n; i++)
            if (n%i == 0)
                return minSteps(n/i) + 1 + i-1; //-1 cause 4*3 we dont neec paste 4 3 times. we have 4 already
        return n;
    }
};
