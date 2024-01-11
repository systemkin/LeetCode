class Solution {
public:
	int videoStitching(vector<vector<int>>& clips, int time) {
		sort(begin(clips), end(clips));
        int currentMaxLen = 0;
        int res = 0;
        if (clips[0][0] > 0)
            return -1;
        int maxFoundLen = clips[0][1];
        //return clips[3][0];
		for (int i = 0; (i < clips.size()) && (maxFoundLen < time); i++) {
            if (clips[i][0] > currentMaxLen)
                if (clips[i][0] > maxFoundLen)
                    return -1;
               else { 
                   currentMaxLen = maxFoundLen;
                   res++;
               }
            maxFoundLen = std::max(clips[i][1], maxFoundLen);
        }
        if (maxFoundLen < time)
            return -1;
        if (currentMaxLen < time)
            res++;
        return res;

	}
};
