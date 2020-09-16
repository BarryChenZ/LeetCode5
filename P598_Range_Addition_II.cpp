class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int r, l;
        for(int i = 0; i < ops.size(); i++){
            l = min(l, ops[i][0]);
            r = min(r, ops[i][1]);
        }
        int res = min(l, m) * min(r, n);
        return res;
    }
};
