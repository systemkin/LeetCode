class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1; i < s.size()/2+1; i++)
        {
            //If string can't consist of i*n elements - then create new substring
            if(s.size() % i != 0)
                continue;
             //Create a substring with first "i" elements
            string sub = s.substr(0, i);
            for(int j = 1; j < s.size()/i; j++)
                if(s.substr(j*i, i) != sub)
                    //If string not a repeated substring - then create new substring size (i+1). go to end of main "for"
                    goto A;
            //If string - repeated substring. substring size = i
            return true;  
            A:;
        }
        // if none of substrings represents a pattern
        return false;
    }
};
