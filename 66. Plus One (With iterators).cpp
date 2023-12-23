class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(vector<int>::iterator i = digits.end()-1; i >= digits.begin(); i--)
        {
            //digits[0] = *i;
            if (*i <= 8)
            {
                i = digits.insert(i, *i+1);
                digits.erase(i+1);
                return digits;
            }
            
            digits.erase(i);
            digits.insert(i, 0);
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
