//Unsigned integer represented as vector of digits
//Task: make function f(x) = x+1 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int pos = digits.size()-1;
        for(int pos = digits.size()-1; pos != -1; pos--)
        {
            if (digits[pos] <= 8)
            {
                digits[pos] += 1;
                return digits;
            }
            digits[pos] = 0;
        }
        digits[0] = 1;
        digits.emplace_back(0);
        return digits;
    }
};
