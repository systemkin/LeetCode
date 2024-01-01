//In discussoun page was "try look for a pattern".
//So thats why i implement this  without knowing math under pattern
class Solution {
public:
    int numTilings(int n) {
        switch (n)
        {
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 5;
            default:
                long left = 1;
                long center = 2;
                long right = 5;
                long next = 0;
                long moduloBase = (pow(10, 9) + 7);
                for(int i = 3; i < n; i++)
                {
                    next = (2*right + left)%moduloBase;
                    left = center;
                    center = right;
                    right = next;
            
                }
                return next;
        }
        
    }           
};
