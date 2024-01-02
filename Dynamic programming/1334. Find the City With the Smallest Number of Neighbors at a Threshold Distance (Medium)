class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
// Vector shits - really better to do it only with dp[n][n]. (memory beats 30%). i will not update it for like beats 60% cause i want sleep
        vector<vector<int>> edges2;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for(int j = 0; j < n; j++)
            {
                if (i == j)
                    temp.emplace_back(0);
                else
                    temp.emplace_back(INT_MAX/2);
            }
                
            edges2.emplace_back(temp);
        }
        for (int i = 0; i < edges.size(); i++)
        {
            edges2[edges[i][0]][edges[i][1]] = edges[i][2];
            edges2[edges[i][1]][edges[i][0]] = edges[i][2];
        }
//Vector shit ended. We are created a matrix of ways
//now floyid-warshell algo
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j ++){
                for (int k = 0; k < n; k ++){
                    if(edges2[j][k] > (edges2[j][i] + edges2[i][k]))
                        edges2[j][k] = edges2[j][i] + edges2[i][k];
                }
            }
        }
    int min = INT_MAX;
    int m = 0;
// just count and found minimum
    for (int i = 0; i < n; i ++){
        int result = 0;
        for (int j = 0; j < n; j ++)
            if (edges2[i][j] <= distanceThreshold)
                result++;
        if(result <= min)
        {
            
            min = result;
            m = i;
        }
    }
        return m;
    }
    
};
