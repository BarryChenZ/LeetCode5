class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty()) return 0;
        vector<bool> visited(M.size(), false);
        int res = 0;
        for(int i = 0; i < visited.size(); i++){
            res += !visited[i] ? dfs(M, visited, i),1 : 0;
        }
        return res;
    }
    void dfs(vector<vector<int>>& M, vector<bool>& visited, int i){
        visited[i] = true;
        for(int j = 0; j < visited.size(); j++){
            if(i != j && !visited[j] && M[i][j]){
                dfs(M, visited, j);
            }
        }
    }
};
