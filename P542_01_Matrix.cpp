class Solution {
public:
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, -1, 0, 1};
           
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(),-1));
        queue<pair<int,int>> q;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int, int> tmp = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int xd = tmp.first + x[i];
                int yd = tmp.second + y[i];
                if(xd >= 0 && yd >= 0 && xd < matrix.size() && yd < matrix[0].size() && matrix[xd][yd] == 1 && ans[xd][yd] == -1){
                    ans[xd][yd] = ans[tmp.first][tmp.second] + 1;
                    q.push({xd,yd});
                }
            }
        }
        return ans;
    }
};
