class Solution {
public:
    int countSubstrings(string s) {
        int res = 1;
        for (int i = 1; i < s.size(); i++)
        {
            res++;
            for (int j = 0; j < i; j++)
            {
                int sizeOfSubstring = (i-j)/2 + (i-j)%2;
                for (int k = 0; k < sizeOfSubstring; k++)
                    if(s[j+k] != s[i-k])
                        goto A;
                res++;
                A:;
            }
        }
        return res;
    }
};
