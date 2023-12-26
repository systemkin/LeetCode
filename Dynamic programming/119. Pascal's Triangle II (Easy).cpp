/*
Get info about row in a pascal's triangle
like:
0 -> 1
1 -> 1, 1
2 -> 1, 2, 1
3 -> 1, 3, 3, 1
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result{1};
        for(int row = 0; row < rowIndex; row++)
        {
            for(int column = result.size()-1; column > 0; column--)
            {
                result[column] += result[column-1];
            }
            result.emplace_back(1);
        }
        return result;
    }
};
