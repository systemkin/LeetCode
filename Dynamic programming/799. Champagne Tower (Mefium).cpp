/*
We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  Each glass holds one cup of champagne.

Then, some champagne is poured into the first glass at the top.  When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.  When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.  (A glass at the bottom row has its excess champagne fall on the floor.)
/*

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<float> filled = {(float) poured} ;
        for (int i = 1; i <= query_row; i++)
        {
            if (filled.back() > 1)
                filled.emplace_back((filled.back()-1)/2);
            else
                filled.emplace_back(0);
            for(int j = i-1; j > 0; j--)
            {
                if (filled[j] > 1)
                    filled[j] = (filled[j]-1)/2;
                else filled[j] = 0;
                if (filled[j-1] > 1)
                    filled[j] += (filled[j-1]-1)/2;
            }
            if(filled[0] > 1)
                filled[0] = (filled[0]-1)/2;
            else
                filled[0] = 0;
        }
        if (filled[query_glass] > 1)
            return 1;
        return filled[query_glass];
    }

};
