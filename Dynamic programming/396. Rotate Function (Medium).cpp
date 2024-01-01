/*You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int result = 0;
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            result += nums[i]*i;
            sum += nums[i];
        }
        int max = result;
        //After rotate value += sum of all digits - last digit*size (cause all digits except last moves -> and its mean a more time to add it)
        //thats the main idea
        for(auto i = nums.end()-1; i != nums.begin(); i--)
        {
            result += sum - (*i)*nums.size();
            if (result > max)
                max = result;
        }
        return max;
    }
};
