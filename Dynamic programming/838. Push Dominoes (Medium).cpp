class Solution {
public:
    string pushDominoes(string dominoes) {
        if (dominoes.size() < 2)
            return dominoes;
        bool force = false;
        int Rpos;
        for (int i = 0; i < dominoes.size(); i++) {
            if (force && (dominoes[i] != 'L')) 
                dominoes[i] = 'R';

            else if (dominoes[i] == 'R') {
                force = true;
                Rpos = i;
            }

            else if (force && (dominoes[i] == 'L')) {
                for (int j = Rpos+1; j <= (Rpos+i)/2; j++) {
                    dominoes[j] = 'R';
                    dominoes[Rpos-j + i] = 'L';
                }
                if ((Rpos + i) % 2 != 1)
                    dominoes[(Rpos+i)/2] = '.';
                
                force = false;
            }
        }

        //Some of optimization can be done here
        for (int i = dominoes.size()-1; i > 0; i--)
            if (dominoes[i] == '.' && dominoes[i+1] == 'L' && dominoes[i-1] != 'R')
                dominoes[i] = 'L';
        if (dominoes[0] == '.' && dominoes[1] == 'L')
            dominoes[0] = 'L';
        return dominoes;
    }
};
