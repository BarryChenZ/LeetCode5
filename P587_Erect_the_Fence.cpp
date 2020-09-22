class Solution {
public:
    int orientation(vector<int> p1, vector<int> p2, vector<int> p3){
        return (p2[0] - p1[0])*(p3[1] - p2[1]) - (p2[1] - p1[1])*(p3[0] - p2[0]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        if(points.size() < 4) return points;
        
        sort(points.begin(), points.end(), [](vector<int> p1, vector<int> p2){
            return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
        });
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < points.size(); i++){
            while(ans.size() >= 2 && orientation(ans[ans.size()-2], ans.back(), points[i]) < 0) ans.pop_back();
            
            ans.push_back(points[i]);    
        }
        
        if(ans.size() == points.size()) return ans;
        
        for(int i = points.size() -2 ; i >= 0; i--){
            while(ans.size() >= 2 && orientation(ans[ans.size()-2], ans.back(), points[i]) < 0)
                ans.pop_back();
            ans.push_back(points[i]);
        }
        
        ans.pop_back();
        return ans;
    }
};
