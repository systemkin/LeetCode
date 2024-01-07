class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) 
            return 1;
        int way = 0;
        int last = 1;
        int cnt = 1;
        if (nums[1] != nums[0]) {
            cnt++;
            if (nums[1] > nums[0]) 
                way = 1;
            else way = -1;
        }
        
        for (int i = 2; i < nums.size(); i++) {
            if ((nums[i] < nums[i-1]) && (way != -1)) {
                way = -1;
                cnt++;
            }
            else if ((nums[i] > nums[i-1]) && (way != 1)) {
                way = 1;
                cnt++;
            }
        }
        return cnt;    
    }
};
