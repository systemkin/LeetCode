class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.size(); i++)
        {
            for(int j = 0; j < needle.size(); j++)
            {
                if (haystack[i+j] != needle[j])
                    goto A;
            }
            return i;
            A:
            ;
        }
        return -1;
    }
};
