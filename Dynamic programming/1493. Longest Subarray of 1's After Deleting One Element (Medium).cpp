class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int np = 0;
        int sp = 0;
        int size = 0;
        int max = 0;
        bool stepOver = false;
        for (int i = 0; sp+i < nums.size(); i++) {
            if (nums[sp+i] == 1)
                size++;
            else if (!stepOver) {
                stepOver = true;
                np = sp+i;
            }
            else {
                max = std::max(max, size);
                size = 0;
                stepOver = false;
                sp = np;
                if (nums[sp] == 0) 
                    sp++;
                i=-1;
            }
        }

        if (size == nums.size())
            return size-1;
        return std::max(max, size);
    }   
};
