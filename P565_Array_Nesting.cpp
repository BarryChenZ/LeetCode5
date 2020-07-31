class Solution {
public:
    int res = 0;
    int arrayNesting(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == false){
                int idx = nums[i], distance = 1;
                idx = nums[idx];
                while(idx != nums[i]){
                    idx = nums[idx];
                    distance ++;
                    visited[idx] = true;
                }
                res = max(res, distance);
            }
        }
        return res;
    }
};
