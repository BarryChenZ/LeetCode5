class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> m;
        for(int i = 0; i < candies.size(); i++){
            if(m.find(candies[i]) == m.end()){
                m[candies[i]] = 0;
            }
            m[candies[i]] ++;
        }
        
        unordered_map<int, int>::iterator it;
        int res = 0;
        for(it = m.begin(); it != m.end(); it++){
            res++;
        }
        return res > candies.size() / 2 ? candies.size() / 2 : res;
    }
};
