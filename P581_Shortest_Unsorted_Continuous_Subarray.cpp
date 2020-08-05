class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums.size());
        for(int i = 0; i < nums.size(); i++){
            temp[i] = nums[i];
        }
        
        sort(nums.begin(), nums.end());
        
        int front = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(temp[i] != nums[i]){
                front = i;
                break;
            }        
        }
        if(front == INT_MIN) return 0;
        int end = INT_MAX;
        
        for(int i = nums.size() - 1; i >= 0; i--){
            if(temp[i] != nums[i]){
                end = i;
                break;
            }
        }
        
        return end - front + 1;
    }
};
