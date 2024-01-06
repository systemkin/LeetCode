class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        F(1, n, cost);
        return result;
    }

    int F(int i, int n, vector<int>& cost) {
        if (i > n/2)
            return cost[i-1];
        int F1 = F(i*2, n, cost);
        int F2 = F(i*2+1, n, cost);
        result += abs(F1-F2);
        cost[i-1] += max(F1, F2);
        return cost[i-1];
    }
int result = 0;
};
