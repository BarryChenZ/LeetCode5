class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, pre = 0;
        unordered_set<int> m;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;
            if(m.count(mod)) return true;
            m.insert(pre);
            pre = mod;
        }
        return false;
    }
};
