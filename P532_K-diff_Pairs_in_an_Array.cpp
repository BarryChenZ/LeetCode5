class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        unordered_map<int, int> record;
        
        for(auto num : nums) record[num]++;
        
        int cnt = 0;
        for(auto i : record){
            if((k == 0 && i.second > 1) || 
               (k != 0 && record.count(i.first + k))) cnt++;
        }
        return cnt;
        
    }
};
