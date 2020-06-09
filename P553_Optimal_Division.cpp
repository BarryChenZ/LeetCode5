class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        string expr;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                expr += "/";
            }
            if (i == 1 && n > 2) {
                expr += "(";
            }
            expr += to_string(nums[i]);
            if (i == n - 1 && n > 2) {
                expr += ")";
            }
        }
        return expr;
    }
};
