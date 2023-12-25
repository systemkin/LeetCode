/*
// Trying to find characters for note from magazine
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;
        while(!ransomNote.empty())
        {
            int pos = magazine.find(ransomNote.back());
            if (pos != -1)
            {
                ransomNote.pop_back();
                magazine.erase(pos, 1);
            }
            else return false;
        }
        return true;
    }
};
*/
// Trying to find place for magazine characters in note.
// IDK WHY THIS IS FASTER. I mean complexity-s is m*n and n*m
// After submitting first solution i got beats around 5% for runtime and 50-80% for memory
//This is 69.47% and 85.78% (randomed to beat 97% on memory)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        while((ransomNote.size()) && (ransomNote.size() <= magazine.size()))
        {
            int pos = ransomNote.find(magazine.back());
            magazine.pop_back();
            if (pos != -1)
                ransomNote.erase(pos, 1);
        }
        return !ransomNote.size();
    }
};
