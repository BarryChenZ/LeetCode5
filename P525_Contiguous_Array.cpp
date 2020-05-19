class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return 0;   
        //sum = 1/2 * size
        map<int, int> m;
        int cntZero = 0, cntOne = 0;
        int out = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]) cntOne++;
            else cntZero++;
            
            if(cntOne == cntZero){
                out = max(out , i + 1);
            }
            
            if(m.find(cntOne-cntZero) == m.end()) m[cntOne-cntZero] = i;
            else out = max(out, i - m[cntOne-cntZero]);
        }
        return out;
    }
};
