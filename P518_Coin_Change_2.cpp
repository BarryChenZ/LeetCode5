class Solution {
private:
    //vector<vector<int>> dp;
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
        dp[0][0] = 1;
        for(int i = 1; i <= coins.size(); i++){
            dp[i][0] = 1;
            for(int j = 1; j <= amount; j++){
                dp[i][j] = dp[i-1][j];//不包含
                if(j - coins[i-1] >= 0){
                    dp[i][j] += dp[i][j - coins[i-1]];//包含
                }
            }
        }
        return dp[coins.size()][amount];   
    }
    /*
    int dfs(int amount, vector<int>& coins, int currentIndex, vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(amount < 0 || currentIndex == coins.size()) return 0;
        
        if(dp[currentIndex][amount] != NULL) return dp[currentIndex][amount];
        
        int sum1 = dfs(amount-coins[currentIndex], coins, currentIndex, dp);
        int sum2 = dfs(amount, coins, currentIndex + 1, dp);
        dp[currentIndex][amount] = sum1 + sum2;
        return dp[currentIndex][amount];
    }
    */
};
