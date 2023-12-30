//Chek is s the subsequence of t
//s = "abc", t = "adbdc" - true
//s = "abc", t = "bac" - false
class Solution {
public:
    bool isSubsequence(string s, string t) {
        while ((s.size() > 0) && (t.size() > 0))
        {
            if (s.back() == t.back())
                s.pop_back();
            t.pop_back();
        }
        return !s.size();
    }
};
