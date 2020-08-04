#define ll long long int
class Solution {
public:
    const ll mod = 1000000007;
    ll memo[51][51][51];
    int dir[5] = {1,0,-1,0,1};
    int findPaths(int m, int n, int N, int i, int j) {
        memset(memo, -1, sizeof(memo));
        return dfs(m, n, i, j, N);
    }
    ll dfs(int m, int n, int i, int j, int N){
        if(i >= m || j >= n || i < 0 || j < 0) return 1;
        if(N == 0) return 0;
        if(memo[N][i][j] != -1) return memo[N][i][j];
        ll ret = 0;
        for(int d= 0 ;d < 4; ++d){
            ret += (dfs( m, n, i+dir[d], j+dir[d+1], N -1)) % mod;
            ret %= mod;
        }
        memo[N][i][j] = ret;
        return ret;
        
    }
};
