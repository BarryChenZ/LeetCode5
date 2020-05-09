class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        for(auto m : machines) sum+= m;
        int n = machines.size();
        if(sum % n != 0) return -1;
        int target = sum / n;
        int ans = 0, co = 0;
        for(int i = 0; i < n; i++){
            co += machines[i] - target;
            ans = max(ans, max(abs(co), machines[i] - target));
        }
        return ans;
    }
};
