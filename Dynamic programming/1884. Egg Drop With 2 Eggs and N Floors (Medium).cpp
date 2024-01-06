class Solution {
public:
    int twoEggDrop(int n) {
        int i = 1;
        for (; n > 0; i++)
        {
            n-=i;
        }
        return i-1;
    }
};
