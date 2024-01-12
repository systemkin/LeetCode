class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        long long extremumMax = INT_MIN;
        long long extremumMin = INT_MAX;
        long long res = 0;
        bool force = false;
        if (nums[0] > nums[1])
            res += nums[0];
        else force = true;
        for (int i = 2; i < nums.size(); i++) {
            if((force) && nums[i] < nums[i-1]) {
                res += nums[i-1];
                force = false;
            }
            else if((!force) && nums[i] > nums[i-1]) {
                res -= nums[i-1];
                force = true;
            }
        }
        if (force)
            res += nums.back();
        return res;
    }
};
